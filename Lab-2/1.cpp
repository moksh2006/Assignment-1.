#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    int arr[MAX], top;
public:
    Stack() { top = -1; }
    void push(int x) {
        if(top==MAX-1) cout << "Stack Overflow\n";
        else arr[++top]=x;
    }
    void pop() {
        if(top==-1) cout << "Stack Underflow\n";
        else cout << "Popped: " << arr[top--] << endl;
    }
    bool isEmpty() { return top==-1; }
    bool isFull() { return top==MAX-1; }
    void peek() {
        if(top==-1) cout << "Empty\n";
        else cout << "Top: " << arr[top] << endl;
    }
    void display() {
        if(top==-1) cout << "Empty\n";
        else for(int i=top;i>=0;i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s; int ch, val;
    while(true) {
        cout << "\n1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> ch;
        if(ch==1){ cin >> val; s.push(val);}
        else if(ch==2) s.pop();
        else if(ch==3) cout << (s.isEmpty()?"Yes\n":"No\n");
        else if(ch==4) cout << (s.isFull()?"Yes\n":"No\n");
        else if(ch==5) s.display();
        else if(ch==6) s.peek();
        else break;
    }
}
