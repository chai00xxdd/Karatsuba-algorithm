#pragma once
#include"Array.h"
#include"KarastubaStack.h"
class KaratsubaAlgorithem
{
public:

	//the function get two array nubmers x y and return the return of 
	//the the multipcation xy to the xy refernce using karastubaRecursive algoritehm
	static void karatsuba(const Array&x, const Array&y, Array&xy);
	//the function get two array nubmers x y and return the return of 
	//the the multipcation xy to the xy refernce using karastubaIterative algoritehm
	static void karatsubaIterative(const Array&x, const Array&y, Array&xy);
private:
	//the functions calculate the formula of karastuba algorithem
	static void calculateFormula(Array&ac, Array&mul_of_sums, Array&bd, int power, Array&res);
	
	
	
	
	

};

