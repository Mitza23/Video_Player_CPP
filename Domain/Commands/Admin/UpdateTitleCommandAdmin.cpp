//
// Created by mitza on 30-May-21.
//

#include "UpdateTitleCommandAdmin.h"

UpdateTitleCommandAdmin::UpdateTitleCommandAdmin(Repository &repo, const std::string &newTitle,
                                                 const std::string &oldTitle) : repository(repo), newTitle(newTitle),
                                                                                oldTitle(oldTitle) {}

void UpdateTitleCommandAdmin::undo() {
    repository.updateTutorialTitle(newTitle, oldTitle);
}

void UpdateTitleCommandAdmin::redo() {
    repository.updateTutorialTitle(oldTitle, newTitle);
}
