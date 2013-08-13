#ifndef __PET_FOOD_H__
#define __PET_FOOD_H__

#include "cocos2d.h"

namespace crazyfarm
{
	class petFood
	{
	public:
		petFood(unsigned int amount );
		virtual ~petFood(void);

		unsigned int getAmount(){ return amount_;}
	private:
		unsigned int amount_;
	};

}

#endif