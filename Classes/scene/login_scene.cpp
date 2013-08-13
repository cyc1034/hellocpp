
#include "login_scene.h"
#include "bases/studio.h"
USING_NS_CC;

loginScene::loginScene()
{

}

loginScene::~loginScene()
{

}


bool loginScene::init()
{
	bool bret = CCLayer::init();
	
	CCSprite* pbackground = CCSprite::create( "game_title.png" );
	addChild( pbackground );
	pbackground->setAnchorPoint( ccp(0,0));

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"start.png",
		"start.png",
		this,
		menu_selector(loginScene::menuCloseCallback) );
	pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width/2, CCDirector::sharedDirector()->getWinSize().height*1/3) );

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition( CCPointZero );
	addChild(pMenu, 10);

	return bret;
}

void loginScene::menuCloseCallback( CCObject* obj )
{
	Studio::getInstance()->gotoFarmScene();
}

void loginScene::update(float dt)
{
	CCLayer::update(dt);
}

loginScene* loginScene::create()
{
	loginScene *pRet = new loginScene();
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

int loginScene::getNodeTag()
{
	return GAME_SCENE_TAG_LOGIN;
}