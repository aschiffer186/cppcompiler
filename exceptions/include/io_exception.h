#ifndef IO_EXCEPTION_H
#define IO_EXCEPTION_H 1

#include "exception_base.h"

/**
 * \file io_exception.h
 */ 

namespace ascppcompiler::exceptions
{
    /**
     * \brief Base class for all excpetions related to errors in command line arguments
     * 
     * This exception is the base class for all exceptions related to errors in command line 
     * arguments such as invalid command line arguments and source files that cannot be opened. 
     * 
     * This is an abstract base class.
     */ 
    class io_exception : public ascpp_exception
    {
        public:
            explicit io_exception(ascpp_exception* cause) noexcept;
            virtual ~io_exception() = default;
    };

    /**
     * \brief Exception to be thrown when a file cannot be opened 
     * 
     * This exception class can be thrown when the compiler cannot open a file 
     * with the specified filename.
     */ 
    class file_not_found : public io_exception 
    {
        public:
            /**
             * \brief Default constructor 
             * 
             * Default constructor
             */ 
            file_not_found() noexcept = default;
            /**
             * \brief Constructor 
             * 
             * Constructs a new \b file_not_found with the specified message and cause (optional).
             * 
             * \param message A message describing the cause of the exception 
             * \param cause [optional] The cause of the exception
             */ 
            explicit file_not_found(const std::string& message, ascpp_exception* cause = nullptr);

            const char* get_message() const noexcept override;

        private: 
            std::string _M_message;
    };
} // namespace ascppcompiler::exception


#endif