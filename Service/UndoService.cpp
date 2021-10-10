//
// Created by mitza on 30-May-21.
//

#include "UndoService.h"
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

const std::vector<Command*> &UndoService::getList() const {
    return list;
}

UndoService::UndoService(): position{0}{
    list = vector<Command*>();
}


void UndoService::addCommand(Command *command) {
    for(int i = position ; i < list.size() ; i++) {
        delete list[i];
    }
    if (position < list.size()) {
        list.erase(list.begin() + position, list.end());
    }
    list.push_back(command);
    position++;
//    cout << position << " " << list.size();
}

void UndoService::undo() {
    if(position < 1){
        throw ServiceException("No more operations to be undone");
    }
    position--;
//    cout << "undo " << position << endl;
    list[position]->undo();
}

void UndoService::redo() {
    if(position >= list.size() || position < 0){
        throw ServiceException("No more operations to be redone");
    }
//    cout << "redo " << position << endl;
    list[position]->redo();
    position++;
}

UndoService::~UndoService() {
    for(auto & i : list)
        delete i;
}
