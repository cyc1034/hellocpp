#include "timer.h"

timer::timer( timerdelegate* counter, int Id, unsigned int latingtime )
	:istiming_(false),
	time_current_(0),
	time_lasting_(latingtime),
	counter_(counter),
	Id_(Id)
{

}

timer::~timer()
{

}


void timer::beginTimer()
{
	istiming_ = true;
}


void timer::pause()
{
	istiming_ = false;
}


void timer::resume()
{
	istiming_ = true;
}


void timer::update( unsigned int dt )
{
	if ( istiming_ )
	{
		time_current_ += dt;
		if ( time_current_ >= time_lasting_ )
		{
			if (counter_ )
			{
				counter_->onTimer( Id_ );
			}
		}
	}
}
