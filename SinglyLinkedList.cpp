#include <iostream>
#pragma once 

template <class T>
class SinglyLinkedList
{
    private: 
    struct Node 
    {
        T data;
        Node* next;

        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    Node* tail;

    void deallocate()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            Node* toBeDeleted = temp;
            temp = temp->next;
            delete toBeDeleted;
        }
        this->head = this->tail = nullptr;
    }

    void copy(const SinglyLinkedList<T>& other)
    {
        if(other.head == nullptr)
        {
            this->head = this->tail = nullptr;
            return;
        }

        this->head = new Node(other.head->data);
        Node* temp = this->head;
        Node* tempOther = other.head;
        while(tempOther->next != other.tail)
        {
            temp->next = new Node(tempOther->next->data);
            temp = temp->next;
            tempOther = tempOther->next;
        }
        this->tail = new Node(other.tail->data);
        temp->next = this->tail;
    }

    public: 
    SinglyLinkedList<T>() : head(nullptr), tail(nullptr) {}

    SinglyLinkedList<T>& operator = (const SinglyLinkedList<T>& other)
    {
        if(this != &other)
        {
            this->deallocate();
            this->copy(other);
        }
        return *this;
    }

    SinglyLinkedList<T>(const SinglyLinkedList<T>& other)
    {
        this->copy(other);
    }

    ~SinglyLinkedList<T>()
    {
        this->deallocate();
    }

    SinglyLinkedList<T>(std::size_t count, const T& data = T()) : head(nullptr), tail(nullptr)
    {
        for(std::size_t i = 0; i < count; ++i)
        {
            this->push_back(data);
        }
    }

    std::size_t size() const
    {
        if(head == nullptr)
        {
            return 0;
        }

        std::size_t result = 1;
        Node* temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
            ++result;
        }
        return result;
    }

    T& front()
    {
        return this->head->data;
    }

    const T& front() const
    {
        return this->head->data;
    }

    T& back()
    {
        return this->tail->data;
    }

    const T& back() const 
    {
        return this->tail->data;
    }

    void clear()
    {
        this->deallocate();
    }

    bool isEmpty() const
    {
        return this->head == nullptr;
    }

    void print() const 
    {
        Node* temp = this->head;
        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push_back(const T& data)
    {
        if(this->head == nullptr)
        {
            this->head = new Node(data);
            this->tail = this->head;
        }
        else 
        {
            this->tail->next = new Node(data);
            this->tail = this->tail->next;
        }
    }

    





};