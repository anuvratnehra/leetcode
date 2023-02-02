//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    void merge(Node *first,Node *mid,Node*last){
        vector<int>firstarr, secondarr;
        Node *firstit=first, *secondit=mid->next;
        while(firstit!=mid->next){
            firstarr.push_back(firstit->data);
            firstit=firstit->next;
        }
        while(secondit!=last->next){
            secondarr.push_back(secondit->data);
            secondit=secondit->next;
        }
        Node *temp=first;
        int i=0,j=0;
        while(i<firstarr.size() && j<secondarr.size()){
            if(firstarr[i]<secondarr[j]){
                temp->data=firstarr[i++];
            }
            else{
                temp->data=secondarr[j++];
            }
            temp=temp->next;
        }
        while(i<firstarr.size()){
            temp->data=firstarr[i++];
            temp=temp->next;
        }
        while(j<secondarr.size()){
            temp->data=secondarr[j++];
            temp=temp->next;
        }
        vector<int>().swap(firstarr);
        vector<int>().swap(secondarr);
        return;
    }
    void mergingSort(Node* first, Node* last){
        if(first==last) return;
        Node *slow=first, *fast=first;
        while(fast->next!=last && fast->next->next!=last){
            slow=slow->next;
            fast=fast->next->next;
        }
        mergingSort(first,slow);
        mergingSort(slow->next,last);
        merge(first,slow,last);
        return;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        Node* fast=head;
        while(fast->next!=NULL) fast=fast->next;
        mergingSort(head,fast);
        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends