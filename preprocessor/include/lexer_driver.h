#ifndef LEXER_DRIVER_H
#define LEXER_DRIVER_H 1

#include <unordered_map>
#include <string>

#include "lexer_defs.h"

/**
 * \file lexer_driver.h
 */ 

namespace ascppcompiler::preprocessor
{
    /**
     * \brief Lexes the specified list of files
     * 
     * This function takes a list of file names and lexes the file associated with each file,
     * returning a list of preprocessing tokens. 
     *  
     * If the function cannot open a file, a exception is thrown and lexing stops. The tokens 
     * for each file is stored in a \b lexer_result_t which provides information about the 
     * preprocessing tokens in the file and the file the tokens came from. 
     * 
     * 
     * \pre All file names passed to the function are .cc, .c, .cxx, .cpp, .h, .hh, or .hpp 
     *      and have gone through phase 1 of translation.
     * \param filenames a list of file names of the files to be lexed 
     * \return a \b std::vector containing a \b lexer_result_t for each file lexed
     * \see lexer_result_t
     */ 
    std::vector<lexer_result_t> lex(const std::vector<std::string>& filenames);
} // namespace ascppcompiler::preprocessor


#endif