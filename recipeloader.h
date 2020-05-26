#ifndef RECIPELOADER_H
#define RECIPELOADER_H

#include "recipe.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonValue>
#include <QJsonArray>
#include <QRegExp>
#include <stdexcept>


/**
 *  La class RecipeLoader. S'occupe de charger une recette depuis un fichier et de stocker les informations dans une instance de Recipe.
 */
class RecipeLoader
{

    private:
        Recipe* recipe; /**< Recipe* variable. Pointeur sur recipe contenant la recette chargée. */
        QJsonObject obj;  /**< QJsonObject variable. Objet Json chargé. */

    public:
        /**
         * Constructeur de la class RecipeLoader.
         */
        RecipeLoader();
        /**
         * Le destructeur de la class RecipeLoader.
         */
        ~RecipeLoader();

        /**
         * Fonction qui  lit le fichier de recette en JSON
         * @param f un QFile* qui est le fichier contenant la recette.
         */
        void LoadFromFile(QFile* f);
        /**
         * Fonction qui charge une recette depuis les données JSON du QJsonObject
         */
        void LoadRecipe();
        /**
         * Fonction recupere la valeur d'une clé JSON
         * @param s un QString qui correspond a la clé recherchée.
         * @return un QString qui renvoie la valeur si la clé existe et sinon un string vide.
         */
        QString GetString(QString s);
        /**
         * Fonction recupere la valeur d'une clé JSON
         * @param s un QString qui correspond a la clé recherchée.
         * @return un int qui renvoie la valeur si la clé existe et sinon 0.
         */
        int GetInt(QString s);
        /**
         * Fonction convertit le format du temps PTHM en un format plus lisable.
         * @param s un QString qui correspond au temps au format PTHM.
         * @return un QString qui correspond a temps convertie dans un format plus lisbale (heures/minutes=.
         */
        QString GetTime(QString s);
        /**
         * Un getter qui retourne la recette chargée.
         * @return Un Recipe* contenant recette
         */
        inline Recipe* GetRecipe() { return recipe; };
};

#endif // RECIPELOADER_H
