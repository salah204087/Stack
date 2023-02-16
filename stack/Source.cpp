#include <iostream>
using namespace std;
template <class t>
class StackArray
{
private:
	int top;
	t item[100];
public:
	StackArray()
	{
		top = -1;
	}
	void push(t element)
	{
		if (top >= 99)
			cout << "Stack is full" << endl;
		else
		{
			top++;
			item[top] = element;
		}
	}
	bool isempty()
	{
		return top < 0;
	}
	void pop()
	{
		if (isempty())
			cout << "Stack  is already empty" << endl;
		else
			top--;
	}
	void pop(t &element)
	{
		if (isempty())
			cout << "Stack is already empty" << endl;
		else
		{
			element = item[top];
			top--;
		}
			
	}
	void get_top(t& gettop)
	{
		if (isempty())
			cout << "Stack is empty" << endl;
		else
		{
			gettop = item[top];
			cout << gettop << endl;
		}

	}
	void print_stack()
	{
		cout << "[";
		for (int i = top; i >= 0; i--)
			cout << item[i] << " ";
		cout << "]" << endl;
	}
};


template <class t>
class StackLinked
{
private:
	struct node
	{
		t item;
		node *next;
	};
	node *top;
public:
	StackLinked()
	{
		top = NULL;
	}
	void push(t element)
	{
		node *newitem = new node;
		if (newitem == NULL)
			cout << "Stack push can not allocate memory" << endl;
		else
		{
			newitem->item = element;
			newitem->next = top;
			top = newitem;
		}
	}
	bool isempty()
	{
		return top == NULL;
	}
	void pop()
	{
		if (isempty())
			cout << "Stack is already empty" << endl;
		else
		{
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void pop(t&gettop)
	{
		if (isempty())
			cout << "Stack is already empty" << endl;
		else
		{
			gettop = top->item;
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void get_top(t& gettop)
	{
		if (isempty())
			cout << "Stack is already empty" << endl;
		else
		{
			gettop = top->item;
			cout << gettop << endl;
		}
	}
	void print_stack()
	{
		node* curr = top;
		cout << "[";
		while (curr!=NULL)
		{
			cout << curr->item<<" ";
			curr = curr->next;
		}
		cout << "]" << endl;
	}
};

int main()
{
	StackLinked <double>x;
	x.push(5.2);
	x.push(1.1);
	x.push(8.10);
	x.push(10);
	x.push(7.9);
	x.print_stack();
	x.pop();
	x.print_stack();

}