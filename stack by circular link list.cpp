#include<iostream>
#include<stdio.h>
using namespace std;
//stack by circular link list
class node
{
public:
    int info;
    node *next;
};
node* creat(int data)
{
    node *ptr= new node;
    ptr->info=data;
}
void display(node *head)
{
    node *ptr= head->next;
    do {
        cout<<" "<<ptr->info;
        ptr=ptr->next;
    } while(ptr!=head);
}
void push(node *head,int data)
{
    node *ptr= head->next;
    do {

        ptr=ptr->next;
    } while(ptr->next!=head);
    node *p1=creat(data);
    ptr->next=p1;
    p1->next=head;
}
void pop(node *head)
{
    node *ptr= head->next;
    do {

        ptr=ptr->next;
    } while(ptr->next->next!=head);
    delete ptr->next;
    ptr->next=head;

}
int main()
{
    node *head,*p1,*p2,*p3;
    head=new node;
    p1=creat(10);
    p2=creat(20);
    p3=creat(30);

    head->next=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=head;
    display(head);
    cout<<endl<<endl;
    pop(head);
    cout<<"after pop in stack"<<endl;
    cout<<endl<<endl;
    display(head);

    cout<<endl<<endl;
    push(head,99);
    cout<<"after push in stack"<<endl;
    cout<<endl<<endl;
    display(head);

    return 0;
}
