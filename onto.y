%{
/* analisador sintático para reconhecer onto em português */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string>
#include <list>
using std::cout;

int yylex(void);
int yyparse(void);
void yyerror(const char *);
extern int yylineno;    
extern char * yytext;   

bool individual = false;
bool equiva = false;
bool bolProper = false;

std::list<char*> prop{};


// Adcionar as property que encontrar na lista
void addProp(char* proper) {
    prop.push_back(strdup(proper));
}

// Para a classe axioma de fechamento, ele verifica se ele está utilizando um object propertie que já foi declarado 
void declaracoes(char* obj){
	for (const auto& property :prop){
		if (obj == property){
			bolProper = true;
		}
		yyerror("Erro: Está sendo declarado object property que não foi declarado'");
	}
}


// Verifica se a ordem de precedência está correta
void precedencia(char* prec){

// Verifica se é disjoint, caso condição seja verdadeira verifica se 'individuals' já apareceu anteriormente
	if(strcmp(prec, "Disjoint:") == 0){
		if (individual == true){
				yyerror("Erro: 'Disjoint' não é permitido após 'individuals'");
                            
			}
	}

// Verifica se é Subclass, caso condição seja verdadeira verifica se 'equivalentTo' já apareceu anteriormente
	if(strcmp(prec, "SubClassOf:") == 0){
			if (equiva == true){
				yyerror("Erro: 'Subclass' não é permitido após 'EquivalentTo'");
                            
			}
	}

// Caso leia EquivalentTo, vai habilitar a o bool como verdadeiro
	if(strcmp(prec, "EquivalentTo:") == 0){
			equiva = true;
	}

// Caso leia Disjoint, vai habilitar a o bool como verdadeiro
	if(strcmp(prec, "Individuals:") == 0){
		individual = true;
	}


}


%}

%union {
    char * text;


}

%token <text> CLASS
%token <text> INDI
%token <text> DEFIN
%token <text> EQUIV
%token <text> SUB
%token <text> DISJ
%token <text> SOME 
%token <text> ALL 
%token <text> VALUE 
%token <text> NUM 
%token <text> MIN 
%token <text> OPERA 
%token <text> MAX 
%token <text> AUX 
%token <text> COLCH 
%token <text> EXACTLY 
%token <text> THAT
%token <text> ONLY 
%token <text> NOT 
%token <text> AND 
%token <text> OR 
%token <text> PROPERTY 
%token <text> PARENTHESIS 
%token <text> CHAVES 
%token <text> VIRGULA 




%%

sint: owl sint
	 | error owl { yyerrok; yyclearin; } // Tratamento para continuar a leitura mesmo que encontre um erro     
	 ;

owl: DEFIN CLASS opt0 { printf("Classe: %s\n", $2);}
	 ;

opt0: op1
	| op2
	;
op1: definida		{ cout << "\n>>>>>Classe Definida.<<<<<\n" + CLASS ;}
	 | primitiva	{ cout << "\n>>>>>Classe Primitiva.<<<<<\n"; }
	 | closureAxiom { cout << "\n>>>>>Classe Axioma de fechamento.<<<<<\n"; }
	 ;

op2: enumerada		{ cout << "\n>>>>>Classe Enumerada.<<<<<\n"; }
	 | coberta		{ cout << "\n>>>>>Classe Coberta.<<<<<\n"; }
	 | classeAninhada { cout << "\n>>>>>Classe Aninhada.<<<<<\n"; }
	 ;


definida : EQUIV CLASS AND  PARENTHESIS  definida {precedencia($1);}
	| PROPERTY reservado CLASS definida
	| PROPERTY reservado CARD PARENTHESIS definida
	| CLASS PARENTHESIS 
	| PARENTHESIS CLASS definida PARENTHESIS PARENTHESIS 
	| INDIVIDUALS
	;


primitiva:   SUB primitiva  {precedencia($1);}
	 | DISJ CLASS primitiva {precedencia($1);}
	 | PROPERTY reservado CLASS primitiva
	 | PROPERTY reservado CARD primitiva
	 | PROPERTY reservado enumerada
	 | VIRGULA primitiva
	 | CLASS primitiva
	 | CLASS  reservado  CLASS primitiva
	 | CLASS PARENTHESIS primitiva
	 | INDIVIDUALS
	 |
	 ;

closureAxiom: SUB CLASS VIRGULA closureAxiom  {precedencia($1);}
	| PROPERTY reservado CLASS VIRGULA closureAxiom  {addProp($1);}
	| closureAxiom2 
	| INDIVIDUALS
	;

closureAxiom2: PROPERTY ONLY PARENTHESIS coberta PARENTHESIS closureAxiom2
	 | DISJ CLASS closureAxiom2 {precedencia($1);}
	 | VIRGULA closureAxiom2
	 | CLASS closureAxiom2
	 | INDIVIDUALS
	 |
	;

classeAninhada: EQUIV classeAninhada  {precedencia($1);}
	| SUB CLASS classeAninhada {precedencia($1);}
	| CLASS classeAninhada
	| reservado classeAninhada
	| AND PARENTHESIS classeAninhada
	| reservado PARENTHESIS classeAninhada
	| PROPERTY reservado classeAninhada
	| PARENTHESIS classeAninhada 
	| VIRGULA classeAninhada
	| CARD PARENTHESIS
	| INDIVIDUALS 
	;


enumerada: 	EQUIV CHAVES CLASS VIRGULA enumerada CHAVES INDIVIDUALS {precedencia($1);}
	 | CLASS VIRGULA enumerada
	 | CLASS
	 ;

coberta: SUB coberta {precedencia($1);}
	 | EQUIV coberta 
	 | CLASS OR  coberta {declaracoes($1);}
	 | CLASS
	 | INDIVIDUALS
	 |
	 ;

reservado: SOME 
	 | ALL  
	 | AND
	 | VALUE NUM 
	 | MIN NUM
	 | MAX NUM
	 | EXACTLY NUM
	 | THAT
	 | NOT
	 | OR
	 | ONLY
	 ;

INDIVIDUALS: INDI INDIVIDUALS {precedencia($1);}
	| VIRGULA INDIVIDUALS
	|
	;

CARD: AUX CARD
	| CARD2
	|
	;
CARD2: COLCH OPERA NUM COLCH
	|
	;


%%

/* definido pelo analisador léxico */
extern FILE * yyin;  

int main(int argc, char ** argv)
{
	/* se foi passado um nome de arquivo */
	if (argc > 1)
	{
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file)
		{
			cout << "Arquivo " << argv[1] << " não encontrado!\n";
			exit(1);
		}
		
		/* entrada ajustada para ler do arquivo */
		yyin = file;
	}

	yyparse();
}

void yyerror(const char * s)
{
	/* variáveis definidas no analisador léxico */
	

	/* mensagem de erro exibe o símbolo que causou erro e o número da linha */
    cout << "Erro disparado: \"" << yytext << "\" (linha " << yylineno << ")\n";
}
