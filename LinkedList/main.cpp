#include <iostream>
#include "LinkedList.cpp"

int main()
{
    typedef signed long long int euro;
    LinkedList<euro> Money({1,2,3,4,5,6,7,8});
    Money.pop();
    Money.display();
    return 0;
}
