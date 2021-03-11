#include "KarastubaStack.h"


KarastubaStack::KarastubaStack()
	:head(nullptr)
{

}
KarastubaStack::~KarastubaStack()
{
	makeEmpty();
}
void KarastubaStack::makeEmpty()
{
	LNODE*next;
	while (head)
	{
		next = head->next;
		delete head;
		head = next;
	};
	head = nullptr;
}

void KarastubaStack::push(const ItemType&item)
{
	head = new LNODE{ item,head };
}

 KarastubaStack::ItemType KarastubaStack::pop()
{
	 ItemType data = head->data;
	 removehead();
	 return data;

}
 void KarastubaStack::removehead()
 {
	 if (head != nullptr)
	 {
		 LNODE*next = head->next;
		 delete head;
		 head = next;
	 }
 }

 //ItemType class

 KarastubaStack::ItemType::ItemType (const Array*x, const Array*y, Array*xy, int phase)
	 :x(x), y(y), xy(xy), phase(phase), a(nullptr), b(nullptr), c(nullptr)
	 , d(nullptr), asumb(nullptr), csumd(nullptr), ac(nullptr), bd(nullptr)
	 , AsumB_MUL_CsumD(nullptr)
 {

 }
 void KarastubaStack::ItemType::createABCD()
 {

	 int n = x->length();
	 int lower = n / 2;
	 int upper = lower + n % 2;
	 a = x->splitPtr(0, lower - 1);
	 b = x->splitPtr(lower, n - 1);
	 c = y->splitPtr(0, lower - 1);
	 d = y->splitPtr(lower, n - 1);
	 asumb = Math::addArrays(*a, *b);
	 csumd = Math::addArrays(*c, *d);
	 if(n<=3)
		 fix();
	 ac = new Array(a->length() * 2);
	 bd = new Array(2*b->length());
	 AsumB_MUL_CsumD = new Array(2*asumb->length());

 }
 void KarastubaStack::ItemType::fix()
 {
	 Math::fixSizes(*asumb, *csumd);

 }
 void KarastubaStack::ItemType::release()
 {
	 Array*arrays[] = { a,b,c,d,asumb,csumd,ac,bd,AsumB_MUL_CsumD };
	 for (int i = 0; i < sizeof(arrays) / sizeof(Array*); i++)
		 if (arrays[i])
			 delete arrays[i];
 }
 void KarastubaStack::ItemType::print()
 {
	 std::cout << "x=" << *x<<std::endl;
	 std::cout << "y=" << *y << std::endl;
	 std::cout << "a=" << *a << std::endl;
	 std::cout << "b=" << *b << std::endl;
	 std::cout << "c=" << *c << std::endl;
	 std::cout << "d=" << *d << std::endl;
	 std::cout << "a+b=" << *asumb << std::endl;
	 std::cout << "c+d=" << *csumd << std::endl;
	 std::cout << "(a+b)(c+d)=" << *AsumB_MUL_CsumD << std::endl;
 }