
#include "farm_scene.h"
#include "bases/studio.h"
USING_NS_CC;

farmScene::farmScene()
{

}

farmScene::~farmScene()
{

}


bool farmScene::init()
{
	bool bret = CCLayer::init();

	CCSprite* pbackground = CCSprite::create( "background1.png" );
	addChild( pbackground );
	pbackground->setAnchorPoint( ccp(0,0));

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"shop.png",
		"shop.png",
		this,
		menu_selector(farmScene::menuCloseCallback) );
	pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height*1/3) );

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition( CCPointZero );
	addChild(pMenu, 10);

	return bret;
}

void farmScene::menuCloseCallback( CCObject* obj )
{
	Studio::getInstance()->gotoBattleScene();
}

void farmScene::update(float dt)
{
	CCLayer::update(dt);
}

farmScene* farmScene::create()
{
	farmScene *pRet = new farmScene();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

int farmScene::getNodeTag()
{
	return GAME_SCENE_TAG_FARM;
}