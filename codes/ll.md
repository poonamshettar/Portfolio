### Linked List

A linked list is a linear data structure where elements, called nodes, are linked together via pointers. It allows dynamic allocation of memory and efficient insertion and deletion operations compared to arrays.

#### Complexity Analysis

| Operation                     | Time Complexity | Space Complexity |
| ----------------------------- | --------------- | ---------------- |
| Insertion (at head)           | O(1)            | O(1)             |
| Insertion (at tail)           | O(n)            | O(1)             |
| Insertion (at given position) | O(n)            | O(1)             |
| Deletion (at head)            | O(1)            | O(1)             |
| Deletion (at tail)            | O(n)            | O(1)             |
| Deletion (at given position)  | O(n)            | O(1)             |
| Search                        | O(n)            | O(1)             |

#### Code

```c
#include <stdio.h>
struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node *node;

node create_node()
{
    node newnode = (node)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory not allocated");
    }
    printf("Enter data");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    return newnode;
}

node insert_end(node head)
{
    node newnode = create_node();
    node cur;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        cur = head;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = newnode;
    }
    return head;
}
node insert_front(node head)
{
    node newnode = create_node();
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->link = head;
        head = newnode;
    }
    return head;
}

node delete_end(node head)
{
    node cur, prev;
    if (head->link == NULL)
    {
        free(head);
        head = NULL;
        printf("Deleted");
    }
    else
    {
        prev = NULL;
        cur = head;
        while (cur->link != NULL)
        {
            prev = cur;
            cur = cur->link;
        }
        prev->link = NULL;
        free(cur);
    }
    return head;
}

node delete_front(node head)
{
    node temp = head;
    head = head->link;
    free(temp);
    return head;
}

int count(node head)
{
    node cur;
    int c = 0;
    while (cur != NULL)
    {
        c++;
        cur = cur->link;
    }
    return c;
}

node delete_pos(node head)
{
    int pos, c, i;
    node cur, prev;
    c = count(head);
    printf("Enter pos");
    scanf("%d", &pos);
    if (pos == 0 && head->link == NULL)
    {
        free(head);
        head = NULL;
        printf("Deleted");
    }
    else if (pos == 0)
    {
        head = insert_front(head);
    }
    else if (pos == c - 1)
    {
        head = delete_end(head);
    }
    else
    {
        prev = NULL;
        cur = head;
        for (i = 0; i < pos; i++)
        {
            prev = cur;
            cur = cur->link;
        }
        prev->link = cur->link;
        free(cur);
    }
    return head;
}

node insert_pos(node head)
{

    int pos, c, i;
    node cur, prev;
    node newnode = create_node();
    c = count(head);
    printf("Enter pos");
    scanf("%d", &pos);
    if ((pos == 0 && head->link == NULL) || pos == 0)
    {
        head = insert_front(head);
    }
    else if (pos == 0 && head == NULL)
    {
        head = newnode;
    }
    else if (pos == c - 1)
    {
        head = insert_end(head);
    }
    else
    {
        cur = head;
        prev = NULL;
        for (i = 0; i < pos; i++)
        {
            prev = cur;
            cur = cur->link;
        }
        prev->link = newnode;
        newnode->link = cur;
    }
    return head;
}

node search_delete(node head)
{
    int search, s = 0;
    node cur, prev;
    printf("Enter search");
    scanf("%d", &search);
    if (head->data == search && head->link == NULL)
    {
        free(head);
        head = NULL;
        printf("deltetd");
    }
    else if (head->data == search)
    {
        head = delete_front(head);
    }
    else
    {
        prev = NULL;
        cur = head;
        while (cur != NULL)
        {
            if (cur->data == search)
            {
                s = 1;
                break;
            }
            prev = cur;
            cur = cur->link;
        }
        if (cur->data == search)
        {
            s = 1;
        }
        if (s == 1)
        {
            prev->link = cur->link;
            free(cur);
        }
    }
    return head;
}

node sort(node head)
{
    node cur = head;
    int temp;
    node index = NULL;
    while (cur != NULL)
    {
        index = cur->link;
        while (index != NULL)
        {
            if (cur->data > index->data)
            {
                temp = cur->data;
                cur->data = index->data;
                index->data = temp;
            }
            index = index->link;
        }
        cur = cur->link;
    }
    return head;
}
void display(node head)
{
    node cur;
    if (head == NULL)
    {
        printf("Empty");
    }
    else

    {
        cur = head;
        while (cur != NULL)
        {
            printf("%d", cur->data);
            cur = cur->link;
        }
    }
}
int main()
{
    int ch, c;
    node head = NULL;
    while (1)
    {
        printf("Enter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert_end(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insert_front(head);
            break;
        case 4:
            head = delete_end(head);
            break;
        case 5:
            head = delete_front(head);
            break;
        case 6:
            c = count(head);
            break;
        case 7:
            head = delete_pos(head);
            break;
        case 8:
            head = insert_pos(head);
            break;
        case 9:
            head = search_delete(head);
            break;
        case 10:
            head = sort(head);
            break;
        default:
            printf("Invalid");
            break;
        }
    }

    return 0;
}
```
