#ifndef __SCENE_FARM_H__
#define __SCENE_FARM_H__

#include "cocos2d.h"
USING_NS_CC;

class farmScene :public CCLayer
{
public:
	farmScene();
	virtual ~farmScene();

	virtual bool init();
	virtual void update(float dt);
	static farmScene* create();
	void menuCloseCallback( CCObject* obj );

	static int getNodeTag();
};

#endif