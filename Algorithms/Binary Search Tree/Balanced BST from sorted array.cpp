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
// A function that constructs Balanced Binary Search Tree from a sorted array
struct node* sortedArrayToBST(int arr[], int start, int end){
    if (start > end)    return NULL;    // base case
    int mid = (start+end)/2;  // make middle element the root
    struct node *root = newNode(arr[mid]);
// Recursively construct the left subtree and make it left child of root
    root->left =  sortedArrayToBST(arr, start, mid-1);
// Recursively construct the right subtree and make it right child of root
    root->right = sortedArrayToBST(arr, mid+1, end);
    return root;
}
void preOrder(struct node* node){// A utility function to print preorder traversal of BST
    if (node == NULL)   return;
    printf("%d ", node->key);
    preOrder(node->left), preOrder(node->right);
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7}, n = sizeof(arr)/sizeof(arr[0]);
    struct node *root = sortedArrayToBST(arr, 0, n-1);// Convert List to BST
    printf("n PreOrder Traversal of constructed BST ");
    preOrder(root);
    return 0;
}
