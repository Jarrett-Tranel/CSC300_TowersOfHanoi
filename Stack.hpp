#include "Node.hpp"
class Stack
{
    private:
        Node* top;
        int elements;
        void translateDisk(int payload);

    public:
        Stack();
        void push(int payload);
        int pop();
        int peek();
        bool isWin();
        void moveTo(Stack* to);
        void displayTextual();
        void display();
};