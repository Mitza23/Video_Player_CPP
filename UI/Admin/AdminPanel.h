//
// Created by mitza on 14-May-21.
//

#ifndef A89_MITZA23_ADMINPANEL_H
#define A89_MITZA23_ADMINPANEL_H


#include <QWidget>
#include <ServiceAdmin.h>
#include <QListWidget>
#include <QPushButton>
#include <QShortcut>
#include "AddAdmin.h"
#include "DeleteAdmin.h"
#include "UpdateAdmin.h"

class AdminPanel : public QWidget{
    Q_OBJECT
private:
    ServiceAdmin& serviceAdmin;


    // graphical elements
    QListWidget* tutorialList;
    QPushButton* addButton, * deleteButton, * updateButton, * backButton, * undoButton, * redoButton;

    AddAdmin addAdmin;
    DeleteAdmin deleteAdmin;
    UpdateAdmin updateAdmin;
    QShortcut* undoShortcut;
    QShortcut* redoShortcut;

    void initGUI();

    void connectSignalsAndSlots();


public:
    AdminPanel(ServiceAdmin& serviceAdmin);

public slots:
    void showAdd();

    void showDelete();

    void showUpdate();

    void populateList();

    void undo();

    void redo();
};


#endif //A89_MITZA23_ADMINPANEL_H
