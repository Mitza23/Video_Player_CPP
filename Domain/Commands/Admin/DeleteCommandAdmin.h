//
// Created by mitza on 30-May-21.
//

#ifndef A89_MITZA23_DELETECOMMANDADMIN_H
#define A89_MITZA23_DELETECOMMANDADMIN_H


#include <ServiceAdmin.h>
#include "Commands/Command.h"

class DeleteCommandAdmin : public Command{
private:
    Repository& repository;
    std::string title, presenter, link;
    int minutes, seconds, likes;
public:
    DeleteCommandAdmin(Repository &repo, const std::string &title, const std::string &presenter, int minutes,
                       int seconds, int likes, const std::string &link);

    void undo();

    void redo();
};


#endif //A89_MITZA23_DELETECOMMANDADMIN_H
