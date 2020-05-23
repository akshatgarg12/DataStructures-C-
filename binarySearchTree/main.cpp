//
//  main.cpp
//  binarySearchTree
//
//  Created by akshat garg on 25/04/20.
//  Copyright © 2020 akshat garg. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class BSTnode{
public:
    int data;
    BSTnode* left;
    BSTnode* right;
};

class BST{
public:
//    METHODS FOR BASIC OPERATIONS
    BSTnode* CreateNewNode(int data){
        BSTnode* newNode = new BSTnode();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right=nullptr;
        return newNode;
    }
    BSTnode* insert_node(BSTnode* root,int  data){
        if(root==nullptr){
             root= CreateNewNode(data);
        }
        else if(data <= root->data){
            root->left =  insert_node(root->left, data);
        }
        else{
            root->right= insert_node(root->right, data);
        }
        return root;
    }
    BSTnode* Search(BSTnode* root,int data){
        if(root==nullptr){
            return nullptr;
        }
        if(root->data==data){
            return root;
        }
        else if(data <=root->data){
            return Search(root->left, data);
        }
        else{
           return  Search(root->right, data);
               }
        }
    int min_data(BSTnode* root){
        BSTnode* ptr = root;
        while(ptr->left!=nullptr){
            ptr = ptr->left;
        }
        return ptr->data;
    }
    int max_data(BSTnode* root){
        BSTnode* ptr = root;
        while(ptr->right!=nullptr){
            ptr = ptr->right;
        }
        return ptr->data;
    }
    int height_of_tree(BSTnode* root){
        if(root==nullptr){
            return -1;
        }
        return max(height_of_tree(root->left), height_of_tree(root->right))+ 1;
    }
//    METHOD(S) FOR TRAVERSAL
    void preorderTraversal(BSTnode* root){
        if(root==nullptr) return;
        BSTnode* ptr =root;
        cout<<ptr->data<<" ";
        preorderTraversal(ptr->left);
        preorderTraversal(ptr->right);
    }
    void inorderTraversal(BSTnode* root){
           if(root==nullptr) return;
          inorderTraversal(root->left);
           cout<<root->data<<" ";
           inorderTraversal(root->right);
       }
    void postorderTraversal(BSTnode* root){
        if(root==nullptr) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";
    }
    
    void breathFirstTraversal(BSTnode* root){
        queue<BSTnode*> q;
        if(root==nullptr) return;
        else q.push(root);
        while(!q.empty()){
            BSTnode* current = q.front();
            if(current!= nullptr){
            cout<<current->data<<" ";
            }
            if(current->left!=nullptr){
            q.push(current->left);
            }
            if(current->right!=nullptr){
            q.push(current->right);
            }
            q.pop();
        }
    }
//    METHOD 1: FOR FINDING WHETHER THE TREE IS BST. (COMPLEX)
    bool isSubtreeLesser(BSTnode* node, int value){
        if(node==nullptr) return true;
        if(node->data<=value){
            return isSubtreeLesser(node->left, node->data);
        }
        else return false;
    }
    
    bool isSubtreeGreater(BSTnode* node, int value){
        if(node==nullptr) return true;
        if(node->data>value){
            return isSubtreeGreater(node->right, node->data);
        }
        else return false;
    }
    
        bool isBinarySearchTree(BSTnode* root){
            if(root==nullptr) return true;
            if(isSubtreeLesser(root->left, root->data)&&isSubtreeGreater(root->right, root->data)&&isBinarySearchTree(root->left)&&isBinarySearchTree(root->right)){
                return true;
            }
            else return false;
        }
    
    // METHOD-2: TO FIND WHETHER THE GIVEN TREE IS BST OR NOT, ITS BETTER IN TERMS OF COMPLEXITY
   bool  isBSTutil(BSTnode* root, int minVal, int maxVal){
       if(root==nullptr) return true;
        if(root->data > minVal && root->data<maxVal ){
            return (isBSTutil(root->left, minVal, root->data)&&isBSTutil(root->right, root->data, maxVal));
        }
        else return false;
    }
    
    bool isBST(BSTnode* root){
        return isBSTutil(root, INT_MIN, INT_MAX);
    }
    //DELETING A NODE..
    BSTnode* DeleteNode(BSTnode* root, int value){
        if(root==nullptr) return root;
        if(root->data < value){
            return root->right= DeleteNode(root->right, value);
        }
        else if(root->data > value){
           return  root->left = DeleteNode(root->left, value);
        }
        else{
            if(root->left==nullptr && root->right==nullptr){
                delete root;
                root = nullptr;
                
            }
            else if(root->left==nullptr){
                BSTnode* temp = root;
                root=root->right;
                delete temp;
                
            }
            else if(root->right==nullptr){
                BSTnode* temp = root;
                root=root->left;
                delete temp;
                
            }
            else{
                root->data = min_data(root->right);
                return DeleteNode(root->right, root->data);
            }
            return root;
        }
    }


                
    
};


int main() {
    // insert code here...
    BSTnode* root = nullptr;
    root = BST().insert_node(root, 5);
    root = BST().insert_node(root, 4);
    root = BST().insert_node(root, 3);
    root = BST().insert_node(root, 2);
    root = BST().insert_node(root, 1);
    root = BST().insert_node(root, 8);
    root = BST().insert_node(root, 10);
    root = BST().insert_node(root, 13);
    
//    BST().breathFirstTraversal(root);
    cout<<BST().DeleteNode(root, 3);
    
    BST().inorderTraversal(root);
//    cout<<BST().max_data(root)<<endl;
//    cout<< BST().height_of_tree(root)<<endl;
    
//    BSTnode*  node;
//    node= BST().Search(root, 13);
//    if(node!=nullptr) cout<<true<<endl;
//    else cout << false<<endl;
    
    
    return 0;
}
