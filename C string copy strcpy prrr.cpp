#include<iostream>
#include<cstring> //include the header for strcpy()
using namespace std;

int main() {
	    
	    char source[] = "Hello, World!";
	    char destination[50];   //Make sure the destination array
	    
	    
	    // Use strcpy() to copy the source string into destination 
	    strcpy(destination, source);
	    
	    // Print the copied string
	    cout<<"Source string: "<<source <<endl;
	    cout<<"Destination string: "<<destination<<endl;
	    
	    return 0;
}
