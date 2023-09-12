#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// LInked 구현을 위한 구조체 생성
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * rigth;
}TreeNode;

// 이진 트리 LInked로 구현
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

// 루트는 n1 이다.
TreeNode* root = &n1;

// LInked 전위 순회
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->rigth);
	}
}

// LInked 중위 순회
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->rigth);
	}
}

// LInked 후위 순회
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->rigth);
		printf("%d ", root->data);
	}
}

int Arraytree[16];

// Array 전위 출력 함수
void preorder_Array(int Arraytree[], int index)
{
	if (index >= 16) return; // 배열 범위 넘어가실 종료

	if (Arraytree[index] == -1) // -1 = NULL / NULL 일 경우 출력하지 않음
	{
		preorder_Array(Arraytree, index * 2); // 왼쪽 자식
		preorder_Array(Arraytree, index * 2 + 1); // 오른쪽 자식
	}

	else 
	{
		printf("%d ", Arraytree[index]);
		preorder_Array(Arraytree, index * 2); // 왼쪽 자식
		preorder_Array(Arraytree, index * 2 + 1); // 오른쪽 자식
	}
}

// Array 중위 출력 함수
void inorder_Array(int Arraytree[], int index)
{
	if (index >= 16) return; // 배열 범위 넘어가실 종료

	if (Arraytree[index] == -1) // -1 = NULL / NULL 일 경우 출력하지 않음
	{
		inorder_Array(Arraytree, index * 2); // 왼쪽 자식
		inorder_Array(Arraytree, index * 2 + 1); // 오른쪽 자식
	}

	else
	{
		inorder_Array(Arraytree, index * 2); // 왼쪽 자식
		printf("%d ", Arraytree[index]);
		inorder_Array(Arraytree, index * 2 + 1); // 오른쪽 자식
	}
}

// Array 후위 출력 함수
void postorder_Array(int Arraytree[], int index)
{
	if (index >= 16) return; // 배열 범위 넘어가실 종료

	if (Arraytree[index] == -1) // -1 = NULL / NULL 일 경우 출력하지 않음
	{
		postorder_Array(Arraytree, index * 2); // 왼쪽 자식
		postorder_Array(Arraytree, index * 2 + 1); // 오른쪽 자식
	}

	else
	{
		postorder_Array(Arraytree, index * 2); // 왼쪽 자식
		postorder_Array(Arraytree, index * 2 + 1); // 오른쪽 자식
		printf("%d ", Arraytree[index]);
	}
}

int main()
{
	// Linked 구현 순회 출력
	printf("<Linked Tree>\n");
	// Linked전위순회 출력
	printf("1. 전위 순회\n");
	preorder(root);
	printf("\n\n");
	// LInked 중위순회 출력
	printf("2. 중위 순회\n");
	inorder(root);
	printf("\n\n");
	// LInked 후위순회 출력
	printf("3. 후위 순회\n");
	postorder(root);
	printf("\n\n");

	// Arraytree 생성
	int Arraytree[] = { -1, 1, 2, 7, 3, 6, 8, 9, 4, 5, -1, -1, -1, -1, 10, 11 }; // -1 = NULL
	int index = 1; // 루트부터 시작

	printf("<Array Tree>\n");
	// 배열 구현 전위순회 출력
	printf("1. 전위 순회\n");
	preorder_Array(Arraytree, index);
	printf("\n\n");

	//배열 구현 중위순회 출력
	printf("2. 중위 순회\n");
	inorder_Array(Arraytree, index);
	printf("\n\n");

	//배열 구현 후위순회 출력
	printf("3. 후위 순회\n");
	postorder_Array(Arraytree, index);
	printf("\n\n");
	
	return 0;
}
