#include "Math.h"
//public

void Math::printWithOutLeadingZeros(const Array&other)
{
	bool passed_leading_zeros = false;
	for (int i = 0; i < other.length(); i++)
	{
		if (other[i] != 0 || passed_leading_zeros)
		{
			std::cout << other[i];
			passed_leading_zeros = true;
		}
	}
	if (!passed_leading_zeros&&other.length())
		std::cout << "0" << std::endl;
	std::cout << std::endl;
}

void Math::substractArrayFrom(Array&from, Array&arr)
{
	int carry = 0, next_carry;
	int from_index = from.length() - 1;
	
	for (int index = arr.length() - 1; index >= 0&&from_index>=0; index--, from_index--)
	{

		next_carry = (from[from_index] - arr[index] + carry) < 0 ? -1 : 0;
		from[from_index] = moudlo(from[from_index] - arr[index] + carry, 10);
		carry = next_carry;

	}
	while (carry&&from_index >= 0)
	{
		next_carry = (from[from_index] + carry) < 0 ? -1 : 0;
		from[from_index] = moudlo(from[from_index] + carry, 10);
		carry = next_carry;
		from_index--;

	}
	
}
Array* Math::addArrays(const Array&num1, const Array&num2)
{
	int maxSize = num1.length() > num2.length() ? num1.length() : num2.length();
	Array *num1_plus_num2= new Array(1 + maxSize);
	addArrayTo(*num1_plus_num2, num1);
	addArrayTo(*num1_plus_num2, num2);
	
		
	return num1_plus_num2;

}
void Math::addArrayTo(Array&to, const Array&num, int from_right)
{
	int carry = 0, next_carry;
	int to_index = to.length() - 1 - from_right;
	for (int num_index = num.length() - 1; num_index >= 0&&to_index>=0; num_index--)
	{


		next_carry = (to[to_index] + num[num_index] + carry) / 10;
		to[to_index] = (to[to_index] + num[num_index] + carry) % 10;
		carry = next_carry;
		to_index--;
	}

	while (carry&&to_index >= 0)
	{

		next_carry = (to[to_index] + carry) / 10;
		to[to_index] = (to[to_index] + carry) % 10;
		carry = next_carry;
		to_index--;
	}
	

}

void Math::mulArrayByOneDigit(const Array&x, int digit, Array&res)
{
	int carry = 0, next_carry, x_digit;
	for (int x_digit_index = x.length() - 1; x_digit_index >= 0; x_digit_index--)
	{
		x_digit = x[x_digit_index];
		next_carry = (x_digit*digit + carry) / 10;
		res[x_digit_index + 1] = (x_digit*digit + carry) % 10;
		carry = next_carry;
	}
	res[0] = carry;
}
Array Math::longMulArrays(const Array&x, const Array&y)
{
	Array res(x.length() + y.length());
	int add_from_right_index = 0;
	Array y_mul_digit(y.length() + 1);
	for (int x_index = x.length() - 1; x_index >= 0; x_index--)
	{
		mulArrayByOneDigit(y, x[x_index], y_mul_digit);
		addArrayTo(res, y_mul_digit, add_from_right_index++);
	}

	return res;
}
 int Math::findNumberStartIndex(const Array&x)
{
	 for (int i = 0; i < x.length(); i++)
		 if (x[i] != 0)
			 return i;
	 return x.length()-1;

}
  bool Math::isSmallerThenTen(const Array&x)
 {
	 for (int i = 0; i < x.length() - 1; i++)
		 if (x[i] != 0)
			 return false;
	 return x[x.length() - 1] < 10;
 }

//private
 int Math::moudlo(int num, int base)
{
	 while (num < 0)
		 num += base;
	 return num;

}

  void Math::removeLeadingZeros(Array&arr)
 {
	  int farestZero =-1;
	  for (int i = 0; i < arr.length() - 1; i++)
		  if (arr[i] == 0)
			  farestZero = i;
		  else break;
	  int howManyZeros = farestZero + 1;
	  if (howManyZeros)
	  {

		  for (int i = farestZero + 1; i < arr.length(); i++)
			  arr[i - howManyZeros] = arr[i];
		  arr.resize(arr.length() - howManyZeros);
	  }

 }
   void Math::fixSizes(Array&x, Array&y)
  {
	   removeLeadingZeros(x);
	   removeLeadingZeros(y);
	   if (x.length() == y.length())
		   return;
	   Array*max, *min;
	   if (x.length() > y.length())
	   {
		   max = &x;
		   min = &y;
	   }
	   else
	   {
		   max = &y;
		   min = &x;
	   }
	   int howManyZeros = max->length() - min->length();
	   min->addLeft(0, howManyZeros);
  }

