//
// Created by mitza on 13-Apr-21.
//

#include <iostream>
#include <fstream>
#include <ValidatorException.h>
#include "FileRepository.h"

using namespace std;

void FileRepository::saveToText(const string &fileName) {
    ofstream fo(fileName.c_str(), ios::trunc);
    for(int i = 0 ; i < list.size() - 1 ; i++){
        fo << list[i] << endl;
    }
    fo << list[list.size() - 1];
    fo.close();
}

void FileRepository::loadFromText(const string &fileName) {
    list.clear();
    ifstream fi(fileName.c_str());
    while (!fi.eof()){
        Tutorial t;
        fi >> t;
        addTutorial(t);
    }
    fi.close();
}

void FileRepository::saveToHTML(const string &fileName) {
    ofstream fo(fileName, ios::trunc);
    string meta;
    meta += string("<!DOCTYPE html>\n");
    meta += string("<html>\n");
    meta += string("<head>\n");
    meta += string("\t<title>Watchlist</title>\n");
    meta += string("</head>\n");
    meta += string("<body>\n");
    meta += string("<table border=\"1\">\n");
    meta += string("\t<tr>\n");
    meta += string("\t\t<td>Title</td>\n");
    meta += string("\t\t<td>Presenter</td>\n");
    meta += string("\t\t<td>Minutes</td>\n");
    meta += string("\t\t<td>Seconds</td>\n");
    meta += string("\t\t<td>Likes</td>\n");
    meta += string("\t\t<td>YouTube Link</td>\n");
    meta += string("\t</tr>\n");
    for(auto t :list){
        meta+= t.toHTML();
    }
    meta += string("</table>\n");
    meta += string("</body>\n");
    meta += string("</html>\n");

    fo << meta;
    fo.close();
}

void FileRepository::saveToCSV(const string &fileName) {
    ofstream fo(fileName, ios::trunc);
    string meta;
    for(auto t :list){
        meta += t.toCSV();
    }
    fo << meta;
    fo.close();
}

