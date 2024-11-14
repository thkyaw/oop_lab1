//
// Created by User on 2024/10/29.
//

#include "Drink.hpp"

Drink::Drink(Production id) : Food(id), ml(550) {  // 假設初始為中杯，550ml
    MakeFood();
}

void Drink::MakeFood() {
    switch (id) {
        case Production::Cola:
            ingredient = {Ingredients::Cola};
            money = (ml == 550) ? 28 : 38;  // 中杯28、大杯38
            break;
        case Production::Spirit:
            ingredient = {Ingredients::Spirit};
            money = (ml == 550) ? 28 : 38;  // 中杯28、大杯38
            break;
        case Production::CaramelMilktea:
            ingredient = {Ingredients::Milktea, Ingredients::Caramel};
            money = (ml == 550) ? 44 : 44;  // 焦糖奶茶固定價格44
            break;
        case Production::Latte:
            ingredient = {Ingredients::Coffee, Ingredients::Milk};
            money = (ml == 550) ? 45 : 55;  // 中杯45、大杯55
            break;
        default:
            throw std::invalid_argument("Invalid drink type");
    }
}

void Drink::MakeLarger() {
    // 如果不是焦糖奶茶，將容量設為750ml，並重新計算價格
    if (id != Production::CaramelMilktea) {
        if (ml == 550) {
            ml = 750;
            money += 10;  // 例如大杯附加費用
        }
    }
}

int Drink::GetMl() {
    return ml;  // 回傳當前的容量
}



