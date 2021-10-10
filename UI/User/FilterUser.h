//
// Created by mitza on 15-May-21.
//

#ifndef A89_MITZA23_FILTERUSER_H
#define A89_MITZA23_FILTERUSER_H


#include <QWidget>
#include <ServiceUser.h>
#include <QLineEdit>
#include <QPushButton>
#include <pthread.h>
#include <QMessageBox>

class FilterUser : public QWidget{
    Q_OBJECT
private:
    QWidget* parent;
    ServiceUser& serviceUser;

    //graphical elements
    QLineEdit* presenterEdit;
    QPushButton* filterButton;

    QWidget* tutorialWindow;
    QLineEdit* titleEdit;
    QPushButton* addButton;
    QPushButton* nextButton;
    QPushButton* exitButton;
    int position;
    bool done;
    std::vector<Tutorial> tutorials;
    QMessageBox messageBox;

    void initGUI();

    void connectSignalsAndSlots();

public:
    FilterUser(QWidget* parent, ServiceUser& serviceUser);

private slots:
    void filterTutorials();

    void increasePosition();

    void markAsDone();

    void addTutorial();

signals:
    void populateParent();
};


#endif //A89_MITZA23_FILTERUSER_H
