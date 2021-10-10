//
// Created by mitza on 31-May-21.
//

#ifndef A10_MITZA23_1_DELETECOMMANDUSER_H
#define A10_MITZA23_1_DELETECOMMANDUSER_H


#include <Repository.h>
#include <Commands/Command.h>

class DeleteCommandUser : public Command{
private:
    Repository& repository, dataBase;
    std::string title;
public:
    DeleteCommandUser(Repository &repository, const Repository &dataBase, const std::string &title);

    void undo();

    void redo();
};


#endif //A10_MITZA23_1_DELETECOMMANDUSER_H
