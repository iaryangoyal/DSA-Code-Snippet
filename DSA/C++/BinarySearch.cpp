/*Created by Lakshay Goel
  Github Profile link: https://github.com/MrLakshay
  
  
  Problem statement : A sorted array is input by the user and then a key. 
  Binary search is performed on the array if found then the array index will be output
  else -1 will be the output.
  Example : 
  5 //Array size
  1 2 3 4 5 //Array element 
  3 //Key to be searched
  2 // Element found at 2 index of array
  
*/
#include<iostream>
using namespace std;
int binarySearch(int arr[],int n,int key){
    int s=0;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int i,arr[n];
    for (i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<binarySearch(arr,n,key)<<endl;
return 0;
}
