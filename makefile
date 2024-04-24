all: onto

# Compiladores
CPP=g++
FLEX=flex 
BISON=bison

onto: lex.yy.c onto.tab.c
	$(CPP) lex.yy.c onto.tab.c -std=c++17 -o onto

lex.yy.c: onto.l
	$(FLEX) onto.l

onto.tab.c: onto.y
	$(BISON) -d onto.y

clean:
	rm onto lex.yy.c onto.tab.c onto.tab.h
