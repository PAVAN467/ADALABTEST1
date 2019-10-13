#include <bits/stdc++.h> 

using namespace std; 

  
/* Standard Binary Search function*/

int binarySearch(int arr[], int low,  

                  int high, int key) 
{ 

  if (high < low) 

    return -1; 

      

  int mid = (low + high)/2; /*low + (high - low)/2;*/

  if (key == arr[mid]) 

    return mid; 

      

  if (key > arr[mid]) 

    return binarySearch(arr, (mid + 1), high, key); 

      

  // else 

    return binarySearch(arr, low, (mid -1), key); 
} 

  
/* Function to get pivot. For array 3, 4, 5, 6, 1, 2 

   it returns 3 (index of 6) */

int findPivot(int arr[], int low, int high) 
{ 

  // base cases 

  if (high < low) return -1; 

  if (high == low) return low; 

  

   int mid = (low + high)/2; /*low + (high - low)/2;*/

   if (mid < high && arr[mid] > arr[mid + 1]) 

    return mid; 

      

   if (mid > low && arr[mid] < arr[mid - 1]) 

    return (mid-1); 

      

   if (arr[low] >= arr[mid]) 

    return findPivot(arr, low, mid-1); 

      

   return findPivot(arr, mid + 1, high); 
} 

  
/* Searches an element key in a pivoted 

   sorted array arr[] of size n */

int pivotedBinarySearch(int arr[], int n, int key) 
{ 

  int pivot = findPivot(arr, 0, n-1); 

  

  // If we didn't find a pivot,  

  // then array is not rotated at all 

  if (pivot == -1) 

    return binarySearch(arr, 0, n-1, key); 

  

  

  if (arr[pivot] == key) 

    return pivot; 

      

  if (arr[0] <= key) 

    return binarySearch(arr, 0, pivot-1, key); 

      

    return binarySearch(arr, pivot+1, n-1, key); 
} 

  
/* Driver program to check above functions */

int main() 
{ 

 

  int arr1[10];
  int n,i;
    cout<<"enter the size of array";
    cin>>n;
    cout<<"Enter the array elements";
    for(i=0;i<n;i++)
    {
        cin>>arr1[i];
    }

  int key;
  cout<<"enter the key element";
  cin>>key;

    

  // Function calling 

  cout << "Index of the element is : " <<  

           pivotedBinarySearch(arr1, n, key);
  return 0; 
} 
