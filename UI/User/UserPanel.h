//
// Created by mitza on 15-May-21.
//

#ifndef A89_MITZA23_USERPANEL_H
#define A89_MITZA23_USERPANEL_H


#include <QWidget>
#include <ServiceUser.h>
#include <QPushButton>
#include <QListWidget>
#include <QShortcut>
#include <QTableView>
#include "FilterUser.h"
#include "DeleteUser.h"
#include "DisplayUser.h"

class UserPanel : public QWidget{
    Q_OBJECT
private:
    ServiceUser& serviceUser;

    // graphical elements
    QPushButton* filterButton;
    QPushButton* deleteButton;
    QPushButton* displayButton;
    QPushButton* backButton;
    QListWidget* tutorialList;
    QTableView* tutorialTable;
    QPushButton* undoButton;
    QPushButton* redoButton;

    FilterUser filterUser;
    DeleteUser deleteUser;
    DisplayUser displayUser;

    QShortcut* undoShortcut;
    QShortcut* redoShortcut;

    void initGUI();

    void connectSignalsAndSlots();

public:
    UserPanel(ServiceUser& serviceUser);

public slots:
    void showFilter();

    void showDelete();

    void showDisplay();

    void populateList();

    void undo();

    void redo();
};


#endif //A89_MITZA23_USERPANEL_H
