#include <iostream>
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
	return 0;
}
