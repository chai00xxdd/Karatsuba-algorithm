#pragma once
#include"Array.h"
class Math
{
public:
	static void printWithOutLeadingZeros(const Array&other);
	static Array* addArrays(const Array&x, const Array&y);
	static void addArrayTo(Array&to, const Array&num, int from_right = 0);
	static void substractArrayFrom(Array&from, Array&arr);
	static void mulArrayByOneDigit(const Array&x, int digit, Array&res);
	static Array longMulArrays(const Array&x, const Array&y);
	static int findNumberStartIndex(const Array&x);
	static bool isSmallerThenTen(const Array&x);
	static void removeLeadingZeros(Array&arr);
	static void fixSizes(Array&x, Array&y);
	
private:
	static int moudlo(int num, int base);
	

};

