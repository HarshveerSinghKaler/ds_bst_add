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

Node* construct(vector<int>& postorder, vector<int>& inorder, int &postIndex, int inStart, int inEnd) {
    if(inStart > inEnd) return nullptr;

    Node* root = new Node(postorder[postIndex--]);

    int pos = -1;
    for(int i = inStart; i <= inEnd; i++) {
        if(inorder[i] == root->data) {
            pos = i;
            break;
        }
    }

    root->right = construct(postorder, inorder, postIndex, pos + 1, inEnd);
    root->left = construct(postorder, inorder, postIndex, inStart, pos - 1);

    return root;
}

int main() {
    vector<int> in = {3,7,8,10,12,14,21,25,30};
    vector<int> post = {3, 8, 12, 10, 7, 25, 30, 21, 14};

    int postIndex = post.size()-1;
    Node* root = construct(post, in, postIndex, 0, in.size() - 1);

    cout << "Tree bangya!" << endl;
    return 0;
}