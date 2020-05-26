#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>

#include "recipeinfo.h"
#include "recipeloader.h"

/**
 *  La class MainWindow. Représente la fenetre principale de l'application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        RecipeInfo *rInfo;
        RecipeLoader *rloader; /**< RecipeLoader* variable. Chargeur de recette. */
        /**
         * Fonction qui initialise le menu "fichier" dans la barre de menus.
         */
        void setupFileMenu();
        void setupLangMenu();
        void setupHelpMenu();

    public:
        /**
         * Constructeur de la class MainWindow.
         * Initialise la fenetre avec les différents widgets qui la compose.
         * Comme aucune recette n'est chargée au démarrage de l'application, ouvre la fenetre de chargement de recette au lancement.
         */
        MainWindow(QWidget *parent = nullptr);
        /**
         * Le destructeur de la class MainWindow.
         */
        ~MainWindow();

    public slots:
        /**
         * Slot qui charge une recette depuis le RecipeLoader.
         */
        void loadRecipe();
        /**
         * Slot qui emet le signal closeApp(). A appler lorsque l'on souhaite quitter l'application.
         */
        void closeSlot();
    signals:
        /**
         * Signal emis lorsque l'utilisareur demande a fermer l'application.
         */
        void closeApp();
        //TODO doc
        void recipeLoaded(Recipe *);
};
#endif // MAINWINDOW_H
