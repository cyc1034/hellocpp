#ifndef __PLAYER_GEM_H__
#define __PLAYER_GEM_H__

#include "cocos2d.h"

namespace crazyfarm
{
	class playerGem
	{
	public:
		playerGem(unsigned int amount );
		virtual ~playerGem(void);

		unsigned int getAmount(){ return amount_;}

	private:
		unsigned int amount_;
	};

}

#endif