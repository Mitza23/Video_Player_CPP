//
// Created by mitza on 28-Mar-21.
//

#include "testServiceUser.h"
#include "../Service/ServiceUser.h"
#include "../Service/ServiceAdmin.h"
#include <cassert>
#include <iostream>

using namespace std;

void test__addTutorialWatchListServiceUser(){
    FileRepository r;
    ServiceUser s = ServiceUser(r);
    Tutorial t = Tutorial("A", "B", 4 ,5 ,6, "C");
    try {
        s.addTutorialWatchList(t);
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
    s.getDataBase().addTutorial(t);
    s.addTutorialWatchList(t);

    assert(s.getWatchList().getList().size() == 1);
}

void test__deleteTutorialWatchListServiceUser(){
    FileRepository r;
    ServiceUser s = ServiceUser(r);
    Tutorial t = Tutorial("A", "B", 4 ,5 ,6, "C");

    s.getDataBase().addTutorial(t);
    s.addTutorialWatchList(t);

    s.deleteTutorialWatchList("A", true);

    assert(s.getWatchList().getList().size() == 0);
    assert(s.getDataBase().findTutorial("A").getLikes() == 7);
}


void test__filterTutorialsWatchListServiceUser(){
    FileRepository r;
    ServiceUser s = ServiceUser(r);
    Tutorial t1 = Tutorial("A", "B", 4 ,5 ,6,
                          "https://www.youtube.com/watch?v=p_GP0zArKh8");
    s.getDataBase().addTutorial(t1);
    s.addTutorialWatchList(t1);

    Tutorial t2 = Tutorial("B", "B", 4 ,5 ,6,
                           "https://www.youtube.com/watch?v=p_GP0zArKh8");
    s.getDataBase().addTutorial(t2);
    s.addTutorialWatchList(t2);

    Tutorial t3 = Tutorial("C", "B", 4 ,5 ,6,
                           "https://www.youtube.com/watch?v=p_GP0zArKh8");
    s.getDataBase().addTutorial(t3);
    s.addTutorialWatchList(t3);

    Tutorial t4 = Tutorial("D", "C", 4 ,5 ,6,
                           "https://www.youtube.com/watch?v=p_GP0zArKh8");
    s.getDataBase().addTutorial(t4);
    s.addTutorialWatchList(t4);

    Repository filtered_repo = s.filterTutorials("B");
    assert(filtered_repo.getList().size() == 3);

}


void test__toStringWatchListServiceUser() {
    FileRepository r;
    ServiceUser s = ServiceUser(r);

    Tutorial t1 = Tutorial("A", "B", 4, 5, 6,"C");
    s.getDataBase().addTutorial(t1);
    s.addTutorialWatchList(t1);

    Tutorial t2 = Tutorial("B", "B", 4, 5, 6,"C");
    s.getDataBase().addTutorial(t2);
    s.addTutorialWatchList(t2);

    Tutorial t3 = Tutorial("C", "B", 4, 5, 6, "C");
    s.getDataBase().addTutorial(t3);
    s.addTutorialWatchList(t3);

    string str = s.toStringWatchList();
    string result = string("A B 4 5 6 C\n") + string("B B 4 5 6 C\n") + string("C B 4 5 6 C\n");
    assert(str == result);
}


void testAllServiceUser(){
    cout << "Testing ServiceUser" << endl;
    test__addTutorialWatchListServiceUser();
    test__deleteTutorialWatchListServiceUser();
    test__filterTutorialsWatchListServiceUser();
    test__toStringWatchListServiceUser();
}