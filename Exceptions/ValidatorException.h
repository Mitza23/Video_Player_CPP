//
// Created by mitza on 13-Apr-21.
//

#ifndef A67_MITZA23_VALIDATOREXCEPTION_H
#define A67_MITZA23_VALIDATOREXCEPTION_H
#include "Exception.h"

class ValidatorException : public std::exception{
public:
    std::string message;
    explicit ValidatorException(const std::string &message) : message(message) {}

    ValidatorException() {}

    std::string getMessage()const{
        return this->message;
    }
};

#endif //A67_MITZA23_VALIDATOREXCEPTION_H
