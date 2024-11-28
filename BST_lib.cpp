#include "BST_lib.h"

Node::Node(int num)
{
	value = num;
	weight = 1;
	lchild = rchild = nullptr;
}

Node* Node::insertI(int N){
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

Node* Node::insertR(int N){
    if(this == nullptr){
        return new Node(N);
    }
    if(this -> value == N){
        this -> weight++;
		return this;
    }
	
    if(N > this -> value){
        this -> rchild = this -> rchild -> insertR(N);
    }
	
    else{
        this -> lchild = this -> lchild -> insertR(N);
    }
    return this;
};

bool Node::searchI(int N){
	if(this == nullptr){
		return false;
	}
	Node* current{this};
	while(current != nullptr){
		if(current -> value == N){
			return true;
		}
		if(N > current->value){
			current = current->rchild;
		}
		else{
			current = current->lchild;
		}
	}
	return false;
};
bool Node::searchR(int N){
	bool check{false};
	if(this == nullptr){
		return false;
	}
	if(this -> value == N){
		return true;
	}
	
	if(N < this -> value && this -> lchild != nullptr){
		check = this -> lchild -> searchR(N);
	}
	
	else if(N > this -> value && this -> rchild != nullptr){
		check = this -> rchild -> searchR(N);
	}
	return check;
};

void Node::inOrder(){
	if(this == nullptr){
		return;
	}
	this -> lchild -> inOrder();
	cout << this -> value << "  ";
	this -> rchild -> inOrder();
};


