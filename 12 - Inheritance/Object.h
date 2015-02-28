#ifndef _OBJECT
#define _OBJECT

#include <string.h>
using std::string;

class Metric_Object
{
protected: 
	double weight; // GRAMS
	double volume;  // CUBIC CENTIMETRES
	string name;
public:
	virtual ~Metric_Object();
	Metric_Object() {}
	Metric_Object(double, double, string);
	virtual double get_weight(void);
	virtual double get_volume(void);
	string get_name(void);
	virtual double get_density(void);
};

class British_Object : public Metric_Object
{
public:
	British_Object() {}
	~British_Object() {}
	British_Object(double, double, string);	
	double get_weight(void) {return this->weight/453.6;} // POUNDS
	double get_volume(void) {return this->volume/16.4;}  // CUBIC INCHES
	double get_density(void) {return (this->weight/this->volume)*0.036;}// POUNDS PER CUBIC INCHES
};

British_Object::British_Object(double w, double v, string n)
{
	weight = w;
	volume = v;
	name = n;	
}

Metric_Object::Metric_Object(double w, double v, string n)
{
	weight = w;
	volume = v;
	name = n;	
}

Metric_Object::~Metric_Object() {}

double Metric_Object::get_weight()
{
	return weight;	
}

double Metric_Object::get_volume()
{
	return volume;	
}

string Metric_Object::get_name()
{
	return name;	
}

double Metric_Object::get_density()
{
	return weight/volume;	
}

#endif
