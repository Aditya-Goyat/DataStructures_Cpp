/*
Given a generic tree, print the input tree in level wise order.
For printing a node with data N, you need to follow the exact format -
N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N. Note that there is no space in between.
You need to print all nodes in the level order form in different lines.
*/

#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class TreeNode {
   public:
    T data;
    std::vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

//Solution
void printLevelWise(TreeNode<int>* root) {
    std::queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int>* currentNode = pendingNodes.front();
        pendingNodes.pop();
        std::cout << currentNode->data << ":";
        for(int i = 0; i < currentNode->children.size(); i++){
            if(i == currentNode->children.size()-1)
                std::cout << currentNode->children[i]->data;
            else
                std::cout << currentNode->children[i]->data << ",";
            
            pendingNodes.push(currentNode->children[i]);
        }
        std::cout << std::endl;
    }
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    std::cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    std::queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        std::cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            std::cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}