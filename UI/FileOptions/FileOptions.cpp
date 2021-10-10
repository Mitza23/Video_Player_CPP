//
// Created by mitza on 16-May-21.
//

#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <ValidatorException.h>
#include "FileOptions.h"

FileOptions::FileOptions(ServiceAdmin &serviceAdmin) : serviceAdmin{serviceAdmin}{
    initGUI();
    connectSignalsAndSlots();
}

void FileOptions::initGUI() {
    QVBoxLayout* layout = new QVBoxLayout(this);
    loadButton = new QPushButton("Load from file");
    saveTextButton = new QPushButton("Save to text");
    saveHTMLButton = new QPushButton("Save to HTML");
    saveCSVButton = new QPushButton("Save to CSV");
    savePolyButton = new QPushButton("Save to file(polymorphism)");
    layout->addWidget(loadButton);
    layout->addWidget(saveTextButton);
    layout->addWidget(saveHTMLButton);
    layout->addWidget(saveCSVButton);
//    layout->addWidget(savePolyButton);

    loadWindow = new QWidget();
    loadLayout = new QVBoxLayout(loadWindow);
    label = new QLabel("File name");
    fileEdit = new QLineEdit();
    loadFileButton = new QPushButton("Load");
    label->setBuddy(fileEdit);
    loadLayout->addWidget(label);
    loadLayout->addWidget(fileEdit);
    loadLayout->addWidget(loadFileButton);
}

void FileOptions::connectSignalsAndSlots() {
    QObject::connect(loadButton, SIGNAL(clicked(bool)), this, SLOT(loadText()));
    QObject::connect(saveTextButton, SIGNAL(clicked(bool)), this, SLOT(saveText()));
    QObject::connect(saveHTMLButton, SIGNAL(clicked(bool)), this, SLOT(saveHTML()));
    QObject::connect(saveCSVButton, SIGNAL(clicked(bool)), this, SLOT(saveCSV()));
    QObject::connect(loadFileButton, SIGNAL(clicked(bool)), this, SLOT(loadFromText()));
}

void FileOptions::saveText() {
    try {
        serviceAdmin.saveToText("tutorials.txt");
        this->close();
    }catch (...){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString("An error occurred while saving to text"));
        alertBox.exec();
    }
}

void FileOptions::saveHTML() {
    try {
        serviceAdmin.saveToHTML("tutorials.html");
        this->close();
    }catch (...){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString("An error occurred while saving to HTML"));
        alertBox.exec();
    }
}

void FileOptions::saveCSV() {
    try {
        serviceAdmin.saveToCSV("tutorials.csv");
        this->close();
    }catch (...){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString("An error occurred while saving to CSV"));
        alertBox.exec();
    }
}

void FileOptions::loadText() {
    loadWindow->show();
}

void FileOptions::loadFromText() {
    auto fileName = fileEdit->text().toStdString();
    try {
        serviceAdmin.loadFromText(fileName);
        this->close();
    }catch (ValidatorException& e){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString(e.getMessage()));
        alertBox.exec();
    }
    catch (RepositoryException& e){
        QMessageBox alertBox;
        alertBox.setText(QString::fromStdString(e.getMessage()));
        alertBox.exec();
    }
    loadWindow->close();
}
