#include <iostream>
using namespace std;
#ifndef BST_LIB_H
#define BST_LIB_H

class Node
{
private:
    int value, weight;
    Node *lchild, *rchild;
    friend ostream& operator<<(ostream& os, const Node& N);
    friend istream& operator>>(istream& is, Node& N);

public:
    Node(int num);
    Node* insertI(int N);
    Node* insertR(int N);
    bool searchI(int k);
    bool searchR(int k);
    void inOrder();
};

#endif

/*


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
}*/