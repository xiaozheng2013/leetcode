
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(s.size() == 0) return true;
        if(s.size()%2 == 1) return false;
        
        stack<char> brackets; 
        for(int i=0;i<n;i++) {
            if( s[i] == '(' || s[i] == '{' || s[i] == '[' ) brackets.push(s[i]); 
            else {
                if(brackets.empty() ) return false;
                char tp = brackets.top();
// if ( (tp == '(' && s[i] == ')') || (tp == '{' && s[i] == '}')
//                        || (tp == '[' && s[i] == ']') ) brackets.pop();
                if ( (tp == '(') && (s[i] == ')') ) brackets.pop();
                else if ((tp == '{') && (s[i] == '}')) brackets.pop();
                else if ((tp == '[') && (s[i] == ']')) brackets.pop();
                else return false;
            }
        }
        if(brackets.empty()) return true;
        else return false;
    }
};

/* Note: from this problem, we noticed that the heirarchy of different operators does matter:
'==' is superior to '||','&&'
!!!!! Note: line 15 to 19, using if...else is much quicker than using one if.... as for the one if, I need to check more boolean values;
	but in my second submit, the time are the same for both cases, there is no big difference

/* algorithm: 
Did a research to find the following properties;
(1) the stack can only hold left parentheses;
(2) each time met a right parentheses, it should match with the top of the bracket in the stack;
(3) Finally the stack should be empty;
time complexity: o(n), space complexity: o(n)
test cases:
a) empty Done
b) () 
