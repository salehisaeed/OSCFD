#include <iostream>
using namespace std;

class myList
{
public:
    myList(int);
    myList(const myList&); // copy constructor
    ~myList(); // destructor
    int get_size();
    int *elements;

private:
    int size;
};

myList::myList(int s)
{
    cout << " --> constructor called <-- \n";
    size = s;
    elements = new int[size];
}

myList::myList(const myList& u)
{
    cout << " --> copy constructor called <-- \n";
    size = u.size;
    // elements = u.elements; // This will do a shallow-copy (default copy constructor)
    elements = new int[u.size];
    for (int i = 0; i < u.size; i++)
        elements[i] = u.elements[i];
}

myList::~myList()
{
    cout << " --> destructor called <-- \n";
    delete[] elements;
}

int myList::get_size()
{
    return size;
}

void print_list(myList v)
{
    cout << "Print the list" << endl;
    for (int i = 0; i < v.get_size(); i++)
        cout << v.elements[i] << endl;
}

int main()
{
    cout << "Hello" << endl;
    myList u(5);
    for (int i = 0; i < u.get_size(); i++)
        u.elements[i] = i;
    print_list(u);
    cout << "Bye" << endl;
}