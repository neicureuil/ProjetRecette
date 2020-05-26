#include "recipe.h"

Recipe::Recipe(QString n)
 : name(n), desc(""), url(""), image(""), category(""), keywords(""), prepTime(""), cookTime(""), totalTime(""), yield(0), ingredients(), instructions() {

}

Recipe::~Recipe() {
}
