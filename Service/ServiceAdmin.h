//
// Created by mitza on 23-Mar-21.
//

#ifndef A45_MITZA23_SERVICEADMIN_H
#define A45_MITZA23_SERVICEADMIN_H

#include <FileRepository.h>
#include <msdasc.h>
#include "../Repository/Repository.h"
#include "../Exceptions/ServiceException.h"
#include "../Validator/Validator.h"
#include "UndoService.h"

class ServiceAdmin{
private:
    FileRepository &repo;
    UndoService undoService;

public:
    FileRepository &getRepo() ;

    ServiceAdmin();

    /// ServiceAdmin class represents the center of operations for the application
    /// \param repo the repo on which the operations are executed - Repository&
    ServiceAdmin(FileRepository &repo);

    void addTutorial(const std::string &title, const std::string &presenter, int minutes, int seconds, int likes,
                     const std::string &link );

//    bool existsTutorial(const std::string &title);
//
//    Tutorial& findTutorial(const std::string &title);

    void deleteTutorial(const std::string title);

    void updateTutorialTitle(std::string title, std::string newTitle);

    void updateTutorialPresenter(std::string title, std::string newPresenter);

    void updateTutorialMinutes(std::string title, int newValue);

    void updateTutorialSeconds(std::string title, int newValue);

    void updateTutorialLikes(std::string title, int newValue);

    void updateTutorialLink(std::string title, std::string newLink);

    std::string toString();

    void saveToText(const std::string& fileName);

    void loadFromText(const std::string& fileName);

    void saveToHTML(const std::string& fileName);

    void saveToCSV(const std::string& fileName);

    std::vector<Tutorial> getAll();

    void undo();

    void redo();

};

#endif //A45_MITZA23_SERVICEADMIN_H
