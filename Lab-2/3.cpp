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

bool isBalanced(string expr) {
    for(int i=0;i<expr.length();i++) {
        char c = expr[i];
        if(c=='(' || c=='{' || c=='[') {
            push(c);
        } else if(c==')' || c=='}' || c==']') {
            if(top == -1) return false;
            char t = pop();
            if((c==')' && t!='(') || (c=='}' && t!='{') || (c==']' && t!='['))
                return false;
        }
    }
    return top==-1;
}

int main() {
    string expr;
    cin >> expr;
    if(isBalanced(expr)) cout << "Balanced\n";
    else cout << "Not Balanced\n";
    return 0;
}
