#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

vector<int> split(const string &s, char delimiter) { // splits out the input of the file provided
    vector<int> tokens;     
    string token;     
    istringstream tokenStream(s);     
    while (getline(tokenStream, token, delimiter)) {      
        tokens.push_back(stoi(token));     
    }     
    return tokens;  
}

void findmaxsubmatrix(vector<vector<int>> myarray)
{
    vector<vector<int>> temp; // create a new temp array
    vector<int> tempintvector; 
    for(int i = 0; i<myarray.size();i++) // fill the first row and the first column of the array
    {
        tempintvector.clear();
        for(int j = 0; j<myarray[i].size();j++)
        {
            if(i == 0 || j == 0)
            {
                tempintvector.push_back(myarray[i][j]);
            }
            else
            {
                tempintvector.push_back(0);
            }
            
        }
        temp.push_back(tempintvector);
    }

    for(int i =1; i < myarray.size();i++) // fill in the temp aray
    {
        for(int j =1; j<myarray[i].size();j++)
        { 
            if(myarray[i][j] == 1)
            {
                //cout<<temp[i-1][j]<<endl<<temp[i][j-1]<<endl<<temp[i-1][j-1];
                temp[i][j] = min(temp[i-1][j], min(temp[i][j-1], temp[i-1][j-1])) + 1;
            }
            else
            {
                temp[i][j] = 0;
            }
        }
    }
    int max =0, max_i=0, max_j=0; 
    for(int i =0; i< temp.size(); i++)
    {
        for(int j =0; j<myarray[i].size(); j++)
        {
            if(temp[i][j] > max)
            {
                max  = temp[i][j]; // find the maximum value and its coordinates
                max_i = i;
                max_j = j;
            }
        }
    }

    /* Now the interesting thing about this algorithm is the way we backtrack through

        Keep in mind:
            1. We are looking for the largest square with only 1s inside
            2. If its anything else it would reset to 0
            3. remember that the number of the max value corresponds to the number 1s to the left, top, and top left
                that are consecutive 1s. 
        
        Hence, we backtrack through our matrix*/
    cout<<"this is the max submatrix"<<endl;
    for(int i = max_i; i> max_i - max;i--)
    {
        for(int j = max_j; j >max_j - max; j--)
        {
            cout<<1;
        }
        cout<<endl;
    }
}

int main()
{
    /* 
    Go ahead and place a file containing the test case named "test.txt" in the folder

    The format of the file should be :

    x - where x is the row number
    y - where y is the column number

    i,i,i,....
    i,i,... 
    i,..
    ..
    .
    .
    where i is an integer of either 1 or 0
        
    */
    ifstream tester;
    tester.open("test.txt",ios::out);
    int x, y;
    if(tester.is_open())
    {
        tester >> x;
        tester >> y;
    }
    string line;
    vector<vector<int>> myarray;
    vector<int> temp;
    getline(tester, line);
    for(int i = 0; i<y;i++)
    {
        getline(tester, line);
        temp = split(line,',');
        myarray.push_back(temp);
        temp.clear();
    }
    cout<<"this is your array:"<<endl;
    for(int x =0 ; x<myarray.size();x++)
    {
        for(int y = 0 ; y<myarray[x].size();y++)
        {
            cout<<myarray[x][y];
        }cout<<endl;
    }cout<<endl;
    findmaxsubmatrix(myarray);
}