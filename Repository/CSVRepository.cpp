//
// Created by mitza on 21-Apr-21.
//

#include "CSVRepository.h"
#include <fstream>

using namespace std;

void CSVRepository::saveToFile() {
    string fileName = "tutorials.csv";
    saveToCSV(fileName);
    string command = "code " + fileName;
    system(command.c_str());
}

//void CSVRepository::saveToCSV(const string &fileName) {
//    ofstream fo(fileName, ios::trunc);
//    string meta;
//    for(auto t :list){
//        meta += t.toCSV();
//    }
//    fo << meta;
//    fo.close();
//}
