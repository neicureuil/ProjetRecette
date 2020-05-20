#include "recipeloader.h"

RecipeLoader::RecipeLoader() : recipe(nullptr){

}

RecipeLoader::~RecipeLoader() {
    delete recipe;
}

void RecipeLoader::LoadFromFile(QFile file){

    QJsonParseError error;

    //Ouverture du fichier en lecture uniquement
    if(file.open(QFile::ReadOnly)) {
        //Récupération du contenu du fichier
        QByteArray donnees = file.readAll();

        //Interprétation du fichier JSON
        QJsonDocument doc = QJsonDocument::fromJson(donnees, &error);

        if(error.error != QJsonParseError::NoError) {
          //Erreur impoosible d'interpreter le fichier
        }else{
            obj = doc.object();
        }

    }else{
        //Erreur impossible d'ouvrir le fichier
    }

}

void RecipeLoader::LoadRecipe() {
    //Si une recette est déjà chargée, la supprime
    delete recipe;

    //Création de la recette
    recipe = new Recipe(GetString("name"));
    recipe->setDesc(GetString("description"));
    recipe->setUrl(GetString("url"));
    recipe->setImage(GetString("image"));
    recipe->setCategory(GetString("recipeCategory"));
    recipe->setKeywords(GetString("keywords"));

    //TODO : CHARGER LE RESTE => YIELS TIMES TOOLS INGREDIENTS STEPS
}

QString RecipeLoader::GetString(QString key){
    if(obj.contains(key)){
        return (obj.value(key)).toString();
    }else {
        return "";
    }
}
