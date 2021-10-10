//
// Created by mitza on 01-Jun-21.
//

#ifndef A10_MITZA23_1_TUTORIALMODEL_H
#define A10_MITZA23_1_TUTORIALMODEL_H


#include <QAbstractTableModel>
#include <Tutorial.h>

class TutorialModel : public QAbstractTableModel{
    Q_OBJECT
private:
    std::vector<Tutorial> items;
public:
    TutorialModel(std::vector<Tutorial> items);

    int columnCount(const QModelIndex &parent) const override;

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};


#endif //A10_MITZA23_1_TUTORIALMODEL_H
