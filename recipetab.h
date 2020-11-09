#ifndef RECIPETAB_H
#define RECIPETAB_H
#include <QLabel>
#include <QPainter>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include <recipe.h>


/**
 *  La class RecipeTab. Widget qui gère l'affichage des informations d'une recette.
 */
class RecipeTab : public QWidget
{
    Q_OBJECT


    private:
        QPixmap pixmap; /**< QPixmap. Contient les données de l'image de la recette. */
        QLabel * nameLabel; /**< QLabel*. Pointe sur le label qui affiche le nom de la recette. */

        QLabel * categoryLabelTitle; /**< QLabel*. Pointe sur le label qui affiche le titre la catégorie de la recette. */
        QLabel * categoryLabel; /**< QLabel*. Pointe sur le label qui affiche la catégorie de la recette. */

        QLabel * imageLabel; /**< QLabel*. Pointe sur le label qui affiche l'image de la recette. */

        QLabel * descLabelTitle; /**< QLabel*. Pointe sur le label qui affiche le titre de la description de la recette. */
        QLabel * descLabel; /**< QLabel*. Pointe sur le label qui affiche la description de la recette. */

        QLabel * prepTimeLabelTitle; /**< QLabel*. Pointe sur le label qui affiche le titre du temps de preparation de la recette. */
        QLabel * prepTimeLabel; /**< QLabel*. Pointe sur le label qui affiche le temps de préparation de la recette de la recette. */

        QLabel * cookTimeLabelTitle; /**< QLabel*. Pointe sur le label qui affiche le titre du temps de cuisson de la recette. */
        QLabel * cookTimeLabel; /**< QLabel*. Pointe sur le label qui affiche le temps de cuisson de la recette de la recette. */

        QLabel * totalTimeLabelTitle; /**< QLabel*. Pointe sur le label qui affiche le titre du temps total de la recette. */
        QLabel * totalTimeLabel; /**< QLabel*. Pointe sur le label qui affiche le temps total de la recette de la recette. */

        QLabel * yieldLabelTitle; /**< QLabel*. Pointe sur le label qui affiche le titre de la quantité produite de la recette. */
        QLabel * yieldLabel; /**< QLabel*. Pointe sur le label qui affiche la quantité produite de la recette. */

        QLabel * kwordsLabelTitle; /**< QLabel*. Pointe sur le label qui affiche le titre des mots clés de la recette. */
        QLabel * kwordsLabel; /**< QLabel*. Pointe sur le label qui affiche les mots clés de la recette. */

        QLabel * urllabel; /**< QLabel*. Pointe sur le label qui affiche l'url de la recette. */

        /**
         * Fonction qui télécharge l'image de la recette a partir de l'url.
         * Une fois finit appel UpdateImage.
         * @see UpdateImage(QNetworkReply*)
         * @param url Un QString correspondant a l'url de l'image
         */
        void LoadImage(QString url);
        /**
         * Fonction creer un vertical layout a partir de deux éléments et l'ajoute a un layout parent.
         * @param container Un QBoxLayout* correspondant au layout parent
         * @param w1 Un QWidget* pointant sur le premier widget a ajouter
         * @param w2 Un QWidget* pointant sur le deuxième widget a ajouter
         */
        void CreateHField(QBoxLayout* container, QWidget* w1, QWidget* w2);


    public:
        /**
         * Constructeur de la class RecipeTab.
         * Initialise le widget et les différents widgets qui compose cette classe.
         * @param parent Un QWidget* correspondant au Widget parent
         */
        explicit RecipeTab(QWidget *parent = nullptr);

    public slots:
        /**
         * Slot qui met a jour l'affichage du wiget avec les informations de la recette.
         * @param r Un Recipe* pointant sur la recette dont on souhaite afficher les informations
         */
        void UpdateUI(Recipe* r);
        /**
         * Slot qui affect l'image de la recette telecharger avec LoadImage au label correspondant.
         * @see LoadImage(QString)
         * @see imageLabel
         * @param r Un QNetworkReply* pointant sur les données de l'image chargée
         */
        void UpdateImage(QNetworkReply* r);
        /**
         * Slot qui actualise la langue de l'affichage des widgets.
         */
        void UpdateLang();

};

#endif // RECIPETAB_H
