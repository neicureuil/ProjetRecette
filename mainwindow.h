#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>

#include "recipeinfo.h"

/**
 *  La class MainWindow. Représente la fenetre principale de l'application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        /**
         * Fonction qui initialise le menu "fichier" dans la barre de menus.
         */
        void setupFileMenu();

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
         * Fonction qui charge une recette depuis le RecipeLoader.
         */
        void loadRecipe();
};
#endif // MAINWINDOW_H
