
/*
 * bst.cpp
 *
 *  Created on: Oct 16, 2022
 *      Author: Kkpau
 */
#include "bstNode.hpp"
#include "bst.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;
bst::bst() {  // empty constructor
	root = NULL;
}

bst::bst(string f, string l, int n, string j) {  // constructor that forms the root
	root = new bstNode( f,l,  n,  j);
}

void bst::clearTree() {  	//clears out an old tree
//This calls the recursive clearTree with the root node
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void bst::clearTree(bstNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}

/*Note: the following three functions’ sole job is to call printTreeIO(BstNode *t),printTreePre(BstNode *t), and printTreePost(BstNode *t) while printint out which
Function is being called.
YOU MUST STILL WRITE THE RECURSIVE VERSION OF THESE FUNCTIONS!!!*/

void bst::printTreeIO() {  // Just the start – you must write the recursive version
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}
void bst::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}
void bst::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}





bool bst::insert(string f, string l, int n, string j){
	//Need to use set heights once written
	bstNode *curr =root;
	bstNode *N = new bstNode(f, l, n, j);
	while (true){
		if(curr==NULL){
			root=N;
			setHeight(N);
			return true;
		}
		else if( curr->student->last<l){
			if(curr->right!=NULL){
				curr=curr->right;
			}else{
				curr->right=N;
				N->parent=curr;
				setHeight(N);
				return true;
			}
		}else if( curr->student->last>l){
			if(curr->left!=NULL){
						curr=curr->left;
					}else{
						curr->left=N;
						N->parent=curr;
						setHeight(N);
						return true;
					}
		}else if( curr->student->last==l){
			//compare first then insert or set curr accordingly
			if(curr->student->first>f){
				if(curr->left!=NULL){
										curr=curr->left;
									}else{
										curr->left=N;
										N->parent=curr;
										setHeight(N);
										return true;
									}
			}else if(curr->student->first<f){
				if(curr->right!=NULL){
								curr=curr->right;
							}else{
								curr->right=N;
								N->parent=curr;
								setHeight(N);
								return true;
							}
			}else if(curr->student->first==f){
				return false;
			}

		}
	}
	return false;
}



