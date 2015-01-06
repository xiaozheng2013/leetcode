/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> occurance;
        ListNode* curNode = head;
        while(curNode) {
            if(occurance.count(curNode) == 0) occurance[curNode] = 1;
            else return true;
            curNode = curNode->next;
        }
        return false;
    }
};
/* algorithm: just scan through the list, to see if an address appears twice? 
test cases:
(1) empty list: DONE
(2) one node; DONE
(3) one node cycle; DONE



/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode* p1;
        ListNode* p2;
        p1 = p2 = head;
        
        do{
            p1 = p1->next;
            p2 = p2->next;
            if(p2!=NULL) p2 = p2->next;
            else return false;
            
        }
        while(p1!=p2 && p2!=NULL);
        
        if(p1 == p2) return true;
        else return false;
    }
};

/* algorithm, use two pointers moving at different speed, if meet, then cycle exists, else not;
Pay attention to the case Not existing...
Mathematical Analysis: 
Assume:
    total length = n; 
    length of cycle = m;
    where (m<=n)
When p1 reach the start of the cycle, n-m steps taken;
position of p1 = n-m+1; but 1 at the cycle;
position of p2 = 1 + 2*(n-m) - (n-m) mod(m) in the cycle;

distance = 1+m - p2;
thus in order to meet, need 1+m-p2 more steps to go;

finally total steps are n-m+1+m-p2 = n+1-p2; where p2 = (1 + n - m) mod(m)

            
Note: in order to get the starting point of the cycle: 
(1) first find where they meet, mark it as m1;
(2) then find where they meet again, mark it as m2; 
then m = dist(m1,m2);

Finally I forget how it was done before...
Actually, 
Assume distance from head to the start of cycle is r1...
then if p1 steps to the start of cycle, then p2 is r1 steps in front, 

Now!!! If we think both move backward r1 steps within the cycle, they will meet each other...
Also, they they meet at one position, they will always meet at the same position in future...

Thus we can see, if we start at head and the position they meet, and move forward at speed 1, they will
finally meet at the start of the cycle;


