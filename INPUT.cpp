#include"INPUT.h"
#include<iostream>

namespace INPUT
{
	bool scanArrays(Array&x, Array&y)
	{
		int n;
		bool valid = true;
		std::string line,linex,liney;
		std::cin >> line;
		if (!isStringNumber(line)||line[0]=='0')
			return false;
		n = strToNumber(line);
		if (n <= 0)
		{
			return false;
		}
		std::cin >> linex;
		if (!isStringNumber(linex)||linex.length()!=n)
		{
			return false;
		}
		
		std::cin >> liney;
		if (!isStringNumber(liney)||liney.length()!=n)
		{
			return false;
		}
		x.resize(n);
		y.resize(n);
		for (int i = 0; i < n; i++)
		{
			x[i] = linex[i] - '0';
			y[i] = liney[i] - '0';
		}
		return true;
		

	}
	bool isStringNumber(const std::string& str)
	{
		bool valid = str.length() != 0;
		for (size_t i = 0; i < str.length() && valid; i++)
			if (!(str[i] >= '0'&&str[i] <= '9'))
				valid = false;
		return valid;
		

	}

	int strToNumber(const std::string& str)
	{
		bool neagtive = str.length() && str[0] == '-';
		size_t i = 0;
		if (neagtive)
			i = 1;
		int num = 0;
		for (; i < str.length(); i++)
			num = num * 10 + (str[i] - '0');
		if (neagtive)
			num *= -1;
		return num;
	}
	
}
