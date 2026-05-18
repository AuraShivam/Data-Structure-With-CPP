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

int main()
{
    string infix = "4+2*3-6/2";

    string postfix = InfixToPostfix(infix);

    cout << "Postfix expression after conversion: "
         << postfix << endl;

    return 0;
}
