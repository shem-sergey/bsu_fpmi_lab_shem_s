#include "Transport.h"

void Transport::add_stop(std::string name)
{
	bool no_such_stop = true;
	for(auto it = stops.begin(); it != stops.end(); ++it)
		if(it->stop_name == name)
				no_such_stop = false;
	if(no_such_stop)
		stops.push_back(stop(name));
}

int Transport::number_of_routes()
{
	return routes.size();	
}

int Transport::number_of_stops()
{
	return stops.size();	
}

void Transport::erase_route(int number, int type)   //CAN BE T
{
	auto it = routes.begin();
	for(it; it != routes.end(); ++it)
		if(it->route_number == number && it->transort_type == type)
			it = routes.erase(it);	
	for(auto it = stops.begin(); it != stops.end(); ++it)
		for(auto it1 = it->stop_route_numbers.begin(); it1 != it->stop_route_numbers.end(); ++it1)
		{
			if(it1->first == number && it1->second == type) 
				it1 = it->stop_route_numbers.erase(it1);
		}
	//WRITE DELETING ROUTES FROM EVERY PARTICULAR STOP
}

void Transport::add_route(int number, int type, std::pair<std::list<stop>::iterator, std::list<stop>::iterator> Stops) //CAN BE T
{
	bool no_such_stop1 = true;
	for(auto it = routes.begin(); it != routes.end(); ++it)
		if(it->route_number == number && it->transort_type == type)
				no_such_stop1 = false;
	if(no_such_stop1)
	{
		Route temp;
		temp.route_number = number;
		temp.transort_type = type;
		auto begin = Stops.first;
		auto end = Stops.second;
		for(; begin != end; begin++)
		{
			bool no_such_stop = true;
			for(auto it = stops.begin(); it != stops.end(); ++it)
				if(*it == *begin)
				{
					it->stop_route_numbers.push_back(std::pair<int, int>(number, type));
					no_such_stop = false;
				}
			if(no_such_stop)
			{
				begin->stop_route_numbers.push_back(std::pair<int, int>(number, type));
				stops.push_back(*begin);
			}
			temp.stops.push_back(*begin);
		}
		routes.push_back(temp);
	}
}

void Transport::erase_stop(std::string name)
{
	for(auto it = stops.begin(); it != stops.end(); ++it)
		if(it->stop_name == name)
			it = stops.erase(it);
	for(auto it = routes.begin(); it != routes.end(); ++it)
	{
		for(auto it1 = it->stops.begin(); it1 != it->stops.begin(); ++it1)
		{
			if(it1->stop_name == name && it->stops.size() == 1)
				it = routes.erase(it);
			else if (it1->stop_name == name)
				it1 = it->stops.erase(it1);
		}	
	}
}

std::pair<std::list<std::pair<int, int> >::iterator, std::list<std::pair<int, int> >::iterator> Transport::get_routes(std::string name)    //RETURNES PAIR OF ITERATORS OF VECTOR, THAT CONTAINS PAIRS <NUMBER_OF_ROUTE, TYPE_OF_ROUTE>
{
	for(auto it = stops.begin(); it != stops.end(); ++it)
		if(it->stop_name == name)
			return std::pair<std::list<std::pair<int, int> >::iterator, std::list<std::pair<int, int> >::iterator>(it->stop_route_numbers.begin(), it->stop_route_numbers.end());
}

bool less_routes(Transport::stop & i, Transport::stop & j)
{
	return i.stop_route_numbers.size() < j.stop_route_numbers.size();
}

std::pair< std::list<Transport::stop>::iterator,  std::list<Transport::stop>::iterator> Transport::get_empty_stops()
{
	std::pair< std::list<Transport::stop>::iterator,  std::list<Transport::stop>::iterator> temp;
	stops.sort(less_routes);
	temp.first = stops.begin();
	auto it = stops.begin();
	for(it; it != stops.end(); ++it)
	{
		if(it->stop_route_numbers.size()==1)
			break;
	}
	std::list<Transport::stop>::iterator t(it);
	temp.second = t;
	return temp;
}

std::string Transport::get_most_popular_stop()
{
	stops.sort(less_routes);
	std::list<stop>::iterator t = stops.end();
	t--;
	return t->stop_name;
}

bool number_is_less(Transport::Route i, Transport::Route j)
{
	return i.route_number < j.route_number;
}

std::pair<std::list<int>::iterator, std::list<int>::iterator> Transport::get_route_numbers(int X, int Y, int type) 
{
	route_numbers.clear();
	routes.sort(number_is_less);
	for(auto it = routes.begin(); it != routes.end(); ++it)
	{
		if((it->transort_type >= X) && (it->transort_type <= Y) && it->route_number == type)
			route_numbers.push_back(it->transort_type);
	}
	return std::pair<std::list<int>::iterator, std::list<int>::iterator>(route_numbers.begin(), route_numbers.end());
}