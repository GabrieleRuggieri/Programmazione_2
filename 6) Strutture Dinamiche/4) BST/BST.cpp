#include <iostream>
using namespace std;

template <typename T>
class BSTNode
{

protected:
    T val;
    BSTNode<T> *parent;
    BSTNode<T> *left;
    BSTNode<T> *right;

    template <typename W>
    friend class BST;

public:
    BSTNode(T val) : val(val)
    {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    T getVal() { return this->val; }

    friend ostream &operator<<(ostream &os, const BSTNode<T> &b)
    {
        os << endl;
        os << "BSTNode :" << endl;

        os << "val = " << b.val << endl;

        if (b.left)
            os << "left -> " << b.left->val << endl;
        else
            os << "left -> nullptr" << endl;

        if (b.right)
            os << "right -> " << b.right->val << endl;
        else
            os << "right -> nullptr" << endl;

        if (b.parent)
            os << "parent -> " << b.parent->val << endl;
        else
            os << "parent -> nullptr" << endl;

        return os;
    }
};

template <typename T>
class BST
{

private:
    BSTNode<T> *root; // radice

public:
    BST() { root = nullptr; }

    bool isEmpty() { return root == nullptr; }

    void insert(T val)
    {
        if (isEmpty())
        {
            root = new BSTNode<T>(val);
            return;
        }

        insert(root, val);
    }

    void insert(BSTNode<T> *ptr, T val)
    {

        if (!ptr->left && val <= ptr->val)
        {
            ptr->left = new BSTNode<T>(val);
            ptr->left->parent = ptr;
            return;
        }

        if (!ptr->right && val > ptr->val)
        {
            ptr->right = new BSTNode<T>(val);
            ptr->right->parent = ptr;
            return;
        }

        if (val <= ptr->val)
            insert(ptr->left, val);

        else
            insert(ptr->right, val);
    }

    void inOrder(BSTNode<T> *ptr)
    {
        if (!ptr)
            return;

        inOrder(ptr->left);
        cout << *ptr << "\t";
        inOrder(ptr->right);
    }

    void inOrder() { inOrder(root); }

    void preOrder(BSTNode<T> *ptr)
    {
        if (!ptr)
            return;

        cout << *ptr << "\t";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }

    void preOrder() { preOrder(root); }

    void postOrder(BSTNode<T> *ptr)
    {
        if (!ptr)
            return;

        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << *ptr << "\t";
    }

    void postOrder() { postOrder(root); }

    BSTNode<T> *max() { return max(root); }

    BSTNode<T> *max(BSTNode<T> *from)
    {

        if (isEmpty())
        {
            cout << "Empty bst..." << endl;
            return nullptr;
        }

        BSTNode<T> *ptr = from;

        while (ptr->right)
            ptr = ptr->right;

        return ptr;
    }

    BSTNode<T> *min() { return min(root); }

    BSTNode<T> *min(BSTNode<T> *from)
    {

        if (isEmpty())
        {
            cout << "Empty bst..." << endl;
            return nullptr;
        }

        BSTNode<T> *ptr = from;
        while (ptr->left)
            ptr = ptr->left;

        return ptr;
    }

    BSTNode<T> *search(T val)
    {
        if (isEmpty())
        {
            cout << "Empty bst..." << endl;
            return nullptr;
        }

        return search(root, val);
    }

    BSTNode<T> *search(BSTNode<T> *ptr, T val)
    {

        if (!ptr)
            return nullptr;

        if (ptr->val == val)
            return ptr;

        if (val <= ptr->val)
            return search(ptr->left, val);

        else
            return search(ptr->right, val);
    }

    BSTNode<T> *successor(T val)
    {

        if (isEmpty())
        {
            cout << "Empty bst..." << endl;
            return nullptr;
        }

        BSTNode<T> *ptr = search(val);

        if (!ptr || ptr == max())
        {
            cout << "no successor" << endl;
            return nullptr;
        }

        return successor(ptr);
    }

    BSTNode<T> *successor(BSTNode<T> *x)
    {

        if (x->right)
            return min(x->right);

        // caso in cui non ce figlio destro
        BSTNode<T> *y = x->parent;

        while (x && x == y->right) // fino a che x non è un figlio sinistro
        {
            x = y;
            y = y->parent;
        }

        return y;
    }

    BSTNode<T> *predecessor(T val)
    {
        if (isEmpty())
        {
            cout << "Empty bst..." << endl;
            return nullptr;
        }

        BSTNode<T> *ptr = search(val);
        if (!ptr || ptr == min())
        {
            cout << "no predecessor" << endl;
            return nullptr;
        }

        return predecessor(ptr);
    }

    BSTNode<T> *predecessor(BSTNode<T> *x)
    {

        if (x->left)
            return max(x->left);

        BSTNode<T> *y = x->parent;
        while (x && x == y->left) // fino a che x non è un figlio destro
        {
            x = y;
            y = y->parent;
        }

        return y;
    }

    void transplant(BSTNode<T> *u, BSTNode<T> *v) // u e' il nodo da rimuovere, v quello con cui devo sostituirlo
    {
        if (!u->parent) // senza genitore
            root = v;

        else if (u == u->parent->left) // u e' figlio sinistro di suo padre
            u->parent->left = v;

        else
            u->parent->right = v;

        if (v)
            v->parent = u->parent;
    }

    void remove(T val)
    {
        BSTNode<T> *node = search(val);

        if (!node)
        {
            cout << "not found" << endl;
            return;
        }

        if (!node->left)

            transplant(node, node->right); // node non ha figlio sinistro e sposto il suo figlio destro in alto al posto di node

        else if (!node->right)

            transplant(node, node->left);

        else
        {
            BSTNode<T> *successorNode = min(node->right);

            transplant(node, successorNode); // sostituisce il nodo da rimuovere con il successore
            successorNode->left = node->left;
            successorNode->left->parent = successorNode;
        }

        delete node;
    }

    T height()
    {
        if (isEmpty())
        {
            cout << "Empty bst..." << endl;
            return 0;
        }

        return height(root);
    }

    T height(BSTNode<T> *ptr)
    {
        if (!ptr)
            return 0;

        int lh = height(ptr->left);
        int rh = height(ptr->right);

        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }

    void printLevel(BSTNode<T> *ptr, int level)
    {
        if (!ptr)
            return;

        if (level == 0)
            cout << ptr->val << "\t";

        else if (level > 0)
        {
            printLevel(ptr->left, level - 1);
            printLevel(ptr->right, level - 1);
        }
    }

    friend ostream &operator<<(ostream &os, BST &bst)
    {

        if (bst.isEmpty())
            return os << "\nEmpty BST!" << endl;

        int h = bst.height();
        os << "Albero di altezza " << h << endl;

        for (int i = 0; i < h; i++)
        {
            bst.printLevel(bst.root, i);
            os << endl;
        }

        return os;
    }
};

int main()
{
    BST<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << bst << endl;

    bst.inOrder();

    return 0;
}