//
// Created by mitza on 13-May-21.
//

#ifndef A89_MITZA23_ROLESELECTOR_H
#define A89_MITZA23_ROLESELECTOR_H


#include <QWidget>
#include <ServiceAdmin.h>
#include <ServiceUser.h>
#include <QPushButton>
#include <QHBoxLayout>
#include <User/UserPanel.h>
#include <FileOptions/FileOptions.h>
#include "Admin/AdminPanel.h"

class RoleSelector : public QWidget{
    Q_OBJECT
private:
    ServiceAdmin& serviceAdmin;
    ServiceUser& serviceUser;

    // graphical elements
    QPushButton* adminButton;
    QPushButton* userButton;
    QPushButton* fileButton;

    AdminPanel adminPanel;
    UserPanel userPanel;
    FileOptions fileOptions;

    void initGUI();

    void connectSignalsAndSlots();


public:
    RoleSelector(ServiceAdmin& serviceAdmin, ServiceUser& serviceUser);

public slots:
    void showAdmin();

    void showUser();

    void showFile();
};


#endif //A89_MITZA23_ROLESELECTOR_H
