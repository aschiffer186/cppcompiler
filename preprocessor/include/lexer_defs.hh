#ifndef LEXER_DEFS_HH
#define LEXER_DEFS_HH 1

#include <string>
#include <vector>

#define YY_DECL int yylex(const lexer_result_t& l)

namespace ascppcompiler::preprocessor
{
    enum class pptok_type 
    {
        e_header_name,
        e_import_keyword,
        e_module_keyword,
        e_export_keyword,
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

    struct pptok_t
    {
        pptok_type _M_type;
        size_t _M_line;
        size_t _M_start_col;
        size_t _M_end_col;
        std::string _M_value;

        pptok_t() noexcept = default;
        pptok_t(pptok_type type, const std::string& value, size_t line, size_t start_col, size_t end_col);
    };

    struct lexer_result_t
    {
        std::string _M_file_name;
        std::vector<pptok_t> _M_toks;

        lexer_result_t() noexcept = default;

        void add_pptok(pptok_type type, const std::string& value);

        std::vector<pptok_t>& get_toks();

        const std::vector<pptok_t>& get_toks() const;
    };
} // namespace ascppcompiler::preprocessor


#endif