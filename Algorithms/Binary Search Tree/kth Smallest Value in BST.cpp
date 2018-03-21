#include <bits/stdc++.h>
using namespace std;
struct node{// Tree structure
    int key, lCount;    // lCOunt keeps track of number of nodes in left subtree
    struct node *left, *right;
};
struct node* newNode(int keyValue){// Creating new node at leaf
    struct node* temp = new node;
    // Assign values and set left and right pointer to null
    temp->key = keyValue, temp->lCount = 0, temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, int keyValue){// Inserting values
    // Leaf node reached
    if(node == NULL)    return newNode(keyValue);
    // keyValue is less than current node key value, go left. So 1 node added to left subtree
    else if (keyValue < node->key)  node->lCount++, node->left = insert(node->left, keyValue);
    // keyValue is greater than current node key value, go right
    else if (keyValue > node->key)  node->right =insert(node->right, keyValue);
    return node;// return root node
}
struct node* minValueFinder(struct node* node){// min value finder
    struct node *current = node;// create iterator to find the min value
    while (current->left != NULL)   current = current->left; // Iterate and find
    return current;// return min key carrying node
}
int k_smallest_element(struct node* root, int k){
    int ret = -1;
    if( root ){
        struct node *itr = root;/* A crawling pointer */
        while(itr){/* Go to k-th smallest */
            if( (itr->lCount + 1) == k ){// This node is the k-th smallest value holder
                ret = itr->key;
                break;
            }
            else if( k > itr->lCount ){// There are less nodes on left subtree Go right
                k -= (itr->lCount + 1);
                itr = itr->right;
            }
            else// The node is on left subtree
                itr = itr->left;
        }
    }
    return ret;
}
int main(void){/* Driver program to test above functions */
    /* just add elements to test */
    /* NOTE: A sorted array results in skewed tree */
    int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    struct node* root = NULL;
    /* Creating the tree given in the above diagram */
    for(int i=0; i<7; i++)  root = insert(root, ele[i]);
    /*  It should print the sorted array */
    for(int i = 0; i < 7; i++)  printf("\n %d-th smallest elment is %d",i, k_smallest_element(root, i));
    return 0;
}

