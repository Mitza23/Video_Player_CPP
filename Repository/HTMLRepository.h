//
// Created by mitza on 21-Apr-21.
//

#ifndef A67_MITZA23_HTMLREPOSITORY_H
#define A67_MITZA23_HTMLREPOSITORY_H


#include "Repository.h"
#include "FileRepository.h"

class HTMLRepository : public FileRepository{

    //void saveToHTML(const std::string &fileName);

    void saveToFile() override;
};


#endif //A67_MITZA23_HTMLREPOSITORY_H
