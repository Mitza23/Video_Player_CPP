//
// Created by mitza on 19-Mar-21.
//

#include <iostream>
#include <ValidatorException.h>
#include <Validator.h>
#include "Tutorial.h"

using namespace std;

int Tutorial::getMinutes() const {
    return minutes;
}

void Tutorial::setMinutes(int minutes) {
    Tutorial::minutes = minutes;
}


int Tutorial::getSeconds() const {
    return seconds;
}

void Tutorial::setSeconds(int seconds) {
    Tutorial::seconds = seconds;
}

int Tutorial::getLikes() const {
    return likes;
}

void Tutorial::setLikes(int likes) {
    Tutorial::likes = likes;
}

const std::string &Tutorial::getTitle() const {
    return title;
}

void Tutorial::setTitle(const std::string title) {
    Tutorial::title = title;
}

const std::string &Tutorial::getPresenter() const {
    return presenter;
}

void Tutorial::setPresenter(const std::string &presenter) {
    Tutorial::presenter = presenter;
}

const std::string &Tutorial::getLink() const {
    return link;
}

void Tutorial::setLink(const std::string &link) {
    Tutorial::link = link;
}

Tutorial::Tutorial(const std::string &title, const std::string &presenter, int minutes, int seconds, int likes,
                   const std::string &link) : title(title), presenter(presenter), minutes(minutes), seconds(seconds),
                                              likes(likes), link(link) {}

Tutorial::Tutorial() {}

bool Tutorial::operator==(const Tutorial &rhs) const {
    return title == rhs.title;
}


std::string Tutorial::toString() {
    std::string s;
    s += this->title + " " + this->presenter + " " + std::to_string(this->minutes)+ " " +
         std::to_string(this->seconds)+ " " + std::to_string(this->likes) + " " + this->link;
    return s;
}

void Tutorial::play(){
    std::string command = "chrome.exe " + link;
    system(command.c_str());
}

istream &operator>>(istream &in, Tutorial &t) {
    if(!in.eof()) {
        getline(in, t.title);
        if (!validTitle(t.title))
            throw ValidatorException("Invalid title");
//    cout << t.title << endl;

        getline(in, t.presenter);
        if (!validPresenter(t.presenter))
            throw ValidatorException("Invalid presenter");

        int nr = 0;
        string number;
        try {
            getline(in, number);
            nr = stoi(number);
        } catch (exception &e) {
            throw ValidatorException("Invalid input: please enter a valid number");

        }
        t.minutes = nr;
        if (!validTime(t.minutes))
            throw ValidatorException("Invalid minutes");

        try {
            getline(in, number);
            nr = stoi(number);
        } catch (exception &e) {
            throw ValidatorException("Invalid input: please enter a valid number");

        }
        t.seconds = nr;
        if (!validSeconds(t.seconds))
            throw ValidatorException("Invalid seconds");

        try {
            getline(in, number);
            nr = stoi(number);
        } catch (exception &e) {
            throw ValidatorException("Invalid input: please enter a valid number");

        }
        t.likes = nr;
        if (!validLikes(t.likes))
            throw ValidatorException("Invalid likes");

        getline(in, t.link);
        if (!validLink(t.link))
            throw ValidatorException("Invalid link");
    }
    return in;
}

ostream &operator<<(ostream &out, const Tutorial &t) {
//    out << t.title << " " << t.presenter << " " << t.minutes << " " << t.seconds << " " << t.likes << " " << t.link << "\n";
    out << t.title << "\n" << t.presenter << "\n" << t.minutes << "\n" << t.seconds << "\n" << t.likes << "\n" << t.link;
    return out;
}

std::string Tutorial::toHTML() {
    string result;
    result += string("\t<tr>\n");
    result += string("\t\t<td>") + title + string("</td>\n");
    result += string("\t\t<td>") + presenter + string("</td>\n");
    result += string("\t\t<td>") + to_string(minutes) + string("</td>\n");
    result += string("\t\t<td>") + to_string(seconds) + string("</td>\n");
    result += string("\t\t<td>") + to_string(likes) + string("</td>\n");
    result += string("\t\t<td><a href=\"") + link + string("\">Link</td>\n");
    result += string("\t</tr>\n");
    return result;
}

std::string Tutorial::toCSV() {
    string result;
    result += title + string(",") + presenter + string(",") + to_string(minutes) + string(",") +
            to_string(seconds) + string(",") + to_string(likes) + string(",") + link + string("\n");
    return result;
}
