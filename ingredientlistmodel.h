#ifndef INGREDIENTLISTMODEL_H
#define INGREDIENTLISTMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include <QStringList>

/**
 * La classe IngredientListModel. Elle correspond au model d'une ListView dédier a l'affichage des ingrédients d'une recette (nom et icon).
 */
class IngredientListModel : public QAbstractListModel
{
    Q_OBJECT

    private:
       QStringList ingredients; /**< QStringList. Liste d'ingrédients a afficher dans la ListeView. */

    public:
       /**
        * Constructeur de la classe IngredientListModel.
        * Initialise le model.
        * @param parent un QObject correspondant au parent.
        */
        IngredientListModel(QObject *parent=nullptr);
        /**
         * Une fonction hérité de la classe mère qui renvoie le nombre de ligne de la liste.
         * @param parent une référence constante de QModelIndex.
         * @return un int correspondant au nombre d'éléments de la liste (c'est a dire le nombre d'ingrédient).
         */
        int rowCount(const QModelIndex &parent=QModelIndex()) const override;
        /**
         * Une fonction hérité de la classe mère qui renvoie les données d'une ligne en fonction de son rôle.
         * @param index une référence constante de QModelIndex correspondant a la ligne de la ListView.
         * @param role un int correspondant au role de l'affichage demander (DisplayRole ou DecorationRole).
         * @return une QVariant correspondant au nom de l'ingrédient si le role est DisplayRole et une icone de l'ingrédient si le role est DecorationRole.
         */
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        /**
         * Fonction qui se charge de remettre a zéro le model. C'est a dire qu'elle vide la liste d'ingredient et supprime les lignes de la liste.
         */
        void reset();
        /**
         * Fonction qui après avoir reset le model, affecte a la liste d'ingrédients a afficher ingredients la liste passée en paramètre.
         * Elle change donc les données du model.
         * @see reset()
         * @param list une référence constante de QStringList correspondant a la liste d'ingrédient a afficher.
         */
        void setIngredients(const QStringList& list);
        /**
         * Fonction static qui renvoi le chemin d'une icon correspondant a un ingrédient ou une icon par défaut si elle ne trouve rien.
         * @param ing un QString correspondant a l'ingrédient dont on cherche l'icon.
         * @return un QString contenant le chemin de l'icon de l'ingrédient. Si aucune icon n'a été trouvé, renvoi le chemin de l'icon par défault.
         */
        static QString getIcon(QString ing);
        /**
         * Fonction static qui teste si un QString contienr une chaine de caractère en ignorant la case.
         * @param source un const QString& correspondant a la chaine source.
         * @param val un const QString& correspondant a la valeur recherchée.
         * @return un bool. True si la source contient la valeur recherchée, sinon False.
         */
        static bool stringContains(const QString& source, const QString& val);
};

#endif // INGREDIENTLISTMODEL_H
