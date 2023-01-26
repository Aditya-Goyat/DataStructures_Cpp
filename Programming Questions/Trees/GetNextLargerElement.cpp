/*
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
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
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    TreeNode<int>* ans = nullptr;
    if(root->data > x)
        ans = root;

    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int>* smallAns = getNextLargerElement(root->children[i], x);

        if(smallAns == nullptr){
            if(root->data > x)
                ans = root;
        }
        else if(root->data < smallAns->data && root->data > x)
            ans = root;
        else
            ans = smallAns;
    }

    return ans;
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
    TreeNode<int>* ans = getNextLargerElement(root, x);
    if (ans != NULL) {
        std::cout << ans->data;
    }
}