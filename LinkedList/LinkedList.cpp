#include <iostream>

/*
display() ->  displays the linkedlist

is_accessible(int index, std::string operation) -> Return true if the index is acessible or throws an exception if the index is unavailable

push(T data) -> Push an element into the list

add_first(T data) -> add an element at the beginning of the list

pop() -> Pop the last element

remove_first() -> what do you think it does?

delete_node(int index) -> Delete the (index)th node


insert(T data, int index) -> Insert an element into the list at the (index)th index and shift all the next ones

set(T data, int index) -> Substitutes the element at the index passed as an argument (index) with the new data (data) 


kill() -> delete the List and print a  string passed as an argument (optional)


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

    LinkedList(std::initializer_list<T> lists)
    {
        for (auto element : lists)
        {
            push(element);
        }
    }

    void display()
    {
        Node *temp = HEAD;
        int i = 0;
        while (temp->next != nullptr)
        {
            std::cout << "[" << i << "]: " << temp->data << '\n';
            temp = temp->next; // dereference of the pointer to the struct
            i++;
        }
        std::cout << "[" << i << "]: " << temp->data << '\n';
    }

    bool is_accessible(int index, std::string operation = "")
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Index " << index << " Not Accessible " << '\n'
                      << operation << ": ";
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
        delete[] temp;
        size--;
    }

    void remove_first()
    {
        Node *temp = HEAD;
        HEAD = temp->next;
        delete[] temp;
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

    void insert(T data, int index)
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

    

    int operator[](int index)
    {
        Node *temp = HEAD;
        for (size_t i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    bool is_empty()
    {
        return (size == 0) ? true : false;
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

    bool is_sorted(){
        Node *temp = HEAD;
        Node *temp1 = temp->next;
        for (size_t i = 0; i < size-1; i++)
        {
            if (temp1->data > temp->data)
            {
                temp1 = temp1->next;
                temp = temp->next;
            }else{
                return false;
            }   
        }
        return true;
        
    }

    void kill(std::string s = "")
    {
        std::cout << s;
        Node *temp = HEAD;

        for (size_t i = 0; i < size; i++)
        {
            temp = temp->next;
        }
        delete HEAD;
    }
    


    

    // TODO reverse
};



