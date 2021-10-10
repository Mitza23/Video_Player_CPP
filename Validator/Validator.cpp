//
// Created by mitza on 23-Mar-21.
//

#include "Validator.h"

bool validTitle(const std::string &title) {
    if(title.empty())
        return false;
        //throw ServiceException("Title can't be empty");
    return true;
}

bool validPresenter(const std::string &presenter) {
    if(presenter.empty())
        return false;
        //throw ServiceException("Presenter's name can't be empty");
    return true;
}

bool validTime(int value) {
    if(value < 0)
        return false;
        //throw ServiceException("Time duration can't be negative");
    return true;
}

bool validSeconds(int value) {
    if(value < 0 || value > 59)
        return false;
    return true;
}

bool validLikes(int likes) {
    if(likes < 0)
        return false;
        //throw ServiceException("Likes can't be negative");
    return true;
}

bool validLink(const std::string &link) {
    if(link.empty())
        return false;
        //throw ServiceException("Links can't be empty");
    return true;
}

bool validTutorial(const std::string &title, const std::string &presenter, int minutes, int seconds, int likes,
                   const std::string &link) {
    if(validTitle(title) && validPresenter(presenter) && validTime(minutes) && validSeconds(seconds) &&
       validLikes(likes) && validLink(link))
        return true;
    return false;
}
