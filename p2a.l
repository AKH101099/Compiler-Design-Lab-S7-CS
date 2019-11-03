%{
    #include<stdio.h>
    #include<stdlib.h>
%}

KEY "while"|"if"|"else"|"int"|"float"|"double"|"bool"|"for"|"else"|"main"|"return"|"const"

%%  
{KEY} { printf("\n keywords : %s", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("\n identifier : %s", yytext); } 
"<="|"=="|"="|"++"|"-"|"*"|"+" { printf("\n operator : %s", yytext); }
[(){}|, ;]    { printf("\n symbol : %s", yytext);}
[0-9]*"."[0-9]+ { printf("\n constant : %s", yytext); }
[0-9]+ { printf("\n constant : %s", yytext); }
. ;
%%  

int main(){ 
    system("clear");
    yylex();
    return 0;
} 