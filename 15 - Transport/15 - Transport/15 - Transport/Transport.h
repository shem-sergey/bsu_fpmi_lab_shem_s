#ifndef _TRANSPORT
#define _TRNASPORT
#include <list>
#include <map>
#include <string>
#include <utility>

const int BUS = 0, TROLLEY = 1, TRAM = 2;

class Transport
{
public:
    struct stop
    {
         std::string stop_name;  
         std::list<std::pair<int, int> > stop_route_numbers;     //FIRST ARGUMENT CAN BE T  // NUMBER - TYPE
         stop(){}
         stop(std::string t):stop_name(t){}
		 bool operator==(stop a) {return (stop_name == a.stop_name);}
    };    
    struct Route
    {
         int route_number;         //CAN BE T
         int transort_type;
         std::list<stop> stops;    
    };
private:        
    std::list<Route> routes;
    std::list<stop> stops;
	std::list<int> route_numbers; //CAN BE T
public:
	void add_stop(std::string);
	int number_of_routes();
	int number_of_stops();
	
	void erase_route(int, int);  //FIRST ARGUMENT CAN BE T 
	void add_route(int, int, std::pair<std::list<stop>::iterator, std::list<stop>::iterator>);  //SECOND ARGUMENT CAN BE T
	void erase_stop(std::string);
	std::pair<std::list<std::pair<int, int> >::iterator, std::list<std::pair<int, int> >::iterator> get_routes(std::string);
	std::pair< std::list<stop>::iterator,  std::list<stop>::iterator> get_empty_stops();  
	std::string get_most_popular_stop();
	std::pair<std::list<int>::iterator, std::list<int>::iterator> get_route_numbers(int, int, int);//CAN BE T
};

#endif
