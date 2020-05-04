/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/


class Solution {
public:

     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        int i = 0, n = strs.size(), j;
        
        unordered_map<string, vector<string>> m;
        for(int i = 0; i<n; i++) {
            m[anagram(strs[i])].push_back(strs[i]);
        }
        unordered_map<string, vector<string>>::iterator itr= m.begin();
        while(itr != m.end()) {
            ans.push_back(itr->second);
            itr++;
        }
       return ans;        
    }
    
    string anagram(string a) {
        int arr[26] = {0}, n = a.length();
        for(int i =0; i<n; i++)
            arr[a[i] - 'a']++;
        string s = "";
        for(int i =0; i<26; i++){
            s += '0' + arr[i] + '#';
        }
        return s;
    }
};
