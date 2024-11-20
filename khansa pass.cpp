#include<iostream>
using namespace std;

 // Function Defination
 void passByvalue(int num)
 {
 	num=num+10; //Modify the value
 	cout<<"inside function (pass by value):"<<num<<endl;
 }	
  void mult(int mul)
 {
 	mul=mul*10; //Modify the value
 	cout<<"inside function (pass by value):"<<mul<<endl;
 }	
  void subt(int sub)
 {
 	sub=sub-10; //Modify the value
 	cout<<"inside function (pass by value):"<<sub<<endl;
 }	
 
	
int main()	
{
	int number=5,multiply=2,subtraction=3;
	cout<<"before function call:"<<number<<endl;
	passByvalue(number);//passing the value
	cout<<"After function call:"<<number<<endl;
	cout<<"before function call:"<<multiply<<endl;
	mult(multiply);//passing the value
	cout<<"After function call:"<<multiply<<endl;
	cout<<"before function call:"<<subtraction<<endl;
	subt(subtraction);//passing the value
	cout<<"After function call:"<<subtraction<<endl;
	return 0;
}	
	
