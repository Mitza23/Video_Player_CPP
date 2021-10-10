//
// Created by mitza on 23-Mar-21.
//

#ifndef A45_MITZA23_SERVICEEXCEPTION_H
#define A45_MITZA23_SERVICEEXCEPTION_H
#include "Exception.h"

class ServiceException : public std::exception{
public:
    std::string message;
    explicit ServiceException(const std::string &message) : message(message) {}

    ServiceException() {}

    std::string getMessage()const{
        return this->message;
    }
};
#endif //A45_MITZA23_SERVICEEXCEPTION_H
