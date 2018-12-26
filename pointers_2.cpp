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

void printArr(char ** arr, int count_of_lines)
{
    for(int i = 0; i< count_of_lines; i++)
    {
        int j = 0; 
        while(arr[i][j] != '\0')
        {
            printf("%c", arr[i][j]); 
            j++;
        }
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
  
        ofstream outStream;
        outStream.open("out.txt"); 
        if(outStream.is_open())
        {
        for(int i = 0; i< *row; i++)
        {
        int j = 0; 
        while(arr_of_txt[i][j] != '\0')
        {
            outStream << arr_of_txt[i][j];
            j++;
        }
        if(i !=(*row) -1)
        {
            outStream << "\n";
        }
    }

        ofstream reverseStream;
        reverseStream.open("reverse.txt"); 
        if(reverseStream.is_open())
        {
        for(int i = *row -1; i >= 0; i--)
        {
        int j = 0; 
        while(arr_of_txt[i][j] != '\0')
        { 
            printf("kek");
            reverseStream << arr_of_txt[i][j];
            j++;
        }
        if(i >*row)
        {
            reverseStream << "\n";
        }
    }
        }


        }
    }
    
    else
    {
        printf("Not success!");
    }
} 

void copy_string_to_file()
{

}

int main()
{
    openFile(); 
    printf("vowels: %d\n", *count_vowels); 
    printf("consonants: %d\n", *count_consonants);
    return 0;
}
