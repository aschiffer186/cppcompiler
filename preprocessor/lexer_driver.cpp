#include "include/lexer_defs.h"
#include "lexer.h"

namespace ascppcompiler::preprocessor
{
    std::vector<lexer_result_t> lex(const std::vector<std::string>& filenames)
    {
        std::vector<lexer_result_t> lexed_files;
        for (const auto& filename: filenames)
        {
            FILE* curr_file = fopen(filename.c_str(), "r");
            if (!curr_file)
                //error
            YY_BUFFER_STATE curr_buffer = yy_create_buffer(curr_file, YY_BUF_SIZE);
        }
    }
} // namespace ascppcompiler::preprocessor
