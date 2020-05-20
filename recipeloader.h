#ifndef RECIPELOADER_H
#define RECIPELOADER_H

#include "recipe.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonValue>
#include <QJsonArray>


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
         * @param un QFile qui est le fichier contenant la recette.
         */
        void LoadFromFile(QFile);
        /**
         * Fonction qui charge une recette depuis les données JSON du QJsonObject
         */
        void LoadRecipe();
        /**
         * Fonction recupere la valeur d'une clé JSON
         * @param un QString qui correspond a la clé recherchée.
         * @return un QString qui renvoie la valeur si la clé existe et sinon un string vide.
         */
        QString GetString(QString);
        /**
         * Un getter qui retourne la recette chargée.
         * @return Un Recipe* contenant recette
         */
        inline Recipe* GetRecipe() { return recipe; };
};

#endif // RECIPELOADER_H
