//
// Created by mitza on 04-Apr-21.
//

#include <Repository.h>
#include <ServiceAdmin.h>
#include <ServiceUser.h>
#include <UI.h>
#include <algorithm>
#include <FileRepository.h>
#include <CSVRepository.h>
#include <HTMLRepository.h>
#include <RoleSelector.h>
#include <QApplication>
#include <fstream>
#include <ValidatorException.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv){
    QApplication a(argc, argv);
//    testAll();
    FileRepository dataBase;
    ServiceAdmin serviceAdmin = ServiceAdmin(dataBase);
    ServiceUser serviceUser = ServiceUser(dataBase);
//    CSVRepository csv;
//    ServiceAdmin serviceAdmin = ServiceAdmin(csv);
//    ServiceUser serviceUser = ServiceUser(csv);
//    HTMLRepository html;
//    ServiceAdmin serviceAdmin = ServiceAdmin(html);
//    ServiceUser serviceUser = ServiceUser(html);
//    UI ui(serviceAdmin, serviceUser);
//    ui.start();
    try {
        serviceAdmin.loadFromText("initial_data.txt");
    }catch (ValidatorException& e){
        cout << e.getMessage();
    }
    RoleSelector* roleSelector = new RoleSelector(serviceAdmin, serviceUser);
    roleSelector->show();
    return a.exec();
}
