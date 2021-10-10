//
// Created by mitza on 24-Mar-21.
//

#include "testAll.h"
#include "testTutorial.h"
#include "testRepo.h"
#include "testServiceAdmin.h"
#include "testServiceUser.h"
#include "testFile.h"
#include <iostream>

using namespace std;

void testAll(){
    testAllTutorial();
    testAllRepo();
    testAllServiceAdmin();
    testAllServiceUser();
    testAllFile();
    cout << "All systems are up and running, Sir!" << endl;
}