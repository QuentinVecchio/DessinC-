#!/usr/bin/python2.7
#-*- coding: utf-8 -*-
import sys
import random

if(len(sys.argv) == 2):
	length = int(sys.argv[1])
	fichier = open("std.in", "a")
	nbRectangle = 0
	nbSegment = 0
	nbUnion = 0
	nbIntersection = 0
	#Génération des données
	for i in range(1,length) :
		choice = random.randint(1,2)
		x1 = random.randint(1,1000)
		y1 = random.randint(1,1000)
		x2 = random.randint(1,1000)
		y2 = random.randint(1,1000)
		if(choice == 1):
			stringTest = "R rec" + str(nbRectangle) + " " + x1 + " " + y1 + " " + x2 + " " + y2 
			nbRectangle++
		else:
			stringTest = "S seg" + str(nbSegment) + " " + x1 + " " + y1 + " " + x2 + " " + y2 
			nbSegment++
		fichier.write(stringTest)
	#Génération d'ensemble
	for i in range(1,length/10)
		choice = random.randint(1,2)
		if(choice == 1):
			stringTest = "OR union" + str(nbUnion) + " rect" + str(random.randint(1,nbRectangle)) + " seg" + str(random.randint(1,nbSegment)) + " rec" + str(random.randint(1,nbRectangle)) + " seg" + str(random.randint(1,nbSegment)) 
			nbUnion++
		else:
			stringTest = "OI intersection" + str(nbUnion) + " rect" + str(random.randint(1,nbRectangle)) + " seg" + str(random.randint(1,nbSegment)) + " rec" + str(random.randint(1,nbRectangle)) + " seg" + str(random.randint(1,nbSegment)) 
			nbIntersection++
		fichier.write(stringTest)
	#Génération de test d'appartenance
	for i in range(1,length/10)
		x1 = random.randint(1,1000)
		y1 = random.randint(1,1000)
		stringTest
		fichier.write(stringTest)
	#Génération de déplacement
	for i in range(1,length/10)
	fichier.close()
else:
	print "erreur parametre"