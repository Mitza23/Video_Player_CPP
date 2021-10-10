//
// Created by mitza on 30-May-21.
//

#ifndef A89_MITZA23_UPDATEPRESENTERCOMMANDADMIN_H
#define A89_MITZA23_UPDATEPRESENTERCOMMANDADMIN_H


#include <ServiceAdmin.h>
#include "Commands/Command.h"

class UpdatePresenterCommandAdmin  : public Command{
private:
    Repository& repository;
    std::string title, newPresenter, oldPresenter;
public:
    UpdatePresenterCommandAdmin(Repository &repo, const std::string &title, const std::string &newPresenter,
                                const std::string &oldPresenter);
    void undo();

    void redo();

};


#endif //A89_MITZA23_UPDATEPRESENTERCOMMANDADMIN_H
