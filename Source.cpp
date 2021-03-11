#include<iostream>
#include"Array.h"
#include"INPUT.h"
#include"Math.h"
#include"Karatsuba.h"
#include<chrono>
#include<fstream>
#include <iomanip>
using namespace std;

void messureLongMul(std::ofstream&file, const Array&x, const Array&y);
void messureKarastubaRecursive(std::ofstream&file,const Array&x, const Array&y);
void messureKarastubaIterative(std::ofstream&file, const Array&x, const Array&y);
int main()
{
	
	Array x, y;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	int n = 100000;
	/*bool valid_input=INPUT::scanArrays(x, y);
	if (!valid_input)
	{
		cout << "wrong output"<<std::endl;
		return 0;
	}*/
	
	ofstream file("Measure.txt");
	x.resize(n);
	y.resize(n);
	x.setAll(9);
	y.setAll(9);
	//messureLongMul(file, x, y);
	messureKarastubaRecursive(file, x, y);
	messureKarastubaIterative(file, x, y);
	file.close();
	
}
void messureLongMul(std::ofstream&file, const Array&x, const Array&y)
{

	auto start = chrono::high_resolution_clock::now();
	//ios_base::sync_with_stdio(false);
	Array xy = Math::longMulArrays(x, y);
	ios_base::sync_with_stdio(false);
	auto end = chrono::high_resolution_clock::now();
	double time_taken =
		static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	time_taken *= 1e-9;
	file << "Time taken by function <long mul> is : " << fixed
		 << setprecision(9)<<time_taken;
	file << " sec" << endl;
	cout << "Long multiplication: x * y =";
	Math::printWithOutLeadingZeros(xy);

}
void messureKarastubaRecursive(std::ofstream&file, const Array&x, const Array&y)
{
	Array xy(2*x.length());
	auto start = chrono::high_resolution_clock::now();
	KaratsubaAlgorithem::karatsuba(x, y, xy);
	auto end = chrono::high_resolution_clock::now();
	double time_taken =
		static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	time_taken *= 1e-9;
	file << "Time taken by function <Karatusba recursive> is : " << fixed
		<< time_taken << setprecision(9);
	file << " sec" << endl;
	cout << "Karatsuba(recursive) : x * y =";
	Math::printWithOutLeadingZeros(xy);
}
void messureKarastubaIterative(std::ofstream&file, const Array&x, const Array&y)
{
	Array xy(2 * x.length());
	auto start = chrono::high_resolution_clock::now();
	//ios_base::sync_with_stdio(false);
	KaratsubaAlgorithem::karatsubaIterative(x, y, xy);
	auto end = chrono::high_resolution_clock::now();
	double time_taken =
		static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(end - start).count());
	time_taken *= 1e-9;
	file << "Time taken by function <KarastubeIterative> is : " << fixed
		<< time_taken << setprecision(9);
	file << " sec" << endl;
	std::cout << "Karatsuba (iterative): x * y =";
	Math::printWithOutLeadingZeros(xy);

}




