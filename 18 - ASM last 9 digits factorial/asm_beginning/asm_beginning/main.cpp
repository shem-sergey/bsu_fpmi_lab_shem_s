#include <iostream>

using namespace std;

int main()
{
	int num, res = 1, i = 1;
	cout << "Enter your number:\n";
	cin >> num;	
	_asm
	{
		cmp num, 44
		jg zer

		mov eax, 1
		xor edx, edx
		mov ecx, 1000000000
		mov ebx, num
cyc:
		mov ecx, 1000000000
//		xor edx, edx
		div ecx
		mov eax, edx
		mul i  
 		inc i
		cmp ebx, i
		jl eloop
		loop cyc
eloop:
	
		div ecx
		mov res, edx
		jmp me
zer:
		mov res, 0
me:
}
	cout << "Last 9 digits of it's factorial are " << res << endl;
	system("PAUSE");
	return 0;
}