#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root;
struct node* create(struct node *root,int ele);
void inorderTraversal(struct node* root);
void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);
void search(struct node *root,int d );
struct node* findsmallest(struct node *root);
void findlargest(struct node *root);
int countleaves(struct node *root);
int countnonleaves(struct node *root);
int totalnodes(struct node *root);
int height(struct node *root);
struct node* delnode(struct node *root,int ele1);
void mirrorimage(struct node *root);
main()
{
	root=NULL;
	struct node *p;
	int ch,ele,d,c,e,f,ele1;
	while(1)
	{
		printf("\nEnter 1 to insert 2 to inordertraverse 3 to preorderTraversal 4 to postorderTraversal 5 search 6 to find smallest 7 find largest 8 to count leaf nodes 9 to count non-leaf nodes 10 to count total nodes 11 to determine height 12 to delete node 13 to find mirror image 14 to exit:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the data:");
				scanf("%d",&ele);
				root=create(root,ele);
				break;
			case 2:
			    inorderTraversal(root);
			    break;
			case 3:
				preorderTraversal(root);
				break;
			case 4:
				postorderTraversal(root);
				break;
			case 5:
				printf("Enter the element to search:");
				scanf("%d",&d);
				search(root,d);
				break;
			case 6:
				p=findsmallest(root);
				printf("Smallest element is %d",p->data);
				break;
			case 7:
				findlargest(root);
				break;
			case 8:
				c=countleaves(root);
				printf("Number of leaf nodes are:%d\n",c);
				break;
			case 9:
				d=countnonleaves(root);
				printf("Number of non leaf nodes are:%d\n",d);
				break;
			case 10:
				e=totalnodes(root);
				printf("Total nodes:%d\n",e);
				break;
			case 11:
				f=height(root);
				printf("Height of the tree is:%d\n",f);
				break;
			case 12:
				printf("Enter the element:");
				scanf("%d",&ele1);
				root=delnode(root,ele1);
				break;
			case 13:
				mirrorimage(root);
				break;
			case 14:
				exit(1);
		}
	}
}
 struct node* create(struct node *root,int ele)
 {
 	if(root==NULL)
 	{
 		struct node *temp=(struct node*)malloc(sizeof(struct node));
 		temp->data=ele;
 		temp->left=NULL;
 		temp->right=NULL;
 		return temp;
	 }
	else if(ele<=root->data)
	{
		root->left=create(root->left,ele);
	}
	else{
		root->right=create(root->right,ele);
	}
 }
 void inorderTraversal(struct node* root) {
  if (root == NULL) 
  return;
  else
  {
  inorderTraversal(root->left);
  printf("%d ->", root->data);
  inorderTraversal(root->right);
}
}
void preorderTraversal(struct node* root) {
  if (root == NULL) 
  return;
  else
  {
  printf("%d ->", root->data);
  inorderTraversal(root->left);
  inorderTraversal(root->right);
}
}
void postorderTraversal(struct node* root) {
  if (root == NULL) 
  return;
  else
  {
  inorderTraversal(root->left);
  inorderTraversal(root->right);
  printf("%d ->", root->data);
}
}
void search(struct node *root,int d ){
	if(root==NULL)
	printf("Not found");
	else if(root->data==d)
	printf("Element found");
	else if(d<=root->data)
	search(root->left,d);
	else
	search(root->right,d);
}
struct node* findsmallest(struct node *root)
{
	if(root==NULL)
	printf("Empty Tree");
	else if(root->left==NULL)
	return root;
	else
	return findsmallest(root->left);
}
void findlargest(struct node *root)
{
	if(root==NULL)
	printf("Empty Tree");
	else if(root->right==NULL)
	printf("Largest element in the tree is:%d",root->data);
	else
	findlargest(root->right);
}
int countleaves(struct node *root){
	if(root==NULL)
	return 0;
	else if(root->left==NULL && root->right==NULL)
	return 1;
	else
	return (countleaves(root->left)+countleaves(root->right));
}
int countnonleaves(struct node *root){
	if(root==NULL || root->left==NULL && root->right==NULL)
	return 0;
	else
	return (countnonleaves(root->left)+countnonleaves(root->right)+1);
}
int totalnodes(struct node *root)
{
	if(root==NULL)
	return 0;
	else
	return (totalnodes(root->left)+totalnodes(root->right)+1);
}
int height(struct node *root)
{
	int lheight,rheight;
	if(root==NULL)
	return 0;
	else
	{
		lheight=height(root->left);
		rheight=height(root->right);
	}
	if(lheight>rheight)
	return ++lheight;
	else
	return ++rheight;
}
struct node* delnode(struct node *root,int ele1)
{
	if(root==NULL)
	return root;
    else if(ele1<root->data)
    root->left=delnode(root->left,ele1);
	else if(ele1>root->data)
	root->right=delnode(root->right,ele1);
	else
	{
		//case 1:having no child
		if(root->left==NULL && root->right==NULL)
		{
			struct node *temp=root;
			free(temp);
			root=NULL;
		}
		// case 2:having 1 child in the right
		else if(root->left==NULL)
		{
			struct node *temp=root;
			root=root->right;
			free(temp);
		}
		//case 3:havig 1 child in the left
		else if(root->right==NULL)
		{
			struct node *temp=root;
			root=root->left;
			free(temp);
		}
		//case 4:having 2 child
		else
		{
			struct node *temp=findsmallest(root->right);
			root->data=temp->data;
			root->right=delnode(root->right,temp->data);
		}
	}
return root;	
}
void mirrorimage(struct node *root)
{
	struct node *temp;
	if(root!=NULL)
	{
		mirrorimage(root->left);
		mirrorimage(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
