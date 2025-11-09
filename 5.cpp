#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

Node* construct(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inStart, int inEnd) {
    if(inStart > inEnd) return nullptr;

    Node* root = new Node(preorder[preIndex++]);

    int pos = -1;
    for(int i = inStart; i <= inEnd; i++) {
        if(inorder[i] == root->data) {
            pos = i;
            break;
        }
    }

    root->left = construct(preorder, inorder, preIndex, inStart, pos - 1);
    root->right = construct(preorder, inorder, preIndex, pos + 1, inEnd);

    return root;
}

int main() {
    vector<int> in = {3,7,8,10,12,14,21,25,30};
    vector<int> pre = {14,7,3,10,8,12,21,30,25};

    int preIndex = 0;
    Node* root = construct(pre, in, preIndex, 0, in.size() - 1);

    cout << "Tree bangya!" << endl;
    return 0;
}