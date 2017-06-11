#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;
long length = 0;
const long max_length = 30000;
int list[max_length];
double total_time,start,end,d1;
void selectionSort()
{
    int temp;long mini;
    for(long i=0;i<length-1;i++)
    {
        mini=i;
        for(long j=i+1;j<length;j++)
        {
            if(list[mini]>list[j])
            {
                mini=j;
            }
        }
        if(mini!=i)
        {
            temp=list[i];
            list[i]=list[mini];
            list[mini]=temp;
        }
    }
}
int main()
{
    int i;
    for (i = 0; i < max_length; i++)
    {
        list[i]=rand();
    }
    cout<<"***********SELECTION SORT ************";
    for (;length<=max_length;length+=10000)
    {
        cout << "\n\nLength: " << length;
        start = clock();
        selectionSort();
        end = clock();
        total_time = ((double) (end- start))/CLOCKS_PER_SEC;
        cout<<"\nWORST Time: "<<total_time;

    }
    ofstream o;
    o.open("selectionSortResult.txt");
    for(int i=0;i<30000;i++)
      o<<list[i]<<"\n";
    return 0;
}
