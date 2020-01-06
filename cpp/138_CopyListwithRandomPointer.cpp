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
        // return func1(head);
        return func2(head);
    }
    Node* func1(Node* head) {
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
    Node* func2(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            Node* copy = new Node(curr->val);
            copy->random = curr->random;
            curr->next = copy;
            copy->next = next;
            curr = next;
        }

        curr = head;
        while (curr != NULL) {
            if (curr->next->random != NULL) {
                curr->next->random = curr->next->random->next;
            }
            curr = curr->next->next;
        }

        Node* head1 = head;
        Node* head2 = head->next;
        Node* curr1 = head1;
        Node* curr2 = head2;
        while (curr1 != NULL) {
            curr1->next = curr2->next;
            if (curr2->next != NULL) {
                curr2->next = curr2->next->next;
            } else {
                curr2->next = NULL;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return head2;
    }
};