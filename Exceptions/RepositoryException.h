//
// Created by mitza on 21-Mar-21.
//

#ifndef A45_MITZA23_REPOSITORYEXCEPTION_H
#define A45_MITZA23_REPOSITORYEXCEPTION_H

#include "Exception.h"

class RepositoryException : public std::exception{
public:
    std::string message;
    explicit RepositoryException(const std::string &message) : message(message) {}

    RepositoryException() {}

    std::string getMessage()const{
        return this->message;
    }
};


#endif //A45_MITZA23_REPOSITORYEXCEPTION_H
