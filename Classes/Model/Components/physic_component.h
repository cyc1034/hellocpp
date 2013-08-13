#ifndef __COMPONENT_HEALTH_H__
#define __COMPONENT_HEALTH_H__

#include "cocos2d.h"

namespace crazyfarm
{
	class physicComponent
	{
	public:
		physicComponent(void);
		virtual ~physicComponent(void);

		void initPhysic( unsigned int typeId );

	private:
		
	};

}

#endif