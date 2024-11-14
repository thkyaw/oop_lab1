//
// Created by User on 2024/10/29.
//

#include "Package.hpp"

Package::Package() : money(0) {}

void Package::SetMainDish(MainDish maindish) {
    this->maindish = std::make_shared<MainDish>(maindish);
}

void Package::SetSideDish(SideDish sidedish) {
    this->sidedish = std::make_shared<SideDish>(sidedish);
}

void Package::SetDrink(Drink drink) {
    this->drink = std::make_shared<Drink>(drink);
}

void Package::CountMoney() {
    money = 0;
    if (maindish) money += maindish->GetMoney();  // Null check before access
    if (sidedish) money += sidedish->GetMoney();
    if (drink) money += drink->GetMoney();

    if (maindish && sidedish && drink) {
        money -= 15;  // Package discount
    }
}

int Package::GetMoney() {
    return money;
}


