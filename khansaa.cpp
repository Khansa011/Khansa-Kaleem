#include<iostream>
using namespace std;
int main()
{
	int rows,col;
	int sum=0;
	cout<<"\nEnter rows:";
	cin>>rows;
	cout<<"\nEnter columns:";
	cin>>col;
	//Declare a 2D array
	int arr[rows][col];
	
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<col;j++)
		{
			cout<<"Elements ["<<i<<"]["<<j<<"]:";
			cin>>arr[i][j];
		}
	}
	cout<<"\nDIsplay 2D array is:\n";
		for (int i=0;i<rows;i++)
	{
		for (int j=0;j<col;j++)
		{
			
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	

return 0;	
	
}