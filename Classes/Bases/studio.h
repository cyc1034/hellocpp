#ifndef __BASE_STUDIO_H__
#define __BASE_STUDIO_H__

#include "Tools/FSM.h"
#include "Tools/singleton.h"
#include "cocos2d.h"
USING_NS_CC;

enum gameSceneTag
{
	GAME_SCENE_TAG_NONE = 0,
	GAME_SCENE_TAG_LOGIN,
	GAME_SCENE_TAG_FARM,
	GAME_SCENE_TAG_BATTLE
};
class loginScene;

class Studio : public Singleton<Studio>
{
public:
	Studio();
	~Studio();

	bool initGame();
	void gotoLoginScene();
	void gotoFarmScene();
	void gotoBattleScene();
	
	CCScene* getMainScene(){ return pscene_;}
private:
	Fsm<Studio>* studiofsm_;
	CCScene* pscene_;

};

#endif