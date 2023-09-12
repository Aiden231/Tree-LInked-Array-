#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// LInked ������ ���� ����ü ����
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * rigth;
}TreeNode;

// ���� Ʈ�� LInked�� ����
TreeNode n11 = { 11,NULL,NULL };
TreeNode n10 = { 10,NULL,NULL };
TreeNode n9 = { 9, &n10,&n11 };
TreeNode n8 = { 8, NULL,NULL };
TreeNode n7 = { 7, &n8,&n9 };
TreeNode n6 = { 6,NULL,NULL };
TreeNode n5 = { 5, NULL,NULL };
TreeNode n4 = { 4,NULL,NULL };
TreeNode n3 = { 3,&n4,&n5 };
TreeNode n2 = { 2,&n3,&n6 };
TreeNode n1 = { 1,&n2,&n7 };

// ��Ʈ�� n1 �̴�.
TreeNode* root = &n1;

// LInked ���� ��ȸ
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->rigth);
	}
}

// LInked ���� ��ȸ
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->rigth);
	}
}

// LInked ���� ��ȸ
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->rigth);
		printf("%d ", root->data);
	}
}

int Arraytree[16];

// Array ���� ��� �Լ�
void preorder_Array(int Arraytree[], int index)
{
	if (index >= 16) return; // �迭 ���� �Ѿ�� ����

	if (Arraytree[index] == -1) // -1 = NULL / NULL �� ��� ������� ����
	{
		preorder_Array(Arraytree, index * 2); // ���� �ڽ�
		preorder_Array(Arraytree, index * 2 + 1); // ������ �ڽ�
	}

	else 
	{
		printf("%d ", Arraytree[index]);
		preorder_Array(Arraytree, index * 2); // ���� �ڽ�
		preorder_Array(Arraytree, index * 2 + 1); // ������ �ڽ�
	}
}

// Array ���� ��� �Լ�
void inorder_Array(int Arraytree[], int index)
{
	if (index >= 16) return; // �迭 ���� �Ѿ�� ����

	if (Arraytree[index] == -1) // -1 = NULL / NULL �� ��� ������� ����
	{
		inorder_Array(Arraytree, index * 2); // ���� �ڽ�
		inorder_Array(Arraytree, index * 2 + 1); // ������ �ڽ�
	}

	else
	{
		inorder_Array(Arraytree, index * 2); // ���� �ڽ�
		printf("%d ", Arraytree[index]);
		inorder_Array(Arraytree, index * 2 + 1); // ������ �ڽ�
	}
}

// Array ���� ��� �Լ�
void postorder_Array(int Arraytree[], int index)
{
	if (index >= 16) return; // �迭 ���� �Ѿ�� ����

	if (Arraytree[index] == -1) // -1 = NULL / NULL �� ��� ������� ����
	{
		postorder_Array(Arraytree, index * 2); // ���� �ڽ�
		postorder_Array(Arraytree, index * 2 + 1); // ������ �ڽ�
	}

	else
	{
		postorder_Array(Arraytree, index * 2); // ���� �ڽ�
		postorder_Array(Arraytree, index * 2 + 1); // ������ �ڽ�
		printf("%d ", Arraytree[index]);
	}
}

int main()
{
	// Linked ���� ��ȸ ���
	printf("<Linked Tree>\n");
	// Linked������ȸ ���
	printf("1. ���� ��ȸ\n");
	preorder(root);
	printf("\n\n");
	// LInked ������ȸ ���
	printf("2. ���� ��ȸ\n");
	inorder(root);
	printf("\n\n");
	// LInked ������ȸ ���
	printf("3. ���� ��ȸ\n");
	postorder(root);
	printf("\n\n");

	// Arraytree ����
	int Arraytree[] = { -1, 1, 2, 7, 3, 6, 8, 9, 4, 5, -1, -1, -1, -1, 10, 11 }; // -1 = NULL
	int index = 1; // ��Ʈ���� ����

	printf("<Array Tree>\n");
	// �迭 ���� ������ȸ ���
	printf("1. ���� ��ȸ\n");
	preorder_Array(Arraytree, index);
	printf("\n\n");

	//�迭 ���� ������ȸ ���
	printf("2. ���� ��ȸ\n");
	inorder_Array(Arraytree, index);
	printf("\n\n");

	//�迭 ���� ������ȸ ���
	printf("3. ���� ��ȸ\n");
	postorder_Array(Arraytree, index);
	printf("\n\n");
	
	return 0;
}
