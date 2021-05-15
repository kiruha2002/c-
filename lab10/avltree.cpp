#include<iostream>

// узел дерева
struct avl_node
{
    int              data;
    struct avl_node* left;
    struct avl_node* right;
};
//------------------------------------------------------------------
class avl_tree
{
    avl_node* root;                         // указатель на корень дерева

    int       height(avl_node*) const;    // Высота AVL-дерева
    int       balance_factor(avl_node*);
    avl_node* rr_rotation(avl_node*);    // Вращения,
    avl_node* ll_rotation(avl_node*);    // используемые
    avl_node* lr_rotation(avl_node*);    // для
    avl_node* rl_rotation(avl_node*);    // балансировки.
    avl_node* balance(avl_node*);        // Балансировка дерева
    avl_node* get_min(avl_node*) const;
    avl_node* insert_helper(avl_node*, int);  // Вставка узла в дерево
    avl_node* remove_helper(avl_node*, int);  // Удаление узла
    void      display_helper(avl_node*, int) const; // распечатка дерева
    int       leaf_count_helper(avl_node*)   const; // счетчик листьев
    int       node_count_helper(avl_node*)   const; // счетчик узлов
    bool      equality(avl_node*, avl_node*);       // == деревьев
    void      delete_tree(avl_node*);               // удаление дерева

public:
    avl_tree()
    {
        root = NULL;
    }
    void insert(int value)   // вставка узла
    {
        this->root = insert_helper(this->root, value);
    }
    void remove(int value)   // удаление узла
    {
        this->root = remove_helper(this->root, value);
    }
    void display()             // распечатка дерева
    {
        display_helper(this->root, 1);
    }
    int  leaf_count()          // счетчик листьев
    {
        return  leaf_count_helper(this->root);
    }
    int  node_count()          // счетчик узлов
    {
        return  node_count_helper(this->root);
    }
    // оператор < по количеству вершин деревьев
    friend bool operator < (avl_tree& l, avl_tree& r)
    {
        return  l.node_count() < r.node_count();
    }
    // проверка на равенство деревьев
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
// Высота AVL-дерева
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
// Разность высот левого и правого поддеревьев
//------------------------------------------------------------------
int avl_tree::balance_factor(avl_node* temp)
{
    return height(temp->left) - height(temp->right);
}
//------------------------------------------------------------------
// Право-правый поворот, Right-Right Rotation
//------------------------------------------------------------------
avl_node* avl_tree::rr_rotation(avl_node* parent)
{
    avl_node* temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
//------------------------------------------------------------------
// Лево-левый поворот, Left-Left Rotation
//------------------------------------------------------------------
avl_node* avl_tree::ll_rotation(avl_node* parent)
{
    avl_node* temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
//------------------------------------------------------------------
// Лево-правый поворот, Left-Right Rotation
//------------------------------------------------------------------
avl_node* avl_tree::lr_rotation(avl_node* parent)
{
    avl_node* temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}
//------------------------------------------------------------------
// Право-левый поворот, Right-Left Rotation
//------------------------------------------------------------------
avl_node* avl_tree::rl_rotation(avl_node* parent)
{
    avl_node* temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}
//------------------------------------------------------------------
// Балансировка AVL дерева при помощи поворотов
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
// Вставка узла в AVL-дерево
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
    return balance(t); // возвращаем указ. на сбалансированное дерево
}
//------------------------------------------------------------------
// Распечатка AVL дерева, лежащего на боку
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
// Удаление узла
//------------------------------------------------------------------
avl_node* avl_tree::remove_helper(avl_node* t, int x)
{
    avl_node* temp = NULL;
    if (t == NULL)       // узел не найден
        return NULL;
    else
        if (x < t->data)
            t->left = remove_helper(t->left, x);
        else
            if (x > t->data)
                t->right = remove_helper(t->right, x);
            else
                if (t->left && t->right)  // узел имеет 2 потомка
                {
                    temp = get_min(t->right);
                    t->data = temp->data;
                    t->right = remove_helper(t->right, t->data);
                }
                else  // узел имеет меньше 2-х потомков
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
    return  balance(t); // возвращаем указ. на сбалансированное дерево
}
//------------------------------------------------------------------
// Счётчик листьев дерева
//------------------------------------------------------------------
int  avl_tree::leaf_count_helper(avl_node* t) const
{
    if (!t)
        return 0;
    if (!(t->left) && !(t->right)) // лист, если нет потомков
        return 1;
    else
        return leaf_count_helper(t->left)
        + leaf_count_helper(t->right);
}
//------------------------------------------------------------------
// Счётчик узлов дерева
//------------------------------------------------------------------
int avl_tree::node_count_helper(avl_node* t) const
{
    if (!t)
        return 0;
    return 1 + node_count_helper(t->left) + node_count_helper(t->right);
}
//------------------------------------------------------------------
// Удаление дерева
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
// Сравнение на равенство
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
    avl_tree* avl = new avl_tree();  // исходное дерево
    int  data[] = { 10, 20, 30, 40, 50, 25, 45 };
    const int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; ++i)
        avl->insert(data[i]);

    std::cout << "Original tree: avl\n";
    avl->display();
    std::cout << "\nNumber of leaves = " << avl->leaf_count()
        << "\nNumber of nodes = " << avl->node_count() << "\n";

    avl->remove(20); // удалили узел 20
    std::cout << "\n\n Remove from avl 20\n";
    avl->display();
    std::cout << "\nNumber of leaves = " << avl->leaf_count()
        << "\nNumber of nodes = " << avl->node_count() << "\n";

    avl->insert(90);  // добавили узлы 90
    avl->insert(5);   // и 5
    std::cout << "\n\n Insert into avl 90, 5 \n";
    avl->display();
    std::cout << "\nNumber of leaves = " << avl->leaf_count()
        << "\nNumber of nodes = " << avl->node_count() << "\n";
    std::cout << "\n\n";

    avl_tree* avl_1 = new avl_tree(); // ещё одно дерево
    int  data1[] = { 10, 20, 50, 25, 45 };
    const int m = sizeof(data1) / sizeof(data1[0]);
    for (int i = 0; i < m; ++i)
        avl_1->insert(data1[i]);

    std::cout << "Another tree: avl_1\n";
    avl_1->display();
    std::cout << "\nNumber of leaves = " << avl_1->leaf_count()
        << "\nNumber of nodes = " << avl_1->node_count() << "\n";

    // Сравнение < по количеству вершин
    if (*avl_1 < *avl)
        std::cout << "\navl_1 < avl \n";
    else
        std::cout << "\navl_1 >= avl \n";

    // Сравнение на равенство
    if (*avl_1 == *avl)
        std::cout << "\navl_1 == avl \n";
    else
        std::cout << "\navl_1 != avl \n";

    // ещё одно дерево для сравнения avl_2, идентичное avl_1
    avl_tree* avl_2 = new avl_tree();
    for (int i = 0; i < m; ++i)
        avl_2->insert(data1[i]);

    // Сравнение на равенство
    if (*avl_1 == *avl_2)
        std::cout << "\navl_1 == avl_2 \n";
    else
        std::cout << "\navl_1 != avl_2 \n";

    delete avl;   avl = NULL;
    delete avl_1; avl_1 = NULL;
    delete avl_2; avl_2 = NULL;

    return 0;
}
