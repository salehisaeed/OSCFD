#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "Constructor\n";
    }

    MyClass(const MyClass&)
    {
        std::cout << "Copy Constructor\n";
    }

    ~MyClass() 
    {
        std::cout << "Destructor\n";
    }
};

MyClass createObject()
{
    MyClass obj;
    return obj;
}

int main()
{
    MyClass obj = createObject();
}
