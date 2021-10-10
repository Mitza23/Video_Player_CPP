//
// Created by mitza on 31-May-21.
//

#include "DeleteCommandUser.h"

DeleteCommandUser::DeleteCommandUser(Repository &repository, const Repository &dataBase, const std::string &title) : repository(
        repository), dataBase(dataBase), title(title) {}

void DeleteCommandUser::undo() {
    repository.addTutorial(dataBase.findTutorial(title));
}

void DeleteCommandUser::redo() {
    repository.deleteTutorial(title);
}
