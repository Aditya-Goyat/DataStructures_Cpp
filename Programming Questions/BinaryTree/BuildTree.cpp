#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


BinaryTreeNode<int>* buildTreeHelper(int* preorder, int* inorder, int inS, int inE, int preS, int preE){
	if(inS > inE)
		return nullptr;
	
	int rootData = preorder[preS];
	int rootIndex = -1;
	for(int i = inS; i <= inE; i++){
		if(inorder[i] == rootData){
			rootIndex = i;
			break;
		}
	}

	int linS = inS;
	int linE = rootIndex - 1;
	int rinS = rootIndex + 1;
	int rinE = inE;
	int lpreS = preS + 1;
	int lpreE = lpreS + linE - linS;
	int rpreS = lpreE + 1;
	int rpreE = preE;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(preorder, inorder, linS, linE, lpreS, lpreE);
	root->right = buildTreeHelper(preorder, inorder, rinS, rinE, rpreS, rpreE);

	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
	return buildTreeHelper(preorder, inorder, 0, inLength - 1, 0, preLength - 1);
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    std::cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    std::queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        std::cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        std::cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    std::queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            std::cout << std::endl;
            q.push(NULL);
            continue;
        }
        std::cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    std::cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) std::cin >> pre[i];
    for (int i = 0; i < size; i++) std::cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}