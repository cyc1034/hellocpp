#ifndef __TOOLS_TIMER_H__
#define __TOOLS_TIMER_H__

#include <map>
#include <list>

class timerdelegate
{
public:
	timerdelegate(){};
	~timerdelegate(){};

	virtual void onTimer( int id ) = 0;
};

class timer
{
public:
	timer( timerdelegate* counter, int Id, unsigned int latingtime );
	~timer();

	void update( unsigned int dt );
	void beginTimer();
	void pause();
	void resume();
	bool isIntiming( unsigned int timerid );

private:
	unsigned int time_lasting_;
	unsigned int time_current_;
	bool istiming_;
	timerdelegate* counter_;
	int Id_;
};

template<typename T >
class timeCounter : public timerdelegate
{
public:
	timeCounter(){};
	~timeCounter()
	{
		clearAll();
		realDelete();
	}
	void setTimer( unsigned int timelasting, T* father, int Id )
	{
		father_ = father;
		timer* ptimer = new timer( this, Id, timelasting );
		this->TimerNeedtoAdd( Id, ptimer );
		/*this->killTimer(Id);
		timers_[Id] = ptimer;
		ptimer->beginTimer();*/
	}

	void TimerNeedtoAdd(  int Id, timer* ptimer )
	{
		std::map<int, timer*>::iterator itTimer = timersNeedtoAdd_.find( Id );
		if( itTimer != timersNeedtoAdd_.end() )
		{
			timer* needkill = timersNeedtoAdd_[Id];
			timersNeedtoAdd_.erase(Id);
			delete needkill;
		}
		timersNeedtoAdd_[Id] = ptimer;
	}

	void realSetTimer()
	{
		std::map<int, timer*>::iterator itTimer;
		for ( itTimer = timersNeedtoAdd_.begin(); itTimer != timersNeedtoAdd_.end(); ++itTimer )
		{
			timer* ptimer = itTimer->second;
			int Id = itTimer->first;
			this->killTimer(Id);
			timers_[Id] = ptimer;
			ptimer->beginTimer();
		}
		timersNeedtoAdd_.clear();
	}

	void update( unsigned int dt )
	{
		realSetTimer();
		std::map<int, timer*>::iterator itTimer;
		for( itTimer = timers_.begin(); itTimer != timers_.end(); ++itTimer )
		{
			itTimer->second->update( dt );
		}

		realDelete();
	}

	void addtoNeedDelete( int id )
	{
		timerNeedtoDel_.push_back(id);
	}

	void realDelete()
	{
		std::list<int>::iterator itdel;
		for ( itdel = timerNeedtoDel_.begin(); itdel != timerNeedtoDel_.end(); ++itdel )
		{
			killTimer( *itdel );
		}
		timerNeedtoDel_.clear();
	}

	void killTimer( int id )
	{
		std::map<int, timer*>::iterator itTimer = timers_.find( id );
		if( itTimer != timers_.end() )
		{
			timer* needkill = timers_[id];
			timers_.erase(id);
			delete needkill;
		}
	}

	void pauseTimer( int id )
	{
		std::map<int, timer*>::iterator itTimer = timers_.find( id );
		if( itTimer != timers_.end() )
		{
			itTimer->second->pause();
		}
	}


	void resumeTimer( int id )
	{
		std::map<int, timer*>::iterator itTimer = timers_.find( id );
		if( itTimer != timers_.end() )
		{
			itTimer->second->resume();
		}
	}


	virtual void onTimer( int id )
	{
		this->addtoNeedDelete(id);
		father_->onTimer( id );
	}

	void clearAll()
	{
		std::map<int, timer*>::iterator itTimer;
		for( itTimer = timers_.begin(); itTimer != timers_.end(); ++itTimer )
		{
			killTimer( itTimer->first );
		}
	}
private:
	std::map<int, timer*> timers_;
	std::map<int, timer*> timersNeedtoAdd_;
	std::list<int> timerNeedtoDel_;
	T* father_;
};


#endif