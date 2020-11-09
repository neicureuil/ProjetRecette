#ifndef RECIPEINFO_H
#define RECIPEINFO_H

#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>

#include "stepsdialog.h"
#include "ingredienttab.h"
#include "recipetab.h"

/**
 * La classe RecipeInfo. Widget correspondant au Wigdet principal de l'application.
 * Il contient les différentes Tabs et Dialogs permettant l'affichage des informations d'une recette.
 */
class RecipeInfo : public QWidget
{
    Q_OBJECT

    private:
        QLabel* startLabel;  /**< QLabel*. Label qui contient le message d'acceuil de l'application. */
        StepsDialog* stepdialog; /**< StepsDialog*. Dialogue qui affiche les différents étapes de la recette. */
        QPushButton* startBtn; /**< QPushButton*QPushButton. Permet d'ouvrir le dialogue qui montre les étapes de la recette. @see stepdialog */
        QTabWidget* tabs;  /**< QTabWidget*. Contient les différents tabs de ce Wigdet. */
        RecipeTab* recipetab; /**< RecipeTab*. La tab contenant l'affichage des informations de la recette (nom, ctégorie, desc, ...). */
        IngredientTab* ingtab; /**< IngredientTab*. La tab contenant l'affichage des ingrédients de la recette. */

    public:
        /**
         * Constructeur de la class RecipeInfo.
         * Initialise la fenetre les différents widgets qui compose cette classe.
         * @param parent Un QWidget* correspondant au Widget parent
         */
        RecipeInfo(QWidget *parent = nullptr);
        /**
         * Getter qui renvoie un pointeur sur la recipetab.
         * @see recipetab
         * @return Un RecipeTab* correspondant a la tab d'information de le recette
         */
        inline RecipeTab* GetRecipeTab() { return recipetab; };
        /**
         * Getter qui renvoie un pointeur sur la tab d'ingredients ingtab.
         * @see ingtab
         * @return Un IngredientTab* correspondant a la tab d'ingredients de le recette
         */
        inline IngredientTab* GetIngredientTab() { return ingtab; };

    public slots:
        /**
         * Slot qui ouvre le dialog qui montre les différentes étapes de la recette : stepdialog.
         * Appelé par le QPushButton startBtn.
         * @see startBtn
         * @see stepdialog
         */
        void StartCooking();
        /**
         * Slot qui envoie les informations a afficher d'une recette passée en paramètre aux différentes tabs et dialog.
         * @param r Un Recipe* correspondant a la recette.
         */
        void LoadRecipe(Recipe* r);
        /**
         * Slot qui actualise la langue des textes du widget.
         * Envoie aussi une demande d'actualisation de la langue aux différentes tabs et dialog.
         * @see changeLang()
         */
        void UpdateLang();


    signals:
        /**
         * Signal emis afin de demander l'affichage des informations de la recette au Widget correspondant.
         * @see recipetab
         * @param r un Recipe* correspondant a la recette
         */
        void recipeLoaded(Recipe* r);
        /**
         * Signal emis afin de demander l'affichage des ingredients de la recette au Widget correspondant.
         * @see ingtab
         * @param list un const QStringList& contenant la liste des ingredients
         */
        void ingredientsLoaded(const QStringList& list);
        /**
         * Signal emis afin de demander l'affichage des différentes étapes de la recette au Widget correspondant.
         * @see stepdialog
         * @param list un const QStringList& contenant la liste des étapes
         */
        void stepLoaded(const QStringList& list);
        /**
         * Signal emis afin de demander une actualisation de la langue aux différents Widgets qui compose cette classe.
         */
        void changeLang();

};

#endif // RECIPEINFO_H

