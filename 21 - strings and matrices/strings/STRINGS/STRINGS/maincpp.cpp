#include <iostream>

using namespace std;
/*
int main()
{
	char arra[100];
	int len, count = 0;
	char res = 0;
	cout << "Enter string:\n";
	cin >> arra;
	_asm
	{
		cld
		lea edi, arra[0]
		mov esi, edi
		mov ecx, 100000
		xor al, al
		repne scasb
		sub edi, esi
		dec edi
		mov len, edi

		xor eax, eax
cyc1:
		mov cl, arra[eax]
		cmp cl, 0
		je fin
		
		mov edx, eax

		push eax
		push ecx

		mov al, cl

		lea edi, arra[0] // +/- 1
		cld
		
		mov ecx, len
		          
		and edx, 0 //zf = 0
beg:
		repnz scasb
		jecxz skip1488

		jz counting
skip1488:		
		mov eax, count
		cmp eax, 1
		je prefin
		jmp preprefin

counting:	
		push eax
		mov eax, count
		inc eax
		mov count, eax
		pop eax
		jmp beg


preprefin:
		pop ecx
		pop eax
		mov count, 0
		
		inc eax
		jmp cyc1
prefin:
		mov res, al
		pop ecx
		pop eax
fin:
	}
	 cout << res << endl;
	system("PAUSE");
	return 0;
}*/


int main()
{
	char arra[100];
	int len, count = 0;
	char res = 0;
	cout << "Enter string:\n";
	cin >> arra;

	_asm
	{
		cld
		lea edi, arra[0]
		mov esi, edi
		mov ecx, 100000
		xor al, al
		repne scasb
		sub edi, esi
		dec edi
		mov len, edi

		xor eax, eax
cyc1:
		mov cl, arra[eax]
		cmp cl, 0
		je very_fin

		push eax
		push ecx
		cld
		mov al, cl
		mov ecx, len
		inc ecx ///???????????????????
		lea edi, arra
beg:
		and edx, 0
		repne scasb
		jecxz skip
		jz counting
skip:

		mov edx, count
		cmp edx, 1
		je prefin
		jmp fin

counting:
		mov edx, count
		inc edx
		mov count, edx
		cmp edx, 1
		jg fin
		jmp beg

fin:
		pop ecx
		pop eax
		mov count, 0
		inc eax
		jmp cyc1
		jmp very_fin
prefin:
		mov res, al
		pop ecx
		pop eax
very_fin:
	}
	cout << res << endl;
	system("PAUSE");
	return 0;
}