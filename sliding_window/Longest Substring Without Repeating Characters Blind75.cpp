class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string str:strs){
            string s=str;
            sort(s.begin(),s.end());
            if(mp.find(s)!=mp.end()){
                mp[s].push_back(str);
            }
            else{
                mp[s]=vector<string>();
                mp[s].push_back(str);
            }
        }
        vector<vector<string>> res;
        for(const auto& [key, value] : mp) {
            res.push_back(value);
        }
        return res;
    }
};
