#include <bits/stdc++.h>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node *left, *right;
        Node(int x) : data(x), left(NULL), right(NULL) {}
    };
    Node* root;

    void inorder(Node* r, vector<int>& v) {
        if(!r) return;
        inorder(r->left, v);
        v.push_back(r->data);
        inorder(r->right, v);
    }

    Node* insertNode(Node* r, int x) {
        if(!r) return new Node(x);
        if(x < r->data) r->left = insertNode(r->left, x);
        else r->right = insertNode(r->right, x);
        return r;
    }

public:
    BST() : root(NULL) {}
    
    void insert(int x) {
        root = insertNode(root, x);
    }
    
    void getSorted(vector<int>& v) {
        inorder(root, v);
    }
};

class DLL {
private:
    struct Node {
        int data;
        Node *prev, *next;
        Node(int x) : data(x), prev(NULL), next(NULL) {}
    };
    Node* head;

public:
    DLL() : head(NULL) {}

    void build(vector<int>& v) {
        if(v.empty()) return;
        head = new Node(v[0]);
        Node* cur = head;
        for(int i = 1; i < v.size(); i++) {
            Node* t = new Node(v[i]);
            cur->next = t;
            t->prev = cur;
            cur = t;
        }
    }

    void print() {
        Node* cur = head;
        while(cur) {
            cout << cur->data << " <--> ";
            cur = cur->next;
        }
        cout << "null\n";
    }
};

int main() {
    BST t1, t2;

    t1.insert(20);
    t1.insert(10);
    t1.insert(30);
    t1.insert(25);
    t1.insert(100);

    t2.insert(50);
    t2.insert(5);
    t2.insert(70);

    vector<int> a, b, c;
    t1.getSorted(a);
    t2.getSorted(b);

    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));

    DLL d;
    d.build(c);
    d.print();
}
