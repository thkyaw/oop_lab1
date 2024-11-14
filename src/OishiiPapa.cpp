#include "OishiiPapa.hpp"
#include <stdexcept>

void OishiiPapa::SendOrder(const Order& order) {
    pipeline.push(order);  // 把訂單加入 pipeline
}

void OishiiPapa::MakeDish() {
    if (pipeline.empty()) {
        throw std::out_of_range("No more orders");  // 如果 pipeline 為空，丟出異常
    }

    // 取出並移除最上面的訂單
    Order order = pipeline.front();
    pipeline.pop();

    Package package;
    std::vector<Production> products = order.GetProductInfo();
    std::vector<Ingredients> additional = order.GetAddtionalInfo();
    std::vector<bool> larger = order.GetLargerInfo();

    // 處理主餐，如果有指定的話
    if (products[0] != Production::_NULL) {
        MainDish maindish(products[0]);
        maindish.AddIngredients(additional);  // 添加配料
        package.SetMainDish(maindish);  // 設定主餐
    }

    // 處理附餐，如果有指定的話
    if (products[1] != Production::_NULL) {
        SideDish sidedish(products[1]);
        if (larger[0]) {
            sidedish.MakeLarger();  // 如果需要，將附餐加大
        }
        package.SetSideDish(sidedish);  // 設定附餐
    }

    // 處理飲料，如果有指定的話
    if (products[2] != Production::_NULL) {
        Drink drink(products[2]);
        if (larger[1]) {
            drink.MakeLarger();  // 如果需要，將飲料加大
        }
        package.SetDrink(drink);  // 設定飲料
    }

    // 最後計算包裝金額並加入 chest
    package.CountMoney();
    chest.push(package);
}

Package OishiiPapa::Pickup() {
    if (chest.empty()) {
        // 如果 chest 為空，檢查 pipeline 是否有訂單來製作餐點
        if (!pipeline.empty()) {
            MakeDish();  // 如果有訂單，製作餐點
        } else {
            throw std::out_of_range("No packages to pick up");  // 若無訂單，丟出異常
        }
    }

    // 取出最上面的 Package
    Package package = chest.front();
    chest.pop();

    // 將該 Package 的金額加入 OishiiPapa 的金額
    money += package.GetMoney();

    return package;  // 返回已取出的包裝
}

int OishiiPapa::GetMoney() {
    return money;  // 返回當前金額
}
