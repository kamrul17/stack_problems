#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues
{
private:
    queue<int> q1, q2;

public:
    void push(int x)
    {

        q1.push(x);

        // Move all elements from q2 to q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        // Swap the names of q1 and q2
        swap(q1, q2);
    }

    int pop()
    {

        if (q2.empty())
        {
            return -1;
        }

        int topElement = q2.front();
        q2.pop();

        return topElement;
    }

    bool isEmpty()
    {
        return q2.empty();
    }
};

int main()
{
    StackUsingQueues stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.pop() << endl;
    cout << "Top element: " << stack.pop() << endl;

    stack.push(4);

    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
