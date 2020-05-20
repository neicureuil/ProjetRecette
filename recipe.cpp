#include "recipe.h"

Recipe::Recipe(QString n)
 : name(n), desc(""), url(""), image(""), category(""), keywords(""), prepTime(""), cookTime(""), totalTime(""), yield(0), ingredients(nullptr), tools(nullptr), instructions(nullptr) {

}

Recipe::~Recipe() {
    delete [] ingredients;
    delete [] tools;
    delete [] instructions;
}
