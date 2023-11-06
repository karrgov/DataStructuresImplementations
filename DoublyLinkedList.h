#include <iostream>
#pragma once 

template <typename T>
class DoublyLinkedList
{
    private:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
        Node(T value) : data(value), previous(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;

    public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() 
    {
        for(int i = 0; i < length(); i++)
        {
            pop_front();
        }
    }

    void push_front(T value)
    {
        if(head == nullptr)
        {
            head = new Node(value);
            tail = head;
        }
        else 
        {
            Node* node = new Node(value);
            head->previous = node;
            node->next = head;
            head = node;
        }
    }

    void push_back(T value)
    {
        if(tail == nullptr)
        {
            tail = new Node(value);
            head = tail;
        }
        else 
        {
            Node* node = new Node(value);
            tail->next = node;
            node->previous = tail;
            tail = node;
        }
    }

    void pop_front()
    {
        if(head == nullptr)
        {
            return;
        }
        else if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = head->next;
            delete head;
            head = temp;
            head->previous = nullptr;
        }
    }

    void pop_back()
    {
        if(head == nullptr)
        {
            return;
        }
        else if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else 
        {
            Node* temp = tail->previous;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }

    int length()
    {
        int counter = 0;
        if(head == nullptr)
        {
            return counter;
        }
        else
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                counter++;
                temp = temp->next;
            }
            return counter;
        }
    }

    void print()
    {
        if(head == nullptr)
        {
            std::cout << "Empty doubly linked list" << std::endl;
        }
        else 
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                if(temp->next != nullptr)
                {
                    std::cout << temp->data << " <=> ";
                }
                else 
                {
                    std::cout << temp->data;
                }
                temp = temp->next;
            }
        }
    }

    Node* get_head()
    {
        return head;
    }

    Node* get_tail()
    {
        return tail;
    }





    
};

