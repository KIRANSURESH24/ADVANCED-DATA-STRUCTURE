#include<stdio.h>
#include<stdlib.h>
struct node {
 int data;
 struct node *left, *right;
};
struct node *root=NULL;
struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* search(struct node*, int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node *minValue(struct node*);
int main(){
 int data, ch;
 struct node *node;
 printf("\n\t\tBinary Search Tree Implementation!!");
 do{
 printf("\nChoose:\n1.Insert\n2.Delete\n3.Search\n4.Display \n5. Exit\n");
 printf("\n Enter your choice:");
 scanf("%d", &ch);
 switch(ch){
 case 1:
 printf("Enter the data to be inserted: ");
 scanf("%d", &data);
 root = insert(root, data);
 break;
 case 2:
 printf("Enter the data to be deleted: ");
 scanf("%d", &data);
 root = delete(root, data);
 break;
 case 3:
 printf("Enter the data to search: ");
 scanf("%d", &data);
 node = search(root, data);
 if(node == NULL)
 printf("%d is not found!!", data);
 else
 printf("%d is found!!", data);
 break;
 case 4:
 printf("\nInorder Traversal: ");
 inorder(root);
 break;
 case 5:
 printf("\n\t\tProgram Terminated Successfully!!");
 break;
 default:
 printf("\n\t\tWrong Input!! Try Again!!\n");
 break;
 }
 }while(ch!=7);
 return 0;
}
struct node* insert(struct node *temp, int data){
 struct node *node = (struct node*)malloc(sizeof(struct node));
 node->data = data;
 node->left = node->right = NULL;
 if (temp == NULL)
 return node;
 if (data < temp->data)
 temp->left = insert(temp->left, data);
 else if (data > temp->data)
 temp->right = insert(temp->right, data);
 return temp;
}
struct node *minValue(struct node *root){
 if(root->left != NULL)
 return minValue(root->left);
 return root;
}
struct node *delete(struct node *root, int data){
 if(root == NULL)
 return root;
 if(root->data<data)
 root->right = delete(root->right, data);
 else if(root->data>data)
 root->left = delete(root->left, data);
 else{
 if(root->left == NULL){
 struct node* temp = root->right;
 free(root);
 return temp;
 }
 else if(root->right == NULL){
 struct node* temp = root->left;
 free(root);
 return temp;
 }
 else{
 struct node *temp = minValue(root->right);
 root->data = temp->data;
 root->right = delete(root->right, temp->data);
 }
 }
 return root;
}
struct node *search(struct node *root, int data){
 if(root == NULL || root->data == data)
 return root;
 if(root->data<data)
 return search(root->right, data);
 return search(root->left, data);
}
void inorder(struct node *root){
 if(root!=NULL){
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
 }
}
