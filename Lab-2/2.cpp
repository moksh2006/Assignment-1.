#include <iostream>
using namespace std;

#define MAX 100
char st[MAX];
int top = -1;

void push(char c) {
    if(top == MAX-1) {
        cout << "Stack Overflow\n";
        return;
    }
    st[++top] = c;
}

char pop() {
    if(top == -1) {
        cout << "Stack Underflow\n";
        return '\0';
    }
    return st[top--];
}

int main() {
    string s;
    cin >> s;

    for(int i=0;i<s.length();i++) {
        push(s[i]);
    }

    while(top != -1) {
        cout << pop();
    }

    cout << endl;
    return 0;
}

