//
// Created by mitza on 23-Mar-21.
//

#include <Tutorial.h>
#include <assert.h>
#include <iostream>
#include "testTutorial.h"

void test__Tutorial(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    assert(typeid(t) == typeid(Tutorial));
}

void test__getTitle(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    assert(t.getTitle() == "A");
}

void test__setTitle(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    t.setTitle("Alba");
    assert(t.getTitle() == "Alba");
}

void test__getPresenter(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    assert(t.getPresenter() == "B");
}

void test__getMinutes(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    assert(t.getMinutes() == 4);
}

void test__getSeconds(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    assert(t.getSeconds() == 5);
}

void test__getLikes(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    assert(t.getLikes() == 6);
}

void test__getLink(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    assert(t.getLink() == "C");
}

void test__toString(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6, "C");
    assert(t.toString() == "A B 4 5 6 C");
}

void test_play(){
    Tutorial t = Tutorial("A", "B", 4, 5, 6,
                          "https://www.youtube.com/watch?v=p_GP0zArKh8");
    t.play();
    assert(true);
}

void testAllTutorial(){
    std::cout << "Testing Tutorial\n";
    test__Tutorial();
    test__getPresenter();
    test__getMinutes();
    test__getSeconds();
    test__getLikes();
    test__getLink();
    test__toString();
    //test_play();
}