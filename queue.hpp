/* Array implementation of queue */

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
private:
    int front = -1;
    int rear = -1;
    int size = 0;
    int capacity = 10;
    int *data = new int[capacity];

public:
    Queue() {}

    Queue(int capacity)
    {
        this->capacity = capacity;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (size == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool enqueue(int n)
    {
        if (this->isFull())
        {
            return false;
        }
        else if (this->isEmpty())
        {
            this->data[0] = n;
            this->front = 0;
            this->rear = 0;
            this->size++;
            return true;
        }
        else
        {
            if (this->rear == this->size - 1)
            {
                this->rear = 0;
                this->data[0] = n;
                this->size++;

                return true;
            }
            else
            {
                this->rear++;
                this->data[this->rear] = n;
                this->size++;

                return true;
            }
        }
    }

    bool dequeue()
    {
        if (this->isEmpty())
        {
            return false;
        }
        else
        {
            this->front++;
            this->size--;
            return true;
        }
    }
};

#endif