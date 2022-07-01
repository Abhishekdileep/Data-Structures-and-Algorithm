/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 , j = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i == s.size();
    }
};
// @lc code=end

