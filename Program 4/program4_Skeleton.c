//Name:
//Dr. Steinberg
//COP3502C Computer Science 1
//Programming Assignment 4

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
	int data;
	struct node_s * leftchild;
	struct node_s * rightchild;
}node_t;

node_t * createNode(int val);
node_t* insertLeft(node_t* root, int value);
node_t* insertRight(node_t* root, int value);
void postorder(node_t * root);
void preorder(node_t * root);
//node_t * addTree(node_t * t1, node_t * t2);
//node_t * subtractTree(node_t * t1, node_t * t2);

int main()
{
	node_t * tree1 = createNode(1);
	node_t * tree2 = createNode(6);
	
	insertLeft(tree1, 4);
	insertRight(tree1, 6);
	insertLeft(tree1->leftchild, 7);
	insertLeft(tree1->rightchild, 5);
	insertRight(tree1->rightchild, 1);
	
	insertLeft(tree2, 3);
	insertRight(tree2, 3);
	insertLeft(tree2->leftchild, 1);
	insertRight(tree2->leftchild, 9);
	insertRight(tree2->rightchild, 8);
	
	printf("Testing Add...\n");
	
	//node_t * addresult = addTree(tree1, tree2);
	
	printf("Now Displaying Add Result...\n");
	
	//preorder(addresult);
	printf("\n");
	//postorder(addresult);
	printf("\n");
	
	node_t * tree3 = createNode(4);
	node_t * tree4 = createNode(6);
	
	insertLeft(tree3, 6);
	insertRight(tree3, 6);
	insertLeft(tree3->rightchild, 5);
	
	insertLeft(tree4, 2);
	insertRight(tree4, 1);
	insertLeft(tree4->leftchild, 8);
	insertRight(tree4->leftchild, 4);
	
	printf("Testing Subtract...\n");
	
	//node_t * subresult = subtractTree(tree3, tree4);
	
	printf("Now Displaying Subtract Result...\n");
	
	//preorder(subresult);
	printf("\n");
	//postorder(subresult);
	printf("\n");
	
	return 0;
}

//creates a new node
node_t * createNode(int val)
{
	node_t * node = (node_t *) malloc(sizeof(node_t));
	
	if(node == NULL)
	{
		printf("malloc not successful\n");
		return NULL;
	}

	node->data = val;
	
	node->leftchild = NULL;
	node->rightchild = NULL;
	
	return node;
}

//inserts to the left child
node_t* insertLeft(node_t* root, int value) 
{
  root->leftchild = createNode(value);
  return root->leftchild;
}

//inserts to the right child
node_t* insertRight(node_t* root, int value) 
{
  root->rightchild = createNode(value);
  return root->rightchild;
}


//postorder display
void postorder(node_t * root)
{
	if(root != NULL)
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%d\t", root->data);
	}	
}

//preorder display
void preorder(node_t * root)
{
	if(root != NULL)
	{
		printf("%d\t", root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}