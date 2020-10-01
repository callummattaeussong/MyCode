#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 100

struct Plane
{
    string name;
    int waittime;
};

void printarray(Plane *planearray, int length)
{   
    if(length == 0)
    {
        cout<<"There are no planes in queue right now."<<endl;
    }
    else
    {
        cout<<"The landing queue is:"<<endl;
        for(int i = 0;i<length;i++)
        {
            cout<<"Plane "<<planearray[i].name<<" with a waiting time of "<<planearray[i].waittime<<endl;
        }
    }
}

void MINHEAPIFY (Plane *planearray, int i, int n)
{
    int smallest;
    Plane temp;
    int left = 2*i+1;
    int right = (2*i)+2;
    if(left<n && planearray[left].waittime < planearray[i].waittime)
    {
        smallest = left;
    }
    else 
    {
        smallest = i;
    }
    if(right<n && planearray[right].waittime < planearray[smallest].waittime)
    {
        smallest = right;
    }
    if(smallest != i)
    {
        temp = planearray[i];
        planearray[i] = planearray[smallest];
        planearray[smallest] = temp;
        MINHEAPIFY(planearray, smallest, n);

    }
}

void HEAPDECREASEKEY(Plane *planearray,int i, Plane val)
{
    Plane temp;
    if(val.waittime<=planearray[i].waittime)
    {
        cout<<"error: valid input of time";
    }
    planearray[i] = val;
    while(i>0 && planearray[(i-1)/2].waittime > planearray[i].waittime)
    {
        temp = planearray[(i-1)/2];
        planearray[(i-1)/2] = planearray[i];
        planearray[i] = temp;
        i = (i-1)/2;
    }
}

void MINHEAPINSERT(Plane *planearray, Plane val, int length)
{
    length = length + 1;
    planearray[length-1].waittime = 0;
    HEAPDECREASEKEY (planearray,length-1,val);
}

void EXTRACTMINIMUM(Plane *planearray, int length)
{
    if(length == 0)
    {
        cout<<"There are no planes to land."<<endl;   
    }
    else
    {
        cout<<"Plane "<<planearray[0].name<<" has landed"<<endl;
        planearray[0] = planearray[length-1];
        length = length-1;
        MINHEAPIFY(planearray, 0, length);
    }
}

int main()
{   
    Plane *planearray = new Plane[MAX];
    Plane val;
    int arraysize = 0;
    cout<<" Welcome to plane landing system\n"<<endl;
    int exit=0;
    while(exit!=1)
    {
        cout<<"1. Make a landing request"<<endl;
        cout<<"2. Land a plane"<<endl;
        cout<<"3. List all the landing requests"<<endl;
        cout<<"4. Exit\n"<<endl;
        cout<<"Select your option: ";
        int i;
        cin>>i;
        string name;
        int waittime;
        switch(i)
        {
            case 1:
                cout<<"Enter plane name: ";
                cin>>name;
                cout<<"Enter wait time before landing: ";
                cin>>waittime;
                val.waittime = waittime;
                val.name=name;
                MINHEAPINSERT(planearray,val,arraysize);
                cout<<"Landing request made"<<endl;
                arraysize++;
                break;
            case 2:
                EXTRACTMINIMUM(planearray, arraysize);
                arraysize--;
                break;
            case 3:
                printarray(planearray, arraysize);
                break;
            case 4:
                exit=1;
                break;
            default:
                cout<<"Invalid option...Try again"<<endl;
                break;
        }    
    }
    return 0;
}
