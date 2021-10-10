//
// Created by mitza on 15-May-21.
//

#include <QVBoxLayout>
#include "DisplayUser.h"

DisplayUser::DisplayUser(ServiceUser &serviceUser) : serviceUser{serviceUser}{
    initGUI();
    connectSignalsAndSlots();
}

void DisplayUser::initGUI() {
    htmlButton = new QPushButton("HTML");
    csvButton = new QPushButton("CSV");
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(htmlButton);
    layout->addWidget(csvButton);
}

void DisplayUser::connectSignalsAndSlots() {
    QObject::connect(htmlButton, SIGNAL(clicked(bool)), this, SLOT(saveHTML()));
    QObject::connect(htmlButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(csvButton, SIGNAL(clicked(bool)), this, SLOT(saveCSV()));
    QObject::connect(csvButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void DisplayUser::saveHTML() {
    serviceUser.saveToHTML("watchlist.html");
}

void DisplayUser::saveCSV() {
    serviceUser.saveToCSV("watchlist.csv");
}
