#pragma once
#include"Array.h"
#include"Math.h"
class KarastubaStack
{

public:
	//dtors ctors
	KarastubaStack();
	~KarastubaStack();
	class ItemType//implented by pointers for better perfomance
	{
	public:
		const Array *x, *y;
		Array*xy;
		int phase;
		Array *a, *b, *c, *d;
		Array*asumb, *csumd;
		Array *ac, *bd;
		Array *AsumB_MUL_CsumD;
		ItemType() = delete;
		ItemType(const Array*x, const Array*y, Array*xy, int phase = 0);
		void createABCD();
		void release();
		void print();
	private:
		void fix();
	
	};
	//stack basic operations
	void push(const ItemType&item);
	 ItemType&top()const { return head->data; }
	void makeEmpty();
	ItemType pop();
	bool isEmpty()const { return head == nullptr; }
private:
	//stack implemnted by Linkedlist
	struct LNODE
	{
		ItemType data;
		LNODE*next;
	};
	LNODE*head;
	void removehead();

};

