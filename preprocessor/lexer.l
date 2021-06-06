%{
    #include "include/lexer_defs.h"
    #include "include/lexer_driver.h"
    #include <string>
    //Redefine yylex
    #define YY_DECL bool yylex(ascppcompiler::preprocessor::lexer_result_t& l)
    //Type aliases
    using pptok_type = ascppcompiler::preprocessor::pptok_type;
    using pptok_t = ascppcompiler::preprocessor::pptok_t;
%}
%option outfile="lexer.cpp" header-file="lexer.h"
%option noyywrap

h_char [^\n\>]
q_char [^\n\"]
octal_digit [0-7]
digit [0-9]
hexadecimal_digit [0-9]|[aA]|[bB]|[cC]|[dD]|[eE]|[fF]
hexadecimal_quad {hexadecimal_digit}{4}
univeral_character_name (\\u{hexadecimal_quad}|(\\U{hexadecimal_quad}{2}))
nondigit [a-zA-Z]|_
ident_nodigit {nondigit}|{univeral_character_name}
identifier {ident_nodigit}({digit}|{ident_nodigit})*
encoding_prefix u8|u|U|L
basic_c_char [^\'\\\n]
simple_escape_sequence \\[\'\"\?\\abfnrtv]
octal_escape_sequence \\{octal_digit}{1,3}
hexadecimal_escape_sequence \\x{hexadecimal_digit}+
conditional_escape_sequence \[^{octal_digit}\'\"\?\\abfnrtvuUx]
escape_sequence {simple_escape_sequence}|{octal_escape_sequence}|{hexadecimal_escape_sequence}|{conditional_escape_sequence}
c_char {basic_c_char}|{escape_sequence}|{univeral_character_name}
character_literal {encoding_prefix}?\'{c_char}+\'
ud_suffix {identifier}
basic_s_char [^\"\\\n"]
s_char {basic_s_char}|{encoding_prefix}|{univeral_character_name}
s_char_sequence {s_char}+
string_literal {encoding_prefix}?\"{s_char_sequence}?\"

%%

\<{h_char}+\> l.add_pptok(ascppcompiler::preprocessor::pptok_type::e_header_name, yytext);
\"{q_char}+\" l.add_pptok(ascppcompiler::preprocessor::pptok_type::e_header_name, yytext);
"import" l.add_pptok(pptok_type::e_import_keyword, yytext);
"module" l.add_pptok(pptok_type::e_module_keyword, yytext);
{digit}*\.?{digit}+(\.?({digit}|{nondigit})|[eEpP][+-])* l.add_pptok(pptok_type::e_pp_number, yytext);
{identifier} l.add_pptok(pptok_type::e_identifier, yytext);
{character_literal} l.add_pptok(pptok_type::e_char_literal, yytext);
{character_literal}{ud_suffix} l.add_pptok(pptok_type::e_ud_char_literal, yytext);
{string_literal} l.add_pptok(pptok_type::e_string_literal, yytext);
{string_literal}{ud_suffix} l.add_pptok(pptok_type::e_ud_string_literal, yytext);

\\\n
\n l.next_line();
[ \t\r\f\v]+ l.add_pptok(pptok_type::e_whitespace, yytext);
\\\\[^\n]*\n l.add_pptok(pptok_type::e_whitespace, yytext); l.next_line();
"/*" {
        char c;
        std::string text;
        for(; ;)
        {
            while((c = yyinput()) != '*' && c != EOF)
                text += ' ';
            if(c == '*')
            {
                while((c = yyinput()) == '*')
                {
                    text += ' ';
                }
                if (c == '/')
                {
                    l.add_pptok(pptok_type::e_whitespace, text.c_str());
                    break;
                }
            }
            if (c == EOF)
            {
                throw 1; //Indicate an error
                break;
            }
        }
    }
%%
