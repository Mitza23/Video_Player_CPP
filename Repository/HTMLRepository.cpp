//
// Created by mitza on 21-Apr-21.
//

#include "HTMLRepository.h"
#include <fstream>

using namespace std;

//void HTMLRepository::saveToHTML(const string &fileName) {
//    ofstream fo(fileName, ios::trunc);
//    string meta;
//    meta += string("<!DOCTYPE html>\n");
//    meta += string("<html>\n");
//    meta += string("<head>\n");
//    meta += string("\t<title>Watchlist</title>\n");
//    meta += string("</head>\n");
//    meta += string("<body>\n");
//    meta += string("<table border=\"1\">\n");
//    meta += string("\t<tr>\n");
//    meta += string("\t\t<td>Title</td>\n");
//    meta += string("\t\t<td>Presenter</td>\n");
//    meta += string("\t\t<td>Minutes</td>\n");
//    meta += string("\t\t<td>Seconds</td>\n");
//    meta += string("\t\t<td>Likes</td>\n");
//    meta += string("\t\t<td>YouTube Link</td>\n");
//    meta += string("\t</tr>\n");
//    for(auto t :list){
//        meta+= t.toHTML();
//    }
//    meta += string("</table>\n");
//    meta += string("</body>\n");
//    meta += string("</html>\n");
//
//    fo << meta;
//    fo.close();
//}

void HTMLRepository::saveToFile() {
    string fileName = "tutorials.html";
    saveToHTML(fileName);
    string command = "chrome.exe " + fileName;
    system(command.c_str());
}
