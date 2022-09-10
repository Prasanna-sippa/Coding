class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int left=0,right=(row*col)-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(matrix[mid/col][mid%col]==target){
                return true;
            }
            else if(matrix[mid/col][mid%col]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return false;
    }
};



//////////////////
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int X) {
        int N=mat.size(),M=mat[0].size();
        int l=0,h=M-1;
	    while(l<N && h>=0){
	        if(mat[l][h]==X){
	            return true;
	        }
	        else if(mat[l][h]<X){
	            l++;
	        }
	        else{
	            h--;
	        }
	    }
	    return 0;
    }
};
