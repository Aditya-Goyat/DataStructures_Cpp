/*
Given a generic tree and an integer x, check if x is present in the given tree or not. 
Return true if x is present, return false otherwise.
*/

#include <iostream>
#include <queue>
#include <vector>

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
bool isPresent(TreeNode<int>* root, int x) {
    if(root == nullptr)
        return false;

    if(root->data == x)
        return true;

    for(int i = 0; i < root->children.size(); i++){
      if (isPresent(root->children[i], x))
        return true;
    }

    return false;
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
    int x;
    std::cin >> x;
    std::cout << (isPresent(root, x) ? "true" : "false");
}