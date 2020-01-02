/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        
        Node* head1 = head;
        Node* curr1 = head1;
        Node* head2 = new Node(head1->val);
        Node* curr2 = head2;
        map<Node*, int> map1;
        map<int, Node*> map2;
        int index = 0;
        map1[curr1] = index;
        map2[index] = curr2;

        curr1 = curr1->next;
        while (curr1) {
            index++;
            map1[curr1] = index;

            Node* node = new Node(curr1->val);
            curr2->next = node;
            curr2 = curr2->next;
            map2[index] = curr2;

            curr1 = curr1->next;
        }
        
        curr1 = head1;
        curr2 = head2;
        while (curr1) {
            if (curr1->random) {
                curr2->random = map2[map1[curr1->random]];
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return head2;
    }
};