
#include "FSM.h"


gameFsm::gameFsm() : 
currentState_(0)
{
}
gameFsm::~gameFsm()
{
}

void gameFsm::update()
{
	if ( currentState_)
	{
		currentState_->update();
	}
}
