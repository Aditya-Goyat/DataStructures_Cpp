#include <iostream>
#include <queue>
#include <utility>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

//Solution
pair<int, int>* DiameterOfTree(BinaryTreeNode<int>* root){
    if(root == nullptr){
        pair<int, int>* res = new pair<int, int> (0,0);
        return res;
    }

    pair<int, int>* leftAns = DiameterOfTree(root->left);
    pair<int, int>* rightAns = DiameterOfTree(root->right);

    int height = 1 + max(leftAns->first, rightAns->first);
    int diameter = max(leftAns->first + rightAns->first, max(leftAns->second, rightAns->second));

    pair<int, int>* res = new pair<int, int> (height, diameter);
    return res;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    std::cout << DiameterOfTree(root)->second << std::endl;
}