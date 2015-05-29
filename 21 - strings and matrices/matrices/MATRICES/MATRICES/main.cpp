#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int m[5][5];
	//cout << "Enter the width:\n";
	int w;
	w = 5;
	//cout << "Enter the height:\n";
	int h;
	h = 5;
	for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
			//cin >> m[j][i];
			m[j][i] = rand() % 14;

	for(int i = 0; i < h; ++i)
	{
		for(int j = 0; j < w; ++j)
			cout << m[i][j] << "  ";
		cout << endl;
	}

	int sum = 0;

	//C++ CODE:
	//for(int i = 0; i < h; ++i)
	//	for(int j = i; j < w; ++j)
	//		sum += m[j][i];
	
	_asm
	{
		mov ecx, h
cyc1:
		mov eax, w
		dec eax
cyc2:
		mov ebx, w

		//mov ebx, m[12]

		push eax
		mov eax, ecx
		mul ebx
		mov ebx, eax
		pop eax

		add ebx, eax

		mov edx, m[ebx * 4]

		add edx, sum
		mov sum, edx
		
		dec eax
		cmp eax, ecx
		jge cyc2
		
		loop cyc1

	}

	cout << sum << endl;

	system("PAUSE");
	return 0;
}