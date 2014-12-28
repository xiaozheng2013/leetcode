class Solution {
public:
    int minDistance(string word1, string word2) {
        // edge cases
        int l1 = word1.size();
        int l2 = word2.size();
        
        if( l1 == 0 ) return l2;
        else if(l2 == 0) return l1;
        
        // ordinary cases
        int a[l1+1][l2+1];
        for(int i=0;i<=l2;i++) a[0][i] = i;
        for(int i=0;i<=l1;i++) a[i][0] = i;
        for(int i=1;i<=l1;i++) {
            for(int j=1;j<=l2;j++) {
                a[i][j] = i+j;
                if(word1[i-1] == word2[j-1]) a[i][j] = min(a[i][j],a[i-1][j-1]);
                else a[i][j] = min(a[i][j], 1 + a[i-1][j-1]);
                a[i][j] = min(a[i][j], 1+a[i-1][j]);
                a[i][j] = min(a[i][j], 1+a[i][j-1]);
            }
        }
        
        return a[l1][l2];
    }
};

/* dynamic programming
time complexity = m*n, eg. used a m*n size matrix to store result 
/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        
        if( l1 == 0 ) return l2;
        else if(l2 == 0) return l1;
        // check 3 cases separately 
        int d1 = minDistance( word1.substr(1), word2.substr(1));
        if(word1[0] != word2[0]) d1 = d1 + 1;
        int d2 = 1 + minDistance( word1, word2.substr(1));
        int d3 = 1 + minDistance( word1.substr(1), word2 );
        return min(d1,min(d2,d3));
        
    }
};

/* brute force: each compare between w1[0..m] and w2[0...n], check all three cases:
(1) insert w1[0...m], w2[1...n]
(2) remove w1[1...m], w2[0...n]
(3) transform w1[1...m], w2[1...n]
