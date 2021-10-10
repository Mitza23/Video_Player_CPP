//
// Created by mitza on 13-May-21.
//

#include "RoleSelector.h"

RoleSelector::RoleSelector(ServiceAdmin& serviceAdmin, ServiceUser& serviceUser) : serviceAdmin{serviceAdmin},
                                                                                   serviceUser{serviceUser},
                                                                                   adminPanel{serviceAdmin},
                                                                                   userPanel{serviceUser},
                                                                                   fileOptions{serviceAdmin}{
    initGUI();
    connectSignalsAndSlots();
}

void RoleSelector::initGUI() {
    QVBoxLayout* layout = new QVBoxLayout{ this };

    adminButton = new QPushButton("Administrator");
    userButton = new QPushButton("User");
    fileButton = new QPushButton("File options");

    layout->addWidget(adminButton);
    layout->addWidget(userButton);
    layout->addWidget(fileButton);
}

void RoleSelector::connectSignalsAndSlots() {
    QObject::connect(adminButton, SIGNAL(clicked()), this, SLOT(showAdmin()));
    QObject::connect(adminButton, SIGNAL(clicked()), &adminPanel, SLOT(populateList()));
    QObject::connect(userButton, SIGNAL(clicked(bool)), this, SLOT(showUser()));
    QObject::connect(fileButton, SIGNAL(clicked(bool)), this, SLOT(showFile()));
}

void RoleSelector::showAdmin() {
    adminPanel.show();
}

void RoleSelector::showUser() {
    userPanel.show();
}

void RoleSelector::showFile() {
    fileOptions.show();
}
