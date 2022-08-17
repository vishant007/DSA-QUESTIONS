// find first and last position of given element in array, facebook question, binary search approach
#include <bits/stdc++.h> 
using namespace std; 
    int findFirst(vector<int>& nums, int target)
    {
         int ans = -1;
    int s = 0;
    int e = nums.size() - 1;
    while(s <= e){
        int mid =s+ (e-s) / 2;
        if (nums[mid] < target) 
            s = mid + 1;
        else if (nums[mid] > target) 
            e = mid - 1;
        else  {
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
    }
     int findLast(vector<int>& nums, int target)
    {
          int ans = -1;
    int s = 0;
    int e = nums.size() - 1;
    while(s <= e){
        int mid =s+ (e-s) / 2;
        if (nums[mid] < target) 
            s = mid + 1;
        else if (nums[mid] > target) 
            e = mid - 1;
        else  {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
    }
    vector<int> find(vector<int>& nums, int target) {
        vector<int>result(2);
         result[0] = findFirst(nums, target);
         result[1] = findLast(nums, target);
         return result;
    }
int main() 
{ 
 vector<int> arr = {1,2,5,5,5,9}; 
int target=5;
vector<int> ans(2);
ans=  find(arr,target);
for(int i=0;i<2;i++)
 cout<<ans[i]<<" "; 
 return 0;
}