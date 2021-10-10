//
// Created by mitza on 14-May-21.
//

#ifndef A89_MITZA23_DELETEADMIN_H
#define A89_MITZA23_DELETEADMIN_H


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <ServiceAdmin.h>

class DeleteAdmin : public QWidget{
    Q_OBJECT
private:
    QWidget* parent;
    ServiceAdmin& serviceAdmin;

    // graphical elements
    QLineEdit* titleEdit;
    QPushButton* deleteButton;

    void initGUI();

    void connectSignalsAndSlots();

public:
    DeleteAdmin(QWidget* parent, ServiceAdmin& serviceAdmin);

private slots:
    void deleteTutorial();
};


#endif //A89_MITZA23_DELETEADMIN_H
