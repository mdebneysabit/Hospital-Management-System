#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

// if input condition is 1 means it's emergency patient & if condition is 2 then it's normal patient
// You should give input only 1 or 2 for patient condition

class Node
{
public:
    string name;
    string source;
    int priority;
    Node *next;

    Node(string n, string s, int p)
    {
        this->name = n;
        this->source = s;
        this->priority = p;
        this->next = NULL;
    }
};

class SinglyLinkList
{
public:
    Node *head;
    Node *tail;

    queue<Node *> q;
    stack<Node *> s1, s2;

    SinglyLinkList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(string n, string s, int p)
    {
        Node *newNode = new Node(n, s, p);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        tail = newNode;
        return;
    }

    void enqueue()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            q.push(temp);
            temp = temp->next;
        }
    }

    void inputStack()
    {
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->priority == 1)
            {
                s1.push(temp);
            }
            if (temp->priority == 2)
            {
                s2.push(temp);
            }
        }
    }

    void displayQueue()
    {
        // Base call
        if (q.empty())
        {
            return;
        }

        Node *temp = q.front();
        q.pop();
        cout << "Name: " << temp->name << endl;
        cout << "Number: " << temp->source << endl;
        cout << "Condition: " << temp->priority << endl;
        cout << endl;
        displayQueue();

        q.push(temp);
    }

    void displayStack1()
    {
        // Base call
        if (s1.empty())
        {
            return;
        }

        Node *temp = s1.top();
        s1.pop();
        cout << "Name: " << temp->name << endl;
        cout << "Number: " << temp->source << endl;
        cout << "Condition: " << temp->priority << endl;
        cout << endl;
        displayStack1();

        s1.push(temp);
    }

    void displayStack2()
    {
        // Base call
        if (s2.empty())
        {
            return;
        }

        Node *temp = s2.top();
        s2.pop();
        cout << "Name: " << temp->name << endl;
        cout << "Number: " << temp->source << endl;
        cout << "Condition: " << temp->priority << endl;
        cout << endl;
        displayStack2();

        s2.push(temp);
    }

    void stackReplacePrint()
    {
        int i = 1;
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << endl;
            cout << "Patient service successful" << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Number: " << temp->source << endl;
            cout << "Condition: " << temp->priority << endl;
            cout << endl;
            i++;
            cout << "Press enter to provide service to the next patient" << endl;
            getch();
        }

        if (s1.empty())
        {
            while (!s2.empty())
            {
                Node *temp = s2.top();
                s2.pop();
                s1.push(temp);
            }
            stackReplacePrint();
        }
        stackReplacePrint();
    }
};

int main()
{
    SinglyLinkList sll;
    cout << "Enter number of patients" << endl;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter data of the patient " << i << endl;
        string name, num;
        cout << "Name: ";
        cin >> name;
        cout << "Number: ";
        cin >> num;
        int condition;
        cout << "Condition: ";
        cin >> condition;
        cout << endl;

        sll.insert(name, num, condition);
    }

    sll.enqueue();
    cout << "Displaying patient records" << endl;
    cout << "---------------------------" << endl
         << endl;
    sll.displayQueue();
    sll.inputStack();
    cout << "Displaying Emergency patient data" << endl
         << endl;
    cout << "----------------------------------" << endl;
    sll.displayStack1();
    cout << "Displaying Normal patient data" << endl
         << endl;
    cout << "---------------------------" << endl;
    sll.displayStack2();

    cout << "Patient Service" << endl;
    cout << "----------------" << endl;
    cout << "Press enter to provide service to the patient" << endl;
    getch();
    sll.stackReplacePrint();
    return 0;
}
