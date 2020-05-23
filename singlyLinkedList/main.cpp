//
//  main.cpp
//  singlyLinkedList
//
//  Created by akshat garg on 10/04/20.
//  Copyright © 2020 akshat garg. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    int key;
    Node * next;
    Node(){
        data=0;
        key=0;
        next=nullptr;
    }
    Node(int k, int d){
        key=k;
        data=d;
    }
};
class singlyLinkedList{
public:
    Node *head;
    singlyLinkedList(){
        head=nullptr;
    }
    singlyLinkedList(Node *n){
        head= n;
    }
     Node * ifExists(int k) {
       Node * temp = NULL;

       Node * ptr = head;
       while (ptr != NULL) {
         if (ptr->key == k) {
           temp = ptr;
         }
         ptr = ptr->next;

       }
       return temp;
     }

   void appendNode(Node * n) {
      if (ifExists(n -> key) != NULL) {
        cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
      } else {
        if (head == NULL) {
          head = n;
          cout << "Node Appended" << endl;
        } else {
          Node * ptr = head;
          while (ptr -> next != NULL) {
            ptr = ptr -> next;
          }
          ptr -> next = n;
          cout << "Node Appended" << endl;
        }
      }

    }
    void PrependNode(Node* n){
        if(ifExists(n->key)!=0){
                   cout<<"An link with similar key already exists. pls change the key and append again."<<endl;
        }
        else{
        if(head==0){
            head=n;
        }
        else{
            n->next=head;
            head=n;
        }
    }
    }
    void insertNode(Node* n,int k){
     if(ifExists(n->key)!=0){
                       cout<<"An link with similar key already exists. pls change the key and append again."<<endl;
            }
     else{
         if(ifExists(k)==nullptr){
             cout<<"no such link exists with key "<<k<<endl;
         }
         else{
             Node* temp;
             temp= head;
             while(temp->key!=k){
                 temp=temp->next;
             }
             n->next=temp->next;
             temp->next=n;
         }
     }
    }
    void DeleteNode(int k){
        if(ifExists(k)==nullptr) cout<<"no such link with key "<<k<<"exists"<<endl;
        else{
            Node* temp=head;
            Node* ctr=head->next;
            while(ctr->key!=k){
                temp=temp->next;
                ctr=ctr->next;
            }
            temp->next= ctr->next;
            ctr->next=nullptr;
                        
        }
    }
    void display(){
        Node*temp=head;
        while(temp!=nullptr){
            cout<<"("<<temp->key<<","<<temp->data<<")"<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    singlyLinkedList s;
    int option;
   do {
       cout<<"1.check if a link exists by key"<<endl;
       cout<<"2.append a link"<<endl;
       cout<<"3.prepend a link"<<endl;
       cout<<"4.insert a link after a given key"<<endl;
       cout<<"5.delete a link by its key value"<<endl;
       cout<<"6.display the list"<<endl;
       cout<<"0.to exit"<<endl;
       cin>>option;
       
       Node* n = new Node();
       int d1,k1;
       switch (option) {
           case 1:
               int k;
               cout<<"enter a key value"<<endl;
               cin>>k;
               if(s.ifExists(k)==nullptr) cout<<"link doesnt exists"<<endl;
               else cout<<"key exists"<<endl;
               break;
           case 2:
               cout<<"enter the key and the data of link you want to append"<<endl;
               
               cin>>k1>>d1;
               n->data=d1;
               n->key=k1;
               s.appendNode(n);
               break;
               
           case 3:
               cout<<"enter the key and the data of link you want to prepend"<<endl;
               cin>>k1>>d1;
               n->data=d1;
               n->key=k1;
               s.PrependNode(n);
               break;
           case 4:
            
                cout<<"enter the key after which you want to insert the link"<<endl;
                cin>>k; cout<<"\n";
                cout<<"enter the key and the data of link you want to prepend"<<endl;
                cin>>k1>>d1;
                n->data=d1;
                n->key=k1;
               s.insertNode(n, k);
               break;
           case 5:
               cout<<"enter the key of element to be removed"<<endl;
               cin>>k;
               s.DeleteNode(k);
               break;
           case 6:
               s.display();
               cout<<"endl";
               
           default:
               break;
       }
       
    } while (option!=0);
    
    std::cout << "program ended!\n";
    return 0;
}
