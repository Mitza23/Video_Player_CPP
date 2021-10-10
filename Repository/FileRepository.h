//
// Created by mitza on 13-Apr-21.
//

#ifndef A67_MITZA23_FILEREPOSITORY_H
#define A67_MITZA23_FILEREPOSITORY_H


#include "Repository.h"

class FileRepository: public Repository{
public:
    void saveToText(const std::string &fileName);

    void loadFromText(const std::string &fileName);

    void saveToHTML(const std::string &fileName);

    void saveToCSV(const std::string &fileName);

};


#endif //A67_MITZA23_FILEREPOSITORY_H
