class Solution {
public:
    bool areAlmostEqual(string str1, string str2) {
        int len1=str1.size(),len2=str2.size();
        if(len1!=len2)return false;
       vector<int> mis_match;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                mis_match.push_back(i);
            }
            if(mis_match.size()>2)return false;
  
        }
        if(mis_match.size()==0)return true;
        

        if(mis_match.size() == 2) 
            swap(str1[mis_match[0]], str1[mis_match[1]]);
        
        return str1 == str2;
    }
};
