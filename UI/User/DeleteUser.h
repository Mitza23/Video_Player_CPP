//
// Created by mitza on 15-May-21.
//

#ifndef A89_MITZA23_DELETEUSER_H
#define A89_MITZA23_DELETEUSER_H


#include <QWidget>
#include <ServiceUser.h>
#include <QPushButton>
#include <QLineEdit>

class DeleteUser : public QWidget{
    Q_OBJECT
private:
    QWidget* parent;
    ServiceUser& serviceUser;

    // graphical elements
    QLineEdit* titleEdit;
    QPushButton* deleteButton;
    QPushButton* likeButton;
    QPushButton* passButton;
    QWidget* likeWindow;
    bool like;
    std::string title;

    void initGUI();

    void connectSignalsAndSlots();

public:
    DeleteUser( QWidget* parent, ServiceUser& serviceUser);

public slots:
    void likeTutorial();

    void passTutorial();

    void deleteTutorial();
};


#endif //A89_MITZA23_DELETEUSER_H
