#include <iostream>
#include <stack>
/*
* METHOD LIST
* 
* display() ->  displays the linkedlist
* 
* is_accessible(index, operation) -> Return true if the index is acessible or throws an exception if the index is unavailable
* 
* push(data) -> Push an element into the list
* 
* add_first(data) -> add an element at the beginning of the list
* 
* pop() -> Pop the last element
* 
* remove_first() -> what do you think it does?
* 
* delete_node(index) -> Delete the (index)th node
* 
* insert_node(data, index) -> Insert a node into the list at the (index)th index and shift all the next ones
* 
* set(data, index) -> Substitutes the element at the index passed as an argument (index) with the new data (data) 
* 
* length() -> return the size of the list
* 
* opreator[] -> return the element at the index inside the [] ;
* 
* sort() -> sorts the list by increasing order
* 
* sort(comparing function) -> sorts the list with your ordering criteria
* 
* is_sorted() -> return true only if the list is ordered in increasing or decreasing order 
* 
* is_empty() -> return true if the list is empty
* 
* reverse() -> reverse the list
*
* kill() -> delete the List and print a  string passed as an argument (optional)
* 
* dbg() -> print all the nodes addresses, datas, and next pointers
* 
* dbg(index) -> print the address, data, and next pointer of the node at indexth position
*/




template <class T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node() = default;
        Node(T data, Node *p)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *HEAD = nullptr;
    size_t size = 0;

    void swap(T &a, T &b)
    {
        T c = a;
        a = b;
        b = c;
    }

public:
    LinkedList() {}

    LinkedList(std::initializer_list<T> list)
    {
        for (auto element : list)
        {
            push(element);
        }
    }

    void display()
    {
        Node *temp = HEAD;
        int i = 0;
        while (temp != nullptr)
        {
            std::cout << "[" << i << "]: " << temp->data << '\n';
            temp = temp->next; // dereference of the pointer to the struct
            i++;
        }
    }

    bool is_accessible(int index, std::string operation = "")
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Index " << index << " Not Accessible " << '\n' << operation << ": ";
            throw std::invalid_argument("Index out of bound \n");
            return false;
        }
        return true;
    }

    void push(T data)
    {
        Node *newNode = new Node(data, nullptr);

        if (!HEAD)
        {
            HEAD = newNode;
            size++;
            return;
        }

        Node *temp = HEAD;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;

        size++;
    }

    void add_first(T data)
    {
        Node *temp = HEAD;
        Node *newNode = new Node(data, nullptr);
        HEAD = newNode;
        newNode->next = temp;
        size++;
    }

    void pop()
    {
        Node *temp = HEAD;
        Node *temp1;
        while (temp->next != nullptr)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = nullptr;
        delete temp;
        size--;
    }

    void remove_first()
    {
        Node *temp = HEAD;
        HEAD = temp->next;
        delete temp;
        size--;
    }

    void delete_node(int index)
    {

        if (index == 0)
        {
            remove_first();
            return;
        }
        else if (index == size - 1)
        {
            pop();
            return;
        }
        is_accessible(index, "Delete Node");

        Node *temp = HEAD;
        Node *temp1 = temp->next;

        for (size_t i = 0; i < index - 1; i++)
        {
            temp = temp->next;
            temp1 = temp->next;
        }
        Node *del = temp1;
        temp1 = temp1->next;
        temp->next = temp1;
        delete del;
    }

    void insert_node(T data, int index)
    {
        if (index == 0)
        {
            add_first(data);
            size++;
            return;
        }
        else if (index == size)
        {
            push(data);
            size++;
            return;
        }
        is_accessible(index, "Insert");

        Node *temp = HEAD;
        Node *temp1;

        for (size_t i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        temp1 = temp->next;
        Node *newNode = new Node(data, nullptr);
        temp->next = newNode;
        newNode->next = temp1;
        size++;
    }

    void set(T data, int index)
    {
        is_accessible(index, "Set");

        Node *temp = HEAD;

        for (size_t i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->data = data;
    }

    size_t length()
    {
        return size;
    }


    T operator[](int index)
    {
        Node *temp = HEAD;
        for (size_t i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }



    void sort()
    {        
        for (int i = 0; i < size; i++)
        {
            Node *temp = HEAD;
            Node *temp1 = temp->next;
            for (int j = 0; j < size - 1; j++)
            {
                if (temp->data > temp1->data)
                {
                    swap(temp1->data, temp->data);
                }
                temp = temp->next;
                temp1 = temp->next;
            }
        }
    }

    void sort(bool (*comp)(T,T))
    {        
        for (int i = 0; i < size; i++)
        {
            Node *temp = HEAD;
            Node *temp1 = temp->next;
            for (int j = 0; j < size - 1; j++)
            {
                if (comp(temp->data, temp1->data))
                {
                    swap(temp1->data, temp->data);
                }
                temp = temp->next;
                temp1 = temp->next;
            }
        }
    }
    

    bool is_sorted(){
        Node *temp = HEAD;
        Node *temp1 = temp->next;
        bool sortedIn = true;
        bool sortedDec = true;
        for (size_t i = 0; i < size-1; i++)
        {
            if (temp1->data > temp->data) 
            {
                temp1 = temp1->next;
                temp = temp->next;
            }else{
                sortedIn = false;
                break;
            }   
        }


        
        if(!sortedIn){
            temp = HEAD;
            temp1 = temp->next;
            for (size_t i = 0; i < size-1; i++)
            {
                if (temp->data > temp1->data) 
                {
                    temp1 = temp1->next;
                    temp = temp->next;
                }else{
                    sortedDec = false;
                    break;
                }   
            }
        }
        
        return sortedIn+sortedDec;
    }

    bool is_empty()
    {
        return (size == 0) ? true : false;
    }

    void kill(std::string s = "")
    {
        std::cout << s;
        Node *temp = HEAD;
        Node *temp1;

        for (size_t i = 0; i < size; i++)
        {
            temp1 = temp;
            temp = temp->next;
            delete temp1;
        }
        delete HEAD;
    }

    void dbg(){
        Node *temp = HEAD;
        int i = 1;
        std::cout << "Lenght: " << length() << '\n';
        std::cout << "Head Pointer: " << HEAD->next << '\n';
        while (temp != nullptr)
        {
            std::cout << "Node "<< i << ": " << "Address: " << &temp->data << " Data: " << temp->data << " Pointer: " << temp->next << '\n';
            temp = temp->next;
            i++;
        }
    }
    void dbg(int index){
        is_accessible(index);
        
        Node *temp = HEAD;
        int i;
        for (i = 1; i < index-1; i++)
        {
            temp = temp->next;
        }
        std::cout << "Node "<< i << ": " << "Address: " << &temp->data << " Data: " << temp->data << " Pointer: " << temp->next << '\n';
    }

    void reverse(){
        Node *current = HEAD, *prev = nullptr, *next;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        HEAD = prev;
    }

    void reverse_(){
        std::stack<Node*> stack;
        Node* temp = HEAD;
        while (temp != NULL)
        {
            stack.push(temp);
            temp = temp->next;
            std::cout << stack.top() << '\n';
        }
        temp = stack.top();
        HEAD = temp; 
        stack.pop();    //pop the head from the stack
        while (!stack.empty())
        {
            temp->next = stack.top(); //last node next = to stack  top
            stack.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        
    }

    
};

