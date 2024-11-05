#include <iostream>

using namespace std;

struct Node{				
    int value, weight;		
    Node* lchild, *rchild;
    Node(int num){
        value = num;
        weight = 1;
        lchild = rchild = nullptr;
    }
};

Node* insert_recoursive(Node* r, int N){
    if(r == NULL){
        return new Node(N);
    }
    if(r -> value == N){
        r -> weight++;
		return r;
    }
	
    if(N > r -> value){
        r -> rchild = insert_recoursive(r -> rchild, N);
    }
	
    else{
        r -> lchild = insert_recoursive(r -> lchild, N);
    }
    return r;
}


Node* insert_iterative(Node* r, int N){
	Node* current{r};
    Node* dad{nullptr};
    bool isleft;
    
	while(current != nullptr){
		
		if(N == current -> value){
			current -> weight++;
			return r;
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
    return r;
}

void preOrder(Node* r){
	if(r == NULL){
		return;
	}
	cout << r -> value << "  ";
	preOrder(r -> lchild);
	preOrder(r -> rchild);
}

void inOrder(Node* r){
	if(r == NULL){
		return;
	}
	inOrder(r -> lchild);
	cout << r -> value << "  ";
	inOrder(r -> rchild);
}

void postOrder(Node* r){
	if(r == NULL){
		return;
	}
	postOrder(r -> lchild);
	postOrder(r -> rchild);
	cout << r -> value << "  ";	
}


bool Research(Node* r, int N){
	bool check{false};
	
	if(r == NULL){
		cout << "The number " << N << " hasn't been found" << endl;
		return false;
	}
	if(r -> value == N){
		cout << "The number " << N << " has been found" << endl;
		return true;
	}
	
	if(N < r -> value){
		check = Research(r -> lchild, N);
	}
	else{
		check = Research(r -> rchild, N);
	}
	return check;
}

Node* Research_iterative(Node* r, int N){
	if(r == NULL){
		return r;
	}
	Node* current{r};
	while(current != NULL && current->value != N){
		if(N > current->value){
			current = current->rchild;
		}
		else{
			current = current->lchild;
		}
	}
	return current;
}

Node* EraseNode(Node* r, int N){
	if(r == NULL){
		cout << "The bst is empty" << endl;
		return nullptr;
	}
	if(Research(r, N) == false){
		return nullptr;
	}
	
	Node* current{r};
	Node* dad{nullptr};
	
	while(current -> value != N && current != NULL){
		dad = current;
		
		if(N < current -> value){
			current = current -> lchild;
			continue;
		}
		
		if(N > current -> value){
			current = current -> rchild;
			continue;
		}
	}
	if(current -> value == N){
		
		if(current -> lchild == NULL && current -> rchild == NULL){
			if(dad == NULL){
				return nullptr;
			}
			else if(dad -> lchild == current){
				dad -> lchild = nullptr;
			}
			else{
				dad -> rchild = nullptr;
			}
		}
		
		else if(current -> lchild == NULL){
			if(dad == NULL){
				return current -> rchild;
			} 
			else if(dad -> lchild == current){
				dad -> lchild = current -> rchild;
			}
			else{
				dad -> rchild = current -> rchild;
			}
		}
		
		else if(current -> rchild == NULL ){
			if(dad == NULL){
				return current -> lchild;
			}
			else if(dad -> lchild == current){
				dad -> lchild = current -> lchild;
			}
			else{
				dad -> rchild = current -> lchild;
			}
		}
		
		else{
			Node* successor = current->rchild;
			while(successor -> lchild != nullptr){
				successor = successor -> lchild;
			}
			current -> value = successor -> value;
			current -> rchild = EraseNode(current->rchild, successor->value);
		}

	}
	return r;
}

bool isBST(Node* r){
	if(r == NULL){
		return true;
	}
	
	if(r -> lchild != NULL && r -> lchild -> value > r -> value){
		cout << "This is not a BST" << endl;
		return false;
	}
	if(r -> rchild != NULL && r -> rchild -> value < r -> value){
		cout << "This is not a BST" << endl;
		return false;
	}
	return isBST(r -> lchild) && isBST(r -> rchild);
}

int heightCalc(Node* r){
	if(r == NULL){
		return 0;
	}
	int left{heightCalc(r -> lchild)};
	int right{heightCalc(r -> rchild)};
	return max(right, left) + 1;
}