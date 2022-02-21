#include<iostream>
using namespace std;

template <class T>
void swap(T a, T b)
{
	cout<<"Before swap:"<<a<<"\t"<<b<<endl;
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout<<"Afer swap:"<<a<<"\t"<<b<<endl;
}

int main()
{
	swap<float>(1.2,2.3);
	return 0;
}