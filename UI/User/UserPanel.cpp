//
// Created by mitza on 15-May-21.
//

#include <QHBoxLayout>
#include <iostream>
#include "UserPanel.h"
#include "TutorialModel.h"

using std::string;
using std::cout;
using std::endl;

UserPanel::UserPanel(ServiceUser &serviceUser) : serviceUser{serviceUser},
                                                 filterUser{this, serviceUser},
                                                 deleteUser{this, serviceUser},
                                                 displayUser(serviceUser){
    initGUI();
    connectSignalsAndSlots();

}

void UserPanel::initGUI() {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QVBoxLayout *buttonsLayout = new QVBoxLayout();
    filterButton = new QPushButton("Filter");
    deleteButton = new QPushButton("Delete");
    displayButton = new QPushButton("Display");
    backButton = new QPushButton("Back");
    tutorialList = new QListWidget();
    tutorialTable = new QTableView();
    undoButton = new QPushButton("Undo");
    redoButton = new QPushButton("Redo");
    buttonsLayout->addWidget(filterButton);
    buttonsLayout->addWidget(deleteButton);
    buttonsLayout->addWidget(displayButton);
    buttonsLayout->addWidget(undoButton);
    buttonsLayout->addWidget(redoButton);
    buttonsLayout->addWidget(backButton);
    mainLayout->addLayout(buttonsLayout);
//    mainLayout->addWidget(tutorialList);
    mainLayout->addWidget(tutorialTable);

    undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);

    auto items = serviceUser.getWatchList().getList();
    auto model = new TutorialModel(items);
    tutorialTable->setModel(model);
    tutorialTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
}

void UserPanel::connectSignalsAndSlots() {
    QObject::connect(backButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(filterButton, SIGNAL(clicked(bool)), this, SLOT(showFilter()));
    QObject::connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(showDelete()));
    QObject::connect(displayButton, SIGNAL(clicked(bool)), this, SLOT(showDisplay()));
    QObject::connect(undoButton, SIGNAL(clicked(bool)), this, SLOT(undo()));
    QObject::connect(redoButton, SIGNAL(clicked(bool)), this, SLOT(redo()));
    QObject::connect(undoShortcut, SIGNAL(activated()), this, SLOT(undo()));
    QObject::connect(redoShortcut, SIGNAL(activated()), this, SLOT(redo()));

}

void UserPanel::showFilter() {
    filterUser.show();
}

void UserPanel::showDelete() {
    deleteUser.show();
}

void UserPanel::showDisplay() {
    displayUser.show();
}

void UserPanel::populateList() {
    tutorialList->clear();
    for(auto t: serviceUser.getWatchList().getList()){
        tutorialList->addItem(QString::fromStdString(t.toString()));
    }
    auto items = serviceUser.getWatchList().getList();
    delete tutorialTable->model();
    auto model = new TutorialModel(items);
    tutorialTable->setModel(model);
}

void UserPanel::undo() {
    try {
        serviceUser.undo();
        populateList();
    }
    catch (ServiceException& e) {
        string message = e.getMessage();
        QMessageBox messageBox;
        messageBox.setText(QString::fromStdString(message));
        messageBox.exec();
    }
}

void UserPanel::redo() {
    try {
        serviceUser.redo();
        populateList();
    }
    catch (ServiceException& e) {
        string message = e.getMessage();
        QMessageBox messageBox;
        messageBox.setText(QString::fromStdString(message));
        messageBox.exec();
    }
}
