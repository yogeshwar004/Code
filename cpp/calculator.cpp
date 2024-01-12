#include <iostream>
using namespace std;
int main()
{
    double n1,n2;
    char op;
    cout <<"Enter first number:";
    cin >> n1;
    cout <<"Enter the operator:";
    cin >>op;
    cout <<"Enter second number:";
    cin >>n2;
    switch(op)
    {
        case '+':
            cout << n1 << '+' << n2 << '=' << n1+n2 << endl;
            break;
        case '-':
            cout << n1 << '-' << n2 << '=' << n1-n2 << endl;
            break;
        case '*':
            cout << n1 << '*' << n2 << '=' << n1*n2 << endl;
            break;
        case '/':
            if(n2!=0)
            {
                cout << n1 << '/' << n2 << '=' << n1/n2 << endl;
            }
            else
            {
                cout << "Invalid Input...ZeroDivisionError";
            }
            break;
        default:
            cout << "Invalid Operation or Number";
            break;
    }
}