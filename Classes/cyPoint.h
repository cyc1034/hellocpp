#ifndef __CY_POINT_H__
#define __CY_POINT_H__

#include "Box2D/Box2D.h"
#include "cocos2d.h"


class CyPoint
{
public:
	CyPoint();
	virtual ~CyPoint(void);

	void setWorldPt( const b2Vec2* pt ){ ptWorld_ = pt; }
	const b2Vec2* GetWorldPt(){ return ptWorld_; }
	const cocos2d::CCPoint& GetPixpt();
	static void transFormPixpt2Worldpt( const cocos2d::CCPoint& ptpix, b2Vec2& worldpt );
	static void transFormWorldpt2Pixpt( cocos2d::CCPoint& ptpix, const b2Vec2& worldpt );
	static float32 transFormPix2World(float32 pix );
	static float32 transFormWorld2Pix(float32 world );

private:
	cocos2d::CCPoint  ptInPix_;
	const b2Vec2*	  ptWorld_;
	
};

#endif