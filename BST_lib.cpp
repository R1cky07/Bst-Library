#include "BST_lib.h"

ostream& operator<<(ostream& os, const Node& N)
{
    os << endl << endl << "Current Node -> " << N.value << endl << "weight -> " << N.weight << endl << endl;
    if(N.lchild == NULL) {
        os << "Left child is NULL" << endl << endl;
    } else {
        os << "Left child -> " << N.lchild->value << endl << "weight -> " << N.lchild->weight << endl << endl;
    }
    if(N.rchild == NULL) {
        os << "Right child is NULL" << endl << endl;
    } else {
        os << "Right child -> " << N.rchild->value << endl << "weight -> " << N.rchild->weight << endl << endl;
    }
    return os;
};

istream& operator>>(istream& is, Node& N)
{
    cout << "Value: ";
    is >> N.value;
    N.lchild = nullptr;
	
    N.rchild = nullptr;

    return is;
};

Node::Node() { weight = 1; };

Node::Node(int num)
{
    value = num;
    weight = 1;
    lchild = rchild = nullptr;
}

Node* Node::insertI(int N)
{
    Node* current{ this };
    Node* dad{ nullptr };
    bool isleft;

    while(current != nullptr) {

        if(N == current->value) {
            current->weight++;
            return this;
        }
        if(N > current->value) {
            dad = current;
            current = dad->rchild;
            isleft = false;
        } else {
            dad = current;
            current = dad->lchild;
            isleft = true;
        }
    }
    if(isleft) {
        dad->lchild = new Node(N);
    } else {
        dad->rchild = new Node(N);
    }
    return this;
};

Node* Node::insertR(int N)
{
    if(this == nullptr) {
        return new Node(N);
    }
    if(this->value == N) {
        this->weight++;
        return this;
    }

    if(N > this->value) {
        this->rchild = this->rchild->insertR(N);
    }

    else {
        this->lchild = this->lchild->insertR(N);
    }
    return this;
};

bool Node::searchI(int N)
{
    if(this == nullptr) {
        return false;
    }
    Node* current{ this };
    while(current != nullptr) {
        if(current->value == N) {
            return true;
        }
        if(N > current->value) {
            current = current->rchild;
        } else {
            current = current->lchild;
        }
    }
    return false;
};

bool Node::searchR(int N)
{
    bool check{ false };
    if(this == nullptr) {
        return false;
    }
    if(this->value == N) {
        return true;
    }

    if(N < this->value && this->lchild != nullptr) {
        check = this->lchild->searchR(N);
    }

    else if(N > this->value && this->rchild != nullptr) {
        check = this->rchild->searchR(N);
    }
    return check;
};

Node* Node::deleteNode(int N)
{
    if(this == nullptr) {
        cout << "The bst is empty" << endl;
        return nullptr;
    }
    if(this -> searchR(N) == false) {
        return nullptr;
    }

    Node* current{ this };
    Node* dad{ nullptr };

    while(current->value != N && current != nullptr) {
        dad = current;

        if(N < current->value) {
            current = current->lchild;
            continue;
        }

        if(N > current->value) {
            current = current->rchild;
            continue;
        }
    }
    if(current->value == N) {

        if(current->lchild == nullptr && current->rchild == nullptr) {
            if(dad == nullptr) {
                return nullptr;
            } else if(dad->lchild == current) {
                dad->lchild = nullptr;
            } else {
                dad->rchild = nullptr;
            }
        }

        else if(current->lchild == nullptr) {
            if(dad == nullptr) {
                return current->rchild;
            } else if(dad->lchild == current) {
                dad->lchild = current->rchild;
            } else {
                dad->rchild = current->rchild;
            }
        }

        else if(current->rchild == nullptr) {
            if(dad == nullptr) {
                return current->lchild;
            } else if(dad->lchild == current) {
                dad->lchild = current->lchild;
            } else {
                dad->rchild = current->lchild;
            }
        }

        else {
            Node* successor = current->rchild;
            while(successor->lchild != nullptr) {
                successor = successor->lchild;
            }
            current->value = successor->value;
            current->rchild = current->rchild->deleteNode(successor->value);
        }
    }
    return this;
};

bool Node::isBst()
{
    if(this == nullptr) {
        return true;
    }

    if(this->lchild != nullptr && this->lchild->value > this->value) {
        cout << "This is not a BST" << endl;
        return false;
    }
    if(this->rchild != nullptr && this->rchild->value < this->value) {
        cout << "This is not a BST" << endl;
        return false;
    }
    return this -> lchild -> isBst() && this -> rchild -> isBst();
};

void Node::inOrder()
{
    if(this == nullptr) {
        return;
    }
    this->lchild->inOrder();
    cout << this->value << "  ";
    this->rchild->inOrder();
};

void Node::preOrder()
{
    if(this == nullptr) {
        return;
    }
    cout << this->value << "  ";
    this->lchild->inOrder();
    this->rchild->inOrder();
};
void Node::postOrder()
{
    if(this == nullptr) {
        return;
    }
    this->lchild->inOrder();
    this->rchild->inOrder();
    cout << this->value << "  ";
};