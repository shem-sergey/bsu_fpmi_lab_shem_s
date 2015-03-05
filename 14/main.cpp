//#include <cstdlib>
#include <iostream>
//#include <string>
#include <vector>
//#include <cctype>
#include <algorithm>

using namespace std;

struct result 
{
	string name;
	int problems;
	int time;	
};

result get_result(char * c)
{
	result temp;
	temp.problems = 0;
	temp.time = 0;
	char word[strlen(c)-4];
	int counter = 0;
	while(*c != '-')
	{
		word[counter] = *c;
		counter++;
		c++;
	}
	temp.name.assign(word,counter); 
	c++;
	while(isdigit(*c))
	{
		temp.problems = temp.problems*10 + (*c - 48);		
		c++;
	}
	c++;
	while(isdigit(*c))
	{
		temp.time = temp.time*10 + (*c - 48);		
		c++;
	}
	return temp;
}

bool comparator(result a, result b)
{
	if(a.problems > b.problems)
		return true;
	if(a.problems < b.problems)
		return false;
	else
	{
		if(a.time < b.time)
			return true;
		if(a.time > b.time)
			return false;
		else return false;			
	}			
}

int main(int argc, char *argv[])
{
	vector<result> v;
	result temp;
	for(int i = 1; i < argc; i++)
	{
		temp = get_result(argv[i]);
		v.push_back(temp);
	}
	cout << "==================================================================\n";
	cout << "Inputed results:\n";
	cout << "==================================================================\n";
	for(int i = 1; i < argc; i++)
	{
		cout << v[i-1].name << endl;
		cout << v[i-1].problems << " problems solved" << endl;
		cout <<"In " << v[i-1].time << " minutes" << endl;
		cout << endl;
	}
	
	sort(v.begin(),v.end(),comparator);
	cout << "==================================================================\n";
	cout << "Sorted results:\n";
	cout << "==================================================================\n";
	for(int i = 1; i < argc; i++)
	{
		cout << v[i-1].name << endl;
		cout << v[i-1].problems << " problems solved" << endl;
		cout <<"In " << v[i-1].time << " minutes" << endl;
		cout << endl;
	}	
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
