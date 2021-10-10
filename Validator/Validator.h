//
// Created by mitza on 23-Mar-21.
//

#ifndef A45_MITZA23_VALIDATOR_H
#define A45_MITZA23_VALIDATOR_H

#include <string>
#include "../Exceptions/ServiceException.h"

bool validTitle(const std::string &title);

bool validPresenter(const std::string &presenter);

bool validTime(int value);

bool validSeconds(int value);

bool validLikes(int likes);

bool validLink(const std::string &link);

bool validTutorial(const std::string &title, const std::string &presenter, int minutes, int seconds, int likes,
                   const std::string &link);
#endif //A45_MITZA23_VALIDATOR_H
