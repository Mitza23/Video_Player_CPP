//
// Created by mitza on 30-May-21.
//

#include "DeleteCommandAdmin.h"

DeleteCommandAdmin::DeleteCommandAdmin(Repository &repo, const std::string &title, const std::string &presenter,
                                       int minutes, int seconds, int likes, const std::string &link) : repository(repo),
                                                                                                       title(title),
                                                                                                       presenter(
                                                                                                               presenter),
                                                                                                       link(link),
                                                                                                       minutes(minutes),
                                                                                                       seconds(seconds),
                                                                                                       likes(likes) {}

void DeleteCommandAdmin::undo() {
    Tutorial t(title, presenter, minutes, seconds, likes, link);
    repository.addTutorial(t);
}

void DeleteCommandAdmin::redo() {
    repository.deleteTutorial(title);
}
