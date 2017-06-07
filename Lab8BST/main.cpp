#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

struct Element
{
    string key;
    int value;
};

struct Node
{
    Element elem;
    Node *par;
    Node *lc;
    Node *rc;
};

struct BST
{
    Node *root;
};

void init(BST & tree)
{
    tree.root = NULL;
    return;
}

bool isEmpty(BST &tree)
{
    return (tree.root == NULL);
}

void insertElem(BST & tree, string key)
{
    Node *p = NULL;
    Node *q = tree.root;

    if(!isEmpty(tree))
    {
        while(q != NULL)
        {
            if(key == q->elem.key)
            {
                q->elem.value++;
                return;
            }
            p = q;
            if(key < q->elem.key)
            {
                q = q->lc;
            }
            else
            {
                q = q->rc;
            }
        }
    }

    Node *n = new Node();
    Element el;

    el.key = key;
    el.value = 1;
    n->elem = el;
    n->par = p;

    if(p == NULL)
    {
        tree.root = n;
    }
    else if(key < p->elem.key)
    {
        p->lc = n;
    }
    else
    {
        p->rc = n;
    }
    return;
}

void showInorder(Node *n)
{
    if(n == NULL)
    {
        return;
    }
    showInorder(n->lc);
    cout << n->elem.key << "(" << n->elem.value << "),";
    showInorder(n->rc);
    return;
}
void showInorder(BST & tree)
{
    if(!isEmpty(tree))
    {
        showInorder(tree.root);
    }
    cout << endl;
    return;
}

void showPreorder(Node *n)
{
    if(n == NULL)
    {
        return;
    }
    cout << n->elem.key << "(" << n->elem.value << "),";
    showPreorder(n->lc);
    showPreorder(n->rc);
    return;
}
void showPreorder(BST & tree)
{
    if(!isEmpty(tree))
    {
        showPreorder(tree.root);
    }
    cout << endl;
    return;
}

void showPostorder(Node *n)
{
    if(n == NULL)
    {
        return;
    }
    showPostorder(n->lc);
    showPostorder(n->rc);
    cout << n->elem.key << "(" << n->elem.value << "),";
    return;
}
void showPostorder(BST & tree)
{
    if(!isEmpty(tree))
    {
        showPostorder(tree.root);
    }
    cout << endl;
    return;
}

Node *findNode(Node *node, string key)
{
    Node *p = node;
    while(p != NULL)
    {
        if(key < p->elem.key)
        {
            p = p->lc;
        }
        else if(key > p->elem.key)
        {
            p = p->rc;
        }
        else
        {
            return p;
        }
    }
    return NULL;
}

bool findKey(BST & tree, string key, Element &elem)
{
    Node *n = findNode(tree.root, key);
    if(n == NULL)
    {
        return false;
    }
    elem.key = n->elem.key;
    elem.value = n->elem.value;
    return true;
}

Node *minimalNode(Node *node)
{
    Node *p = node;
    while(p != NULL && p->lc != NULL)
    {
        if(p->lc->elem.key > node->elem.key)
        {
            p = p->lc;
        }
        else
        {
            p = p->rc;
        }
    }
    return p;
}

bool removeKey(BST & tree, string key)
{
    Node *n = findNode(tree.root, key);
    if(n == NULL)
    {
        return false;
    }

    Node *p = NULL;
    Node *q = NULL;

    if(n->lc == NULL || n->rc == NULL)
    {
        p = n;
    }
    else
    {
        p = minimalNode(n);
    }

    if(p->lc != NULL)
    {
        q = p->lc;
    }
    else
    {
        q = p->rc;
    }

    if(q != NULL)
    {
        q->par = p->par;
    }

    if(p->par == NULL)
    {
        tree.root = q;
    }
    else if(p == p->par->lc)
    {
        p->par->lc = q;
    }
    else
    {
        p->par->rc = q;
    }

    if(p != n)
    {
        n->elem.key = p->elem.key;
        n->elem.value = p->elem.value;
    }

    return true;
}

