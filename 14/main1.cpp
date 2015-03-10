#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<int, std::stack<int> > a;
	int i;
	for(i = 10; i > 0; i--)
	{
		a.push(i);
	}
	a.push(i);
	a.push(i);
	while(!a.empty())
	{
		cout << "Now minimal element is " << a.min() << endl;
		a.pop();	
	}	
	a.push(20);
	cout << "Now minimal element is " << a.min() << endl;
	a.push(11);
	cout << "Now minimal element is " << a.min() << endl;
	a.push(16);
	cout << "Now minimal element is " << a.min() << endl;
	while(!a.empty())
	{
		cout << "Now minimal element is " << a.min() << endl;
		a.pop();	
	}	
    system("PAUSE");
    return 0;
}
