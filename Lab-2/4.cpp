#include <iostream>
using namespace std;

#define MAX 100
char st[MAX];
int top = -1;

void push(char c) {
    if(top == MAX-1) return;
    st[++top] = c;
}

char pop() {
    if(top == -1) return '\0';
    return st[top--];
}

char peek() {
    if(top == -1) return '\0';
    return st[top];
}

int precedence(char c) {
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

string infixToPostfix(string expr) {
    string res = "";
    for(int i=0; i<expr.length(); i++) {
        char c = expr[i];
        if(isalnum(c)) {
            res += c;
        }
        else if(c=='(') {
            push(c);
        }
        else if(c==')') {
            while(top!=-1 && peek()!='(') {
                res += pop();
            }
            pop(); // remove '('
        }
        else {
            while(top!=-1 && precedence(peek()) >= precedence(c)) {
                res += pop();
            }
            push(c);
        }
    }
    while(top!=-1) {
        res += pop();
    }
    return res;
}

int main() {
    string expr;
    cin >> expr;
    cout << infixToPostfix(expr) << endl;
    return 0;
}

