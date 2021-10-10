//
// Created by mitza on 31-May-21.
//

#include "AddCommandUser.h"

void AddCommandUser::undo() {
    repository.deleteTutorial(title);
}

void AddCommandUser::redo() {
    repository.addTutorial(dataBase.findTutorial(title));
}
