#ifndef __OBJ_FACTORY_H__
#define __OBJ_FACTORY_H__


template< typename Obj >
class objBuider
{
public:
	objBuider() : object_(NULL)
public:
	void creat( unsigned int Id )
	{
		if(!object_)
		{
			object_ = new Obj;
			object_->init(Id);
		}
	};

	void buildHelth()
	{

	}

	void buidPhysical()
	{

	}

	Obj* getObj()
	{
		return object_;
	}

private:
	Obj* object_;

};


template<typename Obj, typename designer >
class objFactory
{
public:
    static Obj* creatObject( unsigned int Id)
	{
		objBuider<Obj> buider;
		designer->creatObj( &buider, Id );
		Obj* objneed = buider.getObj();
		return objneed;
	}
    
public:
	objFactory(){};
	~objFactory(){};
    
};

#endif // __HELLOWORLD_SCENE_H__
