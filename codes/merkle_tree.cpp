#include <bits/stdc++.h>
using namespace std;
int maxim = 15;
int size = 0;

struct node
{
    int key;
    int value;
    struct node *left;
    struct node *right;
};
struct bst
{

    struct node *head;
};

struct bst *arr;

void insert_element(struct node *tree, struct node *item);

struct node *find(struct node *tree, int key);

struct node *remove_element(struct node *tree, int key);

void display_tree(struct node *tree);

int hashcode(int key) { return (key % maxim); }

void add(int key, int value)
{
    int index = hashcode(key);

    struct node *tree = (struct node *)arr[index].head;

    struct node *new_item = (struct node *)malloc(sizeof(struct node));

    new_item->key = key;
    new_item->value = value;
    new_item->left = NULL;
    new_item->right = NULL;

    if (tree == NULL)
    {
        cout << "Inserting " << key << " and " << value
             << endl;
        arr[index].head = new_item;
        size++;
    }

    else
    {

        struct node *temp = find(tree, key);

        if (temp == NULL)
        {

            cout << "Inserting " << key << "and" << value
                 << endl;

            insert_element(tree, new_item);
            size++;
        }

        else
        {

            temp->value = value;
        }
    }
}

struct node *find(struct node *tree, int key)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->key == key)
    {
        return tree;
    }
    else if (key < tree->key)
    {
        return find(tree->left, key);
    }
    else
    {
        return find(tree->right, key);
    }
}

void insert_element(struct node *tree, struct node *item)
{

    if (item->key < tree->key)
    {
        if (tree->left == NULL)
        {
            tree->left = item;
            return;
        }
        else
        {
            insert_element(tree->left, item);
            return;
        }
    }

    else if (item->key > tree->key)
    {
        if (tree->right == NULL)
        {
            tree->right = item;
            return;
        }
        else
        {
            insert_element(tree->right, item);
            return;
        }
    }
}

void display()
{
    int i = 0;
    for (i = 0; i < maxim; i++)
    {
        struct node *tree = arr[i].head;
        if (tree == NULL)
        {
            cout << "arr[" << i
                 << "] has no elements " << endl;
        }
        else
        {
            cout << "arr[" << i
                 << "] has elements " << endl;
            display_tree(tree);
        }
    }
}

void display_tree(struct node *tree)
{

    if (tree == NULL)
    {
        return;
    }

    cout << tree->key << " and " << tree->value << "   ";

    if (tree->left != NULL)
    {
        display_tree(tree->left);
    }

    if (tree->right != NULL)
    {
        display_tree(tree->right);
    }
}
void init()
{
    int i = 0;
    for (i = 0; i < maxim; i++)
    {
        arr[i].head = NULL;
    }
}

int size_of_hashTree() { return size; }

void del(int key)
{
    int index = hashcode(key);
    struct node *tree = (struct node *)arr[index].head;
    if (tree == NULL)
    {
        cout << key << " Key not present" << endl;
    }

    else
    {
        struct node *temp = find(tree, key);
        if (temp == NULL)
        {
            cout << key << " is not present";
        }
        else
        {
            tree = remove_element(tree, key);
            cout << key
                 << " has been removed form the hash tree " << endl;
        }
    }
}

struct node *remove_element(struct node *tree, int key)
{

    if (tree == NULL)
    {
        return NULL;
    }

    if (key < tree->key)
    {
        tree->left = remove_element(tree->left, key);
        return tree;
    }

    else if (key > tree->key)
    {
        tree->right = remove_element(tree->right, key);
        return tree;
    }

    else
    {

        if (tree->left == NULL && tree->right == NULL)
        {
            size--;
            return tree->left;
        }

        else if (tree->left != NULL && tree->right == NULL)
        {
            size--;
            return tree->left;
        }

        else if (tree->left == NULL && tree->right != NULL)
        {
            size--;
            return tree->right;
        }

        else
        {
            struct node *left_one = tree->left;
            while (left_one->right != NULL)
            {
                left_one = left_one->right;
            }

            tree->key = left_one->key;
            tree->value = left_one->value;
            tree->left = remove_element(tree->left, tree->key);
            return tree;
        }
    }
}

int main()
{
    int choice, key, value, n, c;
    arr = (struct bst *)malloc(maxim * sizeof(struct bst *));
    init();
    do
    {
        cout << "\n1.Insert"
                "\n2.Remove"
                "\n3.Check size"
                "\n4.Display ";

        cin >> choice;
        switch (choice)
        {

        case 1:
            cout << "Inserting element in Hash Tree " << endl;
            cout
                << "Enter key and value-:    ";
            cin >> key >> value;
            add(key, value);
            break;

        case 2:
            cout << "Deleting item from Hash Tree  \n Enter the key to delete -: ";
            cin >>
                key;
            del(key);
            break;

        case 3:
            n = size_of_hashTree();
            cout << "Size of Hash Tree is-:" << n << endl;
            break;

        case 4:
            display();
            break;

        default:
            cout << "Wrong Input" << endl;
        }
        cout << "\n Do you want to continue-:(press 1 for yes)     ";
        cin >> c;

    } while (c == 1);
    return 0;
}