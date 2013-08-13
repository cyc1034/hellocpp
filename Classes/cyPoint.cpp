#include "cyPoint.h"

USING_NS_CC;

const float pixPerMeter = 50.f;

CyPoint::CyPoint()
{
	ptWorld_ = NULL;
}


CyPoint::~CyPoint(void)
{

}


const CCPoint& CyPoint::GetPixpt()
{
	ptInPix_.x = ptWorld_->x*pixPerMeter;
	ptInPix_.y = ptWorld_->y*pixPerMeter;
	return ptInPix_;
}

void CyPoint::transFormPixpt2Worldpt( const CCPoint& ptpix, b2Vec2& worldpt )
{
	worldpt.x = ptpix.x/pixPerMeter;
	worldpt.y = ptpix.y/pixPerMeter;
}

void CyPoint::transFormWorldpt2Pixpt( CCPoint& ptpix, const b2Vec2& worldpt )
{
	ptpix.x = worldpt.x*pixPerMeter;
	ptpix.y = worldpt.y*pixPerMeter;
}

float32 CyPoint::transFormPix2World(float32 pix )
{
	return pix/pixPerMeter;
}


float32 CyPoint::transFormWorld2Pix(float32 world )
{
	return world*pixPerMeter;
}