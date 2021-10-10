//
// Created by mitza on 15-May-21.
//

#include <QFormLayout>
#include <QMessageBox>
#include "DeleteUser.h"

DeleteUser::DeleteUser( QWidget* parent, ServiceUser& serviceUser) :parent{parent}, serviceUser{serviceUser}{
    initGUI();
    connectSignalsAndSlots();
}

void DeleteUser::initGUI() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QFormLayout* titleLayout = new QFormLayout();
    titleEdit = new QLineEdit();
    deleteButton = new QPushButton("&Delete");
    titleLayout->addRow("&Title", titleEdit);
    mainLayout->addLayout(titleLayout);
    mainLayout->addWidget(deleteButton);
    likeButton = new QPushButton("Like");
    passButton = new QPushButton("Pass");
    likeWindow = new QWidget();
    QHBoxLayout* likeLayout = new QHBoxLayout(likeWindow);
    likeLayout->addWidget(likeButton);
    likeLayout->addWidget(passButton);

}

void DeleteUser::connectSignalsAndSlots() {
    QObject::connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteTutorial()));
    QObject::connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(likeButton, SIGNAL(clicked(bool)), this, SLOT(likeTutorial()));
    QObject::connect(likeButton, SIGNAL(clicked(bool)), parent, SLOT(populateList()));
    QObject::connect(passButton, SIGNAL(clicked(bool)), this, SLOT(passTutorial()));
    QObject::connect(passButton, SIGNAL(clicked(bool)), parent, SLOT(populateList()));
}

void DeleteUser::deleteTutorial() {
    title = titleEdit->text().toStdString();
    likeWindow->show();
}

void DeleteUser::likeTutorial() {
    like = true;
    try{
        serviceUser.deleteTutorialWatchList(title, like);
    }
    catch (RepositoryException& e){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString(e.getMessage()));
        alertBox.exec();
    }
    catch (ServiceException& e){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString(e.getMessage()));
        alertBox.exec();
    }
    likeWindow->close();
}

void DeleteUser::passTutorial() {
    like = false;
    try{
        serviceUser.deleteTutorialWatchList(title, like);
    }
    catch (RepositoryException& e){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString(e.getMessage()));
        alertBox.exec();
    }
    catch (ServiceException& e){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString(e.getMessage()));
        alertBox.exec();
    }
    likeWindow->close();
}
