#ifndef INGREDIENTTAB_H
#define INGREDIENTTAB_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QListView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMediaPlayer>

#include "ingredientlistmodel.h"

/**
 * La classe IngredientTab. Widget correspondant a la Tab contenant la liste des ingrédients.
 */
class IngredientTab : public QWidget
{
    Q_OBJECT

    private:
        QMediaPlayer* player;  /**< QMediaPlayer*. Lecteur de musique qui a comme unique but de joueur un extrait des Sardines de Patrick Sebastien. */
        QListView* list; /**< QListView*. Pointeur sur ListeView correspondant a la liste des ingrédients de la recette. */
        IngredientListModel* model; /**< IngredientListModel*. Pointeur sur le model de la ListeView permettant de controller ses données. */

    public:
        /**
         * Constructeur de la classe IngredientTab.
         * Initialise les différents Widgets et élements contenus dans cette Tab.
         * Initialise la ListView et lui assigne son model.
         * @param parent un QObject correspondant au parent.
         */
        IngredientTab(QWidget *parent = nullptr);

    public slots:
        /**
         * Slot permettant de recevoir la liste des ingrédients a afficher et les affectes au model IngredientListModel model.
         * @see model
         * @param liste une reférence constante de QStringList correspondant la liste des ingrédients.
         */
        void SetIngredients(const QStringList &list);
        /**
         * Slot appeler a chaque fois q'un ingredient est selectionner dans la liste.
         * Si une sardine est selectionnée, joue l'hymne internationale des sardines.
         * @see list
         * @see player
         * @param selected Un const QItemSelection&  contenant la liste des items selectionnées.
         * @param deselected Un const QItemSelection& contenant la liste des items deselectionnés.
         */
        void ListItemSelected(const QItemSelection& selected, const QItemSelection& deselected);

};

#endif // INGREDIENTTAB_H
