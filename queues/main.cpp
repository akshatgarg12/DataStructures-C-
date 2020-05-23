//
//  main.cpp
//  queues
//
//  Created by akshat garg on 02/04/20.
//  Copyright © 2020 akshat garg. All rights reserved.
//

#include <iostream>
using namespace std;
class queue{
    private:
    int front,rear,i;
    int A[10];
    public:
    queue(){
        front=rear=-1;
        for(i=0;i<10;i++) A[i]=0;
    }
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else return false;
    }
    bool isFull(){
        if(rear==9) return true;
        else return false;
    }
    void enqueue(int val){
        if(isFull()){
            cout<<"overflow"<<endl;
        }
        else if(isEmpty()) {
            front = rear =0;
            A[rear]=val;
        }
        else{
            rear++;
            A[rear]=val;
        }
    }
    int dequeue(){
        int x=0;
        if(isEmpty()){
            cout<<"nothing,the queue is empty"<<endl;
        
        }
        else if(rear==front){
            x=A[front];
            front--;
            rear--;
        }
        else {
            x=A[front];
            front++;
        }
        return x;
    }
};
int main() {
    queue q1;
    cout<<q1.isEmpty()<<endl;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    cout<<q1.isFull()<<" "<<q1.isEmpty()<<endl;
    cout<<q1.dequeue()<<" "<<q1.dequeue();
    return 0;
}
