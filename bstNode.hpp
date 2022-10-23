/*
 * bstNode.hpp
 *
 *  Created on: Oct 10, 2022
 *      Author: Kkpau
 */

#ifndef BSTNODE_HPP_
#define BSTNODE_HPP_
#include "Student.hpp"
class bstNode {
	friend class bst;
	Student *student;
	bstNode *left;
	bstNode *right;
	bstNode *parent;
	int height;
public:
	bstNode();
	bstNode(string first, string last, int num,string joke);
	~bstNode();
	void printNode();

};





#endif /* BSTNODE_HPP_ */




