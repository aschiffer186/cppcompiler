#include "include/exception_base.h"

namespace ascppcompiler::exceptions
{
    ascpp_exception::ascpp_exception(ascpp_exception* cause) noexcept
        : _M_cause(cause)
    {

    }

    ascpp_exception* ascpp_exception::peek_cause() const noexcept
    {
        return _M_cause.get();
    }

    ascpp_exception* ascpp_exception::get_cause() noexcept
    {
        return _M_cause.release();
    }

    
} // namespace ascppcompiler::exceptions
