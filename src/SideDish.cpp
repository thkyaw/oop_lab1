//
// Created by User on 2024/10/29.
//

#include "SideDish.hpp"
SideDish::SideDish(Production id): Food(id){
    MakeFood();
}

void SideDish::MakeFood() {
    if (id == Production::Frenchfries){
        ingredient = {Ingredients::FranchFries};
        money = 44;
    }
    else if (id == Production::Nugget){
        ingredient = {Ingredients::ChickenNugget};
        money = 44;
    }
    else if (id == Production::Salad){
        ingredient = {Ingredients::Salad};
        money = 59;
    }
}

void SideDish::MakeLarger() {
    if (id == Production::Salad) {
        return;
    }
    else{
        type = SideDishType::BIG;
        money = 59;
    }
    
}

SideDishType SideDish::GetType() {
    return type;
}