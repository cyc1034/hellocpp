
#include "battle_scene.h"
#include "bases/studio.h"
USING_NS_CC;

battleScene::battleScene()
{

}

battleScene::~battleScene()
{

}


bool battleScene::init()
{
	bool bret = CCLayer::init();

	CCSprite* pbackground = CCSprite::create( "background3.png" );
	addChild( pbackground );
	pbackground->setAnchorPoint( ccp(0,0));

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"setting.png",
		"setting.png",
		this,
		menu_selector(battleScene::menuCloseCallback) );
	pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height*1/3) );

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition( CCPointZero );
	addChild(pMenu, 10);

	return bret;
}

void battleScene::menuCloseCallback( CCObject* obj )
{
	Studio::getInstance()->gotoFarmScene();
}

void battleScene::update(float dt)
{
	CCLayer::update(dt);
}

battleScene* battleScene::create()
{
	battleScene *pRet = new battleScene();
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

int battleScene::getNodeTag()
{
	return GAME_SCENE_TAG_BATTLE;
}