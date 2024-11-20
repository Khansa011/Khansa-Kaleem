#include<iostream>
using namespace std;

 // Function Defination
 void passByvalue(int num)
 {
 	num=num+10; //Modify the value
 	cout<<"inside function (pass by value):"<<num<<endl;
 }	
	
int main()	
{
	int number=5;
	cout<<"before function call:"<<number<<endl;
	passByvalue(number);//passing the value
	cout<<"After function call:"<<number<<endl;
	return 0;
}	
	