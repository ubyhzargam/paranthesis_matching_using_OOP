#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node *next;
};


class Stack
{
    private:
        Node *top;
        int size=0;
    public:
        Stack()
    {
            top=NULL;
    }
    void Push(char x);
    int  Pop();
    bool isEmpty();


};

void Stack ::Push(char x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        size++;
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack :: Pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
        return x;
    }
    else
    {
        size--;
        Node *p=top;
        top=top->next;
        x=1;
        free(p);
        return x;
    }
}

bool Stack :: isEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

class Balanced
{
    Stack stk;
    public:
    int isBalanced(char *s);
};

int Balanced :: isBalanced(char s[])
{
    int flag =0;
    int size =0;int i=0;
    while(s[i]!='\0'){
        size++;
        i++;
    }
    for(int i=0;i<size;i++)
    {
        if(s[i]=='(')
        {
            stk.Push('(');
        }
        else if(s[i]==')')
        {
            flag = stk.Pop();
        }
        if(flag ==-1)
        {
            break;
        }
    }
    if(flag ==-1){
        cout<<") brackets are more "<<endl;
    }
    else if(stk.isEmpty()==true){
        cout<<"Balanced"<<endl;
        return true;
    }
    else cout<<"( brackets are more"<<endl;
    return false;
}

int main()
{
    Stack stk;
    char ch[]="(((98)9Uby89)(028)))";
    Balanced bsdk;
    bsdk.isBalanced(ch);
    return 0;
}


