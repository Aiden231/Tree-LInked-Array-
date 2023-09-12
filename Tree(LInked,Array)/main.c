#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * rigth;
}TreeNode;

preorder(TreeNode* root) {
	if (root) {
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->rigth);
	}
}

void main()
{
	TreeNode* n1, * n2, * n3, * n4, * n5, * n6, * n7, * n8, * n9, * n10, * n11;

	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n6 = (TreeNode*)malloc(sizeof(TreeNode));
	n7 = (TreeNode*)malloc(sizeof(TreeNode));
	n8 = (TreeNode*)malloc(sizeof(TreeNode));
	n9 = (TreeNode*)malloc(sizeof(TreeNode));
	n10 = (TreeNode*)malloc(sizeof(TreeNode));
	n11 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 1;
	n1->left = n2;
	n1->rigth = n3;

	n2->data = 2;
	n2->left = n4;
	n2->rigth = n5;

	n3->data = 7;
	n3->left = n6;
	n3->rigth = n7;

	n4->data = 3;
	n4->left = n8;
	n4->rigth = n9;

	n5->data = 6;
	n5->left = NULL;
	n5->rigth = NULL;

	n6->data = 8;
	n6->left = NULL;
	n6->rigth = NULL;

	n7->data = 9;
	n7->left = n10;
	n7->rigth = n11;

	n8->data = 4;
	n8->left = NULL;
	n8->rigth = NULL;

	n9->data = 5;
	n9->left = NULL;
	n9->rigth = NULL;

	n10->data = 10;
	n10->left = NULL;
	n10->rigth = NULL;

	n11->data = 11;
	n11->left = NULL;
	n11->rigth = NULL;

	TreeNode* root = &n1;
	
	printf("전위 순회\n");
	preorder(root);
	printf("\n");

	free(n1); free(n2); free(n3);
	return 0;
}
