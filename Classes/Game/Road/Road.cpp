#include "Road.h"
#include <Vector>

USING_NS_CC;

Vector<Road*> listRoad;

Road* Road::create()
{ 
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Road* road = new Road();


    float roadLandWidth = visibleSize.width / 3; 
    float roadLandHeight = visibleSize.height; 

    //  roadLand1
    road->roadLand1 = Sprite::create("Roads/13.png");
    road->roadLand1->setAnchorPoint(Vec2(0, 0));
    road->roadLand1->setScaleX(roadLandWidth / road->roadLand1->getContentSize().width);
    road->roadLand1->setScaleY(roadLandHeight / road->roadLand1->getContentSize().height);
    road->addChild(road->roadLand1);

    //  roadLand2
    road->roadLand2 = Sprite::create("Roads/13.png");
    road->roadLand2->setAnchorPoint(Vec2(0, 0));
    road->roadLand2->setScaleX(roadLandWidth / road->roadLand2->getContentSize().width);
    road->roadLand2->setScaleY(roadLandHeight / road->roadLand2->getContentSize().height);
    road->roadLand2->setPosition(Vec2(roadLandWidth, 0));
    road->addChild(road->roadLand2);

    // roadLand3
    road->roadLand3 = Sprite::create("Roads/13.png");
    road->roadLand3->setAnchorPoint(Vec2(0, 0));
    road->roadLand3->setScaleX(roadLandWidth / road->roadLand3->getContentSize().width);
    road->roadLand3->setScaleY(roadLandHeight / road->roadLand3->getContentSize().height);
    road->roadLand3->setPosition(Vec2(roadLandWidth * 2, 0)); 
    road->addChild(road->roadLand3);

    return road;
}



bool Road::init()
{
	if (!Sprite::init())
	{
		log("Init road faild");
		return false;
	}
	//Road::create();
	this->scheduleUpdate();
	return true;
}



void Road::update(float dt)
{
	/*float scrollSpeed = 100.0f;
	roadLand1->setPositionY(roadLand1->getPositionY() - scrollSpeed * dt);
	roadLand2->setPositionY(roadLand2->getPositionY() - scrollSpeed * dt);
	roadLand3->setPositionY(roadLand3->getPositionY() - scrollSpeed * dt);

	float roadHeight = roadLand1->getContentSize().height;
	if (roadLand1->getPositionY() <= -roadHeight) {
		roadLand1->setPositionY(roadLand3->getPositionY() + roadHeight);
	}
	if (roadLand2->getPositionY() <= -roadHeight) {
		roadLand2->setPositionY(roadLand1->getPositionY() + roadHeight);
	}
	if (roadLand3->getPositionY() <= -roadHeight) {
		roadLand3->setPositionY(roadLand2->getPositionY() + roadHeight);
	}*/
}
