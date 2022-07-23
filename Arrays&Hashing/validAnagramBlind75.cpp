class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1=s.size(),len2=t.size();
        if(len1!=len2)return false;
        vector<int> dict(26,0);
        for(int i=0;i<len1;i++){
            dict[s[i]-'a']++;
            dict[t[i]-'a']--;
            
        }
        
        for(int i=0;i<26;i++){
           
            if(dict[i]){
                return false;
            }
        }
        return true;
    }
};
