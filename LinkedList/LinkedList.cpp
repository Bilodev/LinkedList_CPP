#include <iostream>

class LinkedList{
    private:

        struct Node{
            int data;
            Node* next;

            Node(int data, Node* p){
                this->data = data;
                this->next = nullptr;
            }
        };


        Node* HEAD = nullptr;
        size_t size = 0;

    public:
        LinkedList(){}

        //costruttore con val iniziali
        LinkedList(std::initializer_list<int> lists){
            Node* temp = HEAD;
            
            for (auto element:lists){
                push(element);
            }
        }


        void display()
        {
            Node* temp = HEAD;
            int i = 0;
            while (temp->next != nullptr) 
            {
                std::cout << "[" << i << "]: " << temp->data << '\n';
                temp = temp->next;  //dereference of the pointer to the struct
                i++;

            }
            std::cout << "[" << i << "]: " << temp->data << '\n';
        }

        
        bool is_accessible(int index, bool msg = true){
            if(index > size){
                if(msg == true) 
                    std::cout << "Index " << index << " Not Accessible" << '\n';
                return false;
            }
        }


        //PUSH AN ELEMENT INTO THE LIST
        void push(int data)
        {
            Node* newNode = new Node(data,nullptr);

            if (!HEAD)
            {
                HEAD = newNode; 
                size++;
                return;
            }

            Node* temp = HEAD;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;


            size++;
        }
        
        //ADD AN ELEMENT AT THE FIRST INDEX AND SHIFT ALL THE OTHERS
        void add(int data){
            Node* temp = HEAD;
            Node* newNode = new Node(data,nullptr);
            HEAD = newNode;
            newNode->next = temp;
            size++;
        }

        //POP THE LAST ELEMENT
        void pop(){
            Node* temp = HEAD;
            Node* temp1;
            while (temp->next != nullptr)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = nullptr;
            delete[] temp;
            size--;
        }

        //REMOVE THE ELEMENT AT THE FIRST INDEX
        void remove(){
            Node* temp = HEAD;
            HEAD = temp->next;
            delete[] temp;
            size--;
        }


        //ADD AN ELEMENT AT THE INDEX  POSITION AND SHIFT ALL THE OTHERS
        void insert(int data,int index){
            
            if(index > size){ is_accessible(index) ;return;}
            
            else if(index == 0){
                add(data);
                size++;
                return;
            }
            else if(index == size){
                push(data);
                size++;
                return;
            }

            Node* temp = HEAD;
            Node* temp1;

            for (size_t i = 0; i < index-1; i++)
            {
                temp = temp->next;
            }
            

            temp1 = temp->next;
            Node* newNode = new Node(data,nullptr);
            temp->next = newNode;
            newNode->next = temp1;
            size++;
        }


        //RETURN THE ELEMENT AT THE INDEX
        int get(int index){
            if(!is_accessible(index)){
                return NULL;
            }
            
            Node* temp = HEAD;
            for (size_t i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }


        
        //Substitutes the element at the index passed as an argument (index) with the new data (data)
        void set(int data, int index){
            if(!is_accessible(index)){
                return;
            }
            
            Node* temp = HEAD;
            
            for (size_t i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->data = data;
        }


        size_t length(){
            return size;
        }

        void kill(std::string s = ""){
            std::cout << s ;
            Node* temp = HEAD;
            
            for (size_t i = 0; i < size; i++)
            {
                temp = temp->next;
            }
            delete[] HEAD;
        }

        int operator[](int index)
        {          
            Node* temp = HEAD;
            for (size_t i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp->data;
        }

        



};


