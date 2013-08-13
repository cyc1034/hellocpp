#ifndef __TOOLS_SINGLETON_H__
#define __TOOLS_SINGLETON_H__

class noncopitable
{
protected:
	noncopitable(){};
	noncopitable(noncopitable& rvalue){};
	virtual ~noncopitable(){};

};


template<typename T>
class Singleton : public noncopitable
{
public:

	static T* getInstance()
	{
		static T t;
		return &t;
	}

};

#endif