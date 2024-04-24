%{
// Reconhecedor de uma linguagem simplificada
#include <iostream>
using std::cout;
#include "onto.tab.h"
%}

%option noyywrap 
%option yylineno

delim	[\n\t ]
spacos   {delim}+
letter	[A-Za-z_]
digit	[0-9]   
num	    {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
opera    (<|>|<>|=)+
chav    \{|\}
virg    \,
prts    \(|\)
aux     xsd:{letter}*
colch   \[|\]
pprt    has[A-Z]{letter}*|is[A-Z]{letter}*
class   [A-Za-z]{letter}*
defin   Class:
sub     SubClassOf:
disj    DisjointClasses:
equiv   EquivalentTo:
indi    Individuals:|{class}{digit}

%%
{spacos}	 // Não realizar nenhuma ação
some		return  SOME; 
all		    return ALL;
value		return VALUE;
min		    return MIN;
max		    return MAX;
exactly		return EXACTLY;
that		return THAT;
only        return ONLY;
not		    return NOT;
and		    return AND;
or		    return OR;
{colch}     return COLCH;
{aux}       return AUX;
{opera}      return OPERA;
{chav}      return CHAVES;
{virg}      return VIRGULA;
{prts}      return PARENTHESIS;
{pprt}      return PROPERTY;
{class}     {yylval.text = strdup(yytext); return CLASS;}
{defin}     return DEFIN;
{disj}      return DISJ;
{sub}       return SUB;
{equiv}     return EQUIV;
{num}       return NUM;
{indi}      return INDI;
%%

// nenhuma função auxiliar é necessária