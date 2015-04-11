#include <iostream>
#include <thread>
#include <chrono>
#include <climits>
#include <vector>
#include <utility>
#include <queue>
#include <mutex>

using namespace std;

struct piece
{
	int begin, end;
};

queue<piece> q;
double PI = 3;
mutex MUTEX;

void calculate(int begin, int end)
{
	double sum = 0;
	for(unsigned long long int i = begin; i < end; ++i)
	{
		sum = sum + 4./((4.*i+2)*(4.*i+3)*(4.*i+4)) - 4./((4.*i+4)*(4.*i+5)*(4.*i+6));
	}
	cout << "sum = " << sum << endl;
	MUTEX.lock();
	PI = PI + sum;
	MUTEX.unlock();
}

void calc()
{
	while(!q.empty())
	{
		piece tmp;
		MUTEX.lock();
		tmp = q.back();
		q.pop();
		MUTEX.unlock();
		calculate(tmp.begin, tmp.end);
	}
}

int main()
{
	cout << "Enter the number of threads:\n";
	short threads;
	cin >> threads;

	piece temp;
	for(int i = 0; i < 1; ++i)
	{
		temp.begin = i * 1000000;
		temp.end = (i + 1) * 1000000;
		q.push(temp);
	}

	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	std::thread *THR = new std::thread [threads];


	for(int i = 0; i < threads; i++)
		THR[i] = std::thread(calc);
	for(int i = 0; i<threads; i++)
		THR[i].join();

	cout.precision(16);
	cout << PI << endl;   
	cout << "3,14159265358979 3238462643383279 502\n";

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_result = end - start;
	std::cout << time_result.count() <<" seconds\n";
	system("PAUSE");
	return 0;
}
