/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int sum = 0 , left  = 0 ; 
       // sum of all elements in the array
       for( int i = 0 ; i < nums.size() ;  i++ ) sum = sum + nums[i] ;
        //Checking if the difference are equal to the sum of all elements in the array
       for (int i = 0 ; i < nums.size() ; i++ ){
        if(left == sum - left - nums[i]){
            return i ; 
        }
        left = left + nums[i] ;
       }
       return -1;
    }
};


// @lc code=end

