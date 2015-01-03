class Solution {
public:
    int maxSubArray(int A[], int n) {
        // solve the problem by just one scan 8:42
        
        int maxSum = A[0];
        int curSum = 0;
        for(int i=0;i<n;i++) {
            curSum += A[i];
            if(A[i] >= 0) maxSum = max( maxSum, curSum);
            else if( curSum < 0 ) {
                if(maxSum <= 0) maxSum = max(maxSum, curSum);
                curSum = 0;
            }
        }
        return maxSum;
        
    }
};
/*
test cases: 
(1) non-emtpy: 
(2) one element:
    1 DONE; 0 DONE; -1 DONE
(3) 2 elements:
    -1 0
    -1 -1 DONE
    -1 1 DONE
    1 1 
(4) −2,1,−3,4,−1,2,1,−5,4
max = -2->1->4->5->6->6
DONE
/*
Algorithm: 
if current sum < 0, set current sum to be 0;
also keep updating maxSum

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // solve the problem by just one scan 8:42
        
        int maxSum = A[0];
        int curSum = 0;
        for(int i=0;i<n;i++) {
            curSum += A[i];
            maxSum = max( maxSum, curSum);
            curSum = max(0, curSum);
        }
        return maxSum;
        
    }
};