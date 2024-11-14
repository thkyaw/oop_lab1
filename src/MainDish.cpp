//
// Created by User on 2024/10/29.
//

#include "MainDish.hpp"
MainDish::MainDish(Production id) : Food(id){
    MakeFood();
}

void MainDish::MakeFood() {
    if (id == Production::FishBurger){
        ingredient = {Ingredients::FishSteak, Ingredients::Lattuce, Ingredients::BurgerBread, Ingredients::Cheese};
        money = 79;
    }

    else if (id == Production::PorkBurger){
        ingredient = {Ingredients::PorkSteak, Ingredients::Lattuce, Ingredients::BurgerBread, Ingredients::Cheese};
        money = 59;
    }

    else if (id == Production::BeefBurger){
        ingredient = {Ingredients::BeefSteak, Ingredients::Lattuce, Ingredients::BurgerBread, Ingredients::Cheese};
        money = 69;
    }
}

void MainDish::AddIngredients(std::vector<Ingredients> additional) {   
    
    for (auto i = 0; i < additional.size(); i++){
        if ((additional[i] != Ingredients::FishSteak) && 
        (additional[i] != Ingredients::PorkSteak) && 
        (additional[i] != Ingredients::BeefSteak) && 
        (additional[i] != Ingredients::Lattuce) && 
        (additional[i] != Ingredients::Cheese)) 
        {
            throw std::invalid_argument("Cannot add this item");
        }
        addtional.push_back(additional[i]);
        if ((additional[i] == Ingredients::FishSteak) ||
            (additional[i] == Ingredients::BeefSteak) ||
            (additional[i] == Ingredients::PorkSteak)) {
            money += 20;
        }
        else if ((additional[i] == Ingredients::Lattuce) || (additional[i] == Ingredients::Cheese)){
            money += 10;
        }
    }    
}
