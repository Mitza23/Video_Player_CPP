//
// Created by mitza on 30-May-21.
//

#include "UpdatePresenterCommandAdmin.h"

UpdatePresenterCommandAdmin::UpdatePresenterCommandAdmin(Repository &repo, const std::string &title,
                                                         const std::string &newPresenter,
                                                         const std::string &oldPresenter) : repository(repo),
                                                                                            title(title),
                                                                                            newPresenter(newPresenter),
                                                                                            oldPresenter(
                                                                                                    oldPresenter) {}

void UpdatePresenterCommandAdmin::undo() {
    repository.updateTutorialPresenter(title, oldPresenter);
}

void UpdatePresenterCommandAdmin::redo() {
    repository.updateTutorialPresenter(title, newPresenter);
}
