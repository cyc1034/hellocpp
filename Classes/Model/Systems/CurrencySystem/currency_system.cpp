#include "currency_system.h"
#include "../../Components/Currencies/pet_food.h"
#include "../../Components/Currencies/player_gold.h"
#include "../../Components/Currencies/player_gem.h"

namespace crazyfarm
{
	currencySystem::currencySystem() 
		: pet_food_(new petFood(0)),
		player_gold_(new playerGold(0)),
		player_gem_(new playerGem(0))
	{

	}

	currencySystem::~currencySystem()
	{

	}


	void currencySystem::init()
	{
		
	}

	unsigned int currencySystem::getGold()
	{
		return pet_food_->getAmount();
	}
	unsigned int currencySystem::getGem()
	{
		return player_gem_->getAmount();
	}
	unsigned int currencySystem::getFood()
	{
		return player_gold_->getAmount();
	}
}