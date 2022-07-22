class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,z=s.size();
        if(s.empty()){
            return true;
        }
        while(i<z){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[z])){
                z--;
                continue;
            }
            if(tolower(s[i++])!=tolower(s[z--])){
                return false;
            }
        }
        return true;
    }
};

Explanation: Isalnum does exactly what is sounds like, checks if the ASCII value passed in has a character equivalent to a number of letter. It returns non-zero for true, and zero for false.
/*
 * O(n) Time and
 * O(1) Space
 */
