#include <iostream>
#include <conio.h>
#include "Transport.h"
using namespace std;

int main()
{
	Transport city;
	city.add_stop("Independence avenue");
	city.add_stop("School");
	list<Transport::stop>::iterator start = city.get_empty_stops().first;
	list<Transport::stop>::iterator finish = city.get_empty_stops().second;
	cout << "STOPS WITHOUT ROUTES:\n"; 
	for(; start != finish; start++)
	{
		cout << start->stop_name << endl;
	}
	cout << "\nTOTAL AMOUNT OF STOPS:\n" << city.number_of_stops() << endl;
	cout << "\nTOTAL AMOUNT OF ROUTES:\n" << city.number_of_routes() << endl;

	list<Transport::stop> st1;
	st1.push_back(Transport::stop("University"));
	st1.push_back(Transport::stop("Kolasa square"));
	pair<list<Transport::stop>::iterator, list<Transport::stop>::iterator> temp_pair(st1.begin(), st1.end());
	city.add_route(BUS, 1, temp_pair);

	st1.clear();
	st1.push_back(Transport::stop("University"));
	st1.push_back(Transport::stop("Victory square"));
	st1.push_back(Transport::stop("Art Museum"));
	temp_pair = pair<list<Transport::stop>::iterator, list<Transport::stop>::iterator>(st1.begin(), st1.end());
	city.add_route(TRAM, 15, temp_pair);

	cout << "\nMOST POPULAR STOP:\n" << city.get_most_popular_stop() << endl;

	pair<list<pair<int, int> >::iterator, list<pair<int, int> >::iterator> temp_pair2;
	temp_pair2 = city.get_routes("University");
	cout << "\nROUTES GOING THROUGH \"University\":\n";
	for(auto i = temp_pair2.first; i != temp_pair2.second; ++i)
	{
		if(i->first == BUS)
			cout << "Bus route, number ";
		else if(i->first == TRAM)
			cout << "Tram route, number ";
		else if(i->first == TROLLEY)
			cout << "Trolley route, number ";
		else cout << i->first << "th type of transport, number ";
		cout << i->second << endl;
	}

	start = city.get_empty_stops().first;
	finish = city.get_empty_stops().second;
	cout << "\nSTOPS WITHOUT ROUTES:\n"; 
	for(; start != finish; start++)
	{
		cout << start->stop_name << endl;
	}

	city.erase_stop("School");
	start = city.get_empty_stops().first;
	finish = city.get_empty_stops().second;
	cout << "\nSTOPS WITHOUT ROUTES:\n"; 
	for(; start != finish; start++)
	{
		cout << start->stop_name << endl;
	}

	st1.clear();
	st1.push_back(Transport::stop("Victory square"));
	st1.push_back(Transport::stop("Art Museum"));
	st1.push_back(Transport::stop("Opera Theatre"));
	temp_pair = pair<list<Transport::stop>::iterator, list<Transport::stop>::iterator>(st1.begin(), st1.end());
	city.add_route(4, 37, temp_pair);

	st1.clear();
	st1.push_back(Transport::stop("Marketplace"));
	st1.push_back(Transport::stop("Kolasa Square"));
	st1.push_back(Transport::stop("Independence avenue"));
	temp_pair = pair<list<Transport::stop>::iterator, list<Transport::stop>::iterator>(st1.begin(), st1.end());
	city.add_route(4, 53, temp_pair);

	cout << "\nROUTES OF THE 4TH TYPE OF TRANSPORT WITH NUMBER FROM 1 TO 60:\n";
	auto t = city.get_route_numbers(1, 60, 4);
	for(auto it = t.first; it != t.second; ++it)
		cout << "4th type of transport, number " << *it << endl;

    cout << "Press any key to continue...";
    getch();
    return 0;
}
