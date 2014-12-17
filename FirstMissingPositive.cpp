class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int result = 1;
        if(n <= 0) return result;
        map<int, int> existMap;
        for(int i=0;i<n;i++) {
            if(A[i] <= 0) continue;
            if( existMap.count(A[i]) == 0) existMap[ A[i] ] = 1;
            while( existMap.count(result) != 0 ) result++;
        }
        return result;
    }
};

/* test:
(1) empty case, return 1;
(2) missing 1: 2 3 4 -1 
(3) missing 2: 3 1 4 -1 