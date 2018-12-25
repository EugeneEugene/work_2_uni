#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
using namespace std; 

int *count_vowels = new int; 
int *count_consonants = new int; 

void count_vowels_consonants(string line)
{   
    for(int i = 0; i < line.length(); ++i)
    { 
        if(isalpha(line[i]) != 0) {
            if(line[i]=='a' || line[i]=='e' || line[i]=='i' ||
                line[i]=='o' || line[i]=='u' || line[i]=='A' ||
                line[i]=='E' || line[i]=='I' || line[i]=='O' ||
                line[i]=='U')
            { 
                (*count_vowels)++;
            } 
            else
            {
                (*count_consonants)++;
            }
        }
    }
}

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
            count_vowels_consonants(line);
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
    printf("vowels: %d\n", *count_vowels); 
    printf("consonants: %d\n", *count_consonants);
    return 0;
}
