//
// Created by mitza on 14-May-21.
//

#ifndef A89_MITZA23_ADDADMIN_H
#define A89_MITZA23_ADDADMIN_H


#include <QWidget>
#include <QLineEdit>
#include <ServiceAdmin.h>
#include <QPushButton>

class AddAdmin : public QWidget{
    Q_OBJECT

private:
    QWidget* parent;
    ServiceAdmin& serviceAdmin;

    // graphical elements
    QLineEdit* titleEdit;
    QLineEdit* presenterEdit;
    QLineEdit* minutesEdit;
    QLineEdit* secondsEdit;
    QLineEdit* likesEdit;
    QLineEdit* linkEdit;
    QPushButton* addButton;

    void initGUI();

    void connectSignalsAndSlots();

public:
    AddAdmin(QWidget* parent , ServiceAdmin& serviceAdmin);

private slots:
    void addTutorial();

public slots:
    void clear();
};


#endif //A89_MITZA23_ADDADMIN_H
