//
// Created by User on 2024/10/29.
//

#ifndef OOP_FOOD_HPP
#define OOP_FOOD_HPP

#include <string>
#include <vector>
#include "Ingredients.hpp"

class Food {
protected:
    Production id;          
    std::vector<Ingredients> ingredient;
    int money;
public:
    Food(Production id);                // 建構子   
    Production getId() const;           // Getter
    std::vector<Ingredients> GetIngredient();  // Getter
    virtual void MakeFood() = 0;
    int GetMoney();                     // Getter
};

#endif // OOP_FOOD_HPP
