// Given n non-negative integers representing an elevation map where the width of each bar is 1
// compute how much water it is able to trap after raining.

// Approach: In the previous solution, to find the highest bar on the left and right, array traversal is needed which reduces the efficiency of the solution. 
// To make this efficient one must pre-compute the highest bar on the left and right of every bar in linear time. 
// Then use these pre-computed values to find the amount of water in every array element.
//this aaproach will have the time omplrexity of O(n)
#include <bits/stdc++.h>
using namespace std;
 
int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
 
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
 
    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;
}
 
// Driver program
int main()
{
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "
         << findWater(arr, n);
    return 0;
}






// //simple approach having O(n2)
// #include<bits/stdc++.h>
// using namespace std;
// // function to return the maximum water that can be stored

// int maxWater(int arr[],int n)
// {
//     int res = 0;
//     for(int i=1; i< n-1; i++){
//         // find the max element on its left
//         int left = arr[i];
//         for (int j=0; j<i; j++){
//             left = max(left, arr[j]);
//         }
//         // fin the min element on its right
//         int right = arr[i];
//         for(int j=i+1; j<n; j++){
//             right = max(right, arr[j]);
//         }
//         // update the max water
//         res = res + (min(left,right)- arr[i]);

//     }
//     return res;
// }

// int main(){
//     int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout<< maxWater(arr,n);
//     return 0;

// }

// approach using stacks 


// int trap(vector<int>& height)
// {
//     int ans = 0, current = 0;
//     stack<int> st;
//     while (current < height.size()) {
//         while (!st.empty() && height[current] > height[st.top()]) {
//             int top = st.top();
//             st.pop();
//             if (st.empty())
//                 break;
//             int distance = current - st.top() - 1;
//             int bounded_height = min(height[current], height[st.top()]) - height[top];
//             ans += distance * bounded_height;
//         }
//         st.push(current++);
//     }
//     return ans;
// }