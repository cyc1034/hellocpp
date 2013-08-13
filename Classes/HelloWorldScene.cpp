#include "HelloWorldScene.h"
#include "GameObject.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

	CCMenuItemImage *pRightItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuRightCallback) );
	pRightItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width/2 - 20, 20) );
	pRightItem->setScale( 0.5f );

	CCMenuItemImage *pUpItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuUpCallback) );
	pUpItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width/4 - 20, 20) );
	pUpItem->setScale( 0.5f );

	CCMenuItemImage *pLeftItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuLeftCallback) );
	pLeftItem->setPosition( ccp(20, 20) );
	pLeftItem->setScale( 0.5f );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem,pRightItem,pLeftItem,pUpItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 10);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 50) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

	b2Vec2 vec( 0.f, -10.f );
	phyWorld = new b2World( vec );

	b2BodyDef def;
	def.type = b2_staticBody;
	def.position.Set( -5.f, 0.f );

	groundbody_ = phyWorld->CreateBody( &def );
	b2PolygonShape shap;
	shap.SetAsBox( 100.f,0.5f );

	groundbody_->CreateFixture( &shap, 0 );

	GameObject* obj = GameObject::create( "birdred.png", phyWorld );
	GameObject* obj1 = GameObject::create( "birdred.png", phyWorld );
	GameObject* obj2 = GameObject::create( "birdred.png", phyWorld );
	GameObject* obj3 = GameObject::create( "birdred.png", phyWorld );

	addChild( obj, 1, 1 );
	addChild( obj1, 1, 2 );
	addChild( obj2, 1, 3 );
	addChild( obj3, 1, 4 );

	obj->setPosition( ccp(getContentSize().width/2, getContentSize().height) );
	obj1->setPosition( ccp(getContentSize().width*2/3, getContentSize().height) );
	obj2->setPosition( ccp(getContentSize().width*2/3, getContentSize().height/2) );
	obj3->setPosition( ccp(getContentSize().width*2/3, getContentSize().height/3) );
	obj1->GetBody()->ApplyAngularImpulse( 0.5f);

    // add "HelloWorld" splash screen"
    //CCSprite* pSprite = CCSprite::create("birdred.png");

    //// position the sprite on the center of the screen
    //pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    //this->addChild(pSprite, 0);
    scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt)
{
	if ( phyWorld )
	{
		phyWorld->Step( dt, 6, 2 );
	}
	
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::menuLeftCallback(CCObject* pSender)
{
	
	GameObject* obj = (GameObject*)getChildByTag(1);
	b2Vec2 vec( -5, 0 );
	obj->GetBody()->SetLinearVelocity( vec );
	
}


void HelloWorld::menuRightCallback(CCObject* pSender)
{
	b2Vec2 vec( 5.f, 0 );
	GameObject* obj = (GameObject*)getChildByTag(1);
	obj->GetBody()->SetLinearVelocity( vec );
}

void HelloWorld::menuUpCallback(CCObject* pSender)
{
	b2Vec2 vec( 0.f, 3.5f );
	GameObject* obj = (GameObject*)getChildByTag(1);
	obj->GetBody()->ApplyLinearImpulse( vec,obj->GetBody()->GetWorldCenter() );
	obj->GetBody()->ApplyAngularImpulse( 1.f );
}