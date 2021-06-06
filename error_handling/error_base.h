#ifndef ERROR_BASE_H
#define ERROR_BASE_H 1

/**
 * \brief A file containing a base class for error handling
 */ 

namespace ascppcompler::exceptions
{
    /**
     * \brief Base class for all exceptions
     * 
     * The \b ascpp_error class is an abstract base class that all other exceptions inherit from.
     */ 
    class ascpp_error 
    {
        public:
            /**
             * \brief Default C
             */ 
            ascpp_error() noexcept = default;
            explicit ascpp_error(ascpp_error* _M_cause) noexcept;
            virtual ascpp_error* get_cause() noexcept;
            virtual const char* get_message() const noexcept;
            virtual ~ascpp_error();
        private:
            ascpp_error* _M_cause;
    };
} // namespace ascppcompler::exceptionss


#endif