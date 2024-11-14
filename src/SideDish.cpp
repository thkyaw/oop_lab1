//
// Created by User on 2024/10/29.
//

#include "SideDish.hpp"

SideDish::SideDish(Production id) : Food(id), type(SideDishType::SMALL) {
    MakeFood();
}

void SideDish::MakeFood() {
    switch (id) {
        case Production::Frenchfries:
            ingredient = {Ingredients::FranchFries};
            money = (type == SideDishType::SMALL) ? 44 : 59;  // Small 44, Large 59
            break;
        case Production::Nugget:
            ingredient = {Ingredients::ChickenNugget};
            money = (type == SideDishType::SMALL) ? 44 : 59;  // Small 44, Large 59
            break;
        case Production::Salad:
            ingredient = {Ingredients::Salad};
            money = 59;  // Salad fixed price
            break;
        default:
            throw std::invalid_argument("Invalid side dish type");
    }
}

void SideDish::MakeLarger() {
    if (id == Production::Frenchfries || id == Production::Nugget) {
        if (type == SideDishType::SMALL) {
            type = SideDishType::BIG;
            money = 59;  // Updated to large size price
        }
    }
}

SideDishType SideDish::GetType() {
    return type;
}



