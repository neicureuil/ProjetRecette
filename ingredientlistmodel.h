#ifndef INGREDIENTLISTMODEL_H
#define INGREDIENTLISTMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include <QStringList>

class IngredientListModel : public QAbstractListModel
{
    Q_OBJECT

    private:
       QStringList ingredients;

    public:
        IngredientListModel(QObject *parent=nullptr);
        int rowCount(const QModelIndex &parent=QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        void reset();
        void setIngredients(const QStringList& list);
        static QString getIcon(QString ing);
};

#endif // INGREDIENTLISTMODEL_H
