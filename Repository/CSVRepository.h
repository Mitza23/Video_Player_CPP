//
// Created by mitza on 21-Apr-21.
//

#ifndef A67_MITZA23_CSVREPOSITORY_H
#define A67_MITZA23_CSVREPOSITORY_H


#include "Repository.h"
#include "FileRepository.h"

class CSVRepository : public FileRepository{
public:
//    void saveToCSV(const std::string &fileName);

    void saveToFile() override;
};


#endif //A67_MITZA23_CSVREPOSITORY_H
