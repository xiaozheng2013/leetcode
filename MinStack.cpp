class MinStack {
public:
    //int Min;
    stack<int> myStack;
    stack<int> minStack;
    
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int x) {
        myStack.push(x);
        int newMin = min(minStack.top(), x);
        minStack.push(newMin);
    }

    void pop() {
        if(!myStack.empty()) {
            myStack.pop();
            minStack.pop();
        }
    }

    int top() {
        if(!myStack.empty()) return myStack.top();
        else return 0;
    }

    int getMin() {
        return minStack.top();
    }
};

/* Note the code below ignore the case when we pop, the Min value should also be updated; 
we need to use a stack to keep track of the Min...
Actually if we check the solution, we'll see we can use a smaller stack to track the Mins...

O(n) runtime, O(n) space – Minor space optimization:
If a new element is larger than the current minimum, we do not need to push it on to the min stack. When we perform the pop operation, check if the popped element is the same as the current minimum. If it is, pop it off the min stack too.

/*
you'll all find MLE(memory limit exceed error);
actually the reason is that the c++ list will always double the size of the list when adding more elements
class MinStack {
public:
    int Min;
    list<int> myStack;
    MinStack() {
        Min = INT_MAX;
    }
    void push(int x) {
        myStack.emplace_front(x);
        Min = min(Min, x);
    }

    void pop() {
        if(!myStack.empty())
            myStack.pop_front();
    }

    int top() {
        if(!myStack.empty()) return myStack.front();
        else return 0;
    }

    int getMin() {
        return Min;
    }
};

/*
algorithm: use a list to store the data array:
push: insert at begin, also update Min
pop: erase the top if non-empty
top: return the top if non-empty; else return 0;
getMin: return Min;

Test : Fail: memeory limit exceeded.