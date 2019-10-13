// C++ program to find first and last occurrence of 
// an elements in given sorted array 
#include<bits/stdc++.h> 
using namespace std; 
  
// Function for finding first and last occurrence 
// of an elements 
void findFirstAndLast(int arr[], int n, int x) 
{ 
    int first = -1, last = -1; 
    int count;
    for (int i=0; i<n; i++) 
    { 
        if (x != arr[i]) 
            continue; 
        if (first == -1) 
            first = i; 
        last = i; 
        count++;
    } 
    if (first != -1) 
        cout << "First Occurrence = " << first 
             << "\nLast Occurrence = " << last<<"\ncount="<<count; 
    else
        cout << "Not Found"; 
} 
  
// Driver code 
int main() 
{ 
    int arr[10];
    int n;
    cout<<"Enter The size of N";
    cin>>n;
    cout<<"Enter The array elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cout<<"Enter The key";
    cin>>x;
    findFirstAndLast(arr, n, x); 
    return 0; 
} 