#include<iostream>
#include <string>
#include <sstream>

// BST

using namespace std;


struct Element{
	int key;
	int value;
};

struct Node{
	Element elem;
	Node * parent;
    Node * left_child;
    Node * right_child;
};

// Binary search tree
struct BST{
    Node * root;
};

void init(BST & tree){
    tree.root = NULL;
}

void insertNode(BST & tree, Node * node){
    if (!tree.root){
        tree.root = node;
    }
    else {

        Node *temp = tree.root;

        while (temp) {
            if (temp->elem.key > node->elem.key) {
                if (temp->left_child) {
                    temp = temp->left_child;
                }
                else {
                    temp->left_child = node;
                    node->parent = temp;
                    temp = NULL;
                }
            }
            else {
                if (temp->right_child) {
                    temp = temp->right_child;
                }
                else {
                    temp->right_child = node;
                    node->parent = temp;
                    temp = NULL;
                }
            }
        }
    }
}

bool insertElem(BST & tree, Element elem){
    Node * node = new Node;
    node ->elem = elem;
    node ->left_child = node ->right_child = node ->parent = NULL;

    insertNode(tree,node);

    return true;
}

void print(Node * node){
    cout << node -> elem.key << '(' << node -> elem.value << "),";
}

void showIn_order(Node * root){
    if (root){
        showIn_order(root->left_child);
        print(root);
        showIn_order(root->right_child);
    }
}

void showInorder(BST & tree){
    showIn_order(tree.root);
    cout << endl;
}

void showPreorder(Node * root){
    if (root){
        print(root);
        showPreorder(root->left_child);
        showPreorder(root->right_child);
    }
}

void showPreorder(BST & tree){
    showPreorder(tree.root);
    cout << endl;
}

void showPostorder(Node * root){
    if (root){
        showPostorder(root->left_child);
        showPostorder(root->right_child);
        print(root);
    }
}

void showPostorder(BST & tree){
    showPostorder(tree.root);
    cout << endl;
}

Node *findNode(Node *node,int key){
	return NULL;
}

Node * findkey(BST & tree, int key){
    Node * temp = tree.root;
    while(temp){
        if (temp->elem.key == key){
            return temp;
        }

        if (temp->elem.key > key){
            temp = temp -> left_child;
        }
        else {
            temp = temp -> right_child;
        }
    }
    return temp;
}

bool findKey(BST & tree,int key, Element &elem){
    Node * temp = findkey(tree,key);
    if(temp){
        elem = temp -> elem;
        return true;
    }
    else {
        return false;
    }
}

Node *minimalNode(Node *node){
    Node *temp = node;
    while(temp->left_child){
        temp = temp -> left_child;
    }
    return temp;
}

void transplant(BST & tree, Node * toReplace, Node *replaceBy){
    if (toReplace -> parent){
        if (toReplace->parent->left_child == toReplace){
            toReplace->parent->left_child = replaceBy;
        }
        else {
            toReplace->parent->right_child = replaceBy;
        }

    }
    else {
        tree.root = replaceBy;
    }
    if (replaceBy)
        replaceBy->parent = toReplace->parent;
}

bool removeNode(BST & tree, Node * node){
    if (!node){
        return false;
    }

    if(!node->left_child){
        transplant(tree, node, node->right_child);
    }
    else {
        if (node->right_child){
            Node * temp = minimalNode(node->right_child);
            if (temp->parent!=node){
                transplant(tree, temp, temp->right_child);
                temp -> right_child = node->right_child;
                temp -> right_child -> parent = temp;
            }
            transplant(tree, node, temp);
            temp -> left_child= node -> left_child;
            temp ->left_child -> parent = temp;
        }
        else {
            transplant(tree, node, node->left_child);
        }
    }

    delete node;
    return true;
}

bool removeKey(BST & tree, int key, Element &elem){
    Node * temp = findkey(tree,key);
    if (temp){
        elem = temp->elem;
        removeNode(tree, temp);
        return true;
    }
    else
        return false;
}

void clear(Node *node){
    if(node){
        clear(node->left_child);
        clear(node->right_child);
        delete node;
    }
}

void clear(BST & tree){
    clear(tree.root);
    tree.root = NULL;
}

int CountNum(Node * node){
    if (node){
        return (CountNum(node->left_child)+CountNum(node->right_child)+1);
    }
    return 0;
}

