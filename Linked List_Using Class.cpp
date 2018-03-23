#include<iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *link;
private:
    Node(int value)
    {
        data = value;
        link = NULL;
    }
    friend class LinkedList;
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
            cout<<"List is Empty\n";
            return;
        }
        Node* temp = head;
        while (temp!=tail->link)
        {
            cout<<(*temp).data<<"-->";
            temp = (*temp).link;
        }
        cout<<"null\n";
    }
};
int main()
{
    LinkedList list1;
    list1.add_Node(12);
    list1.add_Node(15);
    list1.add_Node(77);
    list1.add_Node(88);

    list1.print_List();

    list1.delete_Node();
    list1.print_List();

    list1.delete_Node();
    list1.print_List();

    list1.delete_Node();
    list1.print_List();

    list1.delete_Node();
    list1.delete_Node();
    return 0;
}
