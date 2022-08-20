#include<iostream>
using namespace std;

int binarySearch(int arr[],int start, int end, int target){
    if(end>=1){
        int mid = start + (end - 1)/2;
        if(arr[mid]== target){
            return mid;
        }
        if(arr[mid]>target){
            return binarySearch(arr, start, mid-1, target);
        return binarySearch(arr, mid+1, end, target);
        }
    }
    return -1;
}

int findPos(int arr[], int key){
    int left = 0, right = 1;
    int val = arr[0];

    while(val<key){
        left = right;
        right = 2*right;
        val = arr[right];
    }
    return binarySearch(arr,left,right,key);
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
                               140, 160, 170};
    int ans = findPos(arr, 90);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}