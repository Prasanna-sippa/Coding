class Solution {
public:
    vector<int> getPreviousSmaller(vector<int>& height){
        vector<int> prev(height.size()); //to store previous smaller height
        stack<int>s;
        for(int i=0;i<height.size();i++){
            while(!s.empty() && height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.empty()){
                prev[i]=-1;
            }
            if(!s.empty() && height[s.top()]<height[i]){
                prev[i]=s.top();
            }
            s.push(i);
        }   
        return prev;
    }
    vector<int> getNextSmaller(vector<int>& height){
        vector<int> next(height.size()); //to store previous smaller height
        stack<int>s;
        for(int i=height.size()-1;i>=0;i--){
            while(!s.empty() && height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.empty()){
                next[i]=-1;
            }
            if(!s.empty() && height[s.top()]<height[i]){
                next[i]=s.top();
            }
            s.push(i);
        }   
        return next;
    }
    int largestRectangleArea(vector<int>& height) {
        /*
        1. find left smaller and right smaller for each height
        2. for each height do multiply its height with min of both left and right to get area
        */
        vector<int> prevSmaller=getPreviousSmaller(height);
        vector<int> nextSmaller=getNextSmaller(height);
        int area=0;
        for(int i=0;i<height.size();i++){
            int len=height[i];
            if(nextSmaller[i]==-1){
                //meanswhenever we find -1 for right smaller means there is no right smaller for this height, we only have bigger than this so we can find area by considering its next right as last index just take length
                nextSmaller[i]=height.size();
            }
            int width=nextSmaller[i]-prevSmaller[i]-1; //trying to get the width by length btw next ans prev smaller as we have to remove prev smaller so do -1
            area=max(area,len*width);
        }
        return area;
    }
};