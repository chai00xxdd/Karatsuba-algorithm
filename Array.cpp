#include "Array.h"
#include<iostream>
#include"Math.h"


//ctors dtors
Array::Array(int size)
	:size(size), arr(size <= 0 ? nullptr : new int[size] {0})
{
	
	
}
Array::Array(int*arr, int size)
	: size(size)
{
	if (size)
	{
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
			this->arr[i] = arr[i];
	}

}
Array::Array()
	:Array(0)
{

}
Array::Array(const Array&other)
	: Array(0)
{
	*this = other;
}
Array::~Array()
{
	
	clear();

}




void Array::resize(int _size)
{
	if (_size == size)
		return;
	if (_size == 0)
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
		return;
    }
	int*resized_arr = new int[_size] {0};
  int elementsToCopy = size < _size ? size : _size;
  copy(resized_arr, arr,elementsToCopy);
  
  delete[] arr;
  arr = resized_arr;
  size = _size;
}
void Array::setAll(int value)
{
	for (int i = 0; i < length(); i++)
		arr[i] = value;

}
void Array::addLeft(int value, int howmany)
{
	int oldsize = length()-1;
	resize(length() + howmany);
	for (int i =oldsize; i>=0; i--)
	{
		arr[i + howmany] = arr[i];
	}
	for (int i = 0; i < howmany; i++)
		arr[i] = 0;
	
}
Array*Array::splitPtr(int left, int right)const
{
	int split_size = right - left + 1;
	Array *split_arr = new Array(split_size);
	copy(split_arr->arr, arr + left, split_size);
	return split_arr;
}
Array Array::split(int left, int right)const
{
	int split_size = right - left + 1;
	Array split_arr(split_size);
	copy(split_arr.arr, arr + left, split_size );
	return split_arr;
}
void Array::clear()
{
	if(arr)
	delete[] arr;
	arr = nullptr;
	size = 0;
}


//operators
Array Array::operator+(const Array&a)
{
	Array*sum= Math::addArrays(*this, a);
	Array returnSum = *sum;
	delete sum;
	return returnSum;
}
Array Array::operator*(const Array&other)const
{
	return Math::longMulArrays(*this, other);
}
std::ostream& operator<<(std::ostream&out, const Array&arr)
{
	for (int i = 0; i < arr.length(); i++)
		out << arr[i];
	return out;
}
void Array::operator=(const Array&other)
{
	if (this == &other)
	{
		return;
	}
	clear();
	size = other.size;
	if (size)
	{
		arr = new int[size];
		copy(arr, other.arr, size);
	}
}

//static functions
void Array::copy(int*A, int*B, int size)
{
	for (int i = 0; i < size; i++)
		A[i] = B[i];
}






