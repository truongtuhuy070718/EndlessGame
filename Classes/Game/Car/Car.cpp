#include "Car.h"
USING_NS_CC;


Car* Car::createCar(const std::string& filename) {
    Car* car = new (std::nothrow) Car();
    if (car && car->initWithFile(filename)) {
        car->autorelease();
        return car;
    }
    CC_SAFE_DELETE(car);
    return nullptr;
}

bool Car::init() {
    if (!Sprite::init()) {
        return false;
    }
    return true;
}


