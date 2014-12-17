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
// note here is a fastest idea:  very tricky to modify the original array to make it so simple
also O(1) space complexity

int firstMissingPositive(int A[], int n) {
if(n==0)
    return 1;
for (int i(0); i != n;)
{
    if (A[i] != i + 1 && A[i]>0 && A[i] <= n&& A[A[i]-1] != A[i])
    {
        swap(A[i], A[A[i] - 1]);
    }
    else ++i;
}
for (int i(0); i != n; ++i)
{
    if (A[i] != i + 1)
        return i + 1;
}
return n+1;

}