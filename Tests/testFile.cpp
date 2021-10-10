//
// Created by mitza on 13-Apr-21.
//

#include <FileRepository.h>
#include <iostream>
#include <cassert>
#include <ValidatorException.h>
#include "testFile.h"
using namespace std;


void test__loadFromFile(){
//    cout << "Loading from file" << endl;
    FileRepository r;
    try {
        r.loadFromText("initial_data.txt");
    }catch (ValidatorException &e){
        cout << e.getMessage() << endl;
    }
//    cout << "SIZE: " << r.getList().size() << endl;
    assert(r.getList().size() == 10);
    assert(r.findTutorial("Python Fundamentals").getPresenter() == "King AJ");
}

void test__saveToFile(){
//    cout << "Saving o file" << endl;
    FileRepository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    Tutorial t1 = Tutorial("X", "B", 4, 5, 6, "C");
    r.addTutorial(t1);
    Tutorial t2 = Tutorial("Y", "B", 4, 5, 6, "C");
    r.addTutorial(t2);
    r.saveToText("test.txt");
    r.deleteTutorial("A");
    r.deleteTutorial("X");
    r.deleteTutorial("Y");
    try {
        r.loadFromText("test.txt");
        assert(r.getList().size() == 3);
    }catch (ValidatorException& e){
        cout << e.getMessage() << endl;
    }
}


void testAllFile(){
    cout << "Testing File" << endl;
    test__loadFromFile();
    test__saveToFile();
}
