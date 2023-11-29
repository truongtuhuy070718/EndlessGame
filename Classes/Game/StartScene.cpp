#include "StartScene.h"
#include "Road/Road.h"
#include "Item/Item.h"
USING_NS_CC;
Vector<Item*> newItems;
bool isKeyPressedA = false;
bool isKeyPressedD = false;
Size edgeSize = Size(375, 812);
Scene* StartScene::createScene()
{


    return StartScene::create();
}

bool StartScene::init()
{
    if ( !Scene::initWithPhysics() )
    {
        return false;
    }
    gameStarted = false;
    elapsedTime = 0.0f;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
   
    startGame();
    // tao car
    //auto xPos = visibleSize.width / 3 + this->roads.at(0)->roadLand1->getContentSize().width + this->roads.at(0)->roadLand2->getContentSize().width / 2;
    this->car = Car::createCar("Car/car_01.png");
    car->setPosition(Vec2(visibleSize.width / 2 + 5, 70));
    car->setScale(0.3);
    car->setLocalZOrder(3);
    this->addChild(car);
    auto clickToPlayLabel = Label::createWithTTF("Click to Play", "fonts/Marker Felt.ttf", 48);
    if (clickToPlayLabel)
    {
        clickToPlayLabel->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(clickToPlayLabel);
    }
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [=](Touch* touch, Event* event) {
        if (!gameStarted)
        {
            gameStarted = true;
            this->removeChild(clickToPlayLabel);
        }
        return true;
    };

    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = CC_CALLBACK_2(StartScene::onKeyPressed, this);
    eventListener->onKeyReleased = CC_CALLBACK_2(StartScene::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
    
    this->scheduleUpdate();
    return true;
}

void StartScene::update(float dt)
{
    
    if (gameStarted) {
        static float elapsedTime = 0.0f;
        // time troi qua
        elapsedTime += dt;

        // auto spawnSize = roads.at(roads.size() - 1) ->getPositionY();
         //log("%f", spawnSize);
        float scrollSpeed = 100.0f;
        auto visibleSize = Director::getInstance()->getVisibleSize();

        //log("%d", roads.size());
        for (int i = 0; i < roads.size(); i++)
        {
            roads.at(i)->setPositionY(roads.at(i)->getPositionY() - scrollSpeed * dt);

            if (i == roads.size() - 1)
            {
                if (roads.at(i)->getPositionY() <= 0)
                {
                    Road* newRoad = Road::create();
                    newRoad->setPosition(Vec2(0, visibleSize.height));
                    roads.push_back(newRoad);
                    log("new road");
                    this->addChild(newRoad);

                }
            }

            if (roads.at(i)->getPositionY() < -visibleSize.height)
            {
                if (i != roads.size() - 1) {
                    log("delete road " + i);
                    this->removeChild(roads.at(i));
                    delete roads.at(i);
                    roads.erase(roads.begin() + i);
                    i--;
                }
            }
        }

        // create item random time
        auto timeSpwan = rand() % 3 + 1;

        if (elapsedTime >= timeSpwan * 1.0) {
            auto newItem = Item::create(getRandomItemType());
            this->addChild(newItem);
            auto nRandLand = rand() % 3 + 1;
            float xPos = 0.0f;
            newItems.pushBack(newItem);
            if (nRandLand == 1) {
                xPos = visibleSize.width / 3 + this->roads.at(0)->roadLand1->getContentSize().width / 2;
            }
            else if (nRandLand == 2) {
                xPos = visibleSize.width / 3 + this->roads.at(0)->roadLand1->getContentSize().width + this->roads.at(0)->roadLand2->getContentSize().width / 2;
            }
            else if (nRandLand == 3) {
                xPos = visibleSize.width / 3 + this->roads.at(0)->roadLand2->getContentSize().width * 2 + this->roads.at(0)->roadLand3->getContentSize().width / 2;
            }


            newItem->setPosition(Vec2(xPos, visibleSize.height - 1));

            elapsedTime = 0.0f;
        }


        for (int i = 0; i < newItems.size(); ++i) {
            auto item = newItems.at(i);
            item->setPositionY(item->getPositionY() - scrollSpeed * dt);


            if (item->getPositionY() < 0) {
                this->removeChild(item);
                newItems.erase(i);
                i--;
            }
        }
    }
    
    
}
ItemType StartScene::getRandomItemType() {
    int random = rand() % 2;
    if (random == 0) {
        return ItemType::Gold;
    }
    else {
        return ItemType::Bomb;
    }
}

void StartScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
{
    log("click");
   // auto visibleSize = Director::getInstance()->getVisibleSize();
    float moveDistance = 125.0f;
    Vec2 currentPosition = this->car->getPosition();
    Vec2 newPosition = currentPosition;

    switch (keyCode) {
    case EventKeyboard::KeyCode::KEY_A:
    case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        newPosition.x = MAX(currentPosition.x - moveDistance, 0);
        isKeyPressedA = true;
        break;
    case EventKeyboard::KeyCode::KEY_D:
    case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        newPosition.x = MIN(currentPosition.x + moveDistance, Director::getInstance()->getVisibleSize().width);
        isKeyPressedD = true;
        break;
    default:
        break;
    }

    auto moveToAction = MoveTo::create(0.2f, newPosition);
    this->car->runAction(moveToAction);
}
void StartScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
{
    switch (keyCode) {
    case EventKeyboard::KeyCode::KEY_A:
        isKeyPressedA = false;
        break;
    case EventKeyboard::KeyCode::KEY_D:
        isKeyPressedD = false;
        break;
    default:
        break;
    }
}
void StartScene::startGame()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // tao road
    Road* road = Road::create();
    road->setPosition(Vec2(0, 0));
    roads.push_back(road);

    this->addChild(road);

    //tao diem
    auto goldSprite = Sprite::create("Item/Gold.png");
    goldSprite->setPosition(Vec2(30, Director::getInstance()->getVisibleSize().height - 30)); 
    this->addChild(goldSprite, 1); 


    auto goldLabel = Label::createWithTTF("Gold: 0", "fonts/Marker Felt.ttf", 24);

    //goldLabel->setAnchorPoint(Vec2(0, 1));

    goldLabel->setPosition(Vec2(goldSprite->getPositionX() + goldSprite->getContentSize().width / 2 + 40, goldSprite->getPositionY() - 3)); 

    this->addChild(goldLabel, 1); 

    int goldCount = 0; 
    goldLabel->setString("Gold: " + std::to_string(goldCount));
}

void StartScene::onEnter()
{
    Scene::onEnter();
    //auto visibleSize = Director::getInstance()->getVisibleSize();
    auto physicsWorld = this->getPhysicsWorld();
    physicsWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); 
    auto edgeBody = PhysicsBody::createEdgeBox(Size(375, 812), PHYSICSBODY_MATERIAL_DEFAULT, 3);
    edgeBody->setDynamic(false);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Vec2(edgeSize.width / 2, edgeSize.height / 2));

    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);

    /*auto camera = this->getDefaultCamera();
    if (camera) {
        camera->addChild(edgeNode);
    }*/
}
