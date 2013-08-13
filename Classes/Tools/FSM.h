#ifndef __TOOLS_FSM_H__
#define __TOOLS_FSM_H__
#include "state_base.h"
class FsmBase
{
public:
	FsmBase(){
		currentState_ = 0;
		nextState_ = 0;
	};
	virtual ~FsmBase(){};

	virtual void switchState() = 0;
	stateBase* getCurrentState(){ return currentState_;}

protected:
	stateBase* currentState_;
	stateBase* nextState_;
};

template<typename fatherObj>
class Fsm : public FsmBase
{
public:
	Fsm( fatherObj* father) : father_(father){
	};
	virtual ~Fsm(){
		if ( currentState_ )
		{
			delete currentState_;
		}
		if ( nextState_ )
		{
			delete nextState_;
		}

	}

	virtual void switchState()
	{
		if ( nextState_ )
		{
			currentState_->endState();
			delete currentState_;
			currentState_ = nextState_;
			currentState_->beginState();
			nextState_ = 0;
		}
		
	}

	template<typename stateType>
	bool changetoState( bool bforce = false )
	{
		stateType* state = new stateType();
		state->setFsm(this);
		if ( currentState_ == 0 )
		{
			currentState_ = state;
			currentState_->beginState();
			return true;
		}		
		else
		{
			if ( state->getType() != currentState_->getType() )
			{
				nextState_ = state;
				if ( bforce )
				{
					switchState();
				}
				return true;
			}
			else
				delete state;
			
		}
		return false;
	}

protected:
	fatherObj* father_;
};
#endif