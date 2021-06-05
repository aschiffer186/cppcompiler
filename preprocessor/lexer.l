%{
    #include "include/lexer_defs.hh"
    #define YYDECL int yylex(lexer_result_t* l)
%}

%option outfile="lexer.c" header-file="lexer.h"
%option noyywrap

h_char [^\n\>]
q_char [^\n\"]
%%
\<{h_char}+\> l->add_pptok(pptok_type::e_header_name, yytext);
\"{q_char}+\" l->add_pptok(pptok_type::e_header_name, yytext);
