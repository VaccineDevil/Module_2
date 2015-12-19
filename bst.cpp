#include "stdafx.h"
#include "bst.h"
#include "iostream"
using namespace std;

bst::bst()
{
	leftSubtree = NULL;
	rightSubtree = NULL;
	value = 0;
}



bst::bst(int val)
{
	leftSubtree = NULL;
	rightSubtree = NULL;
	value = val;
}



bst::~bst()
{

}





void bst::addNode(bst *root, int key)
{
	if (key < root->value){

		if (root->leftSubtree){
			addNode(root->leftSubtree, key);
		}
		else{
			root->leftSubtree = new bst(key);
		}
	}

	if (key >= root->value){
		if (root->rightSubtree){
			addNode(root->rightSubtree, key);
		}
		else{
			root->rightSubtree = new bst(key);
		}
	}
}




void bst::addNodeWrapper(int key){
	addNode(this, key);
}



//bst bst::find(bst *root, int key)
bst* bst::find(bst *root, int key)
{

	if (!root) return NULL;
	if (key == root->value)
		//return *root;
		return root;
	if (key < root->value)
	{
		return (find(root->leftSubtree, key));
	}
	else
	{
		return find(root->rightSubtree, key);
	}

}



void bst::findWrapper(int key){
	find(this, key);
}


//bst bst::delNode(bst *root, int key)
bool bst::delNode(bst *root, int key)
{
	//bool flag = false;
	bst *min = NULL;
	bst *pv = NULL;
	pv = find(root, key);
	if (pv != NULL)
	{
		if (pv->leftSubtree != NULL && pv->rightSubtree != NULL)
		{
			*min = minimum(pv->rightSubtree);
			pv->value = (min)->value;
			*(pv->rightSubtree) = delNode(pv, (pv->rightSubtree)->value);
		}
		else
		{
			if (pv->leftSubtree != NULL)
				pv = pv->leftSubtree;
			if (pv->rightSubtree != NULL)
				pv = pv->rightSubtree;
		}
		if (pv->leftSubtree == NULL && pv->rightSubtree == NULL)
		{
			pv = find(root, key);
			pv->leftSubtree = 0;
		}

		//return *pv;
		return true;
	}
	else
		return false;
}

bst bst::minimum(bst *root)
{
	bst *pv = root;
	while (pv->leftSubtree)
		pv = pv->leftSubtree;
	return *pv;
}


void bst::delNodeWrapper(int key){
	delNode(this, key);
}





void bst::inorder(bst*root)
{
	cout << endl;
	if (root)
	{
		cout << root->value;
		if (root->leftSubtree != 0)
		{
			inorder(root->leftSubtree);
		}
		if (root->rightSubtree != 0)
		{
			inorder(root->rightSubtree);
		}
	}
}


bst* bst::find1(bst *root, int key, bst *before)
{
	if (!root) return NULL;
	
	if (key < root->value)
	{
		before = root;
		return (find1(root->leftSubtree, key, before));
	} 
		if (key > root->value)
		{
		before = root;
		return find1(root->rightSubtree, key, before);
		}
		else
			if (key == root->value)
				return before;

}
void bst::delNodeWrapper1(int key){
	bst *t = NULL;
	delNode1(this, key);
}
bool bst::delNode1(bst *root, int key)
{
	//bool flag = false;
	bst *min = NULL;
	bst *pv = NULL;
	bst *pvl = NULL;
	bst *before = NULL;
 	pvl = find1(root, key,before);
	pv = pvl->leftSubtree;
	if (pv != NULL)
	{
		if (pv->leftSubtree != NULL && pv->rightSubtree != NULL)
		{
			*min = minimum(pv->rightSubtree);
			pv->value = (min)->value;
			*(pv->rightSubtree) = delNode(pv, (pv->rightSubtree)->value);
		}
		else
		{
			if (pv->leftSubtree == NULL && pv->rightSubtree == NULL)
				pv == NULL;
			if (pv->leftSubtree != NULL)
				pv = pv->leftSubtree;
			if (pv->rightSubtree != NULL)
				pv = pv->rightSubtree;

			
		}


		//return *pv;
		return true;
	}
	else
		return false;
}
