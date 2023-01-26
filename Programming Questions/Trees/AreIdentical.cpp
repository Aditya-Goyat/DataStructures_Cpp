/*
Given two generic trees, return true if they are structurally identical. Otherwise return false.
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
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2) {
    if(root1 == nullptr && root2 != nullptr || root2 == nullptr && root1 != nullptr)
        return false;
    
    if(root1 == nullptr && root2 == nullptr)
        return true;

    if (root1->data != root2->data)
      return false;
      
    int childCount1 = root1->children.size();
    int childCount2 = root2->children.size();
    if (childCount1 != childCount2)
      return false;

    for (int i = 0; i < childCount1; i++) {
      if (!areIdentical(root1->children[i], root2->children[i]))
        return false;
    }

    return true;
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
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    std::cout << (areIdentical(root1, root2) ? "true" : "false");
}