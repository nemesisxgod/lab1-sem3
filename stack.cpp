#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

 
// struct NodeS {
//     string data;
//     NodeS* next;
// };

 
// struct Stack {
//     NodeS* head = nullptr; 
// };

 
void push_stack(Stack* stack, const string& data) {
    NodeS* newNode = new NodeS{data, nullptr};
    newNode->next = stack->head;
    stack->head = newNode;
}

 
void pop_stack(Stack* stack) {
    if (stack->head == nullptr) {
        cout << "stack is empty" << endl;
        return;
    }

    NodeS* newHead = stack->head->next;
    delete stack->head;
    stack->head = newHead;
} 

 
void print_stack(Stack* stack) {
    if (stack->head == nullptr) {
        return;
    }

    NodeS* current = stack->head;
    
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

 
void free_stack(Stack* stack) {
    if (!stack) return;
    while (stack->head) {
        pop_stack(stack);
    }
}

 
void load_from_file_stack(Stack* stack, const string& filename){
    free_stack(stack);
    ifstream file(filename); 
    if (!file.is_open()){ 
        cout<<"file isnot found" << endl;
        return;
    }
    Stack tempStack;  // временный стек
    string stroka;

    // Загружаем элементы в временный стек
    while (getline(file, stroka)) {
        push_stack(&tempStack, stroka);
    }
    file.close();

    // Переносим элементы из временного стека в основной, чтобы сохранить исходный порядок
    while (tempStack.head != nullptr) {
        push_stack(stack, tempStack.head->data);
        pop_stack(&tempStack);
    }

    file.close();
}

 
void upload_to_file_stack(Stack* stack, const string& filename){
    ofstream file(filename);
    if (!file.is_open()) {
            cout << "File not found" << endl;
            return;
        }

    NodeS* current = stack->head;;
    while (current!=nullptr) {
        file << current->data << endl;
        current = current->next;
    }

    file.close();
}

