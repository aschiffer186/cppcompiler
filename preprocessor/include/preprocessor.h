#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H 1

#include <unordered_map>


#include "lexer_driver.h"

/**
 * \file preprocessor.h 
 * 
 * This file contains the preprocessor
 */ 

/**
 * \namespace ascppcompiler::preprocessor 
 * 
 * This namespace contains all code for the preprocessor and lexer.
 */ 
namespace ascppcompiler::preprocessor
{
    class preprocessor 
    {
        public:
            explicit preprocessor(const std::vector<std::string>& exceptions);
        private:
            std::unordered_map<std::string, std::vector<pptok_t>> _M_preprocessing_tokens;
            std::unordered_map<std::string, std::vector<pptok_t>> _M_macros;
    };
} // namespace ascppcompiler::preprocessor


#endif