#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio> 
#include <stdio.h>
#include <string.h>
using namespace std; 

int *count_vowels = new int; 
int *count_consonants = new int;
char **arr_of_txt; 
int *row = new int;

void printArr(char ** arr)
{
    for(int i = 0; i< sizeof arr / sizeof arr[0]; i++)
    {
        for(int j=0; j<(sizeof arr[i] / sizeof(char)) + 1; j++)
        {
            printf("%c", arr[i][j]);
        } 
        printf("\n");
    }
}

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
            count_vowels_consonants(line);
            (*row)++;
        }          
        fileStream.close();
        arr_of_txt = new char*[*row];
        fileStream.open("example.txt");  
        int i = 0;
        while(getline(fileStream, line))
        {
            arr_of_txt[i] = new char[line.length() + 1]; 
            for(int j = 0; j< line.length() + 1; j++)
            {
                arr_of_txt[i][j] = line[j]; 
            } 
            ++i;
        }      
        printArr(arr_of_txt);

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
