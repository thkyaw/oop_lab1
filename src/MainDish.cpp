//
// Created by User on 2024/10/29.
//

#include "MainDish.hpp"

MainDish::MainDish(Production id) : Food(id) {
    MakeFood();
}

void MainDish::MakeFood() {
    switch (id) {
        case Production::PorkBurger:
            ingredient = {Ingredients::PorkSteak, Ingredients::Lattuce, Ingredients::BurgerBread, Ingredients::Cheese};
            money = 59;
            break;
        case Production::BeefBurger:
            ingredient = {Ingredients::BeefSteak, Ingredients::Lattuce, Ingredients::BurgerBread, Ingredients::Cheese};
            money = 69;
            break;
        case Production::FishBurger:
            ingredient = {Ingredients::FishSteak, Ingredients::Lattuce, Ingredients::BurgerBread, Ingredients::Cheese};
            money = 79;
            break;
        default:
            throw std::invalid_argument("Invalid main dish type");
    }
}

void MainDish::AddIngredients(std::vector<Ingredients> additional) {
    for (auto addedIngredient : additional) {  // Renamed loop variable to avoid shadowing
        if (addedIngredient != Ingredients::PorkSteak && addedIngredient != Ingredients::BeefSteak &&
            addedIngredient != Ingredients::FishSteak && addedIngredient != Ingredients::Lattuce &&
            addedIngredient != Ingredients::Cheese) {
            throw std::invalid_argument("Invalid ingredient for main dish");
        }
        this->ingredient.push_back(addedIngredient);
    }

    // Calculate price based on added ingredients
    for (auto addedIngredient : additional) {
        switch (addedIngredient) {
            case Ingredients::PorkSteak:
            case Ingredients::BeefSteak:
            case Ingredients::FishSteak:
                money += 20;  // Ingredient price
                break;
            case Ingredients::Lattuce:
            case Ingredients::Cheese:
                money += 10;
                break;
            default:
                throw std::invalid_argument("Invalid ingredient");
        }
    }
}



