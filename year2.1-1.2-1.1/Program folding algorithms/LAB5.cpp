#include <iostream>
using namespace std;

struct link
{
    char data;
    link* next;
};

link* first = NULL;

void symbs ();
void display();
void additem(char d);

int main()
{
    char d = 0;
    cout << "Input symbols until 0" << endl;
    while (1)
    {
        cin >> d;
        if(d == '0') break;
        additem(d);
    }
    symbs();
    display();
    return 0;
}

void additem(char d)
{
    link* newlink = new link;
    newlink->data = d;
    newlink->next = first;
    first = newlink;
}

void display()
{
    link* current = first;
    while(current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

void symbs ()
{
    int a = 0;
    int o = 0;
    link* current = first;
    while(current)
    {
        if (current->data == 'a')
        {
            a++;
        }
        if (current->data == 'o')
        {
            o++;
        }
        current = current->next;
    }
    if (a > o)
    {
        cout << "'a's more than 'o's " << endl;
    }
    if (a < o)
    {
        cout << "'o's more than 'a's " << endl;
    }
    if (a ==0 && o==0)
    {
        cout << "'a's and 'o's are absent " << endl;
    }
    if ((a!=0 && o!=0) && a==o)
    {
        cout << "number of 'a's and 'o's is equal " << endl;
    }
}
