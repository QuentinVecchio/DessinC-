#!/usr/bin/python2.7
#-*- coding: utf-8 -*-
import sys
import random

if(len(sys.argv) == 3):
	length = int(sys.argv[1])
	fichier = open(sys.argv[2], "a")
	nbRectangle = 0
	nbSegment = 0
	nbUnion = 0
	nbIntersection = 0
	#Génération des données
	for i in range(1,length) :
		choice = random.randint(1,2)
		x1 = random.randint(-1000,1000)
		y1 = random.randint(-1000,1000)
		x2 = random.randint(-1000,1000)
		y2 = random.randint(-1000,1000)
		if(choice == 1):
			while(y1 <= y2 and x1 <= x2):
				x1 = random.randint(-1000,1000)
				y1 = random.randint(-1000,1000)
				x2 = random.randint(-1000,1000)
				y2 = random.randint(-1000,1000)
			stringTest = "R rec" + str(nbRectangle) + " " + str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) 
			nbRectangle = nbRectangle + 1
		else:
			stringTest = "S seg" + str(nbSegment) + " " + str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) 
			nbSegment = nbSegment + 1
		fichier.write(stringTest + "\n")
	#Génération d'ensemble
	intervalle = length/10
	recursive = 1000
	for i in range(1,intervalle):
		choice = random.randint(1,2)
		if(choice == 1):
			stringTest = "OR union" + str(nbUnion) + " rect" + str(random.randint(1,nbRectangle)) + " seg" + str(random.randint(1,nbSegment)) + " rec" + str(random.randint(1,nbRectangle)) + " seg" + str(random.randint(1,nbSegment)) 
			nbUnion = nbUnion + 1 
		else:
			stringTest = "OI intersection" + str(nbIntersection) + " rect" + str(random.randint(1,nbRectangle)) + " seg" + str(random.randint(1,nbSegment)) + " rec" + str(random.randint(1,nbRectangle)) + " seg" + str(random.randint(1,nbSegment)) 
			nbIntersection = nbIntersection + 1 
		fichier.write(stringTest + "\n")
	intervalle2 = 100
	limitUnion = nbUnion - 2
	limitIntersection = nbIntersection - 2
	for i in range(1,intervalle2):
		choice = random.randint(1,2)
		if(choice == 1):
			stringTest = "OR union" + str(nbUnion) + " union" + str(random.randint(limitUnion,nbUnion-1)) + " intersection" + str(random.randint(limitUnion,nbIntersection-1)) 
			nbUnion = nbUnion + 1 
		else:
			stringTest = "OI intersection" + str(nbIntersection) + " union" + str(random.randint(limitIntersection,nbUnion-1)) + " intersection" + str(random.randint(limitIntersection,nbIntersection-1));
			nbIntersection = nbIntersection + 1 
		fichier.write(stringTest + "\n")
	fichier.close()
else:
	print "erreur parametre"