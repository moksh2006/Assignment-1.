#include <iostream>
using namespace std;

#define MAX 100
int st[MAX];
int top = -1;

void push(int x) {
    if(top == MAX-1) return;
    st[++top] = x;
}

int pop() {
    if(top == -1) return -1;
    return st[top--];
}

int evaluate(string expr) {
    for(int i=0; i<expr.length(); i++) {
        char c = expr[i];
        if(isdigit(c)) {
            push(c - '0');
        }
        else {
            int val2 = pop();
            int val1 = pop();
            switch(c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    string expr;
    cin >> expr;
    cout << evaluate(expr) << endl;
    return 0;
}
