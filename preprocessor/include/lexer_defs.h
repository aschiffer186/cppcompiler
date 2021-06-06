#ifndef LEXER_DEFS_H
#define LEXER_DEFS_H 1

#include <string>
#include <vector>

/**
 * \file lexer_defs.h
 * \brief A file containing structs needed for lexing files.
 */ 

namespace ascppcompiler::preprocessor
{
    /**
     * \brief Enum to represent the type of a preprocessing token.
     * 
     * The C++ standard defines several types of preprocessing tokens. 
     * Each value in the enum corresponds to one of the preprocessing token 
     * types defined in the standard.
     */
    enum class pptok_type 
    {
        e_header_name,
        e_import_keyword,
        e_module_keyword,
        e_identifier,
        e_pp_number,
        e_char_literal,
        e_ud_char_literal,
        e_string_literal,
        e_ud_string_literal,
        e_pop,
        e_whitespace,
        e_other
    };

    /**
     * \brief A struct representing a preprocessing token.
     * 
     * The \b pptok_t struct represents a preprocessing token and contains information 
     * on the token's type, line, start and end columns, and the value of the token. 
     * All tokens have a value indicating what the token is.
     */ 
    struct pptok_t
    {
        ///The token's type
        pptok_type _M_type;
        ///The line the token is on
        size_t _M_line;
        ///The start column of the token
        size_t _M_start_col;
        ///The end column of the token
        size_t _M_end_col;
        ///The token's value
        std::string _M_value;

        /**
         * \brief Default constructor 
         * 
         * Default constructor
         */ 
        pptok_t() noexcept = default;
        /**
         * \brief Constructor 
         * 
         * Constructs a new preprocessing token. 
         * \param type the preprocessing token's type 
         * \param value the preprocessing token's value 
         * \param line the line the token is on 
         * \param start_col the start column of the preprocessing token 
         * \param end_col the end column of the preprocessing token
         */ 
        pptok_t(pptok_type type, const std::string& value, size_t line, size_t start_col, size_t end_col);
    };

    /**
     * \brief A struct to hold the preprocessing tokens from lexing a file. 
     * 
     *  
     */ 
    struct lexer_result_t
    {
        /**
         * \brief Default constructor
         * 
         * Default constructor.
         */ 
        lexer_result_t() noexcept = default;
        /**
         * \brief Constructor
         * 
         * Constructs a new \b lexer_result_t that stores preprocessing tokens for the file with the specified filename. 
         * \param filename the name of the file the \b lexer_result_t will be storing files for
         */ 
        explicit lexer_result_t(const std::string& filename);
        /**
         * \brief Adds a new preprocessing token to the lexer output.
         * 
         * Creates a new token with the specified preprocessing token type and value 
         * and attaches the relevant location information to the token. 
         * 
         * \param type the preprocessor token's type 
         * \param value the preprocessor lexer's value
         */ 
        void add_pptok(pptok_type type, const std::string& value);
        /**
         * \brief Advance the location of the lexer result forward one line.
         */ 
        void next_line();

        /**
         * \brief Returns the tokens stored in the \b lexer_result_t
         * 
         * Returns all the tokens in stored in the \b lexer_result_t in the form of a vector. 
         * The caller may store the result by referece and modify the vector (and the tokens
         * stored in the \b lexer_result_t )
         * 
         * \return A std::vector<pptok_t> containing the tokens in the lexer
         */ 
        std::vector<pptok_t>& get_toks();
         /**
         * \brief Returns the tokens stored in the \b lexer_result_t
         * 
         * Returns all the tokens in stored in the \b lexer_result_t in the form of a vector. 
         * The caller may store the result by referece and but cannot modify the vector.
         * 
         * \return A \b std::vector<pptok_t> containing the tokens in the lexer
         */ 
        const std::vector<pptok_t>& get_toks() const;
        /**
         * \brief Returns the name of the file associated with \b *this
         * 
         * Returns the name of the file associated with \b *this in the form of a \b std::string
         * 
         * \return the name of the file associated with \b *ths
         */ 
        const std::string& get_filename() const;

        private:
            std::string _M_file_name;
            std::vector<pptok_t> _M_toks;
            size_t _M_line, _M_col;
    };
} // namespace ascppcompiler::preprocessor


#endif