//
// Created by mitza on 23-Mar-21.
//

#include "UI.h"
#include <iostream>
#include <ValidatorException.h>


using namespace std;



UI::UI(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser) : serviceAdmin(serviceAdmin),
                                                               serviceUser(serviceUser) {}

const ServiceAdmin &UI::getServiceAdmin() const {
    return serviceAdmin;
}

//void UI::setServiceAdmin(const ServiceAdmin &serviceAdmin) {
//    UI::serviceAdmin = serviceAdmin;
//}

ServiceUser &UI::getServiceUser() {
    return serviceUser;
}

//void UI::setServiceUser(const ServiceUser &serviceUser) {
//    UI::serviceUser = serviceUser;
//}


void UI::printMenu() {
    cout << "1. Administrator\n";
    cout << "2. User\n";
    cout << "3. File Options\n";
    cout << "0. Exit\n";
}

void UI::printAdminMenu() {
    cout << "1. Add Tutorial\n";
    cout << "2. Delete Tutorial\n";
    cout << "3. Display Tutorials\n";
    cout << "4. Update Tutorial\n";
    cout << "0. Exit\n";
}

void UI::printUpdateAdmin() {
    cout << "1. Update title\n";
    cout << "2. Update presenter\n";
    cout << "3. Update minutes\n";
    cout << "4. Update seconds\n";
    cout << "5. Update likes\n";
    cout << "6. Update link\n";
}

int UI::getInt() {
    string number;
    int nr = 0;
    bool done = false;
    while(!done) {
        try {
            cout << ">> ";
            getline(cin, number);
            nr = stoi(number);
            done = true;
        }
        catch (exception& e) {
            cout << "Invalid input: please enter a valid number\n";
            //cout << e.what() << endl;
        }
    }
    return nr;
}

void UI::printUserMenu() {
    cout << "1. Filter tutorials" << endl;
    cout << "2. Display watchlist" << endl;
    cout << "3. Delete tutorial" << endl;
    cout << "0. Exit" << endl;
}

void UI::printFilterMenu() {
    cout << "1. Add to watchlist" << endl;
    cout << "2. Play next" << endl;
    cout << "0. Exit" << endl;
}

void UI::filterTutorials() {
    cout << "Which presenter's tutorials would you like to see?" << endl;
    string presenter;
    getline(cin, presenter);
    Repository filteredRepo = this->serviceUser.filterTutorials(presenter);
    if(filteredRepo.getList().size() == 0)
        cout << "No tutorials available from " << presenter << endl;
    else {
        bool done = false;
        int position = 0;
        while (!done) {
            if(position == filteredRepo.getList().size())
                position = 0;
            Tutorial t = filteredRepo.getList()[position];
            cout << t.toString() << endl;
            try {
                t.play();
            } catch (exception &e) {
                cout << "An error occurred while playing the video" << endl;
            }
            printFilterMenu();
            input:
            int cmd = getInt();
            switch (cmd) {
                case 1:
                    this->serviceUser.addTutorialWatchList(t);
                    position++;
                    if (position == filteredRepo.getList().capacity())
                        position = 0;
                    break;
                case 2:
                    position++;
                    if (position == filteredRepo.getList().capacity())
                        position = 0;
                    break;
                case 0:
                    done = true;
                    break;
                default:
                    cout << "Invalid command" << endl;
                    goto input;
            }
        }
    }
}

void UI::deleteTutorialWatchList() {
    try {
        cout << "Title of the tutorial to be deleted: ";
        string title;
        getline(cin, title);
        cout << "1. Like" << endl;
        cout << "0. Don't like" << endl;
        int cmd = getInt();
        bool like = false;
        if (cmd == 1)
            like = true;
        this->getServiceUser().deleteTutorialWatchList(title, like);
    }
    catch (RepositoryException& e){
        cout << e.getMessage() << endl << "Please enter a valid title" << endl;
    }
}

void UI::displayTutorialWatchList() {
    bool done = false;
    while(!done) {
        cout << "1.Text" << endl;
        cout << "2. HTML" << endl;
        cout << "3. CSV" << endl;
        cout << "0. Exit" << endl;
        int cmd = getInt();
        switch (cmd) {
            case 1:
                cout << serviceUser.toStringWatchList();
                break;
            case 2:
                serviceUser.saveToHTML("watchlist.html");
                break;
            case 3:
                serviceUser.saveToCSV("watchlist.csv");
                break;
            case 0:
                done = true;
                break;
            default:
                cout << "Invalid command" << endl;
        }
    }
}

