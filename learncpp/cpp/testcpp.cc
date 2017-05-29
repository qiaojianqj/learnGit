#include <iostream>
#include <numeric>
using namespace  std;

int main()
{
	int i = 1;
	cout<<i<<" "<<++i<<" "<<i++<<endl; //exe sequence is undefined
	cout<<"input value to accumulate"<<endl;
	istream_iterator<int> in(cin), eof;
	cout<<accumulate(in, eof, 0)<<endl;
	return 0;
}
