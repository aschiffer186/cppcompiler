#include "include/io_exception.h"

namespace ascppcompiler::exceptions
{
    io_exception::io_exception(ascpp_exception* cause)
        : ascpp_exception(cause)
    {

    }

    file_not_found::file_not_found(const std::string& message, ascpp_exception* cause)
        : io_exception(cause), _M_message(message)
    {

    }

    const char* file_not_found::get_message() const noexcept 
    {
        std::string what = _M_message; 
        ascpp_exception* cause = peek_cause();
        if(cause)
        {
            what += "Caused by ";
            what += cause->get_message();
        }
    }
} // namespace ascpp_exception
