#ifndef __SCENE_LOGIN_H__
#define __SCENE_LOGIN_H__

#include "cocos2d.h"
USING_NS_CC;

class loginScene :public CCLayer
{
public:
	loginScene();
	virtual ~loginScene();

	virtual bool init();
	virtual void update(float dt);
	static loginScene* create();
	void menuCloseCallback( CCObject* obj );

	static int getNodeTag();
};

#endif