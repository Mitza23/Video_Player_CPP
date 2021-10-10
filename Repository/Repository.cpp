//
// Created by mitza on 21-Mar-21.
//

#include <iostream>
#include <fstream>
#include "Repository.h"
#include "../Exceptions/Exception.h"

using namespace std;

Repository::Repository() = default;

vector<Tutorial>& Repository::getList() {
    return list;
}

int Repository::findTutorialPosition(std::string title) {
    int len = this->list.size();
    for(int i = 0 ; i < len ; i++){
        if(this->list[i].getTitle() == title)
            return i;
    }
    throw Exception("Tutorial hasn't been found");
}

Tutorial &Repository::findTutorial(string title) {
    for( auto &t : list){
        if(t.getTitle() == title)
            return t;
    }
    throw Exception("Tutorial hasn't been found");
}

bool Repository::existsTutorial(std::string title) {
    for( auto &t : list){
        if(t.getTitle() == title)
            return true;
    }
    return false;
}

void Repository::addTutorial(Tutorial& t) {
        if(this->existsTutorial(t.getTitle()))
            throw RepositoryException(std::string("Tutorial with the same name already exists"));
        else
            this->list.push_back(t);
}

void Repository::deleteTutorial(std::string title) {
    try{
        int pos = this->findTutorialPosition(title);
        this->list.erase(list.begin()+pos);
    }catch(Exception& e){
        throw RepositoryException(e.getMessage());
    }
}

void Repository::updateTutorialTitle(std::string title, std::string newTitle) {
    if(this->existsTutorial(title) && !this->existsTutorial(newTitle)){
        Tutorial& t = this->findTutorial(title);
        t.setTitle(newTitle);
    }
    else {
        if(this->existsTutorial(newTitle))
            throw RepositoryException("Tutorial with the same name already exists");
        throw RepositoryException("Tutorial hasn't been found");
    }
}

void Repository::updateTutorialPresenter(std::string title, std::string newPresenter) {
    if(this->existsTutorial(title)){
        Tutorial& t = this->findTutorial(title);
        t.setPresenter(newPresenter);
    }
    else
        throw RepositoryException("Tutorial hasn't been found");
}

void Repository::updateTutorialMinutes(std::string title, int newValue) {
    if(this->existsTutorial(title)){
        Tutorial& t = this->findTutorial(title);
        t.setMinutes(newValue);
    }
    else
        throw RepositoryException("Tutorial hasn't been found");
}

void Repository::updateTutorialSeconds(std::string title, int newValue) {
    if(this->existsTutorial(title)){
        Tutorial& t = this->findTutorial(title);
        t.setSeconds(newValue);
    }
    else
        throw RepositoryException("Tutorial hasn't been found");
}

void Repository::updateTutorialLikes(std::string title, int newValue) {
    if(this->existsTutorial(title)){
        Tutorial& t = this->findTutorial(title);
        t.setLikes(newValue);
    }
    else
        throw RepositoryException("Tutorial hasn't been found");
}

void Repository::updateTutorialLink(std::string title, std::string newLink) {
    if(this->existsTutorial(title)){
        Tutorial& t = this->findTutorial(title);
        t.setLink(newLink);
    }
    else
        throw RepositoryException("Tutorial hasn't been found");
}

std::string Repository::toString() {
    string s;
    for( auto &t : list){
       s += t.toString() + "\n";
    }
    return s;
}

void Repository::saveToFile() {

}


//int main(){
//    return 0;
//}