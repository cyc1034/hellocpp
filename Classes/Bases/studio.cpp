#include "studio.h"
#include "cocos2d.h"
#include "scene/login_scene.h"
#include "scene/farm_scene.h"
#include "scene/battle_scene.h"
#include "scenestate.h"
USING_NS_CC;

Studio::Studio()
{
	studiofsm_ = new Fsm<Studio>(this);
	pscene_ = 0;
}

Studio::~Studio()
{
	if ( studiofsm_ )
	{
		delete studiofsm_;
	}
}

void Studio::gotoLoginScene()
{
	studiofsm_->changetoState< sceneState<loginScene> >( true );
}


void Studio::gotoFarmScene()
{
	studiofsm_->changetoState< sceneState<farmScene> >( true );
}

void Studio::gotoBattleScene()
{
	studiofsm_->changetoState< sceneState<battleScene> >( true );
}

bool Studio::initGame()
{
	pscene_ = CCScene::create();
	CCDirector *pDirector = CCDirector::sharedDirector();
	if (pDirector)
	{
		if ( !pDirector->getRunningScene() )
		{
			pDirector->runWithScene( pscene_ );
		}
	}

	return true;
}