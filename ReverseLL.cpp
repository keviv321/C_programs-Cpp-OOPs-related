#include<iostream>
#include<stdlib.h>
//#include"Linked list_UsingClass.h"

using namespace std;
class Node
{
public:
    int data;
    Node *link;
public:
    Node(int value)
    {
        data = value;
        link = NULL;
    }
};

class LinkedList
{
private:
    Node *head,*tail;
public:
    LinkedList()//default constructor
    {
        head = NULL;
        tail = NULL;
    }
    void initializeHead(Node* temp1)
    {
        head = temp1;
    }
    void add_Node(int val)//to add a new node
    {
        Node* temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->link = temp;
            tail = temp;
        }
    }
    Node* getHead()
    {
        return head;
    }
    void delete_Node()
    {
        if (head == NULL)
            cout<<"List is Empty...Nothing can be deleted\n";
        else
        {
            Node* temp = head;
            head = head->link;
            delete(temp);
            temp = NULL;
            if (head == NULL)
                tail = NULL;
        }
    }
    void print_List()
    {
        if (head == NULL)
        {
            cout<<"List is Empty \n";
            return;
        }
        Node* temp = head;
        while (temp!=NULL)
        {
            cout<<(*temp).data<<"-->";
            temp = (*temp).link;
        }
        cout<<"null\n";
    }
    Node* reverseLL (Node* temp)
    {
        if (temp==NULL||temp->link == NULL)
            return temp;
        else
        {
            Node *newHead = reverseLL(temp->link);
            temp->link->link = temp;
            temp->link = NULL;
            return newHead;
        }
    }
};

int main()
{
    LinkedList list1;
    list1.add_Node(12);
    list1.add_Node(15);
    list1.add_Node(77);
    list1.add_Node(88);

    cout<<"Original Linked List :"<<endl;
    list1.print_List();

    Node * newHead = list1.reverseLL(list1.getHead());
    list1.initializeHead(newHead);

    cout<<"Reversed Linked list :"<<endl;
    list1.print_List();

    list1.delete_Node();
    list1.print_List();

    list1.delete_Node();
    list1.print_List();

    list1.delete_Node();
    list1.print_List();

    list1.delete_Node();
    list1.delete_Node();//*/
    return 0;
}

