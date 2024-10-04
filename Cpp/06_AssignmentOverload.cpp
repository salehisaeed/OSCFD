#include <iostream>
using namespace std;

#define DEFAULT_SIZE 10

class myList
{
public:
    myList(int size = DEFAULT_SIZE);
    myList(const myList&); // copy constructor
    ~myList(); // destructor
    myList& operator=(const myList&);
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
    elements = new int[u.size];
    for (int i = 0; i < u.size; i++)
        elements[i] = u.elements[i];
}

myList::~myList()
{
    cout << " --> destructor called <-- \n";
    delete[] elements;
}

myList& myList::operator=(const myList& u)
{
    size = u.size;
    delete[] elements;
    elements = new int[size];
    for (int i = 0; i < size; i++)
        elements[i] = u.elements[i];

    return *this;
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

    myList v = u;    // copy constructor called 
    myList w(u);     // copy constructor called 

    myList x;
 	x = u; // assignment
}
