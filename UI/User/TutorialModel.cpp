//
// Created by mitza on 01-Jun-21.
//

#include "TutorialModel.h"

TutorialModel::TutorialModel(std::vector<Tutorial> items) : items{items}{}

int TutorialModel::columnCount(const QModelIndex &parent) const {
    return 6;
}

int TutorialModel::rowCount(const QModelIndex &parent) const {
    return (int) items.size();
}

QVariant TutorialModel::data(const QModelIndex &index, int role) const {
    auto row = index.row();
    auto column = index.column();
    auto element = this->items[row];

    switch (role) {
        case Qt::DisplayRole: {
            switch (column) {
                case 0:
                    return QString::fromStdString(element.getTitle());
                case 1:
                    return QString::fromStdString(element.getPresenter());
                case 2:
                    return QString::fromStdString(std::to_string(element.getMinutes()));
                case 3:
                    return QString::fromStdString(std::to_string(element.getSeconds()));
                case 4:
                    return QString::fromStdString(std::to_string(element.getLikes()));
                case 5:
                    return QString::fromStdString(element.getLink());
                default:
                    return QVariant();
            }
        }
        default:
            return QVariant();
    }
}

QVariant TutorialModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Orientation::Horizontal) {
        switch (section) {
            case 0:
                return "Title";
            case 1:
                return "Presenter";
            case 2:
                return "Minutes";
            case 3:
                return "Seconds";
            case 4:
                return "Likes";
            case 5:
                return "Link";
            default:
                return QVariant();
        }
    }
    return QVariant();
}

