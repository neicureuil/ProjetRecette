#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QStringList>

/**
 *  La class Recipe. Contient toute les informations relatives a une recettes (pas de traitement dans cette classe, que du stockage d'informations).
 */
class Recipe {

    private :
        QString name; /**< QString variable. Contient le nom de la recette. */
        QString desc; /**< QString variable. Contient la description de la recette. */
        QString url; /**< QString variable. Contient l'url de la recette. */
        QString image; /**< QString variable. Contient l'url de l'image de la recette. */
        QString category; /**< QString variable. Contient la catégorie de la recette. */
        QString keywords; /**< QString variable. Contient les mots clés de la recette. */
        QString prepTime; /**< QString variable. Contient le temps de préparation de la recette. */
        QString cookTime; /**< QString variable. Contient le temps de cuisson de la recette. */
        QString totalTime; /**< QString variable. Contient le temps total de préparation de la recette. */
        int yield; /**< Int variable. Contient la quantité produite de la recette (ex: nb de personnes/services). */
        QStringList ingredients;  /**< QStringList variable. Liste de QString qui contient la liste des ingrédients de la recette. */
        QString * instructions;  /**< QString* variable. Tableau de QString qui contient les instructions de la recette. */

    public:
        /**
         * Constructeur de la class Recipe.
         * Initialise la class avec des valeurs vides sauf pour le nom qui est passé en paramètre.
         * @param s un QString qui contient le nouveau nom de la recette
         */
        Recipe(QString s);
        /**
         * Le destructeur de la class Recipe.
         * Appelé lors de la destruction d'une recette, détruit les tableau (ingredients, tools, instructions).
         */
        ~Recipe();

        /**
         * Un setter qui permet de modifier le nom de la recette.
         * @param n un QString qui contient le nouveau nom de la recette.
         */
        inline void setName(QString n) { name = n; };
        /**
         * Un setter qui permet de modifier la description de la recette.
         * @param n un QString qui contient la nouvelle description de la recette.
         */
        inline void setDesc(QString n) { desc = n; };
        /**
         * Un setter qui permet de modifier l'url de la recette.
         * @param n un QString qui contient la nouvelle url de la recette.
         */
        inline void setUrl(QString n) { url = n; };
        /**
         * Un setter qui permet de modifier l'url de l'image de la recette.
         * @param n un QString qui contient la nouvelle url de l'image de la recette.
         */
        inline void setImage(QString n) { image = n; };
        /**
         * Un setter qui permet de modifier la catégorie de la recette.
         * @param n un QString qui contient la nouvelle catégorie de la recette.
         */
        inline void setCategory(QString n) { category = n; };
        /**
         * Un setter qui permet de modifier les mots clés de la recette.
         * @param n un QString qui contient la nouvelle liste des mots clés de la recette.
         */
        inline void setKeywords(QString n) { keywords = n; };
        /**
         * Un setter qui permet de modifier le temps de préparation de la recette.
         * @param n un QString qui contient le nouveau temps de préparation de la recette.
         */
        inline void setPrepTime(QString n) { prepTime = n; };
        /**
         * Un setter qui permet de modifier le temps de cuisson de la recette.
         * @param n un QString qui contient le nouveau temps de cuisson de la recette.
         */
        inline void setCookTime(QString n) { cookTime = n; };
        /**
         * Un setter qui permet de modifier le temps total de préparation de la recette.
         * @param n un QString qui contient le nouveau temps total de préparation de la recette.
         */
        inline void setTotalTime(QString n) { totalTime = n; };
        /**
         * Un setter qui permet de modifier la quantité produite de la recette.
         * @param i un Int qui contient la nouvelle quantité produite de la recette.
         */
        inline void setYield(int i) { yield = i; };
        /**
         * Un setter qui permet de modifier les ingrédients de la recette après avoir supprimer le tableau d'ingrédient existant.
         * @param list une QStringList , Liste de Qtring qui contient les nouveaux ingrédients de la recette.
         */
        inline void setIngredients(QStringList list) { ingredients = list; };
        /**
         * Un setter qui permet de modifier les instructions de la recette après avoir supprimer le tableau d'instructions existant.
         * @param n un QString* , tableau de Qtring qui contient les nouvelles instructions de la recette.
         */
        inline void setInstructions(QString * n) { delete [] instructions; instructions = n; };


        /**
         * Un getter qui retourne le nom de la recette.
         * @return Un QString contenant le nom de la recette
         */
        inline QString getName() { return name; };
        /**
         * Un getter qui retourne la description de la recette.
         * @return Un QString contenant la description de la recette
         */
        inline QString getDesc() { return desc; };
        /**
         * Un getter qui retourne l'url de la recette.
         *  @return Un QString contenant l'url de la recette
         */
        inline QString getUrl() { return url; };
        /**
         * Un getter qui retourne l'url de l'image de la recette.
         *  @return Un QString contenant l'url de l'image de la recette
         */
        inline QString getImage() { return image; };
        /**
         * Un getter qui retourne la catégorie de la recette.
         * @return Un QString contenant la catégorie de la recette
         */
        inline QString getCategory() { return category; };
        /**
         * Un getter qui retourne les mots clés de la recette.
         * @return Un QString contenant les mots clés de la recette
         */
        inline QString getKeywords() { return keywords; };
        /**
         * Un getter qui retourne le temps de préparation de la recette.
         * @return Un QString contenant le temp de préparation de la recette
         */
        inline QString getPrepTime() { return prepTime; };
        /**
         * Un getter qui retourne le temps de cuisson de la recette.
         * @return Un QString contenant le temps de cuisson de la recette
         */
        inline QString getCookTime() { return cookTime; };
        /**
         * Un getter qui retourne le temps de préparation total de la recette.
         * @return Un QString contenant le temps total de prépatation de la recette
         */
        inline QString getTotalTime() { return totalTime; };
        /**
         * Un getter qui retourne la quantité produite de la recette.
         *  @return Un Int contenant la quantité produite de la recette
         */
        inline int getYield() { return yield; };
        /**
         * Un getter qui retourne le tableau d'ingredients de la recette.
         * @return Une QStringList& constante contenant une référence sur la liste l'ingredients.
         */
        inline const QStringList& getIngredients() { return ingredients; };
        /**
         * Un getter qui retourne le tableau d'instructions de la recette.
         * @return Un QString* contenant le tableau d'instructions de la recette
         */
        inline QString* getInstructions() { return instructions; };

};

#endif // RECIPE_H
