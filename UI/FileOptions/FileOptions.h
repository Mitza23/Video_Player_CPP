//
// Created by mitza on 16-May-21.
//

#ifndef A89_MITZA23_FILEOPTIONS_H
#define A89_MITZA23_FILEOPTIONS_H


#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <ServiceAdmin.h>

class FileOptions : public QWidget{
    Q_OBJECT
private:
    ServiceAdmin& serviceAdmin;

    // graphical elements
    QPushButton* loadButton;
    QPushButton* saveTextButton;
    QPushButton* saveHTMLButton;
    QPushButton* saveCSVButton;
    QPushButton* savePolyButton;

    QWidget* loadWindow;
    QVBoxLayout* loadLayout;
    QLabel* label;
    QLineEdit* fileEdit;
    QPushButton* loadFileButton;

    void initGUI();

    void connectSignalsAndSlots();

public:
    FileOptions(ServiceAdmin& serviceAdmin);

public slots:
    void saveText();

    void saveHTML();

    void saveCSV();

    void loadText();

    void loadFromText();
};


#endif //A89_MITZA23_FILEOPTIONS_H
