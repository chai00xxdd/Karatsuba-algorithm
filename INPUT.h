#pragma once
#include"Array.h"
#include<string>
namespace INPUT
{
	//the function get two numbers x y in the same length n
	//if failed return false
	bool scanArrays(Array&x, Array&y);
	//the function get a string and return true 
	// <-----> s is a un neagtive number all digits in range [0,9]
	bool isStringNumber(const std::string&);
	//the function get a number string and convert it to int
	int strToNumber(const std::string&);

}