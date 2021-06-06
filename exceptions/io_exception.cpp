#include "include/io_exception.h"

namespace ascppcompiler::exceptions
{
    io_exception::io_exception(ascpp_exception* cause) noexcept
        : ascpp_exception(cause)
    {

    }

    file_not_found::file_not_found(const std::string& message, ascpp_exception* cause)
        : io_exception(cause), _M_message(message)
    {
        if(cause)
        {
            _M_message += "Caused by ";
            _M_message += cause->get_message();
        }
    }

    const char* file_not_found::get_message() const noexcept 
    {
        return _M_message.c_str();
    }
} // namespace ascpp_exception
