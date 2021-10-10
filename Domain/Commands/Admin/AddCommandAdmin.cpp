//
// Created by mitza on 30-May-21.
//

#include "AddCommandAdmin.h"

AddCommandAdmin::AddCommandAdmin(Repository &repo, const std::string &title, const std::string &presenter, int minutes,
                                 int seconds, int likes, const std::string &link) : Command(), repository(repo),
                                                                                    title(title), presenter(presenter),
                                                                                    link(link), minutes(minutes),
                                                                                    seconds(seconds), likes(likes) {}

void AddCommandAdmin::undo() {
    repository.deleteTutorial(title);
}

void AddCommandAdmin::redo() {
    Tutorial t(title, presenter, minutes, seconds, likes, link);
    repository.addTutorial(t);
}
