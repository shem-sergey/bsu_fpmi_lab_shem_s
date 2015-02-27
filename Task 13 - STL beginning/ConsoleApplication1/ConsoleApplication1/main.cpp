#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

template <class T>
void swap_min_max(T container)
{
	T::iterator i = container.begin();
	T::iterator max = container.begin();
	T::iterator min = container.begin();
	
	for(i;i != container.end(); i++)
	{
		if(*i > *max)
			max = i;
		if(*i < *min)
			min = i;
	}
//	cout << "Max: " << *max << ", min: " << *min << endl;
	auto temp = *min;
	*min = (*max);
	*max = temp;

	cout << "Swapped container:\n";
	for(i = container.begin();i != container.end(); i++)
		cout << *i << "\t";
	cout << endl;
}

int main()
{
	vector <int> container1(6);
	container1[0] = 1;
	container1[1] = 2;
	container1[2] = 3;
	container1[3] = 2;
	container1[4] = 1;
	container1[5] = 0;
	list <double> container2;
	container2.push_back(5.1);
	container2.push_back(6.2);
	container2.push_back(6.4);
	container2.push_back(7.6);

	vector<int>::iterator it;
	for(it = container1.begin(); it != container1.end(); it++)
		cout << *it << "\t";
	cout << endl;

	swap_min_max(container1);

	list<double>::iterator iter;
	for(iter = container2.begin(); iter != container2.end(); iter++)
		cout << *iter << "\t";
	cout << endl;
	swap_min_max(container2);

	system("PAUSE");
	return 0;
}