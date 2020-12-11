#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

/*
    This is a sliding window algorithm to find the longest sustring without repeating 
    characters in a string 

    for example, 

    input: abcabcbb
    output: 3
*/

int lengthOfLongestSubstring(string s) {
        int maximum=0;
        map<char, int> hashmap;
        int j=0;
        for(int i =0; i<s.size();i++) // starts off through the array
        {
            
            if(hashmap.count(s[i])) // if its in the hashmap
            {
                j = max(hashmap[s[i]],j);
            }
            maximum = max(maximum, i-j+1);
            hashmap[s[i]] = i+1;
        }
        return maximum;
}

int main()
{
    /* place a file containing a string into your project folder*/
    ifstream tester;
    tester.open("test.txt",ios::out);
    string input;
    getline(tester, input);
    cout<<lengthOfLongestSubstring(input);
    
}