int numberOfNodes(BST & tree){
	return CountNum(tree.root);
}

int height(Node * node){
    if(node){
        int l = height(node->left_child)+1;
        int r = height(node->right_child)+1;

        return ( (l>r) ? l : r);

    }
    else {
        return 0;
    }
}

int height(BST & tree){
	return height(tree.root);
}

/*bool onechild(Node *node){
    if(node != NULL && ((node->left_child == NULL && node->right_child != NULL) ||(node->left_child != NULL && node->right_child==NULL) )){
        return true;
    }
    return false;
} */

int functionA(Node *node){
    if (node == NULL) {
        return 0;
    } else if (node->left_child == NULL && node->right_child != NULL) {
        return functionA(node->right_child) + 1;
    } else if (node->left_child != NULL && node->right_child == NULL) {
        return functionA(node->left_child) + 1;
    } else {
        return functionA(node->left_child) + functionA(node->right_child);
    }
}

int functionA(BST & tree){
    return functionA(tree.root);
	//return -1;
}

int functionB(BST & tree, int key){
	return -1;
}

bool functionC(BST & tree, int key, Element &elem){
	return false;
}


void showBool(bool val){
	if(val)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

bool isCommand(const string command,const char *mnemonic){
	return command==mnemonic;
}

int main(){
	string line;
	string command;
	BST *tree;
	int currentT=0;
	int value;
	cout << "START" << endl;
	while(true){
		getline(cin,line);
		std::stringstream stream(line);
		stream >> command;
		if(line=="" || command[0]=='#')
		{
			// ignore empty line and comment
			continue;
		}

		// copy line on output with exclamation mark
		cout << "!" << line << endl;;

		// change to uppercase
		command[0]=toupper(command[0]);
		command[1]=toupper(command[1]);

		// zero-argument command
		if(isCommand(command,"HA")){
			cout << "END OF EXECUTION" << endl;
			break;
		}

		if(isCommand(command,"SI"))
		{
			showInorder(tree[currentT]);
			continue;
		}

		if(isCommand(command,"SP"))
		{
			showPreorder(tree[currentT]);
			continue;
		}

		if(isCommand(command,"SQ"))
		{
			showPostorder(tree[currentT]);
			continue;
		}

		if(isCommand(command,"CL"))
		{
			clear(tree[currentT]);
			continue;
		}

		if(isCommand(command,"IN"))
		{
			init(tree[currentT]);
			continue;
		}

		if(isCommand(command,"NN"))
		{
			cout << numberOfNodes(tree[currentT]) << endl;
			continue;
		}

		if(isCommand(command,"HE"))
		{
			cout << height(tree[currentT]) << endl;
			continue;
		}

		if(isCommand(command,"FA"))
		{
			cout << functionA(tree[currentT]) << endl;
			continue;
		}

		// read next argument, one int value
		stream >> value;


		if(isCommand(command,"IE"))
		{
			int variable2;
			stream >> variable2;
			Element elem;
			elem.key=value;
			elem.value=variable2;
			showBool(insertElem(tree[currentT],elem));
			continue;
		}

		if(isCommand(command,"FK"))
		{
			Element elem;
			bool ret=findKey(tree[currentT], value, elem);
			if(ret)
				cout << elem.key << '(' << elem.value << ')' << endl;
			else
				cout << "false" << endl;
			continue;
		}

		if(isCommand(command,"RK"))
		{
			Element elem;
			bool ret=removeKey(tree[currentT], value, elem);
			if(ret)
				cout << elem.key << '(' << elem.value << ')' << endl;
			else
				cout << "false" << endl;
			continue;
		}


		if(isCommand(command,"CH"))
		{
			currentT=value;
			continue;
		}

		if(isCommand(command,"GO"))
		{
			tree=new BST[value];
			continue;
		}

		if(isCommand(command,"FB"))
		{
			cout << functionB(tree[currentT],value) << endl;
			continue;
		}

		if(isCommand(command,"FC"))
		{
			Element elem;
			bool ret=functionC(tree[currentT], value, elem);
			if(ret)
				cout << elem.key << '(' << elem.value << ')' << endl;
			else
				cout << "false" << endl;
			continue;
		}

		cout << "wrong argument in test: " << command << endl;

	}
	return 0;
}