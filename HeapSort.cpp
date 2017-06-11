#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ctime>
using namespace std;


void heapify(int heap[],long n)
{
    long i,j,k;
    int flag,v;
    for(i=(n/2);i>=1;i--)
    {
        k=i;
        flag=0;
        v=heap[k];
        while(!flag && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(heap[j]<heap[j+1])
                    j=j+1;
            }
            if(v>=heap[j])
                flag=1;
            else
            {
                heap[k]=heap[j];
                k=j;
            }
        }
        heap[k]=v;
    }
}

void adjust(int heap[],long n)
{
    int i=1,flag,v;
    long j,k;
    k=i;
    flag=0;
    v=heap[k];
    while(!flag && 2*k<=n)
    {
        j=2*k;
        if(j<n)
        {
            if(heap[j]<heap[j+1])
                j=j+1;
        }
        if(v>=heap[j])
            flag=1;
        else
        {
            heap[k]=heap[j];
            k=j;
        }
    }
    heap[k]=v;
}



void heapsort(int heap[],long n)
{
    if(n==0)
        return;
    heap[1]=heap[n];
    n=n-1;
    heapify(heap,n);
    heapsort(heap,n);
}

int main()
{
    double start,end,total_time;
    const long max_length=4000;
    int heap[max_length];
    ofstream o;
    o.open("bubbleSortResult.txt");
    long i,j;
    for(i=0;i<max_length;i+=1000)
    {
        for(j=1;j<=i;j++)
            heap[j]=rand();
            for(int k=0;k<4000;k++)
              o<<heap[k]<<"\n";    
        start=clock();
        heapsort(heap,i);
        end=clock();
        total_time=((double)end-start)/CLOCKS_PER_SEC;


        cout<<"\n\nLength: "<<i;
        cout<<"\nTime: "<<total_time;
    }
    return 0;
}
