#ifndef __TOOLS_STATE_SCENE_H__
#define __TOOLS_STATE_SCENE_H__

#include "Tools/state_base.h"
#include "cocos2d.h"



USING_NS_CC;

template<typename layer>
class sceneState : public stateBase
{
public:
	sceneState(){};
	~sceneState(){};

	virtual int  getType()
	{
		return layer::getNodeTag();
	}
	virtual void beginState()
	{
		CCScene* pscene = Studio::getInstance()->getMainScene();
		if ( pscene )
		{
			CCNode* node = pscene->getChildByTag( layer::getNodeTag() );
			if ( node )
			{
				node->setVisible( true );
				node->scheduleUpdate();
			}
			else
			{
				layer* newNode = layer::create();
				pscene->addChild( newNode );
				newNode->scheduleUpdate();
				newNode->setTag( layer::getNodeTag() );
			}
		}
	}
	virtual void endState()
	{
		CCScene* pscene = Studio::getInstance()->getMainScene();
		if ( pscene )
		{
			CCNode* node = pscene->getChildByTag( layer::getNodeTag() );
			if ( node )
			{
				node->unscheduleUpdate();
				node->removeFromParentAndCleanup(true);
			}
		}
	}
};

//class farmState : public stateBase
//{
//public:
//	farmState();
//	~farmState();
//
//	virtual int  getType();
//	virtual void beginState();
//	virtual void endState();
//};

#endif