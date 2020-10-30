#include <iostream>
#include <cstring>
#include <iterator>
#include <numeric>
#include <vector>

typedef int UINT4;

using namespace  std;

class Hack{};

Hack& operator< (Hack &a, Hack &b)
{
	cerr<<"error in <"<<endl;
	return a;
}

Hack& operator> (Hack &a, Hack &b)
{
	cerr<<"error in >"<<endl;
	return a;
}

class Rational{
	public:
		Rational(int, int);
		Rational(const Rational&);
		~Rational();
		const Rational& operator=(const Rational&);
		int Getnumerator() const
		{
			return numerator;
		}
		int Getdenominator() const
		{
			return denominator;
		}
	private:
		int numerator;
		int denominator;
};

Rational::Rational(int nu, int de):numerator(nu), denominator(de)
{
	cout<<"Constructor..."<<endl;
}

Rational::Rational(const Rational &ra):numerator(ra.numerator), denominator(ra.denominator)
{
	cout<<"Copy Constructor..."<<endl;
}

Rational::~Rational()
{
	cout<<"Destructor..."<<endl;
}

const Rational& Rational::operator=(const Rational& ra)
{
	cout<<"Assign Operator=..."<<endl;
	numerator = ra.numerator;
	denominator = ra.Getdenominator();
	return *this;
}


const Rational operator*(const Rational &one, const Rational &another)
{
	return Rational(one.Getnumerator() * another.Getnumerator(), one.Getdenominator() * another.Getdenominator());
	//4. 0x7fff5fbffa50 Constructor
	//gcc会对此作返回值优化ROV(Return Value Optimization)，不会有5这步Copy Constructor
	//编译时加上-fno-elide-constructors选项可以禁用ROV，则会有5这步Copy Constructor
	//5. 0x7fff5fbffb20 Copy Constructor
}
	//6. 0x7fff5fbffa50 Destructor

//非类型模版参数：常量值
template<unsigned int N, unsigned M>
int compare(const char (&p1) [N], const char (&p2) [M])
{
	return strcmp(p1, p2);
}

int main()
{
	int i = 1;
	cout<<i<<" "<<++i<<" "<<i++<<endl; //exe sequence is undefined

	cout<<"input value to accumulate"<<endl;
	istream_iterator<int> in(cin), eof;
	cout<<accumulate(in, eof, 0)<<endl;

	Hack vector; //vector is not a C++ keyword
	Hack UINT4;
	Hack foo;
	vector<UINT4> foo;

	cout<<compare("Hi", "Hello")<<endl;

	//stl string copy on write
	string str1 = "hello world";
	string str2 = str1;

	cout<<"Sharing the memory:"<<endl;
	cout<<"str1's address: "<<static_cast<const void*>(str1.c_str())<<endl;
	cout<<"str2's address: "<<static_cast<const void*>(str2.c_str())<<endl;

	str1[1]='q';
	str2[1]='w';

	cout<<"After Copy-On-Write:"<<endl;
	cout<<"str1's address: "<<static_cast<const void*>(str1.c_str())<<endl;
	cout<<"str2's address: "<<static_cast<const void*>(str2.c_str())<<endl;

	Rational ra(1, 2); 					//1. 0x7fff5fbffaa0 Constructor
	Rational rb(ra);   					//2. 0x7fff5fbffa90 Copy Constructor
	Rational rc(3, 4); 					//3. 0x7fff5fbffa80 Constructor
	rc = ra*rb;	  		 				//7. 0x7fff5fbffa80 Assign Operator
										//8. 0x7fff5fbffb20 Destructor
	return 0;
										 //9. 0x7fff5fbffa80 Destructor
										 //10.0x7fff5fbffa90 Destructor
										 //11.0x7fff5fbffaa0 Destructor
}
