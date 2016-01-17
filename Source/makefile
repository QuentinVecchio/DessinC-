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
INT= Figure.h Dessin.h Point.h Rectangle.h
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

main.o : 

Rectangle.o : Figure.o Point.o

Dessin.o : Rectangle.o Point.o

%.o : %.cpp
	$(ECHO) "Compilation de $<"
	$(CC) $(DEBUG) $(CPPFLAGS) $(INCPATH) -c $<

.PHONY : $(CLEAR)

$(CLEAR):
	$(RM) $(RMFLAGS) $(OBJ) main.o $(EXECNAME)
