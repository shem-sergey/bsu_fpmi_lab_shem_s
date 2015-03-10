#ifndef _MY_STACK
#define _MY_STACK
#include <stack>
#include <iostream>
template<class T, class C = std::stack<T> > class Stack
{
public:	
	//types
	typedef T value_type;
	
private:
	//fields
	C min_st;
	C st;
public:		
	//stack functions
	bool empty(void) {return st.empty();}
	int size(void) {return st.size();}
	value_type & top() {return st.top();}
	void push(const value_type &);
	void pop(void);	
	value_type & min(void)
	{
	try
	{
		if(!min_st.empty())
			return min_st.top();
		else
			throw 1;
	}		
		catch(int a)
		{
			printf("Stack is empty. Can't find minimal.\n");
		}
	}
};

template<class T, class C>
void Stack<T, C>::push(const value_type & obj)
{
	if(min_st.empty() || obj < min_st.top() || obj == min_st.top())
		min_st.push(obj);	
	st.push(obj);
}

template<class T, class C>
void Stack<T, C>::pop()
{
	if(st.top() == min_st.top())
		min_st.pop();
	st.pop();	
}

#endif
