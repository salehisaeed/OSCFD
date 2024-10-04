#include <iostream>
#include <memory>
using namespace std;

class myList
{
public:
    myList(int);
    ~myList();
    shared_ptr<int[]> elements;

private:
    int size;
};

myList::myList(int s)
{
    cout << " --> constructor called <-- \n";
    size = s;
    elements = shared_ptr<int[]>(new int[size]);
}

myList::~myList()
{
    cout << " --> destructor called <-- \n";
}

int main()
{
    cout << "Hello" << endl;
    myList u(5);
    cout << "Pointer count:" << u.elements.use_count() << endl;
    cout << "Memory address of s.elements:" << u.elements.get() << endl;
    {
        myList v = u;
        cout << "Pointer count:" << u.elements.use_count() << endl;
        cout << "Pointer count:" << v.elements.use_count() << endl;
        cout << "Memory address of u.elements:" << v.elements.get() << endl;
    }
    cout << "Pointer count:" << u.elements.use_count() << endl;
    cout << "Bye" << endl;
}
