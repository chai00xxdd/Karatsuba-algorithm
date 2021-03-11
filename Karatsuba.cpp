#include "Karatsuba.h"
#include"Math.h"
 void KaratsubaAlgorithem::karatsuba(const Array&x, const Array&y, Array&xy)
{
	 int n = x.length(), power = n / 2 + n % 2;
	 
	if (n<=100)
	{
		
		xy = x*y;//long mul
		return;	
	}
	
	KarastubaStack::ItemType abcd(&x, &y, &xy);
	abcd.createABCD();
	karatsuba(*abcd.asumb, *abcd.csumd, *abcd.AsumB_MUL_CsumD);
	karatsuba(*abcd.a, *abcd.c, *abcd.ac);
	karatsuba(*abcd.b, *abcd.d, *abcd.bd);
	calculateFormula(*abcd.ac, *abcd.AsumB_MUL_CsumD, *abcd.bd, power, xy);
	abcd.release();//free Memory
	
	
}
 void KaratsubaAlgorithem::
calculateFormula(Array&ac, Array&mul_of_sums, Array&bd,int power, Array&res)
 {
	
	 Math::substractArrayFrom(mul_of_sums, ac);
	 Math::substractArrayFrom(mul_of_sums, bd);
	
	
	 Math::addArrayTo(res, ac,power*2);
	 Math::addArrayTo(res, mul_of_sums,power);
	 Math::addArrayTo(res, bd);
	
	
 }
 

void KaratsubaAlgorithem::karatsubaIterative(const Array&x, const Array&y, Array&xy)
{
	KarastubaStack s;
	xy.setAll(0);
	KarastubaStack::ItemType current = { &x,&y,&xy,0 };
	int returnFromRecursion = 0;
	bool first = true;

	while (!s.isEmpty() || first)
	{
		first = false;
		if (returnFromRecursion == 1)
		{
			current = s.pop();
		}
		int n = current.x->length();
		int power = n / 2 + n % 2;
    
		if (n<=100)//stop condition
		{
			*current.xy = Math::longMulArrays(*current.x, *current.y);
			returnFromRecursion = 1;
		}
		else
		{
			returnFromRecursion = 0;
			if (current.phase == 0)//CALLING AC RECURSION
			{

				current.phase = 1;
				current.createABCD();
				s.push(current);
				current = { current.a,current.c,s.top().ac,0 };

			}
			else if (current.phase == 1)//CALLIND BD RECURSION
			{
				current.phase = 2;
				s.push(current);
				current = { current.b,current.d,s.top().bd,0};
			}
			else if (current.phase == 2)//CALLING (a+b)(c+d) recursoin 
			{

				current.phase = 3;
				s.push(current);
				current = { current.asumb,current.csumd,s.top().AsumB_MUL_CsumD,0 };

			}
			else if (current.phase == 3)//CALCULATING ALL THETA(N)
			{
				KaratsubaAlgorithem::calculateFormula
				(*current.ac, *current.AsumB_MUL_CsumD, *current.bd, power, *current.xy);
				current.release();//free all the pointers
				returnFromRecursion = 1;


			}
		}
	}

}

 