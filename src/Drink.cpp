//
// Created by User on 2024/10/29.
//

#include "Drink.hpp"
Drink::Drink(Production id): Food(id){
    MakeFood();
}

void Drink::MakeFood(){
    if (id == Production::Cola) {
        ingredient = {Ingredients::Cola};
        ml = 550;
        money = 28;
    }
    else if (id == Production::Spirit) {
        ingredient = {Ingredients::Spirit};
        ml = 550;
        money = 28;
    }
    else if (id == Production::CaramelMilktea) {
        ingredient = {Ingredients::Milktea, Ingredients::Caramel};
        ml = 550;
        money = 44;
    }
    else if (id == Production::Latte) {
        ingredient = {Ingredients::Coffee, Ingredients::Milk};
        ml = 550;
        money = 45;
    }
}

void Drink::MakeLarger() {
    if (id == Production::CaramelMilktea) {
        throw std::invalid_argument("Caramel Milk Tea cannot make larger.");
    }
    if (id == Production::Cola) {       
        ml = 750;
        money = 38;
    }
    else if (id == Production::Spirit) {
        ml = 750;
        money = 38;
    }
    else if (id == Production::Latte) {
        ml = 750;
        money = 55;
    }
}

int Drink::GetMl() {
    return ml;
}