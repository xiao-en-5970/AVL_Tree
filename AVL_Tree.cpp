#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a >= b ? a : b;
}

typedef struct treenode
{
	int Data;
	struct treenode* LeftChild = nullptr;
	struct treenode* RightChild = nullptr;
	int Height = 0;
} Tree, * PTree;

int Get_Height(PTree root)
{
	if (root == nullptr)
	{
		return -1;
	}
	else
	{
		return root->Height;
	}
}

PTree Create_Root(int data);
PTree Insert_Tree(int data, PTree root);
void Print_Tree_P(PTree root);
void Print_Tree_M(PTree root);
void Print_Tree_L(PTree root);
PTree Single_Rotate_Left(PTree root);
PTree Single_Rotate_Right(PTree root);
PTree Double_Rotate_Left(PTree root);
PTree Double_Rotate_Right(PTree root);
void Print_Tree_Height(PTree root);


int main()
{
	PTree root = Create_Root(2);
	root = Insert_Tree(1, root);
	root = Insert_Tree(3, root);
	root = Insert_Tree(5, root);
	
	root = Insert_Tree(4, root);
	Print_Tree_P(root);
	cout << endl;
	Print_Tree_Height(root);
	return 0;
}

PTree Create_Root(int data)
{
	PTree root = new Tree;
	root->Data = data;
	return root;
}

PTree Insert_Tree(int data, PTree root)
{
	if (root == nullptr)
	{
		PTree newNode = new Tree;
		root = newNode;
		newNode->Data = data;
	}
	else if (data < root->Data)
	{
		root->LeftChild = Insert_Tree(data, root->LeftChild);
		if (Get_Height(root->LeftChild) - Get_Height(root->RightChild) == 2)
		{
			if (data < root->LeftChild->Data)
			{
				root = Single_Rotate_Left(root);
			}
			else
			{
				root = Double_Rotate_Left(root);
			}
		}

	}
	else if (data > root->Data)
	{
		root->RightChild = Insert_Tree(data, root->RightChild);
		if (Get_Height(root->RightChild) - Get_Height(root->LeftChild) == 2)
		{
			if (data > root->RightChild->Data)
			{
				//cout <<root->Data << endl;
				root = Single_Rotate_Right(root);
			}
			else
			{
				root = Double_Rotate_Right(root);
			}
		}
	}
	root->Height = max(Get_Height(root->LeftChild), Get_Height(root->RightChild)) + 1;
	return root;
}

void Print_Tree_P(PTree root)
{
	cout << root->Data << " ";
	if (root->LeftChild != nullptr)
	{
		Print_Tree_P(root->LeftChild);
	}
	if (root->RightChild != nullptr)
	{
		Print_Tree_P(root->RightChild);
	}
}

void Print_Tree_M(PTree root)
{

	if (root->LeftChild != nullptr)
	{
		Print_Tree_M(root->LeftChild);
	}
	cout << root->Data << " ";
	if (root->RightChild != nullptr)
	{
		Print_Tree_M(root->RightChild);
	}
}

void Print_Tree_L(PTree root)
{

	if (root->LeftChild != nullptr)
	{
		Print_Tree_L(root->LeftChild);
	}
	if (root->RightChild != nullptr)
	{
		Print_Tree_L(root->RightChild);
	}
	cout << root->Data << " ";
}



PTree Single_Rotate_Left(PTree root)
{
	PTree r = root;
	root = root->LeftChild;
	r->LeftChild = root->RightChild;
	root->RightChild = r;

	r->Height = max(Get_Height(root->LeftChild), Get_Height(root->RightChild)) + 1;
	root->Height = max(Get_Height(root->LeftChild), Get_Height(root->RightChild)) + 1;

	return root;
}
PTree Single_Rotate_Right(PTree root)
{
	PTree r = root;
	root = root->RightChild;
	r->RightChild = root->LeftChild;
	root->LeftChild = r;
	r->Height = max(Get_Height(root->LeftChild), Get_Height(root->RightChild)) + 1;
	root->Height = max(Get_Height(root->LeftChild), Get_Height(root->RightChild)) + 1;

	return root;

}
PTree Double_Rotate_Left(PTree root)
{
	root->LeftChild = Single_Rotate_Right(root->LeftChild);
	return Single_Rotate_Left(root);
}
PTree Double_Rotate_Right(PTree root)
{
	root->RightChild = Single_Rotate_Left(root->RightChild);
	return Single_Rotate_Right(root);
}

void Print_Tree_Height(PTree root)
{

	if (root->LeftChild != nullptr)
	{
		Print_Tree_Height(root->LeftChild);
	}
	cout << root->Height << " ";
	if (root->RightChild != nullptr)
	{
		Print_Tree_Height(root->RightChild);
	}
}