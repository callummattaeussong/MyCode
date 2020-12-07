#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    /* place a file containing a string into your project folder*/
    ifstream tester;
    tester.open("test.txt",ios::out);
    string input;
    getline(tester, input);
    vector<char> array;
    int counter = 1;
    
    char converter[5] = {0};
    for(int i = 0; i<input.length();i++) // places input string into a vector
    {
        array.push_back(input[i]);
    }

    int i =0;
    while(i < array.size())
    {
        if(i == array.size()-1) // we reach the last element in the array 
        {
            if(counter > 1) // last element is part of a stream
            {
                sprintf(converter, "%d",counter);
                array.push_back(converter[0]);
                i++;
            }
            i++;
        }
        else if(array[i] == array[i+1]) // the next one is same 
        {
            if(array[i+1] != array.size()-1)
            {
                array.erase(array.begin()+i+1);
                counter++;
            }
        }
        else if(array[i] != array[i+1]) // if the next one is not the same
        { 
            if(counter > 1) // if there's more than one in the stream
            {
                array.insert(array.begin()+i, array[i]);
                sprintf(converter, "%d",counter);
                array[i+1] = converter[0];
                counter = 1;
            }
            i++;
        }
    }
    for(int x = 0;x<array.size();x++)
    {
        cout<<array[x];
    }
}