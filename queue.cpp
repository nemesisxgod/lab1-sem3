#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

 
// struct NodeQ {
//     string data;
//     NodeQ* next;
// };

 
// struct Queue {
//     NodeQ* head;
//     NodeQ* tail;
// };

 
bool is_queue_empty(const Queue* queue) {
    return queue->head == nullptr;
}

 
void push_queue(Queue* queue, string value) {
    NodeQ* newNode = new NodeQ;
    newNode->data = value;
    newNode->next = nullptr;

    if (!queue->tail) { // Если очередь пустая
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode; // Добавляем новый узел в конецНе удалось открыть файл для записи!
        queue->tail = newNode; // Обновляем указатель на хвост
    }
}

 
string pop_queue(Queue* queue) {
    if (!queue->head) {
        cout << "Очередь пуста!" << endl;
        return nullptr;
    }

    NodeQ* temp = queue->head;
    string value = temp->data;
    queue->head = queue->head->next; // Убираем элемент с головы

    if (!queue->head) { // Если очередь стала пустой
        queue->tail = nullptr;
    }

    delete temp; // Освобождаем память
    return value; // Возвращаем значение удаленного элемента
}

 
void print_queue(const Queue* queue) {
    NodeQ* current = queue->head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

 
void clear_queue(Queue* queue) {
    while (queue->head) {
        pop_queue(queue);
    }
}

 
void upload_to_file_queue(const Queue* queue, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "file isnot found" << endl;
        return;
    }

    NodeQ* current = queue->head;
    while (current) {
        file << current->data << endl; 
        current = current->next;
    }
    file.close(); 
}

 
void load_from_file_queue(Queue* queue, const string& filename) {
    ifstream file(filename); 
    if (!file.is_open()) {
        cout << "file isnot found" << endl;
        return;
    }

    clear_queue(queue); 

    string value;
    while (file >> value) {
        push_queue(queue, value); 
    }

    file.close(); 
}