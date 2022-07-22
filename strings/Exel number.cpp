class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size(),res=0;
        for(int i=0;i<n;i++){
            res=(columnTitle[i]-'A'+1)+res*26;
        }
        return res;
    }
};


logic is 'ZY'  Z*26+Y =701
