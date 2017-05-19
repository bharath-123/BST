#ifndef NODE_H

#define Node_H

struct Node{
	int data; 
	Node*right,*left; 
};

Node*createnewnode(int data){
	Node*newNode = new Node ;
	newNode -> data = data ;
 	newNode -> right = newNode -> left = NULL; 
	return newNode ;
	
}

#endif
