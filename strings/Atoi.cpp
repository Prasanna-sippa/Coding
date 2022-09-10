class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool neg=false;
        while(s[i]==' '){
            i++;
        }
           
            if(s[i]=='+'){
                i++;
            }
            else if(s[i]=='-'){
                i++;
                neg=true;
            }
        
        long long res=0;
        while(s[i]>='0' and s[i]<='9'){
            res=res*10+s[i]-'0';
            if(res>INT_MAX and neg){
                res=INT_MIN;
                break;
            }
            else if(res>=INT_MAX and !neg){
                res= INT_MAX;
                    break;
            }
            i++;
        }
        if(neg){
            res=res*-1;
        }
        return (int)res;
        
    }
};
