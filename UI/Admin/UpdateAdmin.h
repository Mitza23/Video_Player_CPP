//
// Created by mitza on 15-May-21.
//

#ifndef A89_MITZA23_UPDATEADMIN_H
#define A89_MITZA23_UPDATEADMIN_H


#include <QWidget>
#include <ServiceAdmin.h>
#include <QPushButton>
#include <QLabel>

class UpdateAdmin : public QWidget{
    Q_OBJECT
private:
    QWidget* parent;
    ServiceAdmin& serviceAdmin;
    int selection;

    //graphical elements
    QPushButton* titleButton;
    QPushButton* presenterButton;
    QPushButton* minutesButton;
    QPushButton* secondsButton;
    QPushButton* likesButton;
    QPushButton* linkButton;

    QWidget* valueGetter;
    QLineEdit* titleEdit;
    QLineEdit* valueEdit;
    QLabel* labelValue;
    QPushButton* updateButton;

    void initGUI();

    void connectSignalsAndSlots();


private slots:
    void updateTitle();

    void updatePresenter();

    void updateMinutes();

    void updateSeconds();

    void updateLikes();

    void updateLink();

    void updateValue();

public:
    UpdateAdmin(QWidget* parent, ServiceAdmin& serviceAdmin);

};


#endif //A89_MITZA23_UPDATEADMIN_H
