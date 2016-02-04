/*************************************************************************
                           Fonctions  -  description
                             -------------------
    début                : 12/01/2016
    copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	
*************************************************************************/
#include "Fonctions.h"
#include "Command.h"
#include <stdexcept>

//---------------------------- Fonctions --------------------------------
int Parseur(const string & donnees, const char separateur, string *tab, const int taille)
{
	int p = 0;
	string m = "";
	for(unsigned int i=0;i<donnees.length();i++)
	{	if(p< taille)
		{	if(donnees[i] != separateur)
			{	m +=  donnees[i];
			}
			else
			{	tab[p] = m;
				m = "";
				p++;
			}
		}
		else
		{	break;
		}
	}
	if(m != "" && p< taille)
	{	tab[p] = m;
		p++;
	}
	return p;
}

bool interpretreCommande(string commande, Dessin *dessin, UndoRedo *pile, map<string,Figure*> *exclu, bool callByUndoRedo) 
{
		string nomCommande = getCommande(commande);
		int nParam = getNbParametre(commande);
		if(nomCommande == "HIT" && nParam == 4)
		{	try 
			{	int x = atoi(getParametre(commande,2).c_str());
				int y = atoi(getParametre(commande,3).c_str());
				Vect p(x,y);
				if(dessin->IsInFigure(getParametre(commande,1),p))
				{	cout << "YES" << endl;
				}
				else
				{	cout << "NO" << endl;
				}
			}
			catch(std::invalid_argument& e)
			{	cout << "NO" << endl;
				return false;
			}	
		}
		else if(nomCommande == "LIST")
		{	cout << *dessin << endl;
		}
		else if(nomCommande == "DELETE" && nParam >= 1)
		{	string name;
			for(int i=1;i<nParam;i++)
			{
				name = getParametre(commande,i);
				Figure *f = dessin->GetFigure(name);
				if(f != NULL)
				{	string t = getCommande(f->Print());
					if(t == "OI" || t == "OR")
					{	Figure *f1 = f->Copy();
						(*exclu)[f1->GetName()] = f1;
						Command c(commande,"RECUP " + f->GetName());
						if(!callByUndoRedo)
						{	pile->AddUndo(c);
						}
					}
					else
					{	Command c(commande,"ADD " + f->Print());
						if(!callByUndoRedo)
						{	pile->AddUndo(c);
						}
					}
				}
				if(dessin->Remove(name))
				{	cout << "OK" << endl;
				}
				else
				{	cout << "ERR" << endl;
				}
			}
		}
		else if(nomCommande == "MOVE" && nParam == 4)
		{	try 
			{	int x = atoi(getParametre(commande,2).c_str());
				int y = atoi(getParametre(commande,3).c_str());
				Vect p(x,y);
				Figure *f = dessin->GetFigure(getParametre(commande,1));
				if(f != NULL)
				{
					Vect p2(-x,-y);
					Command c(commande,"MOVE " + f->GetName() + " " + p2.Print());
					if(!callByUndoRedo)
					{	pile->AddUndo(c);
					}
				}
				if(dessin->MoveFigure(getParametre(commande,1),p))
				{	cout << "OK" << endl;
				}
				else
				{	cout << "ERR" << endl;
				}
			}
			catch(std::invalid_argument& e)
			{	cout << "ERR" << endl;
				return false;
			}
		}
		else if(nomCommande == "REDO" && nParam == 1)
		{	string cmd = pile->Redo();
			//cout << cmd << endl;
			if(getCommande(cmd) == "RECUP")
			{	Figure *f = (*exclu)[getParametre(cmd,2)]->Copy();
				delete (*exclu)[getParametre(cmd,2)];
				exclu->erase(getParametre(cmd,2));
				return dessin->Add(f);
			} 
			else
			{	return interpretreCommande(cmd, dessin, pile, exclu, true);
			}
		}
		else if(nomCommande == "UNDO" && nParam == 1)
		{	string cmd = pile->Undo();
			//cout << cmd << endl;
			if(getCommande(cmd) == "RECUP")
			{	Figure *f = (*exclu)[getParametre(cmd,2)]->Copy();
				delete (*exclu)[getParametre(cmd,2)];
				exclu->erase(getParametre(cmd,2));
				return dessin->Add(f);
			} 
			else
			{	return interpretreCommande(cmd, dessin, pile, exclu, true);
			}
		}
		else if(nomCommande == "SAVE" && nParam == 2)
		{	if(dessin->Save(getParametre(commande,1)))
			{	cout << "OK" << endl;
			}
			else
			{	cout << "ERR" << endl;
			}
		}
		else if(nomCommande == "LOAD" && nParam == 2)
		{	dessin->Save("temps.txt");
			Command c(commande, "LOAD temps.txt");
			if(!callByUndoRedo)
			{	pile->AddUndo(c);
			}
			if(dessin->Load(getParametre(commande,1)))
			{	cout << "OK" << endl;
			}
			else
			{	cout << "ERR" << endl;
			}
		}
		else if(nomCommande == "CLEAR")
		{	dessin->Save("temps.txt");
			Command c(commande, "LOAD temps.txt");
			if(!callByUndoRedo)
			{	pile->AddUndo(c);
			}
			cout << "OK" << endl;
		}
		else if(nomCommande == "EXIT")
		{	return true;
		}
		else
		{	if(dessin->AddByCmd(commande))
			{	Command c(commande, "DELETE " + getParametre(commande,1));
				if(!callByUndoRedo)
				{	pile->AddUndo(c);
				}
				cout << "OK" << endl;
			}
			else
			{	cout << "ERR" << endl;
			}
		}
		return false;
	}

string getCommande(string commande)
{
	string nomCommande = "";
	for(unsigned int i=0;i<commande.length();i++)
	{	if(commande[i] == ' ' || commande[i] == '\n')
		{	break;
		}
		nomCommande += commande[i];
	}
	return nomCommande;
}

int getNbParametre(string commande) 
{
	int nbParametre = 0;
	for(unsigned int i=0;i<commande.length();i++)
	{	if(commande[i] == ' ')
			nbParametre++;
	}
	nbParametre++;
	return nbParametre;
}

string getParametre(string commande, int n)
{
	int numeroParam = 0;
	string param = "";
	for(unsigned int i=0;i<commande.length();i++)
	{	if(commande[i] == ' ')
		{	numeroParam++;
		}
		if(numeroParam == n)
		{	i++;
			while(commande[i] != ' ' && commande[i] != '\n' && commande[i] != '\0' )
			{	param += commande[i];
				i++;
			}
			break;
		}
	}
	return param;
}