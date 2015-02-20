#ifndef _OBJECT
#define _OBJECT
#include <string>
class General_Object
{
private: 
	double weight; // GRAMS
	double volume;  // CUBIC CENTIMETRES
	string name;
public:
	virtual double get_weight {return weight;}
	virtual double get_volume {return volume;}
	string get_name {return name;}
	virtual double get_density {return weight/volume;}
}

#endif