void numberOfNodes(Node *n, int &counter)
{
    if(n != NULL)
    {
        counter++;
    }
    if(n->lc != NULL)
    {
        numberOfNodes(n->lc, counter);
    }
    if(n->rc != NULL)
    {
        numberOfNodes(n->rc, counter);
    }
    return;
}

int numberOfNodes(BST & tree)
{
    if(isEmpty(tree))
    {
        return 0;
    }
    int c = 0;
    numberOfNodes(tree.root, c);
    return c;
}

Node *findMaxValue(Node *node)
{
    if(node == NULL)
    {
        Node* res = new Node;
        res->elem.value = -1;
        return res;
    }

    Node *l = findMaxValue(node->lc);
    Node *c = node;
    Node *r = findMaxValue(node->rc);

    if(l->elem.value >= c->elem.value && l->elem.value >= r->elem.value)
    {
        return l;
    }
    else if(r->elem.value >= l->elem.value && r->elem.value >= c->elem.value)
    {
        return r;
    }
    return c;
}

void printTopTen(BST & tree)
{
    int s = std::min(10, numberOfNodes(tree));
    Node *maxValue;

    cout << "BST:\n";
    for(int i = 0; i < s; i++)
    {
        maxValue = findMaxValue(tree.root);
        cout<< maxValue->elem.key <<" :: "<< maxValue->elem.value <<endl;
        removeKey(tree, maxValue->elem.key);
    }
}

void printTopTen(unordered_map<string, int> &hash){
    int i = 10;
    int word_count;
    string word = "";
    cout <<"HASH:"<<endl;
    while(i-->0){
        word_count = 0;
        word = "";

        for (auto w : hash){
            if(w.second > word_count){
                word_count = w.second;
                word = w.first;
            }
        }
        if (word==""){
            i = -1;
        }
        else {
            cout << word << " :: " << word_count <<endl;
            hash[word]=0;
        }



    }

}

void printTopTen(map <string, int> &sbbt){
    int i = 10;
    int word_count;
    string word = "";
    cout << "BBST:"<<endl;
    while(i-->0){
        word_count = 0;
        word = "";

        for (auto w : sbbt) {
            if (w.second > word_count) {
                word_count = w.second;
                word = w.first;
            }
        }
        if (word == ""){
            i = -1;
        }
        else {
            cout << word << " :: " << word_count <<endl;
            sbbt.at(word) = 0;
        }

    }
}

int main() {
    BST tree;
    init(tree);
    unordered_map<string, int> hashtable;
    map <string, int> BBST;
    clock_t start, end;

    ifstream in("Nostromo2");
    string buffer, word;

   vector <string> words;

    while (getline(in, buffer)) {
        word = "";
        for (size_t i = 0; i <= buffer.length(); i++) {
            if (word != "" && (i == buffer.length() || !isalpha(buffer[i]))) {
                words.push_back(word);
                //insertElem(tree, word);
                //++hashtable[word];
                //++BBST[word];
                word = "";
            } else if (isalpha(buffer[i])) {
                word += tolower(buffer[i]);
            } else {
                continue;
            }
        }
    }

    //printTopTen(tree);
    //printTopTen(hashtable);
    //printTopTen(BBST);
    in.close();

   int amn = words.size();

    //BST

    start = clock();
    for(int i = 0;i<amn;i++){
        insertElem(tree, words.at(i));
    }
    end = clock();
    cout << end-start<<" clocks"<<endl;
    printTopTen(tree);

    //hash

    start = clock();
    for(int i = 0;i<amn;i++){
        ++hashtable[words.at(i)];
    }
    end = clock();
    cout << end-start<<" clocks"<<endl;
    printTopTen(hashtable);

    //BBST

    start = clock();
    for(int i = 0;i<amn;i++){
        ++BBST[words.at(i)];
    }
    end = clock();
    cout << end-start<<" clocks"<<endl;
    printTopTen(BBST);



}