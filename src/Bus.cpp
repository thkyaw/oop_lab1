//
// Created by 陳世昂 on 2024/11/12.
//

//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Bus.h"

Bus::Bus(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         wheel,
    int         maxSpeed
)
    : Vehicle(country, model, durability, VehicleType::BUS){}

FuelType Bus::GetFuelType() {
    return FuelType::Gasoline;
}
VehicleType Bus::GetVehicleType() {
    return VehicleType::BUS;
}

void Bus::ConsumeDurability() {
    if (country == "USA"){
        durability -= 5;
    }else if(country == "Japan"){
        durability -= 1;
    }else{
        durability -= 10;
    }

    if (durability < 0){
        std::runtime_error;
    }
}

int Bus::GetWheel() const {
    return wheel;
}
int Bus::GetMaxSpeed() const {
    return maxSpeed;
}

void Bus::SetMaxSpeed(int value) {
    this->maxSpeed = value;
    if (maxSpeed > 80)
    {
        throw std::invalid_argument("exceed maxspeed");
    }
}

void Bus::SetWheel(int value) {
    this->wheel = value;
    if (wheel > 12)
    {
        throw std::invalid_argument("exceed wheel");
    }
}
