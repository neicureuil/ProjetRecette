#include "ingredientlistmodel.h"
#include <QPixmap>

IngredientListModel::IngredientListModel(QObject *parent) : QAbstractListModel(parent) {
    ingredients.push_back("coucou");
}

int IngredientListModel::rowCount(const QModelIndex &parent) const {
    return ingredients.length();
}

QVariant IngredientListModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return QString(ingredients[index.row()]);
    }else if (role==Qt::DecorationRole) {
        return QPixmap(getIcon(ingredients[index.row()]));
    }
    return QVariant{};
}

void IngredientListModel::reset() {
    beginRemoveRows(QModelIndex(), 0, ingredients.length()-1);
    ingredients.clear();
    endRemoveRows();
}

void IngredientListModel::setIngredients(const QStringList &list) {
    reset();

    beginInsertRows(QModelIndex(), 0, list.length()-1);
    ingredients = list;
    endInsertRows();
}

QString IngredientListModel::getIcon(QString ing){
    if(stringContains(ing, "sucre")) {
        return ":/images/icon_sugar.png";
    }else if(stringContains(ing, "sardine")) {
        return ":/images/sardine.png";
    }else if(stringContains(ing, "farine")) {
        return ":/images/icon_farine.png";
    }else if(stringContains(ing, "huile")) {
        return ":/images/icon_huile.png";
    }else if(stringContains(ing, "eau")) {
        return ":/images/icon_water.png";
    }else if(stringContains(ing, "sel")) {
        return ":/images/sel.png";
    }else if(stringContains(ing, "oeuf") || ing.contains("œuf")) {
        return ":/images/oeuf.png";
    }else if(stringContains(ing, "chocolat")) {
        return ":/images/chocolat.png";
    }
    return ":/images/icon_default.png";
}
bool IngredientListModel::stringContains(const QString &source, const QString &val) {
    return source.toLower().contains(val.toLower());
}
