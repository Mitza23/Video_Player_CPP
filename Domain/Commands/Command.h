//
// Created by mitza on 30-May-21.
//

#ifndef A89_MITZA23_COMMAND_H
#define A89_MITZA23_COMMAND_H


class Command {
public:
    virtual void undo()=0;
    virtual void redo()=0;

    Command() {}

    virtual ~Command() {}
};


#endif //A89_MITZA23_COMMAND_H
