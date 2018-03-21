#include <bits/stdc++.h>
using namespace std;
/* Binary tree Node */
struct Node{
    int data,   // Stores key information of node
        lCount, // Stores number of left child this node has
        Sum;    // Stores sum of all left child
    struct Node* left, *right;
};
struct Node* createNode(int data){//utility function new Node of BST
    Node* new_Node = new Node;
    new_Node->left = new_Node->right = NULL;
    new_Node->data = data;
    new_Node->lCount = new_Node->Sum = 0;
    return new_Node;
}
// A utility function to insert a new Node with given key in BST and also maintain lcount, Sum
struct Node *insert(Node *root, int key){
// If the tree is empty, return a new Node
    if (root == NULL)   return createNode(key);
// Otherwise, recur down the tree
    if (root->data > key){
// increment lCount of current Node
        root->lCount++;
// increment current Node sum by adding key into it
        root->Sum += key,   root->left = insert(root->left , key);
    }
    else if (root->data < key ) root->right = insert (root->right , key);
    // return the (unchanged) Node pointer
    return root;
}
// function return sum of all element smaller than and equal to Kth smallest element
void ksmallestElementSumRec(Node *root, int k , int &temp_sum){
    if (root == NULL)   return;
// if we fount k smallest element then break the function
    if ((root->lCount + 1) == k){
        temp_sum += root->data + root->Sum ;
        return;
    }
    else if (k > root->lCount){
// store sum of all element smaller than current root ;
        temp_sum += root->data + root->Sum;
// decremented k and call right sub-tree
        k = k -( root->lCount + 1);
        ksmallestElementSumRec(root->right , k , temp_sum);
    }
    else // call left sub-tree
        ksmallestElementSumRec(root->left , k , temp_sum );
}
// Wrapper over ksmallestElementSumRec()
int ksmallestElementSum(struct Node *root, int k){
    int sum = 0;
    ksmallestElementSumRec(root, k, sum);
    return sum;
}
int main(){/* Driver program to test above functions */
    Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 22);
    int k = 3;
    cout <<  ksmallestElementSum(root, k) << endl;
    return 0;
}
