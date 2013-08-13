#ifndef __COMPONENT_HEALTH_H__
#define __COMPONENT_HEALTH_H__

#include "cocos2d.h"

namespace crazyfarm
{
	class healthComponent
	{
	public:
		healthComponent(void);
		virtual ~healthComponent(void);

		void initHealth(int hp );
		int  getHealth(){ return healthPointer_;}

	private:
		int healthPointer_;
	};

}

#endif