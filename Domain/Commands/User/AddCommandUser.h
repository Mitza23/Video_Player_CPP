//
// Created by mitza on 31-May-21.
//

#ifndef A10_MITZA23_1_ADDCOMMANDUSER_H
#define A10_MITZA23_1_ADDCOMMANDUSER_H


#include <Commands/Command.h>
#include <string>
#include <Repository.h>

class AddCommandUser : public Command{
private:
    Repository& repository, dataBase;
    std::string title;
public:
    AddCommandUser(Repository &repository, const Repository &dataBase, const std::string &title) : repository(
            repository), dataBase(dataBase), title(title) {}

    void undo();

    void redo();
};


#endif //A10_MITZA23_1_ADDCOMMANDUSER_H
