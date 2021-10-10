//
// Created by mitza on 26-Mar-21.
//

#include <algorithm>
#include <Commands/User/AddCommandUser.h>
#include <Commands/User/DeleteCommandUser.h>
#include "ServiceUser.h"

using namespace std;

ServiceUser::ServiceUser(FileRepository &dataBase) : dataBase(dataBase) {
    watchList = FileRepository();
    undoService = UndoService();
}

Repository & ServiceUser::getDataBase()  {
    return dataBase;
}

//void ServiceUser::setDataBase(const Repository &dataBase) {
//    ServiceUser::dataBase = dataBase;
//}

Repository &ServiceUser::getWatchList() {
    return watchList;
}

//void ServiceUser::setWatchList(const Repository &watchList) {
//    ServiceUser::watchList = watchList;
//}

//std::string ServiceUser::toStringDataBase() {
//    return this->dataBase.toString();
//}

void ServiceUser::addTutorialWatchList(Tutorial &tutorial) {
    if(this->dataBase.existsTutorial(tutorial.getTitle())){
        this->watchList.addTutorial(tutorial);
        undoService.addCommand(new AddCommandUser(watchList, dataBase, tutorial.getTitle()));
    }
    else
        throw ServiceException("Tutorial doesn't exist in the data base");

}

void ServiceUser::deleteTutorialWatchList(const std::string &title, bool like) {
    this->watchList.deleteTutorial(title);
    if(like)
        likeTutorialWatchList(title);
    undoService.addCommand(new DeleteCommandUser(watchList, dataBase, title));
}

void ServiceUser::likeTutorialWatchList(const std::string &title) {
    int initialValue = this->dataBase.findTutorial(title).getLikes();
    this->dataBase.updateTutorialLikes(title, initialValue + 1);
}

//void ServiceUser::playTutorial(const std::string &title) {
//    std::string link = "chrome.exe " + this->dataBase.findTutorial(title).getLink();
//    system(link.c_str());
//}

Repository ServiceUser::filterTutorials(const std::string &presenter) {
    Repository repository;
    copy_if (dataBase.getList().begin(), dataBase.getList().end(), back_inserter(repository.getList()),
             [&](Tutorial& t){
        return t.getPresenter().find(presenter) != string::npos;
    });
    return repository;
}

std::string ServiceUser::toStringWatchList() {
    return this->watchList.toString();
}

void ServiceUser::saveToHTML(const string &fileName) {
    watchList.saveToHTML(fileName);
    string command = "chrome.exe " + fileName;
    system(command.c_str());
}

void ServiceUser::saveToCSV(const string &fileName) {
    watchList.saveToCSV(fileName);
    string command = "code " + fileName;
    system(command.c_str());
}

void ServiceUser::undo() {
    undoService.undo();
}

void ServiceUser::redo() {
    undoService.redo();
}
