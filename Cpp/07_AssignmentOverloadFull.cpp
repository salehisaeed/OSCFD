#include <iostream>
using namespace std;

#define DEFAULT_SIZE 10

class myList
{
public:
    myList(int size = DEFAULT_SIZE);
    myList(const myList &); // copy constructor
    ~myList();             // destructor
    myList &operator=(const myList &);
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

myList::myList(const myList &s)
{
    cout << " --> copy constructor called <-- \n";
    size = s.size;
    elements = new int[s.size];
    for (int i = 0; i < s.size; i++)
        elements[i] = s.elements[i];
}

myList::~myList()
{
    cout << " --> destructor called <-- \n";
    delete[] elements;
}

myList &myList::operator=(const myList &s)
{
    if (this == &s)
        return *this;

    size = s.size;
    delete[] elements;
    elements = new int[size];
    for (int i = 0; i < size; i++)
        elements[i] = s.elements[i];

    return *this;
}

int myList::get_size()
{
    return size;
}

void print_list(myList s)
{
    cout << "Print the list" << endl;
    for (int i = 0; i < s.get_size(); i++)
        cout << s.elements[i] << endl;
}

int main()
{
    cout << "Hello" << endl;
    myList s(5);
    for (int i = 0; i < s.get_size(); i++)
        s.elements[i] = i;

    myList v = s; // copy constructor called
    myList w(s);  // copy constructor called

    myList x;
    // assignment
    x = s;
}
