#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
using namespace std;

void openFile()
{
    ifstream fileStream;
    fileStream.open("example.txt");
    if (fileStream.is_open())
    {
        printf("Success!");
        string line;
        while(getline(fileStream, line))
        {
            cout << line << endl;
        }          
        fileStream.close();
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
