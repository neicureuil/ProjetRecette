#include "recipeloader.h"

RecipeLoader::RecipeLoader() : recipe(nullptr){

}

RecipeLoader::~RecipeLoader() {
    delete recipe;
}

void RecipeLoader::LoadFromFile(QFile* file){
    QJsonParseError error;

    //Ouverture du fichier en lecture uniquement
    if(file->open(QFile::ReadOnly)) {
        //Récupération du contenu du fichier
        QByteArray donnees = file->readAll();

        //Interprétation du fichier JSON
        QJsonDocument doc = QJsonDocument::fromJson(donnees, &error);

        if(error.error != QJsonParseError::NoError) {
           throw std::runtime_error("Impossible d'interpreter le fichier, ce n'est peut être pas un fichier JSON.");
        }else{
            obj = doc.object();
            LoadRecipe();
        }

    }else{
       throw std::runtime_error("Echec lors que l'ouverture du fichier");
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

    recipe->setPrepTime(GetTime(GetString("prepTime")));
    recipe->setCookTime(GetTime(GetString("cookTime")));
    recipe->setTotalTime(GetTime(GetString("totalTime")));


    recipe->setYield(GetInt("recipeYield"));


    // Chargement des ingrédients
    QJsonArray val = obj.value("recipeIngredient").toArray();
    QStringList ingredients;
    for(int i=0; i<val.size(); i++) {
        ingredients.push_back(val[i].toString());
    }
    recipe->setIngredients(ingredients);


    //Chargement des instructions
    val = obj.value("recipeInstructions").toArray();
    QString * instructions = new QString[val.size()];
    for(int i=0; i<val.size(); i++) {
        instructions[i] = val[i].toString();
    }
    recipe->setInstructions(instructions);
}

QString RecipeLoader::GetTime(QString t) {
    if(t.startsWith("PT")){
       QString s("");

       QRegExp rex_numbers("(\\d+)");
       int pos = 0;
       pos = rex_numbers.indexIn(t, pos);
       s += rex_numbers.cap(1) + "h";

       pos += rex_numbers.matchedLength();
       pos = rex_numbers.indexIn(t, pos);
       s += rex_numbers.cap(1) + "m";
       return s;
    }else {
        //Renvoie le texte initial si il n'est pas dans le bon format.
        return t;
    }
}

QString RecipeLoader::GetString(QString key){
    if(obj.contains(key)){
        return (obj.value(key)).toString();
    }else {
        return "";
    }
}

int RecipeLoader::GetInt(QString key){
    if(obj.contains(key)){
        return (obj.value(key)).toInt();
    }else {
        return 0;
    }
}
