//
// Created by mitza on 15-May-21.
//

#ifndef A89_MITZA23_DISPLAYUSER_H
#define A89_MITZA23_DISPLAYUSER_H


#include <QWidget>
#include <ServiceUser.h>
#include <QPushButton>

class DisplayUser : public  QWidget{
    Q_OBJECT
private:
    ServiceUser& serviceUser;

    // graphical elements
    QPushButton* htmlButton;
    QPushButton* csvButton;

    void initGUI();

    void connectSignalsAndSlots();

public:
    DisplayUser(ServiceUser& serviceUser);

public slots:
    void saveHTML();

    void saveCSV();
};


#endif //A89_MITZA23_DISPLAYUSER_H
