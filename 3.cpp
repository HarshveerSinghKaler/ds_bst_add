#include <iostream>
using namespace std;

int maxNo(int a, int b) {
    if(a > b) return a;
    else return b;
}

class Node {
    int data;
    Node* left, *right;

    public:

        Node(int val) {
            data = val;
            right = left = nullptr;
        }

        int maxDepth(Node* root) {
            if(root == nullptr) return 0;
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            return (1 + maxNo(leftDepth,rightDepth));
        }
};

int main() {
    

    return 0;
}