/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 178795
 * Submitted at:  2021-10-29 16:49:36
 *
 * User ID:       1291
 * Username:      56433494
 * Problem ID:    819
 * Problem Name:  Josephus Problem
 */

#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
};

class linkedList{
public:
    node* head= NULL;
    node* current = NULL;
    
    void addNode(int addData){
        node* n = new node;
        n->data= addData;
        n->next = NULL;
        
        if(head == NULL){
            head = n;
            head->next = head;
            current = head;
        }
        
        current->next = n;
        current = current->next;
        current->next = head;
    }
    
    void Josephus(int m){
        
        current = head;
        node* del = head->next;
        int val;
        
        while(head->next != head){
            for (int i=2; i<m; i++){
                current = current->next;
                del = del->next;
            }
            current->next = del->next;
            if(del == head){
                head = head->next;
            }
            val = del->data;
            cout << val << " ";
            
            delete del;
            current = current->next;
            del = current->next;
        }
        printList();
         
    }
    
    void printList(){
        current = head;
        do{
            cout<< current->data;
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    
    int n,m;
    
    cin >> n;
    cin >> m;
    
    linkedList myList;
    
    for (int i=1;i<n+1; i++){
        myList.addNode(i);
    }
    
    myList.Josephus(m);
    
    return 0;
}