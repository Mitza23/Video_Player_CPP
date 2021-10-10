//
// Created by mitza on 14-May-21.
//

#include <QVBoxLayout>
#include <QMessageBox>
#include "AdminPanel.h"

using namespace std;

AdminPanel::AdminPanel(ServiceAdmin &serviceAdmin) : serviceAdmin{serviceAdmin},
                                                     addAdmin{this, serviceAdmin},
                                                     deleteAdmin{this, serviceAdmin},
                                                     updateAdmin(this, serviceAdmin){
    initGUI();
    connectSignalsAndSlots();
    populateList();
}

void AdminPanel::initGUI() {
    QHBoxLayout* mainLayout = new QHBoxLayout{this};
    QWidget* buttons = new QWidget;
    QVBoxLayout* buttonsLayout = new QVBoxLayout{buttons};
    tutorialList = new QListWidget;
    addButton = new QPushButton("Add");
    deleteButton = new QPushButton("Delete");
    updateButton = new QPushButton("Update");
    backButton = new QPushButton("Back");
    undoButton = new QPushButton("Undo");
    redoButton = new QPushButton("Redo");

    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(deleteButton);
    buttonsLayout->addWidget(updateButton);
    buttonsLayout->addWidget(undoButton);
    buttonsLayout->addWidget(redoButton);
    buttonsLayout->addWidget(backButton);

    mainLayout->addWidget(buttons);
    mainLayout->addWidget(tutorialList);

    undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);

}

void AdminPanel::connectSignalsAndSlots() {
    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(addButton, SIGNAL(clicked()), this, SLOT(showAdd()));
    QObject::connect(deleteButton, SIGNAL(clicked()), this, SLOT(showDelete()));
    QObject::connect(updateButton, SIGNAL(clicked()), this, SLOT(showUpdate()));
    QObject::connect(undoButton, SIGNAL(clicked()), this, SLOT(undo()));
    QObject::connect(redoButton, SIGNAL(clicked()), this, SLOT(redo()));
    QObject::connect(undoShortcut, SIGNAL(activated()), this, SLOT(undo()));
    QObject::connect(redoShortcut, SIGNAL(activated()), this, SLOT(redo()));
}

void AdminPanel::showAdd() {
    addAdmin.show();
    addAdmin.clear();
}

void AdminPanel::showDelete() {
    deleteAdmin.show();
}

void AdminPanel::showUpdate() {
    updateAdmin.show();
}

void AdminPanel::populateList() {
    tutorialList->clear();

    vector<Tutorial> allTutorials = serviceAdmin.getAll();
    for(auto &t: allTutorials){
        tutorialList->addItem(QString::fromStdString(t.toString()));
    }
}

void AdminPanel::undo() {
    try {
        serviceAdmin.undo();
        populateList();
    }
    catch (ServiceException& e) {
        string message = e.getMessage();
        QMessageBox messageBox;
        messageBox.setText(QString::fromStdString(message));
        messageBox.exec();
    }
}

void AdminPanel::redo() {
    try {
        serviceAdmin.redo();
        populateList();
    }
    catch (ServiceException& e) {
        string message = e.getMessage();
        QMessageBox messageBox;
        messageBox.setText(QString::fromStdString(message));
        messageBox.exec();
    }{}
}
