//
// Created by mitza on 23-Mar-21.
//

#ifndef A45_MITZA23_UI_H
#define A45_MITZA23_UI_H


#include "../Service/ServiceAdmin.h"
#include "../Service/ServiceUser.h"

class UI {
private:
    ServiceAdmin serviceAdmin;
    ServiceUser serviceUser;
public:
    UI(Repository &dataBase);

    UI(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser);

    UI();

    void printMenu();

    void printAdminMenu();

    void printUpdateAdmin();

    int getInt();

    void printUserMenu();

    void printFilterMenu();

    void filterTutorials();

    void deleteTutorialWatchList();

    void displayTutorialWatchList();

    void startUser();

    void addTutorial();

    void deleteTutorial();

    void updateTitle();

    void updatePresenter();

    void updateMinutes();

    void updateSeconds();

    void updateLikes();

    void updateLink();

    void updateTutorial();

    void displayTutorial();

    void startAdmin();

    void start();

    void generateEntries();

    const ServiceAdmin &getServiceAdmin() const;

//    void setServiceAdmin(const ServiceAdmin &serviceAdmin);

    ServiceUser &getServiceUser();

//    void setServiceUser(const ServiceUser &serviceUser);

    void printFileMenu();

    void loadFromText();

    void saveToText();

    void saveToHTML();

    void saveToCSV();

    void fileOperations();
};


#endif //A45_MITZA23_UI_H
