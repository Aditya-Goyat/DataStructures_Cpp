#include <iostream>
#include <queue>
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
void printLevelWise(BinaryTreeNode<int> *root) {
	if(root == nullptr)
		return;
	
	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while(!q.empty()){
		BinaryTreeNode<int>* temp = q.front();
		q.pop();
		
		std::cout << temp->data;
		if(temp->left != nullptr) q.push(temp->left);
		if(temp->right != nullptr) q.push(temp->right);
		
		if(temp->left != nullptr)
			std::cout << ":L:" << temp->left->data;
		else
			std::cout << ":L:" << -1;

		if(temp->right != nullptr)
			std::cout << ",R:" << temp->right->data << std::endl;
		else
			std::cout << ",R:" << -1 << std::endl;
	}
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
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}