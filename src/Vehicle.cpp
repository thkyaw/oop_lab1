//
// Created by 陳世昂 on 2024/11/12.
//

#include "Object/Vehicle.h"

Vehicle::Vehicle(str c, str m, int d, VehicleType type) {
    this->country = c;
    this->model   = m;
    this->durability = 0;
    this->energy  = 0;
    this->type    = type;
}

int Vehicle::GetDurability() {
    return durability;
}
int Vehicle::GetEnergy() {
    return energy;
}
std::string Vehicle::GetCountry() {
    return country;
}
std::string Vehicle::GetModel() {
    return model;
}

void Vehicle::AddDurability(int value) {

    if (this->durability > 100)
    {
        throw std::invalid_argument("exceed durability");
    }else{
        this->durability += value;
    }
}

void Vehicle::AddEnergy(int value) {
    if (this->energy > 1000)
    {
        throw std::invalid_argument("exceed energy");
    }else{
        this->energy += value;
    }
}

bool Vehicle::IsDurabilityZero() {
    durability == 0 ? true : false;
}
