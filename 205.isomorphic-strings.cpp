/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t){
         unordered_map<char , char> umap;
         unordered_set<char> s1;
         if(s.size() != t.size())
             return false;
         for (int i = 0 ; i < s.size() ; i++ ){
            char c = s[i];
            char str = t[i];
            if (umap.find(c) == umap.end()){
                if (s1.find(str) != s1.end()) 
                return false;
                umap[c] = str;
                s1.insert(str);
            }
            else{
                if (umap[c] != str)
                    return false;
            }
         }
         return true;
    }
};
// @lc code=end

