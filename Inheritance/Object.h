#ifndef _OBJECT
#define _OBJECT

#include <string.h>
using std::string;

class General_Object
{
private: 
	double weight; // GRAMS
	double volume;  // CUBIC CENTIMETRES
	string name;
public:
	virtual ~General_Object();
	General_Object() {}
	General_Object(double, double, string);
	virtual double get_weight(void);
	virtual double get_volume(void);
	string get_name(void);
	virtual double get_density(void);
};

General_Object::General_Object(double w, double v, string n)
{
	weight = w;
	volume = v;
	name = n;	
}

General_Object::~General_Object() {}

double General_Object::get_weight()
{
	return weight;	
}

double General_Object::get_volume()
{
	return volume;	
}

string General_Object::get_name()
{
	return name;	
}

double General_Object::get_density()
{
	return weight/volume;	
}

#endif
