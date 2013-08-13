
#include "scenestate.h"




//loginState::loginState()
//{
//	
//}
//
//loginState::~loginState()
//{
//	
//}
//
//int  loginState::getType()
//{
//	return 0;
//}
//
//
//void loginState::beginState()
//{
//	CCScene* pscene = Studio::getInstance()->getMainScene();
//	if ( pscene )
//	{
//		CCNode* nodeLogin = pscene->getChildByTag( GAME_SCENE_TAG_LOGIN );
//		if ( nodeLogin )
//		{
//			nodeLogin->setVisible( true );
//			nodeLogin->scheduleUpdate();
//		}
//		else
//		{
//			loginScene* loginLayer = CCObject::create<loginScene>();
//			pscene->addChild( loginLayer );
//			loginLayer->setTag( GAME_SCENE_TAG_LOGIN );
//		}
//	}
//}
//
//
//void loginState::endState()
//{
//	CCScene* pscene = Studio::getInstance()->getMainScene();
//	if ( pscene )
//	{
//		CCNode* nodeLogin = pscene->getChildByTag( GAME_SCENE_TAG_LOGIN );
//		if ( nodeLogin )
//		{
//			nodeLogin->unscheduleUpdate();
//			nodeLogin->removeFromParentAndCleanup(true);
//		}
//	}
//}
//
//
//
//////////////////////////////////////////////////////////////////farmscene////////////////////////////////////////////////////////////////
//
//farmState::farmState()
//{
//
//}
//
//farmState::~farmState()
//{
//
//}
//
//int  farmState::getType()
//{
//	return 1;
//}
//
//
//void farmState::beginState()
//{
//	CCScene* pscene = Studio::getInstance()->getMainScene();
//	if ( pscene )
//	{
//		CCNode* nodefarm = pscene->getChildByTag( GAME_SCENE_TAG_FARM );
//		if ( nodefarm )
//		{
//			nodefarm->setVisible( true );
//			nodefarm->scheduleUpdate();
//		}
//		else
//		{
//			farmScene* farmLayer = CCObject::create<farmScene>();
//			pscene->addChild( farmLayer );
//			farmLayer->setTag( GAME_SCENE_TAG_FARM );
//		}
//	}
//}
//
//
//void farmState::endState()
//{
//	CCScene* pscene = Studio::getInstance()->getMainScene();
//	if ( pscene )
//	{
//		CCNode* nodefarm = pscene->getChildByTag( GAME_SCENE_TAG_FARM );
//		if ( nodefarm )
//		{
//			nodefarm->unscheduleUpdate();
//			nodefarm->removeFromParentAndCleanup(true);
//		}
//	}
//}

