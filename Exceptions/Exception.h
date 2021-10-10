//
// Created by mitza on 21-Mar-21.
//

#ifndef A45_MITZA23_EXCEPTION_H
#define A45_MITZA23_EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception{
public:
    std::string message;
    explicit Exception(const std::string &message) : message(message) {}

    Exception() {}

    std::string getMessage()const{
        return this->message;
    }
};


#endif //A45_MITZA23_EXCEPTION_H