bstNode *bst::find(string l,string f){
	bstNode *curr = root;
	bstNode *ret = NULL;
	//int count =0;
	while (true){
		if(curr->left==NULL&&curr->right==NULL&&curr->student->last!=l){
			return NULL;
}
		if( curr->student->last<l){
			if(curr->right!=NULL){
				curr=curr->right;
			}
		}else if( curr->student->last>l){
			if(curr->left!=NULL){
						curr=curr->left;
			}
		}else if( curr->student->last==l){
			//compare first then insert or set curr accordingly
			if(curr->student->first>f){
				curr=curr->left;

		}else if(curr->student->first<f){
			curr=curr->right;
		}else if(curr->student->first==f){
			ret = curr;
			ret->printNode();
			return ret;
		}
	}


}
	ret = curr;
	ret->printNode();
	return ret;
}
void bst::printTreeIO(bstNode *n){
	if(n==NULL){
		return;
	}
	else{
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}


void bst::printTreePre(bstNode *n){
	if(n==NULL){
		return;
	}
	else{
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}
void bst::printTreePost(bstNode *n){
	if(n==NULL){
		return;
	}
	else{
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}


bstNode *bst::remove(string l, string f){
	bstNode *curr = root;
	bstNode *ret=NULL;
	bstNode *lowest = NULL;
	while (true){
		if(curr->left==NULL&&curr->right==NULL&&curr->student->last!=l){
			return NULL;
		}
		if( curr->student->last<l){
			if(curr->right!=NULL){
				curr=curr->right;
			}
		}else if( curr->student->last>l){
			if(curr->left!=NULL){
						curr=curr->left;
			}
		}else if( curr->student->last==l){

			if(curr->student->first>f){
				curr=curr->left;

		}else if(curr->student->first<f){
			curr=curr->right;
		}else if(curr->student->last==f){
		//now add cases on what to remove
			break;
		}
			//case for 0 children
			if(curr->left==NULL&&curr->right ==NULL){
			ret=removeNoKids(curr);
			return ret;
			}
			//case for 1 child
			else if((curr->left==NULL&&curr->right !=NULL)||(curr->left!=NULL&&curr->right ==NULL)){
				if(curr->left!=NULL){
				ret=removeOneKid(curr,true);
				return ret;
				}else{
					ret=removeOneKid(curr,false);
					return ret;
				}
			}
			//case for 2 kids
			lowest=curr;
			//determining lowest node on the right subtree
			//first check that left tree is not null then loop until right is null
			if(lowest->left!=NULL){
				lowest = lowest->left;
			}
			while(lowest->right!=NULL){
				lowest = lowest->right;
			}
			//now that we have found left childs right most val, we can replace the returned node with this one
			ret=curr;
			//hndles if left is lowest
			if(curr->left==lowest){
				//switch parent


						if(curr->parent->right==curr){
							curr->parent->right=lowest;
							lowest->right=curr->right;
							lowest->right->parent=lowest;
						}else{
							                              //does not clear curr parent??
							curr->parent->left=lowest;
							//now switch kids to lowest
							lowest->right=curr->right;
							lowest->right->parent=lowest;
						}
						lowest->parent=curr->parent;
						break;
			}else{
			//now I need to handle if the node is not the first to the left of curr

				//if the right most node has a left node, then set the lowest parent to the right node
				if(lowest->left!=NULL){
					lowest->parent->right=lowest->left;
					lowest->left->parent=lowest->parent;
				}
				//now swithing children
				lowest->left=curr->left;
				lowest->left->parent=lowest;
				lowest->right=curr->right;
				lowest->right->parent=lowest;
			    // now switching currs parent poitner to lower

				//first, have lowest parent point to curr parent
				lowest->parent=curr->parent;
				//now, detrmine if the node we are switching is a left or right child.

				if(curr->parent->right==curr){
					curr->parent->right=lowest;
				}else{
					curr->parent->left=lowest;
				}



			}

			break;

	}

}
	bst::setHeight(lowest);
	return ret;
}

bstNode *bst::removeNoKids(bstNode *tmp){
	if(tmp->parent->right==tmp){
		tmp->parent->right=NULL;
		tmp->parent=NULL;
	}else{
		tmp->parent->left=NULL;
		tmp->parent=NULL;
	}
	setHeight(tmp->parent);
	return tmp;
}

bstNode *bst::removeOneKid(bstNode *tmp, bool leftFlag){
	//if the node is a left child
	bstNode *t=tmp->parent;
	if(leftFlag==true){
		if(tmp->parent->right==tmp){
			tmp->parent->right=tmp->left;
			tmp->left->parent=tmp->parent;
			tmp->parent=NULL;
		}else{
			tmp->parent->left=tmp->left;
			tmp->left->parent=tmp->parent;
			tmp->parent=NULL;
		}

//if the node is a right child
	}else{
		if(tmp->parent->right==tmp){
				tmp->parent->right=tmp->right;
				tmp->right->parent=tmp->parent;
			}else{
				tmp->parent->left=tmp->right;
				tmp->right->parent=tmp->parent;
				tmp->parent=NULL;
			}

	}
	setHeight(t);
	return tmp;
}

void bst::setHeight(bstNode *n){
//	if(n!=NULL){
//	n->height=n->height+1;
//	setHeight(n->parent);
//
//	}else{
//		return;
//	}
	while(n!=NULL){
		int add=1;
		int leftH=0;
		int rightH=0;
		if(n->left!=NULL){
			leftH=n->left->height;
		}
		if(n->right!=NULL){
			rightH=n->right->height;
		}
		if(leftH>rightH){
			add=add+leftH;
		}
		else if(leftH<rightH){
				add=add+rightH;
				}
		else if(leftH==rightH){
				add=add+rightH;
			}

		n->height=add;
		n=n->parent;
	}
}




