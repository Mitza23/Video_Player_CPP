//
// Created by mitza on 14-May-21.
//

#include <QFormLayout>
#include <QMessageBox>
#include "AddAdmin.h"


AddAdmin::AddAdmin(QWidget* parent , ServiceAdmin &serviceAdmin) : parent(parent) , serviceAdmin{serviceAdmin}{
    initGUI();
    connectSignalsAndSlots();
}

void AddAdmin::initGUI() {

    titleEdit = new QLineEdit();
    presenterEdit = new QLineEdit();
    minutesEdit = new QLineEdit();
    secondsEdit = new QLineEdit();
    likesEdit = new QLineEdit();
    linkEdit = new QLineEdit();

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QFormLayout* formLayout = new QFormLayout();

    formLayout->addRow("&Title", titleEdit);
    formLayout->addRow("&Presenter", presenterEdit);
    formLayout->addRow("&Minutes", minutesEdit);
    formLayout->addRow("&Seconds", secondsEdit);
    formLayout->addRow("&Likes", likesEdit);
    formLayout->addRow("&Link", linkEdit);

    mainLayout->addLayout(formLayout);

    addButton = new QPushButton("Add");
    mainLayout->addWidget(addButton);
}

void AddAdmin::connectSignalsAndSlots() {
    QObject::connect(addButton, SIGNAL(clicked(bool)), this, SLOT(addTutorial()));
    QObject::connect(addButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(addButton, SIGNAL(clicked(bool)), parent, SLOT(populateList()));
}

void AddAdmin::addTutorial() {
    std::string message = "Tutorial has been successfully added";
    auto title = titleEdit->text().toStdString();
    auto presenter = presenterEdit->text().toStdString();
    auto minutes = stoi(minutesEdit->text().toStdString());
    auto seconds = stoi(secondsEdit->text().toStdString());
    auto likes = stoi(likesEdit->text().toStdString());
    auto link = linkEdit->text().toStdString();
    try {
        serviceAdmin.addTutorial(title, presenter, minutes, seconds, likes, link);
    }catch (RepositoryException& e){
        message = e.getMessage();
    }
    catch (ServiceException& e){
        message = e.getMessage();
    }
    QMessageBox messageBox;
    messageBox.setText(QString::fromStdString(message));
    messageBox.exec();
}

void AddAdmin::clear() {
    titleEdit->clear();
    presenterEdit->clear();
    minutesEdit->clear();
    secondsEdit->clear();
    likesEdit->clear();
    linkEdit->clear();
}
