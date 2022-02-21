#include<iostream>
using namespace std;

template <class T>
void swap(T a, T b)
{
	cout<<"Before swap:"<<a<<"\t"<<b<<endl;
	float temp;
	temp = a;
	a = b;
	b = temp;
	cout<<"Afer swap:"<<a<<"\t"<<b<<endl;
}

int main()
{
	swap<float>(1.222,2.333);
	return 0;
}