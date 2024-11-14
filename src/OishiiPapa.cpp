#include "OishiiPapa.hpp"
#include <iostream>
OishiiPapa:: OishiiPapa() : money(0) {

}

void OishiiPapa::SendOrder(Order order) {
    this->pipeline.push(order);
}

void OishiiPapa::MakeDish() {
    if (pipeline.empty()) {
        throw std::out_of_range("Empty pipeline");
    }
    if (chest.size() >= 15) {
        return;
    }

    Order order = pipeline.front();
    pipeline.pop();
    std::vector<Production> product = order.GetProductInfo();
    std::vector<Ingredients> additional = order.GetAddtionalInfo();
    std::vector<bool> larger = order.GetLargerInfo();

    Package pack;
    MainDish maindish = MainDish(product[0]);
    SideDish sidedish = SideDish(product[1]);
    Drink drink = Drink(product[2]);

    maindish.AddIngredients(additional);

    if (larger[0]){
        sidedish.MakeLarger();
    }
    if (larger[1]){
        drink.MakeLarger();
    }
    pack.SetMainDish(maindish);
    pack.SetSideDish(sidedish);
    pack.SetDrink(drink);
    money += pack.GetMoney();
    chest.push(pack);
}

Package OishiiPapa::Pickup() {
    MakeDish();
    if (chest.empty()){
        throw std::out_of_range("Chest is empty.");
    }
    Package pack = chest.front();
    chest.pop();
    return pack;
}

int OishiiPapa::GetMoney() {
    return money;
}

Order OishiiPapa::GetOrderInfo() {
    Order order = pipeline.front();
    pipeline.pop();
    return order;
}




