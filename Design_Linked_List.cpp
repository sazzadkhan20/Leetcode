class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList
{
public:
    Node *head = NULL;
    int size()
    {
        int sz = 0;
        Node *temp = head;
        while (temp)
        {
            sz++;
            temp = temp->next;
        }
        return sz;
    }
    MyLinkedList()
    {
    }

    int get(int index)
    {
        if (!head)
            return -1;
        if (index >= size() || index < 0)
            return -1;
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (!head)
            return;
        if (index > size() || index < 0)
            return;

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index)
    {
        if (!head)
            return;
        if (index >= size() || index < 0)
            return;
        if (index == 0)
        {
            Node *node = head;
            head = head->next;
            delete node;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node *node = temp->next;
        temp->next = temp->next->next;
        delete node;
    }
};