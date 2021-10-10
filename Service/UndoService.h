//
// Created by mitza on 30-May-21.
//

#ifndef A89_MITZA23_UNDOSERVICE_H
#define A89_MITZA23_UNDOSERVICE_H


#include <Commands/Command.h>
#include <vector>
#include <msdasc.h>
#include <ServiceException.h>

class UndoService {
private:
    std::vector<Command*> list;
    int position;
public:
    const std::vector<Command *> &getList() const;

    UndoService();

    void addCommand(Command* command);

    void undo();

    void redo();

    virtual ~UndoService();
};


#endif //A89_MITZA23_UNDOSERVICE_H
