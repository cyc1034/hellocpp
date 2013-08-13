#ifndef __CURRENCY_SYSTEM_H__
#define __CURRENCY_SYSTEM_H__

#include "cocos2d.h"

namespace crazyfarm
{
	class petFood;
	class playerGold;
	class playerGem;
	class currencySystem
	{
	public:
		currencySystem(void);
		virtual ~currencySystem(void);

		void init();
		unsigned int getGold();
		unsigned int getGem();
		unsigned int getFood();

	private:
		petFood*    pet_food_;
		playerGold* player_gold_;
		playerGem*  player_gem_;
	};

}

#endif