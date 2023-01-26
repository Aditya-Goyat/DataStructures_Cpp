/*
Given a generic tree, find and return the height of given tree.
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
int getHeight(TreeNode<int>* root) {
    int maxChildrenHeight = 0;
    if(root == nullptr)
        return 0;
    
    for(int i = 0; i < root->children.size(); i++){
        int childrenHeight = getHeight(root->children[i]);

        if(childrenHeight > maxChildrenHeight)
            maxChildrenHeight = childrenHeight;
    }

    return 1 + maxChildrenHeight;
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
    std::cout << getHeight(root);
}