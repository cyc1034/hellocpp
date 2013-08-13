#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template<class T >
class singleton
{
public:
    static T& instance()
	{
		static T t;
		return t;
	}
    
protected:
	singleton(){};
	~singleton(){};
    
};

#endif // __HELLOWORLD_SCENE_H__
