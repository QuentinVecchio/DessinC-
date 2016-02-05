Architecture du projet

B3323
|
- Doc
	| CDC_B3323.pdf
	| Conception_B3323.pdf
	| Perfs_B3323.pdf
	| UML.png
- Sources
	| Tous les fichiers *.cpp
	| Tous les fichiers *.h
	| Makefile du projet 
	| main.cpp
- Tests
	| Tous les tests sur les classes (tests unitaires et fonctionnels)
	| Tests fonctionnels sur le projet (testFinal 1 - 4)
	| Tests performance (testFinal 5-9)
	| Script de génération de données en python : ./genereTest nbDonnee lienFic

Pour executer les tests : 
	- ./test.sh (nomRepertoire) : le temps est long car il y a compilation du projet

Pour executer les tests de performance :
	- ./test.sh (nomRepertoire) : le temps n'est pas celui d'execution du programme !!!	
								Il faut prendre le temps indiqué par la sortie du programme