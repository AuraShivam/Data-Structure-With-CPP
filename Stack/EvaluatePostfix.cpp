#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;

    return 0;
}

bool isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return false;

    return true;
}

string InfixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    st.push('(');
    infix += ')';

    int i = 0;

    while (!st.empty())
    {
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(st.top()))
            {
                st.push(infix[i]);
                i++;
            }
            else
            {
                if (st.top() == '(' && infix[i] == ')')
                {
                    st.pop();
                    i++;
                }
                else
                {
                    postfix += st.top();
                    st.pop();
                }
            }
        }
    }

    return postfix;
}

int EvaluatePostfix(string postfix)
{
    stack<int> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            st.push(postfix[i] - '0');
        }
        else
        {
            int x2 = st.top();
            st.pop();

            int x1 = st.top();
            st.pop();

            int r = 0;

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;

            case '-':
                r = x1 - x2;
                break;

            case '*':
                r = x1 * x2;
                break;

            case '/':
                r = x1 / x2;
                break;
            }

            st.push(r);
        }
    }

    return st.top();
}

int main()
{
    string infix = "4+2*3-6/2";

    string postfix = InfixToPostfix(infix);

    cout << "Postfix expression after conversion: "
         << postfix << endl;

    cout << "Result is "
         << EvaluatePostfix(postfix) << endl;

    return 0;
}
