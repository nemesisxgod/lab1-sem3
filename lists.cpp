#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

//  
// struct NodeL{
//     string data;
//     NodeL* next;
// };

 
void add_to_head_list(NodeL*& head, string value) {
    NodeL* newNode = new NodeL;
    newNode->data = value; 
    newNode->next = head;              
    head = newNode;                    
}

 
void add_to_tail_list(NodeL*& head, string value) {
    NodeL* newNode = new NodeL;  
    newNode->data = value;
    if (!head) {                       // eсли список пуст
        head = newNode;
        return;
    }
    NodeL* current = head;
    while (current->next) {            // идем до последнего узла
        current = current->next;
    }
    current->next = newNode;          
}

 
void remove_from_head_list(NodeL*& head){
    if (!head){
        return;
    }
    NodeL* temp = head;
    head = head->next;
    delete temp;
}

 
void remove_from_tail_list(NodeL*& head){
    if (!head){
        return;
    }

    if (!head->next){
        delete head;
        head = nullptr;
        return;
    }

    NodeL* current = head;
    while(current->next){
        current = current->next;
    }
    
    current->next = nullptr;
    delete current;
}

 
void remove_by_value_list(NodeL*& head, const string& value){
    if (!head) {
        return;  // Если список пуст, ничего не делаем
    }

    // Если элемент для удаления — это первый элемент списка
    if (head->data == value) {
        remove_from_head_list(head);
        return;
    }

    NodeL* current = head;
    
    // Ищем элемент с заданным значением
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    // Если элемент найден (current->next не равен nullptr)
    if (current->next) {
        NodeL* temp = current->next;  // Элемент, который нужно удалить
        current->next = current->next->next;  // Переназначаем указатель
        delete temp;  // Удаляем элемент
    }
}

 
NodeL* search_list(NodeL*& head, const string& value, int& index) {
    NodeL* current = head;
    index = 0;  // Начальный индекс
    
    while (current) {
        if (current->data == value) {
            return current;  // Возвращаем найденный элемент
        }
        current = current->next;
        index++;  // Увеличиваем индекс, двигаясь по списку
    }
    return nullptr;  // Если не нашли элемент, возвращаем nullptr
}

 
void print_list(NodeL* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

 
void free_list(NodeL* head) {
    while (head) {
        remove_from_head_list(head);
    }
}

 
void load_from_file_list(NodeL*& head, const string& filename){
    free_list(head);
    ifstream file(filename); 
    if (!file.is_open()){ 
        cout<<"file isnot found" << endl;
        return;
    }

    string stroka;
    while(getline(file, stroka)){
        add_to_tail_list(head, stroka);    
    }

    file.close();
}

void upload_to_file_list(NodeL* head, const string& filename){
    ofstream file(filename);
    if (!file.is_open()) {
            cout << "File not found" << endl;
            return;
        }

    NodeL* current = head;
    while (current) {
        file << current->data << endl;
        current = current->next;
    }

    file.close();
}

 
// struct NodeD{
//     string data;
//     NodeD* next;
//     NodeD* prev;
// };

 
void add_to_head_doublylist(NodeD*& head, NodeD*& tail, const string& value) {
    NodeD* newNode = new NodeD;
    newNode->data = value; 
    newNode->next = head;  
    newNode->prev = nullptr;             
    if (head) {
        head->prev = newNode;
    }
    else{
        tail = newNode;
    }
    head = newNode;                  
}

 
void add_to_tail_doublylist(NodeD*& head, NodeD*& tail, const string& value) {
    NodeD* newNode = new NodeD;  
    newNode->data = value;
    newNode->next = nullptr; 
    if (!head) {  
        newNode->prev = nullptr;                 
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }          
}

 
void remove_from_head_doublylist(NodeD*& head, NodeD*& tail){
    if (!head){
        return;
    }
    NodeD* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else{
        tail = nullptr;
    }
    delete temp;
}

 
void remove_from_tail_doublylist(NodeD*& head, NodeD*& tail){
    if (!tail){
        return;
    }

    if (head==tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    NodeD* temp = tail;
    tail=tail->prev;
    tail->next=nullptr;

    delete temp;
}

 
void remove_by_value_doublylist(NodeD*& head, NodeD*& tail, const string& value) {
    if (!head) {
        return;  // Если список пуст, ничего не делаем
    }

    // Если удаляем первый элемент
    if (head->data == value) {
        remove_from_head_doublylist(head, tail);
        return;
    }

    NodeD* current = head;

    // Ищем элемент с данным значением
    while (current && current->data != value) {
        current = current->next;
    }

    // Если элемент найден
    if (current) {
        // Если элемент - последний
        if (!current->next) {
            remove_from_tail_doublylist(head, tail);
        } else {  // Если элемент в середине списка
            tail = current->prev;  // Обновляем указатель следующего элемента
        }
        if (current->prev){
            current->prev->next = current->next;
        }
            delete current;  // Удаляем текущий элемент
        }
    }


 
NodeD* search_doublylist(NodeD* head, NodeD* tail, const string& value,int& index) {
    NodeD* current = head;
    index = 0;  // Начальный индекс
    
    while (current) {
        if (current->data == value) {
            return current;  // Возвращаем найденный элемент
        }
        current = current->next;
        index++;  // Увеличиваем индекс, двигаясь по списку
    }
    return nullptr;
}

 
void print_doublylist(NodeD* head, NodeD* tail) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

 
void free_doublylist(NodeD*& head, NodeD*& tail) {
    while (head) {
        remove_from_head_doublylist(head, tail);
    }
}

 
void load_from_file_doublylist(NodeD*& head, NodeD*& tail, const string& filename){
    free_doublylist(head, tail);
    ifstream file(filename); 
    if (!file.is_open()){ 
        cout<<"file isnot found" << endl;
        return;
    }

    string stroka;
    while(getline(file, stroka)){
        add_to_tail_doublylist(head, tail, stroka);    
    }

    file.close();
}

 
void upload_to_file_doublylist(NodeD* head, NodeD* tail, const string& filename){
    ofstream file(filename);
    if (!file.is_open()) {
            cout << "File not found" << endl;
            return;
        }

    NodeD* current = head;
    while (current) {
        file << current->data << endl;
        current = current->next;
    }

    file.close();
}