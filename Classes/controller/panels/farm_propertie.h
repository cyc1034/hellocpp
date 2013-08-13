#ifndef __TOOLS_STATE_BASE_H__
#define __TOOLS_STATE_BASE_H__



class stateBase
{
public:
	stateBase(){};
	~stateBase(){};

	virtual int  getType() = 0;
	virtual void beginState() = 0;
	virtual void endState() = 0;
	virtual void update() = 0;

};

#endif