/*
 * bstNode.cpp
 *
 *  Created on: Oct 10, 2022
 *      Author: Kkpau
 */



#include "bst.hpp"
#include <stdlib.h>
#include <iostream>
#include "bstNode.hpp"
using namespace std;

bstNode::bstNode(){
	left=NULL;
	right =NULL;
	parent = NULL;
	height=0;
	student=NULL;

}
bstNode::bstNode( string first, string last, int num,string joke){
student = new Student(first,last,num,joke);
right=NULL;
left=NULL;
parent=NULL;
height=0;
}
bstNode::~bstNode(){
		cout<< " destroying "<<this->student->last<<", "<<this->student->first<<endl;
		//delete(this->student);
}
void bstNode::printNode(){
	cout<<"node height: "<<height<<" student name: "<<student->last<<", "<<student->first<<endl;
	cout<<"favorite joke: "<<student->joke<<endl;
	cout<<"favorite number: "<<student->fav_num<<endl;

	cout << "************************************" << endl;


}






