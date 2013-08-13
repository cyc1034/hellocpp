#ifndef __SCENE_BATTLE_H__
#define __SCENE_BATTLE_H__

#include "cocos2d.h"
USING_NS_CC;

class battleScene :public CCLayer
{
public:
	battleScene();
	virtual ~battleScene();

	virtual bool init();
	virtual void update(float dt);
	static battleScene* create();
	void menuCloseCallback( CCObject* obj );

	static int getNodeTag();
};

#endif