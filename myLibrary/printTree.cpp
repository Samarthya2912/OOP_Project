#include <iostream>
#include <string>
#include "./avl.cpp"
using namespace std;

template <class T>
class print_tree
{
private:
    string print;
    // class node
    // {
    //     T val;
    //     node *left;
    //     node *right;
    // };
    // node *root;

public:
    print_tree(AVL<T>::node* root) : root(root), print("") {
        printTree(root);
    } 

    void printSubtree(node *root, const string &prefix)
    {
        if (root == nullptr)
        {
            return;
        }

        bool hasLeft = (root->left != nullptr);
        bool hasRight = (root->right != nullptr);

        if (!hasLeft && !hasRight)
        {
            return;
        }

        this->print += prefix;
        string s = "|--";
        s[0] = char(192);
        this->print += ((hasLeft && hasRight) ? "|-- " : "");
        this->print += ((!hasLeft && hasRight) ? s : "");

        if (hasRight)
        {
            bool printStrand = (hasLeft && hasRight && (root->right->right != nullptr || root->right->left != nullptr));
            string newPrefix = prefix + (printStrand ? "|   " : "    ");
            this->print += root->right->val + "\n";
            printSubtree(root->right, newPrefix);
        }

        if (hasLeft)
        {
            this->print += (hasRight ? prefix : "") + char(192) + "-- " + root->left->val + "\n";
            printSubtree(root->left, prefix + "    ");
        }
    }

    void printTree(node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        this->print += root->val + "\n";
        printSubtree(root, "");
        this->print += "\n";
    }
};

int main() {
    AVL<int> sam;
    for(int i = 0; i < 10; i++) sam.insert(i);
    // auto root = ;
    print_tree<int> p(sam.root);
}