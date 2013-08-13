#include "health_component.h"


namespace crazyfarm
{
	healthComponent::healthComponent() : healthPointer_(0)
	{

	}

	healthComponent::~healthComponent()
	{

	}

	void healthComponent::initHealth(int hp )
	{
		healthPointer_ = hp;
	}
}