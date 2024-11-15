//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Plane.h"

Plane::Plane(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         currentAltitude,
    int         maxAltitude
): Vehicle(country, model, durability, VehicleType::PLANE){
}

FuelType Plane::GetFuelType() {
    return FuelType::Gasoline;
}
VehicleType Plane::GetVehicleType() {
    return VehicleType::PLANE;
}

void Plane::ConsumeDurability() {
    if (country == "USA"){
        durability -= 30;
    }else if(country == "Japan"){
        durability -= 2;
    }else{
        durability -= 10;
    }

    if (durability < 0){
        std::runtime_error;
    }
}

int Plane::GetMaxAltitude() const {
    return maxAltitude;
}
int Plane::GetCurrentAltitude() const {
    return currentAltitude;
}

void Plane::SetMaxAltitude(int value) {
    this->maxAltitude = value;
    if (maxAltitude > 4000)
    {
        throw std::invalid_argument("exceed maxAltitude");
    }
}

void Plane::SetCurrentAltitude(int value) {
    this->currentAltitude = value;
    if (currentAltitude > maxAltitude)
    {
        throw std::invalid_argument("exceed altitude");
    }
}
