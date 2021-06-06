#ifndef EXCEPTION_BASE_H
#define EXCEPTION_BASE_H 1

#include <memory> //std::unique_pointer

/**
 * \file exception_base.h
 * \brief A file containing a base class for exception handling
 */ 

/**
 * \namespace ascppcompiler::exceptions
 * \brief This namespace contains all classes for exception handling.
 */ 
namespace ascppcompiler::exceptions
{
    /**
     * \brief Base class for all exceptions
     * 
     * The \b ascpp_exception class is an abstract base class that all other exceptions inherit from.
     */ 
    class ascpp_exception 
    {
        public:
            /**
             * \brief Default Constructor
             */ 
            ascpp_exception() noexcept = default;
            /**
             * \brief Constructor
             * 
             * Creates a new \b ascpp_exception that contains a pointer to the cause 
             * of the exception. The pointer must be dynamically allocated and the 
             * \b ascpp_exception instance \b takes \b ownership of the pointer. 
             * 
             * \param cause the cause of the exception
             */ 
            explicit ascpp_exception(ascpp_exception* cause) noexcept;
            /**
             * \brief Cannot copy \b ascpp_exceptions
             */ 
            ascpp_exception(const ascpp_exception& ex) noexcept = delete;
            /**
             * \brief Move constructor 
             * 
             * Move constructor
             * \param ex The exception from which \b *this will be move constructed.
             */ 
            ascpp_exception(ascpp_exception&& ex) noexcept = default;
            /**
             * \brief Cannot copy assign \b ascpp_exceptions
             */ 
            ascpp_exception& operator=(const ascpp_exception& ex) noexcept = delete;
            /**
             * \brief Move assignment operator 
             * 
             * Move assignment operator 
             * \param ex The exception from which \b *this will be copy assigned
             */ 
            ascpp_exception& operator=(ascpp_exception&& ex) noexcept = default;
            /**
             * \brief Get the cause of the exception.
             * 
             * Returns a pointer to the cause of the exception. 
             * Does not release ownership.
             * 
             * \return the cause of the exception
             */
            ascpp_exception* peek_cause() const noexcept;
            /**
             * \brief Get the cause of the exception.
             * 
             * Returns a pointer to the cause of the exception. 
             * Releases ownership of the pointer to the caller.
             * 
             * \return the cause of the exception, transferring owernship.
             */ 
            ascpp_exception* get_cause() noexcept;
            /**
             * \brief Returns a message describing the cause of the exception.
             * 
             * Returns a message in the form of a null-terminated character string describing 
             * the cause of the exception. The string will exist for as long as the exception 
             * exists. 
             * \return A null terminated string describing the case of the exception.
             */ 
            virtual const char* get_message() const noexcept = 0;
            /**
             * \brief Destructor 
             * 
             * Destrucor
             */ 
            virtual ~ascpp_exception() = default;
        private:
            std::unique_ptr<ascpp_exception> _M_cause;
    };
} // namespace ascppcompler::exceptionss


#endif