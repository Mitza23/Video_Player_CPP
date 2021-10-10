//
// Created by mitza on 25-Mar-21.
//

#include <cassert>
#include <iostream>
#include "testServiceAdmin.h"

using namespace std;

void test__addTutorialServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    assert(s.getRepo().getList().size() == 1);
    try{
        s.addTutorial("F", "B", -56, 5, 6, "C");
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
}

void test__deleteTutorialServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    s.addTutorial("B", "B", 4, 5, 6, "C");
    s.deleteTutorial("A");
    assert(s.getRepo().getList().size() == 1);
    try{
        s.deleteTutorial("");
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
}

void test__updateTutorialTitleServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    s.addTutorial("B", "B", 4, 5, 6, "C");
    s.updateTutorialTitle("A", "Alba");
    assert(s.getRepo().findTutorial("Alba").getMinutes() == 4);
    try{
        s.updateTutorialTitle("B", "");
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
}

void test__updateTutorialPresenterServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    s.updateTutorialPresenter("A", "Kabral");
    assert(s.getRepo().findTutorial("A").getPresenter() == "Kabral");
    try{
        s.updateTutorialPresenter("A", "");
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
}

void test__updateTutorialMinutesServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    s.updateTutorialMinutes("A", 9);
    assert(s.getRepo().findTutorial("A").getMinutes() == 9);
    try{
        s.updateTutorialMinutes("A", -156);
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
}

void test__updateTutorialSecondsServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    s.updateTutorialSeconds("A", 9);
    assert(s.getRepo().findTutorial("A").getSeconds() == 9);
    try{
        s.updateTutorialSeconds("A", 60);
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
}

void test__updateTutorialLikesServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    s.updateTutorialLikes("A", 9);
    assert(s.getRepo().findTutorial("A").getLikes() == 9);
    try{
        s.updateTutorialLikes("A", -60);
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
}

void test__updateTutorialLinkServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    s.updateTutorialLink("A", "F");
    assert(s.getRepo().findTutorial("A").getLink() == "F");
    try{
        s.updateTutorialLink("A", "");
        assert(false);
    }
    catch (ServiceException& e){
        assert(true);
    }
}

void test__toStringServiceAdmin(){
    FileRepository r;
    ServiceAdmin s = ServiceAdmin(r);
    s.addTutorial("A", "B", 4, 5, 6, "C");
    s.addTutorial("X", "B", 4, 5, 6, "C");
    string result = std::string("A B 4 5 6 C") + std::string("\n") + std::string("X B 4 5 6 C")
            + std::string("\n");
    assert(s.toString() == result);
}

void testAllServiceAdmin(){
    std::cout << "Testing ServiceAdmin\n";
    test__addTutorialServiceAdmin();
    test__deleteTutorialServiceAdmin();
    test__updateTutorialTitleServiceAdmin();
    test__updateTutorialPresenterServiceAdmin();
    test__updateTutorialMinutesServiceAdmin();
    test__updateTutorialSecondsServiceAdmin();
    test__updateTutorialLikesServiceAdmin();
    test__updateTutorialLinkServiceAdmin();
    test__toStringServiceAdmin();
}