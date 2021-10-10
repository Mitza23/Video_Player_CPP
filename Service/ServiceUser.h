//
// Created by mitza on 26-Mar-21.
//

#ifndef A45_MITZA23_SERVICEUSER_H
#define A45_MITZA23_SERVICEUSER_H


#include <FileRepository.h>
#include <msdasc.h>
#include "../Repository/Repository.h"
#include "../Exceptions/ServiceException.h"
#include "UndoService.h"

class ServiceUser {
private:
    FileRepository &dataBase;
    FileRepository watchList;
    UndoService undoService;
public:

    explicit ServiceUser(FileRepository &dataBase);

    Repository & getDataBase();

//    void setDataBase(const Repository &dataBase);

     Repository &getWatchList();

//    void setWatchList(const Repository &watchList);

//    std::string toStringDataBase();

    /// Adds an existing tutorial from the data base to the watchlist
    /// \param tutorial the tutorial to be added - Tutorial&
    /// \raise ServiceException in case the tutorial to be added doesn't exist in the data base
    void addTutorialWatchList(Tutorial &tutorial);

    ///
    /// \param title
    /// \param like
    void deleteTutorialWatchList(const std::string &title, bool like);

    void likeTutorialWatchList(const std::string &title);

//    void playTutorial(const std::string &title);

    Repository filterTutorials(const std::string &presenter);

    std::string toStringWatchList();

    void saveToHTML(const std::string &fileName);

    void saveToCSV(const std::string &fileName);

    void undo();

    void redo();
};


#endif //A45_MITZA23_SERVICEUSER_H
