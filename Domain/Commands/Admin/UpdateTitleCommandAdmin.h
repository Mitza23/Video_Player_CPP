//
// Created by mitza on 30-May-21.
//

#ifndef A89_MITZA23_UPDATETITLECOMMANDADMIN_H
#define A89_MITZA23_UPDATETITLECOMMANDADMIN_H


#include <string>
#include <ServiceAdmin.h>
#include "Commands/Command.h"

class UpdateTitleCommandAdmin : public Command{
private:
    Repository& repository;
    std::string newTitle, oldTitle;
public:
    UpdateTitleCommandAdmin( Repository& repo, const std::string &newTitle, const std::string &oldTitle);

    void undo();

    void redo();
};


#endif //A89_MITZA23_UPDATETITLECOMMANDADMIN_H
