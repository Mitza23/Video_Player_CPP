//
// Created by mitza on 14-May-21.
//

#include <QVBoxLayout>
#include <QDebug>
#include <QFormLayout>
#include <QMessageBox>
#include "DeleteAdmin.h"

DeleteAdmin::DeleteAdmin(QWidget* parent, ServiceAdmin &serviceAdmin) :parent{parent}, serviceAdmin{serviceAdmin}{
    initGUI();
    connectSignalsAndSlots();
}

void DeleteAdmin::initGUI() {
    titleEdit = new QLineEdit();
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QFormLayout* formLayout = new QFormLayout();
    formLayout->addRow("&Title", titleEdit);
    mainLayout->addLayout(formLayout);
    deleteButton = new QPushButton("Delete");
    mainLayout->addWidget(deleteButton);
}

void DeleteAdmin::connectSignalsAndSlots() {
    QObject::connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteTutorial()));
    QObject::connect(deleteButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(deleteButton, SIGNAL(clicked(bool)), parent, SLOT(populateList()));
}

void DeleteAdmin::deleteTutorial() {
    auto title = titleEdit->text().toStdString();
    std::string message = "Tutorial has been successfully deleted";
    try{
        serviceAdmin.deleteTutorial(title);
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