void UI::startUser() {
    bool done = false;
    while(!done) {
        printUserMenu();
        int cmd = getInt();
        try {
            switch (cmd) {
                case 1:
                    filterTutorials();
                    break;
                case 2:
                    displayTutorialWatchList();
                    break;
                case 3:
                    deleteTutorialWatchList();
                    break;
                case 0:
                    done = true;
                    break;
                default:
                    cout << "Invalid command!" << endl;
                    break;
            }
        }
        catch (Exception& e){
            cout << e.getMessage() << endl;
        }
        catch (RepositoryException& e){
            cout << e.getMessage() << endl;
        }

        catch (ServiceException& e){
            cout << e.getMessage() << endl;
        }
    }
}

void UI::addTutorial() {
    string title, presenter, link;
    int minutes, seconds, likes;
    cout << "Title: ";
    getline(cin, title);

    cout << "Presenter: ";
    getline(cin, presenter);

    cout << "Minutes: ";
    minutes = getInt();

    cout << "Seconds: ";
    seconds = getInt();

    cout << "Likes: ";
    likes = getInt();

    cout << "Link: ";
    getline(cin, link);

    this->serviceAdmin.addTutorial(title, presenter, minutes, seconds, likes, link);

}

void UI::deleteTutorial() {
    string title;
    cout << "Title: ";
    getline(cin, title);

    this->serviceAdmin.deleteTutorial(title);
}

void UI::updateTitle() {
    string title;
    cout << "Title: ";
    getline(cin, title);

    string newTitle;
    cout << "New title: ";
    getline(cin, newTitle);

    this->serviceAdmin.updateTutorialTitle(title, newTitle);
}

void UI::updatePresenter() {
    string title;
    cout << "Title: ";
    getline(cin, title);

    string newPresenter;
    cout << "New presenter: ";
    getline(cin, newPresenter);

    this->serviceAdmin.updateTutorialPresenter(title, newPresenter);
}

void UI::updateMinutes() {
    string title;
    cout << "Title: ";
    getline(cin, title);

    int newValue;
    cout << "New time period: ";
    newValue = getInt();

    this->serviceAdmin.updateTutorialMinutes(title, newValue);
}

void UI::updateSeconds() {
    string title;
    cout << "Title: ";
    getline(cin, title);

    int newValue;
    cout << "New time period: ";
    newValue = getInt();

    this->serviceAdmin.updateTutorialSeconds(title, newValue);
}

void UI::updateLikes() {
    string title;
    cout << "Title: ";
    getline(cin, title);

    int newValue;
    cout << "New time period: ";
    newValue = getInt();

    this->serviceAdmin.updateTutorialLikes(title, newValue);
}

void UI::updateLink() {
    string title;
    cout << "Title: ";
    getline(cin, title);

    string newLink;
    cout << "New link: ";
    getline(cin, newLink);

    this->serviceAdmin.updateTutorialLink(title, newLink);
}

void UI::updateTutorial() {
    printUpdateAdmin();
    int cmd = getInt();
    switch (cmd) {
        case 1:
            this->updateTitle();
            break;
        case 2:
            this->updatePresenter();
            break;
        case 3:
            this->updateMinutes();
            break;
        case 4:
            this->updateSeconds();
            break;
        case 5:
            this->updateLikes();
            break;
        case 6:
            this->updateLink();
            break;
        default:
            cout << "Invalid command\n";
    }
}

void UI::displayTutorial() {
    string s = this->serviceAdmin.toString();
    cout<< s;
}

void UI::startAdmin() {
    bool done = false;
    while(!done) {
        try{
            printAdminMenu();
            int cmd = getInt();
            switch (cmd) {
                case 1:
                    this->addTutorial();
                    break;
                case 2:
                    this->deleteTutorial();
                    break;
                case 3:
                    this->displayTutorial();
                    break;
                case 4:
                    this->updateTutorial();
                    break;
                case 0:
                    done = true;
                    break;
                default:
                    cout << "Invalid command\n";
                    break;
            }
        }
        catch (Exception& e){
            cout << e.getMessage() << endl;
        }

        catch (RepositoryException& e){
            cout << e.getMessage() << endl;
        }

        catch (ServiceException& e){
            cout << e.getMessage() << endl;
        }

        catch (ValidatorException& e){
            cout << e.getMessage() << endl;
        }

        catch (exception& e){
            cout << e.what() << endl;
        }
    }
}

