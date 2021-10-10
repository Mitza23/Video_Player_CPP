//
// Created by mitza on 15-May-21.
//

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include "UpdateAdmin.h"
#include <iostream>
#include <QMessageBox>

using std::cout;
using std::endl;

UpdateAdmin::UpdateAdmin(QWidget* parent, ServiceAdmin &serviceAdmin) : parent{parent}, serviceAdmin{serviceAdmin}{
    selection = -1;
    initGUI();
    connectSignalsAndSlots();
}

void UpdateAdmin::initGUI() {
    titleButton = new QPushButton("&Title");
    presenterButton = new QPushButton("&Presenter");
    minutesButton = new QPushButton("&Minutes");
    secondsButton = new QPushButton("&Seconds");
    likesButton = new QPushButton("&Likes");
    linkButton = new QPushButton("&Link");

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(titleButton);
    layout->addWidget(presenterButton);
    layout->addWidget(minutesButton);
    layout->addWidget(secondsButton);
    layout->addWidget(likesButton);
    layout->addWidget(linkButton);

    // value getter window
    valueGetter = new QWidget();
    QVBoxLayout* valueGetterLayout = new QVBoxLayout(valueGetter);
    QFormLayout* formLayout = new QFormLayout();

    QLabel* labelTitle = new QLabel("&Title");
    titleEdit = new QLineEdit();
    labelTitle->setBuddy(titleEdit);

    labelValue = new QLabel("&Value");
    valueEdit = new QLineEdit();

    updateButton = new QPushButton("&Update");

    formLayout->addRow(labelTitle, titleEdit);
    formLayout->addRow(labelValue, valueEdit);
    valueGetterLayout->addLayout(formLayout);
    valueGetterLayout->addWidget(updateButton);

//    valueGetter->hide();
}

void UpdateAdmin::connectSignalsAndSlots() {
    QObject::connect(titleButton, SIGNAL(clicked()), this, SLOT(updateTitle()));
    QObject::connect(presenterButton, SIGNAL(clicked()), this, SLOT(updatePresenter()));
    QObject::connect(minutesButton, SIGNAL(clicked()), this, SLOT(updateMinutes()));
    QObject::connect(secondsButton, SIGNAL(clicked()), this, SLOT(updateSeconds()));
    QObject::connect(likesButton, SIGNAL(clicked()), this, SLOT(updateLikes()));
    QObject::connect(linkButton, SIGNAL(clicked()), this, SLOT(updateLink()));
    QObject::connect(updateButton, SIGNAL(clicked()), this, SLOT(updateValue()));
    QObject::connect(updateButton, SIGNAL(clicked()), valueGetter, SLOT(hide()));
    QObject::connect(updateButton, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(updateButton, SIGNAL(clicked()), parent, SLOT(populateList()));
}

void UpdateAdmin::updateTitle() {
    labelValue->setText(QString("New title"));
    valueGetter->show();
    selection = 0;
}

void UpdateAdmin::updatePresenter() {
    labelValue->setText(QString("New presenter"));
    valueGetter->show();
    selection = 1;
}

void UpdateAdmin::updateMinutes() {
    labelValue->setText(QString("New minutes"));
    valueGetter->show();
    selection = -2;
}

void UpdateAdmin::updateSeconds() {
    labelValue->setText(QString("New seconds"));
    valueGetter->show();
    selection = -3;
}

void UpdateAdmin::updateLikes() {
    labelValue->setText(QString("New likes"));
    valueGetter->show();
    selection = -4;
}

void UpdateAdmin::updateLink() {
    labelValue->setText(QString("New link"));
    valueGetter->show();
    selection = 5;
}

void UpdateAdmin::updateValue() {
    std::string message = "Tutorial successfully updated";
    auto title = titleEdit->text().toStdString();
    auto newValue = valueEdit->text().toStdString();
    try {
        if (selection < 0) {
            int value = stoi(newValue);
            switch (selection) {
                case -2:
                    serviceAdmin.updateTutorialMinutes(title, value);
                    break;
                case -3:
                    serviceAdmin.updateTutorialSeconds(title, value);
                    break;
                case -4:
                    serviceAdmin.updateTutorialLikes(title, value);
                    break;
            }
        } else {
            switch (selection) {
                case 0:
                    serviceAdmin.updateTutorialTitle(title, newValue);
                    break;
                case 1:
                    serviceAdmin.updateTutorialPresenter(title, newValue);
                    break;
                case 5:
                    serviceAdmin.updateTutorialLink(title, newValue);
                    break;
            }
        }
    }catch (ServiceException& e){
        message = e.getMessage();
    }
    catch (RepositoryException& e){
        message = e.getMessage();
    }
    QMessageBox messageBox;
    messageBox.setText(QString::fromStdString(message));
    messageBox.exec();
}
