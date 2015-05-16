	#include <iostream>

	using namespace std;

	int main()
	{
	cout << "Enter the amount\n";
	int amnt;
	cin >> amnt;
	//int * arra = new int[amnt];

	int arra[100];
	cout << "Enter the array:\n";

	for(int i = 0; i < amnt; i++)
		cin >> arra[i];

	int pivot, left_border, right_border;
	int pushed = 0;

	_asm
	{
		xor eax, eax //move left to eax
		mov edx, amnt
		dec edx // move right to edx

strt:
		mov right_border, edx
		mov left_border, eax
		mov ebx, eax
		inc ebx
		cmp edx, ebx
		jg not_two
		mov ebx, arra[4 * eax]
		cmp ebx, arra[4 * edx]
		jng skip1
		push arra[4 * eax]
		mov ebx, arra[4 * edx]
		mov arra[4 * eax], ebx
		pop arra[4 * edx]
		jmp skip1

		//SOMEWHERE HERE BEGINNING OF CYCLE
not_two:
		mov ebx, arra[4 * eax]  //ebx = pivot
		mov pivot, ebx // WE HAVE PIVOT
		//mov eax, left_border // eax = left
		//mov edx, right_border  //edx = right

splitpnt:
	
	incl:
		inc eax
		cmp eax, edx
		jnl endinc
		cmp arra[4 * eax], ebx //cmp arra[left] with pivot
		jng incl  //AFTER CYCLE WE GOT EAX - POINTER TO ELEMENT GREATER OR LESS THAN PIVOT
  
		inc edx
	decr:
		dec edx
		cmp eax, edx
		jnl endinc
		cmp arra[4 * edx], ebx
		jnl decr //AFTER CYCLE WE GOT EDX - POINTER TO ELEMENT LESS OR EQUAL THAN PIVOT

		push arra[4 * eax] //SWAP ARRA[EAX] AND ARRA[EDX]
		mov esi, arra[4 * edx]
		mov arra[4 * eax], esi
		pop arra[4 * edx]
		jmp splitpnt
		
endinc:
		mov ebx, left_border
		inc ebx
		cmp eax, ebx
		je skip1
		mov eax, left_border
		mov ebx, pivot
		cmp ebx, arra[4 * edx]
		jg skip
		dec edx //edx--
skip:
		push arra[4 * eax] //SWAP ARRA[left_border] = pivot AND ARRA[EDX]
		mov ebx, arra[4 * edx]
		mov arra[4 * eax], ebx
		pop arra[4 * edx]
		
skip1:
		mov ebx, right_border
		dec ebx
 		cmp left_border, ebx  //IF THE LENGTH OF PART IS 2
		jne lngth_more_two

		push right_border
		inc pushed
		jmp end_cyc

lngth_more_two:
		push right_border
		inc pushed

		mov ebx, right_border //CHECK IF EDX == RIGHT_BORDER
		cmp ebx, edx
		je skip2
		push edx
		inc pushed
skip2:

		push left_border
		inc pushed
end_cyc:
		cmp pushed, 1
		je fin

		pop eax
		dec pushed
		pop edx
		dec pushed
		jmp strt
fin:
		pop eax
	}
	for(int i = 0; i < amnt; ++i)
		cout << arra[i] << "  ";
	cout << endl;
	system("PAUSE");
	return 0;
	}