void UI::start() {
    generateEntries();
    bool done = false;
    while(!done) {
        printMenu();
        int cmd = getInt();
        switch (cmd) {
            case 1:
                startAdmin();
                break;
            case 2:
                startUser();
                break;
            case 3:
                fileOperations();
                break;
            case 0:
                done = true;
                break;
            default:
                cout << "Invalid command\n";
        }
    }
}

void UI::generateEntries() {
    this->serviceAdmin.addTutorial("C++ Fundamentals", "King AJ", 123, 34, 10000,
                                   "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    this->serviceAdmin.addTutorial("Python Fundamentals", "King AJ", 120, 4, 18900,
                                   "https://www.youtube.com/watch?v=Woc03yg8dqQ");
    this->serviceAdmin.addTutorial("C Fundamentals", "King AJ", 96, 15, 3000,
                                   "https://www.youtube.com/watch?v=Yd-yqtB8UPc");
    this->serviceAdmin.addTutorial("Javra Fundamentals", "King AJ", 85, 6, 25463,
                                   "https://www.youtube.com/watch?v=Vr_NK0LFFnQ");
    this->serviceAdmin.addTutorial("DSA I", "Jhou", 60, 6, 25463,
                                   "https://www.youtube.com/watch?v=0CRbZSqSwwA");
    this->serviceAdmin.addTutorial("DSA II", "Jhou", 56, 12, 6789,
                                   "https://www.youtube.com/watch?v=GuTB-eWPnRs");
    this->serviceAdmin.addTutorial("DSA III", "Jhou", 67, 23, 4566,
                                   "https://www.youtube.com/watch?v=_z5D_VBFB1E");
    this->serviceAdmin.addTutorial("DSA IV", "Jhou", 80, 7, 5004,
                                   "https://www.youtube.com/watch?v=1at7kKzBYxI");
    this->serviceAdmin.addTutorial("CSA Basics", "VanC", 214, 59, 999999,
                                   "https://www.youtube.com/watch?v=n8LUQGOe1Ks");
    this->serviceAdmin.addTutorial("CSA and C", "VanC", 234, 59, 999999,
                                   "https://www.youtube.com/watch?v=U-dwjybcAZw");
}

void UI::printFileMenu() {
    cout << "1. Load from text file" << endl;
    cout << "2. Save to text file" << endl;
    cout << "3. Save to HTML" << endl;
    cout << "4. Save to CSV" << endl;
    cout << "5. Save to HTML/CSV File" << endl;
    cout << "0. Exit" << endl;
}

void UI::loadFromText() {
    string fileName;
    cout << "File name:" << endl;
    getline(cin, fileName);
    serviceAdmin.loadFromText(fileName);
}

void UI::saveToText() {
    string fileName;
    cout << "File name:" << endl;
    getline(cin, fileName);
    serviceAdmin.saveToText(fileName);
}

void UI::saveToHTML() {
    string fileName;
    cout << "File name:" << endl;
    getline(cin, fileName);
    serviceAdmin.saveToHTML(fileName);
}

void UI::saveToCSV() {
    string fileName;
    cout << "File name:" << endl;
    getline(cin, fileName);
    serviceAdmin.saveToCSV(fileName);
}

void UI::fileOperations() {
    bool done = false;
    while(!done) {
        try {
            printFileMenu();
            int cmd = getInt();
            switch (cmd) {
                case 1:
                    loadFromText();
                    break;
                case 2:
                    saveToText();
                    break;
                case 3:
                    saveToHTML();
                    break;
                case 4:
                    saveToCSV();
                    break;
                case 5:
                    serviceAdmin.getRepo().saveToFile();
                case 0:
                    done = true;
                    break;
                default:
                    cout << "Invalid command" << endl;
            }
        }
        catch (ValidatorException &e){
            cout << e.getMessage() << endl;
        }
        catch (ServiceException &e){
            cout << e.getMessage() << endl;
        }
        catch (RepositoryException &e){
            cout << e.getMessage() << endl;
        }
        catch (Exception &e){
            cout << e.getMessage() << endl;
        }
    }
}



