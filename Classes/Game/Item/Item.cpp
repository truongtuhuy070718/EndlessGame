#include "Item.h"

USING_NS_CC;

Item* Item::create(ItemType type)
{
    Item* item = new (std::nothrow) Item();
    if (item && item->init(type)) {
        item->autorelease();
        return item;
    }
    CC_SAFE_DELETE(item);
    return nullptr;
}

bool Item::init(ItemType type)
{
    if (!Sprite::initWithFile(getImagePathForType(type))) {
        return false;
    }

    itemType = type;
    return true;
}
std::string Item::getImagePathForType(ItemType type) {
    switch (type) {
    case ItemType::Gold:
        return "Item/Gold.png";
    case ItemType::Bomb:
        return "Item/Bomb.png";
        
    default:
        return ""; 
    }
}

