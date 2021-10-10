//
// Created by mitza on 23-Mar-21.
//

#include <iostream>
#include <assert.h>
#include "../Repository/Repository.h"
#include "testRepo.h"

void test__Repository(){
    Repository r = Repository();
    assert(typeid(r) == typeid(Repository));
}

void test__getList(){
    Repository r = Repository();
    assert(typeid(r.getList()) == typeid(std::vector<Tutorial>));
}


void test__addTutorial(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    assert(r.getList().size() == 1);
    for(int i = 0 ; i < 30 ; i++){
        Tutorial a = Tutorial(std::to_string(i), "B", 4 ,5 ,6, "C");
        r.addTutorial(a);
    }
    assert(r.getList().size() == 31);
    assert(r.getList().capacity() == 32);
    Tutorial b = Tutorial("A", "B", 4, 5, 6, "C");
    try{
        r.addTutorial(b);
    }
    catch (RepositoryException& e){
        assert(true);
    }
}

void test__findTutorial(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    assert(r.findTutorial("A").getSeconds() == 5);
    try{
        r.findTutorial("X");
    }
    catch (Exception& e){
        assert(true);
    }
}

void test__existsTutorial(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    assert(r.existsTutorial("A"));
}

void test__deleteTutorial(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    r.deleteTutorial("A");
    assert(!r.existsTutorial("A"));
    try{
        r.deleteTutorial("X");
    }
    catch (RepositoryException& e){
        assert(true);
    }
}

void test__updateTutorialTitle(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    r.updateTutorialTitle("A", "Alba");
    assert(r.existsTutorial("Alba"));
    Tutorial a = Tutorial("B", "B", 4, 5, 6, "C");
    try {
        r.updateTutorialTitle("B", "Alba");
    }
    catch (RepositoryException& e) {
        assert(true);
    }
    try{
        r.updateTutorialTitle("X", "Y");
    }
    catch (RepositoryException& e){
        assert(true);
    }
}

void test__updateTutorialPresenter(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    r.updateTutorialPresenter("A", "Alba");
    assert(r.findTutorial("A").getPresenter() == "Alba");
    try{
        r.updateTutorialPresenter("X", "Y");
    }
    catch (RepositoryException& e){
        assert(true);
    }
}

void test__updateTutorialMinutes(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    r.updateTutorialMinutes("A", 23);
    assert(r.findTutorial("A").getMinutes() == 23);
    try{
        r.updateTutorialMinutes("X", 34);
    }
    catch (RepositoryException& e){
        assert(true);
    }
}

void test__updateTutorialSeconds(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    r.updateTutorialSeconds("A", 23);
    assert(r.findTutorial("A").getSeconds() == 23);
    try{
        r.updateTutorialSeconds("X", 34);
    }
    catch (RepositoryException& e){
        assert(true);
    }
}

void test__updateTutorialLikes(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    r.updateTutorialLikes("A", 23);
    assert(r.findTutorial("A").getLikes() == 23);
    try{
        r.updateTutorialLikes("X", 23);
    }
    catch (RepositoryException& e){
        assert(true);
    }
}

void test__updateTutorialLink(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    r.updateTutorialLink("A", "Alba");
    assert(r.findTutorial("A").getLink() == "Alba");
    try{
        r.updateTutorialLink("X", "Y");
    }
    catch (RepositoryException& e){
        assert(true);
    }
}

void test__toStringRepo(){
    Repository r;
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    r.addTutorial(t);
    Tutorial a = Tutorial("X", "B", 4, 5, 6, "C");
    r.addTutorial(a);
    assert(r.toString() == (std::string("A B 4 5 6 C") + std::string("\n") + std::string("X B 4 5 6 C") + std::string("\n")));
}


void testAllRepo(){
    std::cout << "Testing Repository" << std::endl;
    test__Repository();
    test__getList();
    test__addTutorial();
    test__findTutorial();
    test__existsTutorial();
    test__deleteTutorial();
    test__updateTutorialTitle();
    test__updateTutorialPresenter();
    test__updateTutorialMinutes();
    test__updateTutorialSeconds();
    test__updateTutorialLikes();
    test__updateTutorialLink();
    test__toStringRepo();
}