#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
long length = 0;
const long max_length =30000;
int list[max_length];
double total_time,start,end,d1;
void bubbleSort()
{
    int temp,flag=1;
    for(long i=0;i<length;i++)
    {
        //flag=0;
        for(long j=0;j<length-i-1; j++)
        {
            if (list[j]>list[j+1])
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
                //flag=1;
            }
        }
    }
}
int main()
{
    int i;
    for (i = 0; i < max_length; i++)
    {
        list[i] = rand();
    }
    cout << "*******BUBBLE SORT *********";
    for (;length<=max_length;length+=10000)
    {
        cout << "\nLength: " <<length;
        start=clock();
        bubbleSort();
        end=clock();
        total_time=((double)(end- start))/CLOCKS_PER_SEC;
        cout<<"\nAVG Time: "<<total_time<<"\n";

    }
    cout<<"########END########";
    ofstream o;
    o.open("bubbleSortResult.txt");
    for(int i=0;i<30000;i++)
      o<<list[i]<<"\n";
    return 0;
}
