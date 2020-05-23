//
//  main.cpp
//  circular queue
//
//  Created by akshat garg on 02/04/20.
//  Copyright © 2020 akshat garg. All rights reserved.
//

#include <iostream>
using namespace std;
class CircularQueue{
    private:
    int front,rear,i;
    int A[10];
    public:
    CircularQueue(){
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
        if((rear+1)%10==front) return true;
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
            rear=(rear+1)%10;
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
            front = rear=-1;
        }
        else {
            x=A[front];
            front=(front+1)%10;
        }
        return x;
    }
};

int main(int argc, const char * argv[]) {
    CircularQueue q1;
    cout<<q1.isEmpty()<<endl;
    q1.enqueue(6);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.enqueue(1);
    cout<<q1.dequeue()<<endl;
    q1.enqueue(4);
    cout<<q1.dequeue()<<endl;
    cout<<q1.isFull();
    
    return 0;
}
