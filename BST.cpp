#ifndef BST_H

#define BST_H

#include "NODE.h"
#include<iostream>

void insert(Node**root,int data){
	Node*newNode = createnewnode(data);
	if(*root == NULL){
		*root = newNode;
	}
	else{
		if((*root) -> data > data){
			(*(root) -> left) = insert(&(*(root) -> left),data);

		}
		else{
			(*(root) -> right) = insert(&(*(root) -> right),data);
		
		}


	}

}

Node*getmin(Node*root){
	if(root == NULL) return NULL ; 
	else{
		if(root -> left == NULL){
			return root ; 
		}
		else{
			getmin(root -> left);

		}
	}
}

Node*search(Node*root,int data){
	if(root == NULL) return NULL ; 
	else{
		if(root -> data > data){
			search(root -> right,data);
	
		}
		else if(root -> data == data){
			return root ; 
		}

		else{
			search(root -> left,data);
		}


	
	}


}

Node*getmax(Node*root){
	if(root == NULL) return NULL ; 
	else{
		if(root -> right == NULL){
			return root ; 
		}
		else{
			getmax(root -> right);

		}


	}
}

void display(Node*root){
	if(root == NULL) return ; 
	else{
		if(root != NULL)
		display(root -> left);
		if(root != NULL)
		cout<<root -> data<<" ";
		if(root != NULL)
		display(root -> right); 

	}

}

Node*inordersuccessor(Node*root,int data){
	if(root == NULL) return NULL; 
	else{
		Node*findNode = search(root,data);
		if(findNode -> right != NULL){
			return getmin(root -> right);
		}
		else{
			Node*temp = root ; 
			Node*successor = NULL ; 
			while(temp != findNode){
				if(temp -> data > data){
					successor = temp ; 
					temp = temp -> left ;

				}
				else{
					temp = temp -> right ; 
				}

			}
			return successor ; 

		}


	}

}

Node*deletenode(Node*root,int data){
	if(root == NULL) return NULL ; 
	else{
		Node*findNode = search(root, data);
		if(findNode == NULL) return NULL ; 
		else{
			if(findNode -> right == NULL && findNode -> left == NULL){
				delete findNode ;
				findNode = NULL ;  
				return root ; 

			}
			else if(findNode -> right != NULL){
				Node*temp = findNode ; 
				temp = temp -> right ; 
				delete temp ; 
				temp = NULL ; 
				return root ; 

			}
			else if(findNode -> left != NULL){
				Node*temp = findNode ; 
				temp = temp -> left ;
				delete temp ; 
				temp = NULL ; 
				return root ; 
			}	
			else{
				Node*min = getmin(findNode -> right);
				findNode -> data = min -> data ;
				deletenode(findNode -> right,min -> data);
			

			}

		}


	}


}




#endif
