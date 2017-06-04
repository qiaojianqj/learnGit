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

	return 0;
}
