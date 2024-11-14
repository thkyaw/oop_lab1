//
// Created by User on 2024/10/29.
//

#include "Package.hpp"
#include "Package.hpp"
#include <iostream>

Package::Package()
    : maindish(std::make_shared<MainDish>(Production::_NULL)),
      sidedish(std::make_shared<SideDish>(Production::_NULL)),
      drink(std::make_shared<Drink>(Production::_NULL)),
      money(0)
      {}  // Initialize money to zero

void Package::CountMoney() {
      // Check for valid pointers
        int maindishMoney = maindish->GetMoney();
        int sidedishMoney = sidedish->GetMoney();
        int drinkMoney = drink->GetMoney();

        Production maindishID = maindish->getId();
        Production sidedishID = sidedish->getId();
        Production drinkID = drink->getId();

        money = maindishMoney + sidedishMoney + drinkMoney;
        if (maindishID != Production::_NULL && 
            sidedishID != Production::_NULL && 
            drinkID != Production::_NULL) {
            money -= 15;  // Discount condition
        }
    
}

void Package::SetMainDish(MainDish maindish) {
    this->maindish = std::make_shared<MainDish>(maindish);
    CountMoney();
}

void Package::SetSideDish(SideDish sidedish) {
    this->sidedish = std::make_shared<SideDish>(sidedish);
    CountMoney();
}

void Package::SetDrink(Drink drink) {
    this->drink = std::make_shared<Drink>(drink);
    CountMoney();
}

int Package::GetMoney() {
    return money;
}
