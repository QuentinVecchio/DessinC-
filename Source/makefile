#************************************************************************#
#                           Makefile  -  description                     #
#                            -------------------	            		 #
#   début                : 12/01/2016									 #
#   copyright            : (C) 2015 par Adrien Lepic et Quentin Vecchio	 #
#************************************************************************#
CC=g++
EDL=g++
EXECNAME=EXEC
DEBUG=-DMAP
CPPFLAGS=-g -O2 -Wall
EDLFLAGS=-g -O2 -Wall
RM=@rm
ECHO=@echo
RMFLAGS=-f
OUTPUT=-o
INT= Figure.h Dessin.h Vect.h Rectangle.h SetOfFigures.h Union.h Segment.h
CPP=$(INT:.h=.cpp)
OBJ=$(INT:.h=.o)
CLEAR=clear
LIBS=
LIBPATH=
INCPATH=

all : $(EXECNAME)

$(EXECNAME) : main.o $(OBJ)
	$(ECHO) "Edition des liens de $(EXECNAME)"
	$(EDL) $(EDLFLAGS) main.o $(OBJ) $(OUTPUT) $(EXECNAME)

main.o : Figure.o SetOfFigure.o Rectangle.o Vect.o Dessin.o Union.o

SetOfFigure.o : Figure.o

Rectangle.o : Figure.o Vect.o

Dessin.o : Figure.o SetOfFigure.o Vect.o

Union.o : Figure.o SetOfFigure.o Vect.o

%.o : %.cpp
	$(ECHO) "Compilation de $<"
	$(CC) $(DEBUG) $(CPPFLAGS) $(INCPATH) -c $<

.PHONY : $(CLEAR)

$(CLEAR):
	$(RM) $(RMFLAGS) $(OBJ) main.o $(EXECNAME)
