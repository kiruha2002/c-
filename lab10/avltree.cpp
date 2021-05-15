#include<iostream>

// tree node
struct avl_node
{
    int              data;
    struct avl_node* left;
    struct avl_node* right;
};
//------------------------------------------------------------------
class avl_tree
{
    avl_node* root;                         // pointer to the root of the tree

    int       height(avl_node*) const;    // AVL tree height
    int       balance_factor(avl_node*);
    avl_node* rr_rotation(avl_node*);    // Rotation,
    avl_node* ll_rotation(avl_node*);    // used
    avl_node* lr_rotation(avl_node*);    // for
    avl_node* rl_rotation(avl_node*);    // balancing.
    avl_node* balance(avl_node*);        // Balancing the tree
    avl_node* get_min(avl_node*) const;
    avl_node* insert_helper(avl_node*, int);  // Inserting a node into a tree
    avl_node* remove_helper(avl_node*, int);  // Removing a node
    void      display_helper(avl_node*, int) const; // tree printout
    int       leaf_count_helper(avl_node*)   const; // leaf counter
    int       node_count_helper(avl_node*)   const; // knot counter
    bool      equality(avl_node*, avl_node*);       // == trees
    void      delete_tree(avl_node*);               // tree removal

public:
    avl_tree()
    {
        root = NULL;
    }
    void insert(int value)   // insert node
    {
        this->root = insert_helper(this->root, value);
    }
    void remove(int value)   // remove node
    {
        this->root = remove_helper(this->root, value);
    }
    void display()             // tree printout
    {
        display_helper(this->root, 1);
    }
    int  leaf_count()          // leaf counter
    {
        return  leaf_count_helper(this->root);
    }
    int  node_count()          // knot counter
    {
        return  node_count_helper(this->root);
    }
    // operator < by the number of tree vertices
    friend bool operator < (avl_tree& l, avl_tree& r)
    {
        return  l.node_count() < r.node_count();
    }
    // tree equality test
    bool operator == (const avl_tree& r)
    {
        avl_node* a = this->root;
        avl_node* b = r.root;
        return equality(a, b);
    }
    ~avl_tree()
    {
        delete_tree(this->root);
    }
};
//------------------------------------------------------------------
// AVL tree height
//------------------------------------------------------------------
int avl_tree::height(avl_node* temp) const
{
    int h = 0;
    if (temp)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = std::max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
//------------------------------------------------------------------
// Difference in heights of the left and right subtrees
//------------------------------------------------------------------
int avl_tree::balance_factor(avl_node* temp)
{
    return height(temp->left) - height(temp->right);
}
//------------------------------------------------------------------
// Right-Right Rotation
//------------------------------------------------------------------
avl_node* avl_tree::rr_rotation(avl_node* parent)
{
    avl_node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
//------------------------------------------------------------------
// Left-Left Rotation
//------------------------------------------------------------------
avl_node* avl_tree::ll_rotation(avl_node* parent)
{
    avl_node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
//------------------------------------------------------------------
// Left-Right Rotation
//------------------------------------------------------------------
avl_node* avl_tree::lr_rotation(avl_node* parent)
{
    avl_node* temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}
//------------------------------------------------------------------
// Right-Left Rotation
//------------------------------------------------------------------
avl_node* avl_tree::rl_rotation(avl_node* parent)
{
    avl_node* temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}
//------------------------------------------------------------------
// Balancing the AVL tree with turns
//------------------------------------------------------------------
avl_node* avl_tree::balance(avl_node* temp)
{
    int b_factor = balance_factor(temp);
    if (b_factor > 1)
    {
        if (balance_factor(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else
        if (b_factor < -1)
        {
            if (balance_factor(temp->right) > 0)
                temp = rl_rotation(temp);
            else
                temp = rr_rotation(temp);
        }
    return temp;
}
//------------------------------------------------------------------
// Inserting a node into an AVL tree
//------------------------------------------------------------------
avl_node* avl_tree::insert_helper(avl_node* t, int value)
{
    if (!t)
    {
        t = new avl_node;
        t->data = value;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    else
        if (value < t->data)
        {
            t->left = insert_helper(t->left, value);
            t = balance(t);
        }
        else
        {
            t->right = insert_helper(t->right, value);
            t = balance(t);
        }
    return balance(t); // returning the decree to a balanced tree
}
//------------------------------------------------------------------
// AVL printout of a tree lying on its side
//------------------------------------------------------------------
void  avl_tree::display_helper(avl_node* t, int level = 1) const
{
    if (t)
    {
        display_helper(t->right, level + 1);
        std::cout << "\n";
        if (t == this->root)
            std::cout << "< ";
        for (int i = 0; i < level && t != this->root; i++)
            std::cout << "     ";
        std::cout << t->data;
        display_helper(t->left, level + 1);
    }
}
//------------------------------------------------------------------
avl_node* avl_tree::get_min(avl_node* t) const
{
    if (t == NULL)
        return NULL;
    else
        if (t->left == NULL)
            return t;
        else
            return get_min(t->left);
}
//------------------------------------------------------------------
// Removing a node
//------------------------------------------------------------------
avl_node* avl_tree::remove_helper(avl_node* t, int x)
{
    avl_node* temp = NULL;
    if (t == NULL)       // node not found
        return NULL;
    else
        if (x < t->data)
            t->left = remove_helper(t->left, x);
        else
            if (x > t->data)
                t->right = remove_helper(t->right, x);
            else
                if (t->left && t->right)  // node has 2 children
                {
                    temp = get_min(t->right);
                    t->data = temp->data;
                    t->right = remove_helper(t->right, t->data);
                }
                else  // node has less than 2 children
                {
                    temp = t;
                    if (t->left == NULL)
                        t = t->right;
                    else
                        if (t->right == NULL)
                            t = t->left;
                    delete temp;
                }
    if (t == NULL)
        return t;
    return  balance(t); // we return the decree. on a balanced tree
}
//------------------------------------------------------------------
// Tree leaf counter
//------------------------------------------------------------------
int  avl_tree::leaf_count_helper(avl_node* t) const
{
    if (!t)
        return 0;
    if (!(t->left) && !(t->right)) // leaf if there are no descendants
        return 1;
    else
        return leaf_count_helper(t->left)
        + leaf_count_helper(t->right);
}
//------------------------------------------------------------------
// Tree node counter
//------------------------------------------------------------------
int avl_tree::node_count_helper(avl_node* t) const
{
    if (!t)
        return 0;
    return 1 + node_count_helper(t->left) + node_count_helper(t->right);
}
//------------------------------------------------------------------
// Removing a tree
//------------------------------------------------------------------
void  avl_tree::delete_tree(avl_node* t)
{
    if (!t)
        return;
    delete_tree(t->right);
    delete_tree(t->left);
    delete t;
}
//------------------------------------------------------------------
// Comparison for equality
//------------------------------------------------------------------
bool avl_tree::equality(avl_node* a, avl_node* b)
{
    if (a == NULL && b == NULL)
        return true;

    if (a != NULL && b != NULL)
        return  (a->data == b->data &&
            equality(a->left, b->left) &&
            equality(a->right, b->right)
            );
    return false;
}
//==================================================================
int main()
{
    avl_tree* avl = new avl_tree();  // source tree
    int  data[] = { 10, 20, 30, 40, 50, 25, 45 };
    const int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; ++i)
        avl->insert(data[i]);

    std::cout << "Original tree: avl\n";
    avl->display();
    std::cout << "\nNumber of leaves = " << avl->leaf_count()
        << "\nNumber of nodes = " << avl->node_count() << "\n";

    avl->remove(20); //removed node 20
    std::cout << "\n\n Remove from avl 20\n";
    avl->display();
    std::cout << "\nNumber of leaves = " << avl->leaf_count()
        << "\nNumber of nodes = " << avl->node_count() << "\n";

    avl->insert(90);  // added nodes 90
    avl->insert(5);   // and 5
    std::cout << "\n\n Insert into avl 90, 5 \n";
    avl->display();
    std::cout << "\nNumber of leaves = " << avl->leaf_count()
        << "\nNumber of nodes = " << avl->node_count() << "\n";
    std::cout << "\n\n";

    avl_tree* avl_1 = new avl_tree(); // another tree
    int  data1[] = { 10, 20, 50, 25, 45 };
    const int m = sizeof(data1) / sizeof(data1[0]);
    for (int i = 0; i < m; ++i)
        avl_1->insert(data1[i]);

    std::cout << "Another tree: avl_1\n";
    avl_1->display();
    std::cout << "\nNumber of leaves = " << avl_1->leaf_count()
        << "\nNumber of nodes = " << avl_1->node_count() << "\n";

    // Comparison < by the number of vertices
    if (*avl_1 < *avl)
        std::cout << "\navl_1 < avl \n";
    else
        std::cout << "\navl_1 >= avl \n";

    // Comparison for equality
    if (*avl_1 == *avl)
        std::cout << "\navl_1 == avl \n";
    else
        std::cout << "\navl_1 != avl \n";

    // one more tree for comparison avl_2, identical avl_1
    avl_tree* avl_2 = new avl_tree();
    for (int i = 0; i < m; ++i)
        avl_2->insert(data1[i]);

    // Comparison for equality
    if (*avl_1 == *avl_2)
        std::cout << "\navl_1 == avl_2 \n";
    else
        std::cout << "\navl_1 != avl_2 \n";

    delete avl;   avl = NULL;
    delete avl_1; avl_1 = NULL;
    delete avl_2; avl_2 = NULL;

    return 0;
}
