#pragma once
#include<iostream>

class Array
{
private:
	int*arr;
	int size;
	static constexpr int initvalue=0;
	
public:
	Array();
	~Array();
	Array(int size);
	Array(const Array&other);
	Array(int*arr, int size);
	void operator=(const Array&other) ;
	//the functions removes all the elements in the array
	//and set him to empty array
	void clear();
	//resize the array to _size
	void resize(int _size);
	//set all the values in the array to value
	void setAll(int value);
	int& operator[](int index) { return arr[index]; }
	int operator[](int index) const { return arr[index]; }
	//return a new array with the values between indexes [left,right]
	Array split(int left, int right)const;
	//return a new array ptr with the values between indexes[left, right]
	Array*splitPtr(int left, int right)const;
	int length()const { return size; }
	//prints the arr
	friend std::ostream& operator<<(std::ostream&, const Array&);
	//copy the b1,b2,...,bsize elements of B to A
	static void copy(int*A, int*B, int size);	
	void addLeft(int value, int howmany);

	void set(int index, int value);

	//math operators
	Array operator+(const Array&other);
	//long mul
	Array operator*(const Array&other)const;
	



};
std::ostream& operator<<(std::ostream&, const Array&);

