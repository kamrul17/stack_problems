// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

void transfer(stack<int> &X,
              stack<int> &Y)
{
    while (!X.empty())
    {
        Y.push(X.top());
        X.pop();
    }
}

void display(stack<int> S)
{

    while (!S.empty())
    {

        cout << S.top() << " ";

        S.pop();
    }
    cout << endl;
}

void reverseStackUsingTwoStacks(stack<int> &S)
{
    // Two additional stacks
    stack<int> A, B;
    transfer(S, A);
    transfer(A, B);
    transfer(B, S);

    display(S);
}

int main()
{
    stack<int> S;
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
    reverseStackUsingTwoStacks(S);

    return 0;
}