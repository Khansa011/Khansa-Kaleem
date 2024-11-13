#include<iostream>
using namespace std;
int main()
{
int arr[5]={2,3,5,6,7};	
int sum=0;
cout<<"Elements of the array are:";
for (int i=0;i<5;i++)
{
	
	cout<<arr[i]<<"";
	sum+=arr[i];
	
}
cout<<"\nsum"<<sum<<endl;
cout<<endl;	
	return 0;
}