Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.

class Solution
{
    public:
    
    void helper(string cur,int ind,int n,int a[],vector<string> &res){
        if(ind==n){
            res.push_back(cur);
            return;
        }
        
        for(auto c: mp[a[ind]]){
            helper(cur+c,ind+1,n,a,res);
            
        }
    }
    unordered_map<int,vector<char>> mp;
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        
        vector<string>res;
        helper("",0,N,a,res);
        
        return res;
        
    }
};


Expected Time Complexity: O(4N * N).
Expected Auxiliary Space: O(N).
