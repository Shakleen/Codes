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
struct node* minValueFinder(struct node* node){// min value finder
    struct node *current = node;// create iterator to find the min value
    while (current->left != NULL)   current = current->left; // Iterate and find
    return current;// return min key carrying node
}
struct node* deleteNode(struct node* node, int keyValue){// node deleter
    if (node == NULL)   return node; // Base case
    else if (keyValue < node->key)  node->left = deleteNode(node->left, keyValue);
    else if (keyValue > node->key)  node->right = deleteNode(node->right, keyValue);
    else{ // Key value is the same as current node value
        struct node* temp;// temp variable to handle swapping operation
        if (node->left == NULL){// Node has only 1 child
            temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL){// Node has only 1 child
            temp = node->left;
            free(node);
            return temp;
        }
        else{// Node has 2 child
            temp = minValueFinder(node->right); // Find the minimum value in the right sub tree
            node->key = temp->key; // change the key value to the one found in the right sub tree
            node->right = deleteNode(node->right, temp->key); // delete the min value node found in the sub tree
        }
    }
    return node;
}
struct node* findNode(struct node* node, int keyValue){// node finder
    struct node* cur;
    if (node == NULL || keyValue == node->key) cur = node; // Base case & found case
    else if (keyValue < node->key)  cur = findNode(node->left, keyValue);
    else if (keyValue > node->key)  cur = findNode(node->right, keyValue);
    return cur;
}
void inOrder(struct node *root){// In Order Traversal
    if (root != NULL){
        inOrder(root->left);
        printf("%d \n", root->key);
        inOrder(root->right);
    }
}
void preOrder(struct node *root){// Pre Order Traversal
    if (root != NULL){
        printf("%d \n", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root){// Post Order Traversal
    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d \n", root->key);
    }
}
int main(){// Driver Program to test above functions
    int a[] = {50,30,20,40,70,60,80};
    struct node *root = NULL;
    for(int i=0; i<7; i++)	root = insert(root, a[i]);
    printf("inOrder traversal of the given tree \n");       inOrder(root);
    printf("Pre-Order traversal of the given tree \n");     preOrder(root);
    printf("Post-Order traversal of the given tree \n");    postOrder(root);
    printf("\nDelete 20\n");                                root = deleteNode(root, 20);
    printf("inOrder traversal of the modified tree \n");    inOrder(root);
    printf("\nDelete 30\n");                                root = deleteNode(root, 30);
    printf("inOrder traversal of the modified tree \n");    inOrder(root);
    printf("\nDelete 50\n");                                root = deleteNode(root, 50);
    printf("inOrder traversal of the modified tree \n");    inOrder(root);
    return 0;
}
