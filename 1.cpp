#include <iostream>
using namespace std;

class Node {
    int data;
    Node* left, *right;
    
    public:
        Node(int data) {
            this->data = data;
            left = right = nullptr;
        }

        void inorder(Node* root, bool isLeft, int &sum) {
            if(root == nullptr) return;
            if(isLeft == true && !(root->left) && !(root->right)) sum += root->data;
            inorder(root->left, true, sum);
            inorder(root->right, false, sum);
        }

        int sumOfAllLeftLeaves(Node* root) {
            if(root == nullptr) return 0;
            int sum = 0;
            inorder(root, false, sum);
            return sum;
        }
};