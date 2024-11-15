//
// Created by 陳世昂 on 2024/11/12.
//
#include "Object/Train.h"

Train::Train(
    std::string country,
    std::string model,
    int         durability,
    VehicleType type,
    int         carriage,
    int         maxCarriage
)
    : Vehicle("null", "null", -1, type){

    }

FuelType Train::GetFuelType() {
    return FuelType::Electricity;
}
VehicleType Train::GetVehicleType() {
    return VehicleType::TRAIN;
}

void Train::ConsumeDurability() {
    if (country == "USA"){
        durability -= 4;
    }else if(country == "Japan"){
        durability -= 5;
    }else{
        durability -= 10;
    }
    
}

int Train::GetCarriage() const {
    return carriage;
}
int Train::GetMaxCarriage() const {
    return maxCarriage;
}

void Train::SetMaxCarriage(int value) {
    this->maxCarriage = value;
    if (maxCarriage > 12)
    {
        throw std::invalid_argument("exceed maxcarriage");
    }
    
}

void Train::SetCarriage(int value) {
    this->carriage = value;
    if (carriage > maxCarriage)
    {
        throw std::invalid_argument("exceed carriage");
    }
}
