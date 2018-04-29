# Sorting
This contains various sorting techniques using switch case.

#include <iostream>
#include<algorithm>

using namespace std;

/*
Algorithm                  Time Complexity
                  Best          Average       Worst
Selection Sort    Ω(n^2)        θ(n^2)        O(n^2)
Bubble Sort       Ω(n)          θ(n^2)        O(n^2)
Insertion Sort    Ω(n)          θ(n^2)        O(n^2)
Heap Sort         Ω(n log(n))   θ(n log(n))   O(n log(n))
Quick Sort        Ω(n log(n))   θ(n log(n))   O(n^2)
Merge Sort        Ω(n log(n))   θ(n log(n))   O(n log(n))
Bucket Sort       Ω(n+k)        θ(n+k)        O(n^2)
Radix Sort        Ω(nk)         θ(nk)         O(nk)
*/ 


void bubblesort(int a[], int n);
void selectionsort(int a[], int n);
void insertionsort(int a[], int n);
void quicksort(int a[], int l, int h);
int quickpartition(int a[], int l, int h);
void mergesort(int a[], int l, int h);
void merging(int a[], int l, int m, int h);
void countingsort(int a[], int n);
void heapsort(int a[], int n);
void heapify(int a[], int n, int i);
//radixsort - https://www.youtube.com/watch?v=nu4gDuFabIM&list=PLqM7alHXFySHrGIxeBOo4-mKO4H8j2knW&index=6
//bucketsort - https://www.youtube.com/watch?v=VuXbEb5ywrU&list=PLqM7alHXFySHrGIxeBOo4-mKO4H8j2knW&index=7
//treesort - https://www.youtube.com/watch?v=n2MLjGeK7qA&list=PLqM7alHXFySHrGIxeBOo4-mKO4H8j2knW&index=15


int main()
{
    while(1)
    {
        int n,ch;
        cout<<"enter array size\n";
        cin>>n;
        int a[n];
        cout<<"enter array elements\n";
        for(int i=0;i<n;i++)
        cin>>a[i];
        cout<<"enter your choice\n";
        cout<<"enter 1 for bubble sort\n";
        cout<<"enter 2 for selection sort\n";
        cout<<"enter 3 for insertion sort\n";
        cout<<"enter 4 for quick sort\n";
        cout<<"enter 5 for merge sort\n";
        cout<<"enter 6 for counting sort\n";
        cout<<"enter 7 for heap sort\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                bubblesort(a,n);
                break;
            case 2:
                selectionsort(a,n);
                break;
            case 3:
                insertionsort(a,n);
                break;
            case 4:
                quicksort(a,0,n-1);
                break;
            case 5:
                mergesort(a,0,n-1);
                break;
            case 6:
                countingsort(a,n);
                break;
            case 7:
                heapsort(a,n);
                break;
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<endl;
    }
    return 0;
}


void bubblesort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int c=0;
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                c=1;
            }
        }
        if(c==0)
            break;
    }
}


void selectionsort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minm=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minm])
                minm=j;
        }
        swap(a[i],a[minm]);
    }
}


void insertionsort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(key<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}


void quicksort(int a[], int l, int h)
{
    if(l<h)
    {
        int p=quickpartition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
}
int quickpartition(int a[], int l, int h)
{
    int i=l-1;
    int pivot=a[h];
    for(int j=l;j<=h-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return i+1;
}


void mergesort(int a[], int l, int h)
{
    if(l<h)
    {
        int m=l+(h-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merging(a,l,m,h);
    }
}
void merging(int a[], int l, int m, int h)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=h-m;
    int x[n1],y[n2];
    for(i=0;i<n1;i++)
        x[i]=a[l+i];
    for(j=0;j<n2;j++)
        y[j]=a[m+j+1];
    i=0,j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(x[i]<y[j])
            a[k++]=x[i++];
        else
            a[k++]=y[j++];
    }
    while(i<n1)
        a[k++]=x[i++];
    while(j<n2)
        a[k++]=y[j++];
}


void countingsort(int a[], int n)
{
    //let the range be 0 to 9
    int h[10];
    int i;
    for(i=0;i<10;i++)
        h[i]=0;
    for(i=0;i<n;i++)
        h[a[i]]++;
    for(i=1;i<10;i++)
        h[i]+=h[i-1];
    int b[n];
    for(i=0;i<n;i++)
    {
        b[h[a[i]]-1]=a[i];
        h[a[i]]--;
    }
    for(i=0;i<n;i++)
        a[i]=b[i];
}


void heapsort(int a[], int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
void heapify(int a[], int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest])
        largest=left;
    if(right<n && a[right]>a[largest])
        largest=right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
