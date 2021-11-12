#include <iostream>
using namespace std;

template <typename T>
class binaryTree
{
public:
    class node
    {
    public:
        T val;
        int height;
        node *left;
        node *right;
        node(T k)
        {
            height = 1;
            val = k;
            left = nullptr;
            right = nullptr;
        }
    };
    node *root = nullptr;
    int n;
    void insert(T x)
    {
        root = insertUtil(root, x);
    }
    void remove(T x)
    {
        root = removeUtil(root, x);
    }
    node *search(T x)
    {
        return searchUtil(root, x);
    }
    void inorder()
    {
        inorderUtil(root);
        cout << endl;
    }

protected:
    int height(node *head)
    {
        if (head == nullptr)
            return 0;
        return head->height;
    }
    node *rightRotation(node *head)
    {
        node *newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    node *leftRotation(node *head)
    {
        node *newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        head->height = 1 + max(height(head->left), height(head->right));
        newhead->height = 1 + max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    void inorderUtil(node *head)
    {
        if (head == nullptr)
            return;
        inorderUtil(head->left);
        cout << head->val << " ";
        inorderUtil(head->right);
    }

    node *insertUtil(node *head, T x)
    {
        if (head == nullptr)
        {
            n += 1;
            node *temp = new node(x);
            return temp;
        }
        if (x < head->val)
            head->left = insertUtil(head->left, x);
        else if (x > head->val)
            head->right = insertUtil(head->right, x);
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1)
        {
            if (x < head->left->val)
            {
                return rightRotation(head);
            }
            else
            {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1)
        {
            if (x > head->right->val)
            {
                return leftRotation(head);
            }
            else
            {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    node *removeUtil(node *head, T x)
    {
        if (head == nullptr)
            return nullptr;
        if (x < head->val)
        {
            head->left = removeUtil(head->left, x);
        }
        else if (x > head->val)
        {
            head->right = removeUtil(head->right, x);
        }
        else
        {
            node *r = head->right;
            if (head->right == nullptr)
            {
                node *l = head->left;
                delete (head);
                head = l;
            }
            else if (head->left == nullptr)
            {
                delete (head);
                head = r;
            }
            else
            {
                while (r->left != nullptr)
                    r = r->left;
                head->val = r->val;
                head->right = removeUtil(head->right, r->val);
            }
        }
        if (head == nullptr)
            return head;
        head->height = 1 + max(height(head->left), height(head->right));
        int bal = height(head->left) - height(head->right);
        if (bal > 1)
        {
            if (height(head->left) >= height(head->right))
            {
                return rightRotation(head);
            }
            else
            {
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }
        else if (bal < -1)
        {
            if (height(head->right) >= height(head->left))
            {
                return leftRotation(head);
            }
            else
            {
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    node *searchUtil(node *head, T x)
    {
        if (head == nullptr)
            return nullptr;
        T k = head->val;
        if (k == x)
            return head;
        if (k > x)
            return searchUtil(head->left, x);
        if (k < x)
            return searchUtil(head->right, x);
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

        cout << prefix;
        string s = "|--";
        s[0] = char(192);
        cout << ((hasLeft && hasRight) ? "|-- " : "");
        cout << ((!hasLeft && hasRight) ? s : "");

        if (hasRight)
        {
            bool printStrand = (hasLeft && hasRight && (root->right->right != nullptr || root->right->left != nullptr));
            string newPrefix = prefix + (printStrand ? "|   " : "    ");
            cout << root->right->val << endl;
            printSubtree(root->right, newPrefix);
        }

        if (hasLeft)
        {
            cout << (hasRight ? prefix : "") << char(192) << "-- " << root->left->val << endl;
            printSubtree(root->left, prefix + "    ");
        }
    }

    public:
    void printTree(node *root = nullptr)
    {
        root = this->root;
        if (root == nullptr)
        {
            return;
        }

        cout << root->val << endl;
        printSubtree(root, "");
        cout << endl;
    }
};