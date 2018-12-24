#include <iostream> 
#include <stdio.h>
#include <fstream> 
using namespace std;

void openFile()
{
    std::ofstream myFile;  
    myFile.open("example.txt");  
    if (myFile.is_open()) 
    {
        printf("Success!"); 
    
    } 
    else
    {
        printf("Not success!");
    }
}

int main()
{
    openFile();
    return 0;
}
  
