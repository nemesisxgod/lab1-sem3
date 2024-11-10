#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;

const int TABLE_SIZE = 10; // Размер хэш-таблицы

// struct NodeH {
//     string key;
//     string value;
//     NodeH* next;
// };

 
int hash_function(const string& key) {
    size_t hash = 2566341;
        for (auto c : key) {
            hash += 31 *  c;
        }   
        return hash;
}

 
void push_hash(NodeH* table[], const string& key, const string& value) {
    int index = hash_function(key);
    NodeH* newNode = new NodeH;
    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;

    // Если индекс пуст, вставляем новый элемент
    if (table[index] == nullptr) {
        table[index] = newNode;
    } 
    else {
        // Если элемент уже существует, добавляем в цепочку
        NodeH* temp = table[index];
        while (temp->next != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        // Вставляем новый узел в конец цепочки
        temp->next = newNode;
    }
}

 
int search_hash(NodeH* table[], const string& key) {
    int index = hash_function(key);
    NodeH* temp = table[index];

    // Перебираем элементы цепочки
    while (temp != nullptr) {
        if (temp->key == key) {
            return stoi(temp->value);
        }
        temp = temp->next;
    }

    return -1; // Если ключ не найден
}

 
void pop_hash(NodeH* table[], const string& key) {
    int index = hash_function(key);
    NodeH* temp = table[index];
    NodeH* prev = nullptr;

    while (temp != nullptr) {
        if (temp->key == key) {
            // Если элемент найден, удаляем его
            if (prev == nullptr) {
                // Если удаляем первый элемент в цепочке
                table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Key not found!" << endl;
}

 
void print_hash(NodeH* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Table[" << i << "]: ";
        NodeH* temp = table[i];
        while (temp != nullptr) {
            cout << "{" << temp->key << ": " << temp->value << "} -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
}

 
void clear_hash(NodeH* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        NodeH* current = table[i];
        while (current) {
            NodeH* temp = current;
            current = current->next;
            delete temp; // Освобождаем память
        }
        table[i] = nullptr; // Обнуляем указатели
    }
}

 
void load_from_file_hash(NodeH* table[], const string& filename){
    ifstream file(filename); 
    if (!file.is_open()){ 
        cout<<"file isnot found" << endl;
        return;
    }

    clear_hash(table);

    string key, value;
    while (file >> key >> value) {
        push_hash(table, key, value);
    }

    file.close();
}

 
void upload_to_file_hash(NodeH* table[], const string& filename){
    ofstream file(filename);
    if (!file.is_open()) {
            cout << "File not found" << endl;
            return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        NodeH* current = table[i];
        while (current) {
            file << current->key << " " << current->value << endl;
            current = current->next;
        }
    }

    file.close();
}

