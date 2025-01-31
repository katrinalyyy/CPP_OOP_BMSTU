#pragma once
// Файл MyStack.h
// Шаблонный класс MyStack на основе односвязного списка.
#ifndef MyStack_h           // защита от повторной компиляции
#define MyStack_h           // модуль подключен

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode              // узел списка
{
private:
    INF d;                  // информационная часть узла
    ListNode* next;         // указатель на следующий узел списка
    ListNode(void) :d{} { next = nullptr; } //конструктор
    friend FRIEND;
};

// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node* top;
public:
    MyStack(void);           // конструктор
    MyStack(const MyStack& other);
    ~MyStack(void);          // освободить динамическую память
    bool empty(void);        // стек пустой?
    bool push(INF n);        // добавить узел в вершину стека
    bool pop(void);          // удалить узел из вершины стека
    INF top_inf(void);      // считать информацию из вершины стека
    void Clear();
    MyStack& operator = (const MyStack& other);

};

template<class INF>
MyStack<INF>::MyStack(void) {
    top = nullptr;
}

template<class INF>
MyStack<INF>::~MyStack(void) {
    while (!empty()) {
        pop();
    }
}

template<class INF>
bool MyStack<INF>::empty(void) {
    return top == nullptr;
}

template<class INF>
bool MyStack<INF>::push(INF n) {
    Node* temp = new Node;
    if (temp == nullptr) {
        return false; 
    }
    temp->d = n;
    temp->next = top;
    top = temp;
    return true;
}

template<class INF>
bool MyStack<INF>::pop(void) {
    if (empty()) {
        return false; 
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    return true;
}

template<class INF>
void MyStack<INF>::Clear() {
    while (pop());
}

template<class INF>
INF MyStack<INF>::top_inf(void) {
    if (empty()) {
        throw "Stack is empty";
    }
    return top->d;
}

template class MyStack<int>;

template <class INF>
MyStack<INF>::MyStack(const MyStack& other) {
    if (other.top) {
        top = new Node(*other.top);
        Node* current = top;
        Node* otherCurrent = other.top->next;
        while (otherCurrent) {
            current->next = new Node(*otherCurrent);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
}

template<class INF>
MyStack<INF>& MyStack<INF>::operator = (const MyStack& other) {
    if (this != &other) {
        Clear();
        if (other.top) {
            top = new Node(*other.top);
            Node* current = top;
            Node* otherCurrent = other.top->next;
            while (otherCurrent) {
                current->next = new Node(*otherCurrent);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }
    return *this;
}

#endif
