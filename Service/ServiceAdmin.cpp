//
// Created by mitza on 23-Mar-21.
//

#include "ServiceAdmin.h"
#include <iostream>
#include <Commands/Admin/AddCommandAdmin.h>
#include <Commands/Admin/DeleteCommandAdmin.h>
#include <Commands/Admin/UpdateTitleCommandAdmin.h>
#include <Commands/Admin/UpdatePresenterCommandAdmin.h>

using namespace std;



void ServiceAdmin::addTutorial(const std::string &title, const std::string &presenter, int minutes, int seconds,
                               int likes, const std::string &link) {
    if(validTutorial(title, presenter, minutes, seconds, likes, link)){
        Tutorial t = Tutorial(title, presenter, minutes, seconds, likes, link);
        this->repo.addTutorial(t);
        undoService.addCommand(new AddCommandAdmin(this->repo, title, presenter, minutes, seconds, likes, link));
    }
    else{
        throw ServiceException("Invalid parameters for Tutorial\n");
    }
}

void ServiceAdmin::deleteTutorial(const std::string title) {
    if (validTitle(title)) {
        Tutorial t = repo.findTutorial(title);
        this->repo.deleteTutorial(title);
        undoService.addCommand(new DeleteCommandAdmin(this->repo, t.getTitle(), t.getPresenter(), t.getMinutes(),
                                                      t.getSeconds(), t.getLikes(), t.getLink()));
    }
    else
        throw ServiceException("Invalid title");
}

void ServiceAdmin::updateTutorialTitle(std::string title, std::string newTitle) {
    if (validTitle(title) && validTitle(newTitle)) {
        this->repo.updateTutorialTitle(title, newTitle);
        undoService.addCommand(new UpdateTitleCommandAdmin(this->repo, newTitle, title));
    }
    else
        throw ServiceException("Invalid title");
}

void ServiceAdmin::updateTutorialPresenter(std::string title, std::string newPresenter) {
    if(validTitle(title) && validPresenter(newPresenter)) {
        auto oldPresenter = repo.findTutorial(title).getPresenter();
        this->repo.updateTutorialPresenter(title, newPresenter);
        undoService.addCommand(new UpdatePresenterCommandAdmin(this->repo, title, newPresenter, oldPresenter));
    }
    else
        throw ServiceException("Invalid credentials");
}

void ServiceAdmin::updateTutorialMinutes(std::string title, int newValue) {
    if(validTitle(title) && validTime(newValue))
        this->repo.updateTutorialMinutes(title, newValue);
    else
        throw ServiceException("Invalid credentials");
}

void ServiceAdmin::updateTutorialSeconds(std::string title, int newValue) {
    if(validTitle(title) && validSeconds(newValue))
        this->repo.updateTutorialSeconds(title, newValue);
    else
        throw ServiceException("Invalid credentials");
}

void ServiceAdmin::updateTutorialLikes(std::string title, int newValue) {
    if(validTitle(title) && validLikes(newValue))
        this->repo.updateTutorialLikes(title, newValue);
    else
        throw ServiceException("Invalid credentials");
}

void ServiceAdmin::updateTutorialLink(std::string title, std::string newLink) {
    if (validTitle(title) && validLink(newLink))
        this->repo.updateTutorialLink(title, newLink);
    else
        throw ServiceException("Invalid credentials");
}

std::string ServiceAdmin::toString() {
    return this->repo.toString();
}

ServiceAdmin::ServiceAdmin(FileRepository &repo) : repo(repo) {
    undoService = UndoService();
}

FileRepository & ServiceAdmin::getRepo() {
    return repo;
}

void ServiceAdmin::saveToText(const string &fileName) {
    repo.saveToText(fileName);
}

void ServiceAdmin::loadFromText(const string &fileName) {
    repo.loadFromText(fileName);
}

void ServiceAdmin::saveToHTML(const string &fileName) {
    repo.saveToHTML(fileName);
    string command = "chrome.exe D:\\Facultate\\Sem_2\\OOP\\OOP_Assignments\\a89-Mitza23\\" + fileName;
    system(command.c_str());
}

void ServiceAdmin::saveToCSV(const string &fileName) {
    repo.saveToCSV(fileName);
    string command = "code " + fileName;
    system(command.c_str());
}

std::vector<Tutorial> ServiceAdmin::getAll() {
    return repo.getList();
}

void ServiceAdmin::undo() {
    undoService.undo();
}

void ServiceAdmin::redo() {
    undoService.redo();
}

//bool ServiceAdmin::existsTutorial(const string &title) {
//    return this->repo.existsTutorial(title);
//}
//
//Tutorial &ServiceAdmin::findTutorial(const string &title) {
//    return this->repo.findTutorial(title);
//}
