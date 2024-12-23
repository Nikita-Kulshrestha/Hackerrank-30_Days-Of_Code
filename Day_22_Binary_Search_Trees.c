/*The height of a binary search tree is the number of edges between the tree's root and its furthest leaf. 
You are given a pointer,root , pointing to the root of a binary search tree. 
Complete the getHeight function provided in your editor so that it returns the height of the BST.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}


#include <math.h>
int getHeight(Node* root)
{
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (int)(fmax(leftHeight, rightHeight)) + 1;
}

Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    int height=getHeight(root);
    printf("%d",height);
    return 0;
    
}