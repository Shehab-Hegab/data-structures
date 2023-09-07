/* Array implementation of stack */

#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
private:
    int top = -1;
    int size = 10;
    int *data = new int[size];

public:
    Stack(){};

    Stack(int size)
    {
        this->size = size;
    }

    bool isEmpty()
    {
        if (this->top == -1)
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
        if (this->top == this->size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool push(int num)
    {
        if (this->isFull())
        {
            return false;
        }
        else
        {
            this->top++;
            this->data[top] = num;
            return true;
        }
    }

    bool pop()
    {
        if (this->isEmpty())
        {
            return false;
        }
        else
        {
            this->top--;
            return true;
        }
    }

    int peek()
    {
        if (this->isEmpty())
        {
            return -1; // assuming that all the elements are +ve
        }
        else
        {
            return this->data[this->top];
        }
    }

    void print() {
        printf("start\n");

        for (int i = this->top; i >= 0; i--)
        {
            printf("%i\n", this->data[i]);
        }

        printf("end\n");
    }
};

#endif