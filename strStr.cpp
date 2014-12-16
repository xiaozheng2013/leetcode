
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        // 6:44
        // empty string
        if(haystack==NULL || needle==NULL ) return -1;
        
        char* p1 = haystack;
        char* p2 = needle;
        int i=0;
        while((*p2)!='\0') {
            while( *p1 != '\0' && *p1 != *p2) { p1++; i++; } // find the first match char
            if( *p1 == '\0') return -1; // tested
            while( *p1 != '\0' && p2!= '\0' && *p1 == *p2) { p1++; p2++; }
            if( *p2 == '\0') return i; // tested
            else if( *p1 == '\0' ) return -1; // tested
            else { p1 = &(haystack[++i]); p2 = needle; } 
        }
        return i;
        
    }
};
/* */
/* test cases:
(1) h == empty || needle == empty
(2) nihao ni ->pass
(3) haoni ni -> pass
(4) ni nihao -> pass
(5) nhaoni ni 