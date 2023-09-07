#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class LinkedList
{
private:
    struct Node
    {
        int value;
        Node *next = nullptr;
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

public:
    LinkedList() {}

    LinkedList(int *arr, int size)
    {
        for (int i = 0; i < size; i++) {
            this->pushBack(arr[i]);
        }
    }

    LinkedList(Node *head, int size)
    {
        this->head = head;
        this->size = size;
    }

    Node *getHead()
    {
        return this->head;
    }

    Node *getTail()
    {
        return this->tail;
    }

    int getSize()
    {
        return size;
    }

    void pushBack(int num)
    {
        Node *temp = new Node;
        temp->value = num;

        if (size == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {

            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void popBack()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        else
        {
            Node *temp = new Node;
            temp = head;
            int counter = 0;

            while (counter < size - 2)
            {
                temp = temp->next;
                counter++;
            }

            temp->next = nullptr;

            delete tail;

            tail = temp;

            size--;
        }
    }

    void insertFront(int num)
    {
        Node *temp = new Node;
        temp->value = num;

        if (size == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void popFront()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        else
        {
            Node *temp = head->next;
            delete head;
            head = temp;
            size--;
        }
    }

    bool insert(int index, int num)
    {
        if (index > size || index < 0)
        {
            return false;
        }
        else if (index == 0)
        {
            insertFront(num);
            return true;
        }
        else if (index == size)
        {
            pushBack(num);
            return true;
        }

        Node *newNode = new Node;
        newNode->value = num;

        Node *temp = new Node;
        temp = head;
        int i = 0;

        while (i + 1 != index)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        this->size++;

        return true;
    }

    bool remove(int index)
    {
        if (index < 0 || index >= size)
        {
            return false;
        }
        else if (index == 0)
        {
            popFront();
            return true;
        }
        else if (index == size - 1)
        {
            popBack();
            return true;
        }
        else
        {
            Node *temp = new Node;
            Node *prev = new Node;
            temp = head;
            int i = 0;

            while (i != index)
            {
                if (i == index - 1)
                {
                    prev = temp;
                }
                temp = temp->next;
                i++;
            }

            prev->next = temp->next;

            delete temp;

            size--;

            return true;
        }
    }

    int get(int index)
    {
        if (index == 0)
        {
            return head->value;
        }
        else if (index == size - 1)
        {
            return tail->value;
        }
        else if (index < 0 || index >= size)
        {
            std::cout << "ERROR: INDEX OUT OF BOUNDS" << std::endl;
            std::cout << "THE FUNCTION WILL RETURN -1" << std::endl;

            return -1;
        }
        else
        {
            Node *temp = head;
            int i = 0;

            while (i != index)
            {
                temp = temp->next;
                i++;
            }

            return temp->value;
        }
    }

    bool modify(int index, int num)
    {
        if (index == 0)
        {
            head->value = num;
            return true;
        }
        else if (index == size - 1)
        {
            tail->value = num;
            return true;
        }
        else if (index < 0 || index >= size)
        {
            return false;
        }
        else
        {
            Node *temp = head;
            int i = 0;

            while (i != index)
            {
                temp = temp->next;
                i++;
            }

            temp->value = num;

            return true;
        }
    }

    void printList()
    {
        Node *temp = head;
        int size = 0;

        std::cout << "[ ";

        while (temp != nullptr)
        {
            size++;

            if (size != this->size)
            {
                std::cout << temp->value << ", ";
            }
            else
            {
                std::cout << temp->value;

                this->tail = temp;
            }

            temp = temp->next;
        }

        std::cout << " ]" << std::endl;
        std::cout << "size: " << this->size << std::endl;
        std::cout << std::endl;
    }

    void reverse() {
        if (size == 0 || size == 1) {
            return;
        } else {
            Node *tempNode, *prevNode, *nextNode;
            prevNode = this->head;
            tempNode = this->head->next;
            while (tempNode != nullptr) {
                nextNode = tempNode->next;
                tempNode->next = prevNode;
                prevNode = tempNode;
                tempNode = nextNode;
            }

            tempNode = this->head;
            tempNode->next = nullptr;
            this->head = this->tail;
            this->tail = tempNode;
        }
    }
};

#endif