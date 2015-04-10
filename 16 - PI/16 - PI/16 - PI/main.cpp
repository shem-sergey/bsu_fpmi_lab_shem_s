#include <iostream>
#include <thread>
#include <chrono>
#include <climits>
#include <vector>

using namespace std;

double* results;


void calculate( unsigned long long int low_bound, unsigned long long int up_bound, int num)
{
	double sum = 0;
	for(unsigned long long int i = low_bound; i < up_bound; ++i)
	{
		sum = sum + 4./((4.*i+2)*(4.*i+3)*(4.*i+4)) - 4./((4.*i+4)*(4.*i+5)*(4.*i+6));
	}
	results[num] = sum; 
}

int main()
{
	cout << "Enter the number of threads:\n";
	short threads;
	cin >> threads;

	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();
	
	results = new double[threads];
	vector<unsigned long long int> iterations;
	unsigned long long int segment = 12000000 / threads, temp;
	for(short i = 0; i <= threads; ++i)
	{
		temp = i * segment;
		iterations.push_back(temp);
	}

	std::thread *THR = new std::thread [threads];


	for(int i = 0; i < threads; i++)
		THR[i] = std::thread(calculate, iterations[i], iterations[i+1], i);
	for(int i = 0; i<threads; i++)
		THR[i].join();

	double PI = 3;
	for(int i = 0; i < threads; ++i)
		PI += results[i];

	cout.precision(30);
	cout << PI << endl;   
	cout << "3,141592653589793 238462643383279 502\n";

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_result = end - start;
	std::cout << time_result.count() <<" seconds\n";
	system("PAUSE");
	return 0;
}
