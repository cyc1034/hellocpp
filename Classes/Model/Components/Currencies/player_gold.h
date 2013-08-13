#ifndef __PLAYER_GOLD_H__
#define __PLAYER_GOLD_H__

#include "cocos2d.h"

namespace crazyfarm
{
	class playerGold
	{
	public:
		playerGold(unsigned int amount );
		virtual ~playerGold(void);

		unsigned int getAmount(){ return amount_;}

	private:
		unsigned int amount_;
	};

}

#endif