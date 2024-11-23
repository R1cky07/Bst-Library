#include "BST_lib.h"

Node::Node(int num)
{
	value = num;
	weight = 1;
	lchild = rchild = nullptr;
}

Node* Node::insertR(int N){
		Node* current{this};
		Node* dad{nullptr};
		bool isleft;
		
		while(current != nullptr){
			
			if(N == current -> value){
				current -> weight++;
				return this;
			}
			if(N > current -> value){
				dad = current;
				current = dad -> rchild;
				isleft = false;
			}
			else{
				dad = current;
				current = dad -> lchild;
				isleft = true;
			}
			
		}
		if(isleft){
			dad -> lchild = new Node(N);
		}
		else{
			dad -> rchild = new Node(N);
		}
		return this;
};

void Node::inOrder(){
	if(this == nullptr){
		return;
	}
	this -> lchild -> inOrder();
	cout << this -> value << "  ";
	this -> rchild -> inOrder();
}


