#ifndef __ITEM_H__
#define __ITEM_H__
#include <Vector>
#include "cocos2d.h"

enum class ItemType {
    Gold,
    Bomb,
    // ... cac loai khac
};

class Item : public cocos2d::Sprite
{
public:
    static Item* create(ItemType type);
    virtual bool init(ItemType type);
    std::string getImagePathForType(ItemType type);
    ItemType getItemType() const { return itemType; }
protected:
    ItemType itemType;
};

#endif // __ITEM_H__
