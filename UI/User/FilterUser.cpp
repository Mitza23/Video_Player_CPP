//
// Created by mitza on 15-May-21.
//

#include <QFormLayout>
#include <QLabel>
#include <iostream>
#include <unistd.h>
#include "FilterUser.h"
#include "UserPanel.h"

using std::cout;
using std::endl;

FilterUser::FilterUser(QWidget* parent, ServiceUser &serviceUser) :parent{parent}, serviceUser{serviceUser}{
    initGUI();
    connectSignalsAndSlots();
}

void FilterUser::initGUI() {
    presenterEdit = new QLineEdit();
    filterButton = new QPushButton("&Filter");
    QFormLayout* layout = new QFormLayout(this);
    layout->addRow("&Presenter", presenterEdit);
    layout->addWidget(filterButton);

    // Tutorial option
    tutorialWindow = new QWidget();
    QLabel* titleLabel = new QLabel("Title");
    titleEdit = new QLineEdit();
    titleLabel->setBuddy(titleEdit);
    addButton = new QPushButton("Add to WatchList");
    nextButton = new QPushButton("Next");
    exitButton = new QPushButton("Exit");
    QVBoxLayout* tutorialWindowLayout = new QVBoxLayout(tutorialWindow);
    tutorialWindowLayout->addWidget(titleLabel);
    tutorialWindowLayout->addWidget(titleEdit);
    tutorialWindowLayout->addWidget(addButton);
    tutorialWindowLayout->addWidget(nextButton);
    tutorialWindowLayout->addWidget(exitButton);
    tutorialWindow->hide();
}

void FilterUser::connectSignalsAndSlots() {
    QObject::connect(filterButton, SIGNAL(clicked(bool)), this, SLOT(filterTutorials()));
    QObject::connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(increasePosition()));
    QObject::connect(addButton, SIGNAL(clicked(bool)), this, SLOT(addTutorial()));
    QObject::connect(addButton, SIGNAL(clicked(bool)), this, SLOT(increasePosition()));
    QObject::connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(markAsDone()));
    QObject::connect(this, SIGNAL(populateParent()), parent, SLOT(populateList()));
    QObject::connect(exitButton, SIGNAL(clicked(bool)), parent, SLOT(populateList()));
}

void FilterUser::filterTutorials() {
//    pthread_mutex_init(&mutex ,NULL);
//    tutorialWindow->show();
    auto presenter = presenterEdit->text().toStdString();
    tutorials = serviceUser.filterTutorials(presenter).getList();
    position = 0;
    done = false;
//    pthread_mutex_lock(&mutex);
    while(!done) {
//        pthread_mutex_unlock(&mutex);
//        pthread_mutex_lock(&mutex);
        auto t = tutorials[position];
        t.play();
//        titleEdit->setText(QString::fromStdString(t.getTitle()));
        messageBox.setText(QString::fromStdString(t.getTitle()));
        messageBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        messageBox.setDefaultButton(QMessageBox::Save);
        messageBox.show();
        int ret = messageBox.exec();
        switch (ret) {
            case QMessageBox::Save:
                // Save was clicked
                addTutorial();
                break;
            case QMessageBox::Discard:
                // Don't Save was clicked
                increasePosition();
                break;
            case QMessageBox::Cancel:
                // Cancel was clicked
                markAsDone();
                break;
            default:
                // should never be reached
                break;
        }
    }
//    tutorialWindow->close();
}

void FilterUser::increasePosition() {
    position++;
    if(position == tutorials.size())
        position = 0;
}

void FilterUser::markAsDone() {
    done = true;
    this->close();
    emit populateParent();
}

void FilterUser::addTutorial() {
    try {
        serviceUser.addTutorialWatchList(tutorials[position]);
    }catch (RepositoryException& e){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString(e.getMessage()));
        alertBox.exec();
    }
    catch (ServiceException& e){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString(e.getMessage()));
        alertBox.exec();
    }
    increasePosition();
}

