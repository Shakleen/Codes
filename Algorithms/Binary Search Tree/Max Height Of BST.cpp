#include <bits/stdc++.h>
using namespace std;
struct node{// Tree structure
    int key;
    struct node *left, *right;
};
struct node* newNode(int keyValue){// Creating new node at leaf
    struct node* temp = new node;
    // Assign values and set left and right pointer to null
    temp->key = keyValue, temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, int keyValue){// Inserting values
    // Leaf node reached
    if(node == NULL)    return newNode(keyValue);
    // keyValue is less than current node key value, go left
    else if (keyValue < node->key)  node->left = insert(node->left, keyValue);
    // keyValue is greater than current node key value, go right
    else if (keyValue > node->key)  node->right =insert(node->right, keyValue);
    return node;// return root node
}
int maxHeight(struct node* root){
    if (root == NULL)   return 0;
    return (max( maxHeight(root->left) , maxHeight(root->right) ) + 1);
}
int main(){// Driver Program to test above functions
    int a[] = {50,30,20,40,70,60,80};
    struct node *root = NULL;
    for(int i=0; i<7; i++)	root = insert(root, a[i]);
    cout << maxHeight(root) << endl;
    return 0;
}
