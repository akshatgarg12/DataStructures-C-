//
//  main.cpp
//  stacks
//
//  Created by akshat garg on 02/04/20.
//  Copyright © 2020 akshat garg. All rights reserved.
//


#include <iostream>
using namespace std;

class Stack{
    public:
        int top;
        char A[10];
        int i;
    public:
        Stack(){
            top=-1;
            for(i=0;i<10;i++){
                A[i]='0';
            }
        }
        bool isEmpty(){
            if(top==-1)
            return true;
            else return false;
        }
        bool isFull(){
            if(top==9) return true;
            else return false;
        }
        void push(char val){
            if(isFull()==true){
                cout<<"stack overflow"<<endl;
                return;
            }
            else{
                top++;
                A[top]=val;
            }
        }
        char pull(){
            char x=0;
            if(isEmpty()==true) {
                cout<<"stack underflow"<<endl;
                return x;
            }
            else {
                x=A[top];
                A[top]=0;
                top--;
                return x;
            }
        }
        void display(){
            if(isEmpty()==true){
                cout<<"nothing to display"<<endl;
                return;
            }
            else{
                for(i=top;i>=0;i--){
                    cout<<A[i]<<" ";
            }
                return;
            }
        }
        
};



int main()
{
    Stack s1;
    int i,flag=0;
    char B[10];
    for(i=0;i<10;i++){
        cin>>B[i];
    }
    for(i=0;i<10;i++){
        if(B[i]=='{' || B[i]=='(' || B[i]=='[')
            s1.push(B[i]);
    
        else if(B[i]=='}' || B[i]==')' || B[i]==']'){
            char bracket= s1.pull();
            if(B[i]=='}'&& bracket =='{') flag=1;
            else if(B[i]==')'&& bracket =='(') flag=1;
            else if(B[i]==']'&& bracket =='[') flag=1;
            else {flag=0; break;}
    }
    }
    if(flag==1) cout<<"balanced"<<endl;
    else cout<<"unbalanced"<<endl;
    return 0;
}
