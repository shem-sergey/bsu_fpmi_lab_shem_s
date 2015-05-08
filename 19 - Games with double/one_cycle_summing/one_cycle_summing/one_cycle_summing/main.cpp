#include <iostream>

using namespace std;

int main()
{
	int n;
	double x;
	cout << "Enter n:\n";
	cin >> n;
	cout << "Enter x:\n";
	cin >> x;
	double s = 0;
	int minus_one = 1, factorial = 1, multiplier;
	double x_in_power = 1;
	_asm
	{
		mov ecx, 1 //COUNTS BY M
		finit
cyc:
		mov eax, n
		inc eax
		sub eax, ecx // eax = n + 1 - i

		mov ebx, n
		inc ebx
		inc ebx
		sub ebx, ecx // ebx = n + 2 - i

		mul ebx //eax = (n + 1 - i)(n + 2 - i)
		xor edx, edx //just in case something bad is on
		mov ebx, 2
		div ebx // eax = multiplier
		mov multiplier, eax

		mov eax, minus_one
		mov ebx, -1
		imul ebx
		mov minus_one, eax //refreshing minus_one

		mov eax, factorial
		mul ecx
		mov factorial, eax //refreshing factorial

		fld x_in_power
		fmul x
		fmul x
		fstp x_in_power

		fld x_in_power
		fimul minus_one
		fimul multiplier
		fidiv factorial //IN STACK ONE ADDEND
		fadd s
		fstp s

		inc ecx
		cmp ecx, n
		jng cyc 
	}

	cout << "sum = " << s << endl;
	system("PAUSE");
	return 0;
}