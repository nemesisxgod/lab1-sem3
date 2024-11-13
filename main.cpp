#include <iostream>
#include <fstream>
#include <iomanip>
#include "header.h"
#include <sstream>
#include <vector>

using namespace std;

void processQuery(const string& query, DynamicArray& array, Stack* stack, Queue* queue, NodeL*& singlyList, NodeD*& doublyListH,NodeD*& doublyListT, NodeH** hashTable, treeNode*& tree) {
    vector<string> tokens;
    stringstream ss(query);
    string token;

    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    // Массив (Array)
    if (tokens[0] == "APUSHBACK") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            push_back_array(array, value);
        } else {
            cout << "Error: APUSHBACK command requires 1 arguments." << endl;
        }
    }
    else if (tokens[0] == "APUSHIN") {
        if (tokens.size() == 3) {
            int index = stoi(tokens[1]);
            string value = tokens[2];
            push_in_array(array, value, index);
        } else {
            cout << "Error: APUSHIN command requires 2 arguments." << endl;
        }
    } else if (tokens[0] == "APOPBACK") {
        if (tokens.size() == 1) {
            pop_back_array(array);
        } else {
            cout << "Error: APOPBACK command requires no argument." << endl;
        }
    } else if (tokens[0] == "APOPAT") {
        if (tokens.size() == 2) {
            int index = stoi(tokens[1]);
            pop_at_array(array, index);
        } else {
            cout << "Error: APOPAT command requires 1 argument." << endl;
        }
    } else if (tokens[0] == "ASEARCH") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            search_array(array, value);
        } else{
             cout << "Error: ASEARCH command requires 1 argument." << endl;
        }
    } else if (tokens[0] == "ASEARCHBYINDEX") {
        if (tokens.size() == 2) {
            int index = stoi(tokens[1]);
            search_by_index_array(array, index);
        } else {
            cout << "Error: ASEARCHBYINDEX command requires 1 arguments." << endl;
        }
    }
    else if (tokens[0] == "ASET") {
        if (tokens.size() == 3) {
            int index = stoi(tokens[1]);
            string value = tokens[2];
            set_array(array, value, index);
        } else {
            cout << "Error: ASET command requires 2 arguments." << endl;
        }
    }

    // Стек (Stack)
    else if (tokens[0] == "SPUSH") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            push_stack(stack, value);
        } else {
            cout << "Error: SPUSH command requires 1 argument." << endl;
        }
    } else if (tokens[0] == "SPOP") {
        pop_stack(stack);
    }

    // Очередь (Queue)
    else if (tokens[0] == "QPUSH") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            push_queue(queue, value);
        } else {
            cout << "Error: QPUSH command requires 1 argument." << endl;
        }
    } else if (tokens[0] == "QPOP") {
        pop_queue(queue);
    }

    // Односвязный список (Singly Linked List)
    else if (tokens[0] == "LSADDHEAD") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            add_to_head_list(singlyList, value);
        } else {
            cout << "Error: LSADDHEAD requires 1 argument." << endl;
        }
    } else if (tokens[0] == "LSADDTAIL") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            add_to_tail_list(singlyList, value);
        } else {
            cout << "Error: LSADDTAIL requires 1 argument." << endl;
        }
    } else if (tokens[0] == "LSSEARCH") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            int index=0;
            if (search_list(singlyList, value, index)!=nullptr){
                cout<<"index is "<<index << endl;
            }
        } else {
            cout << "Error: LSSEARCH requires 1 argument." << endl;
        }
    } else if (tokens[0] == "LSDELHEAD") {
        remove_from_head_list(singlyList);
    } else if (tokens[0] == "LSDELTAIL") {
        remove_from_tail_list(singlyList);
    } else if (tokens[0] == "LSDELVALUE"){
        if  (tokens.size() == 2) {
            string value = tokens[1];
            remove_by_value_list(singlyList, value);
        } else {
            cout << "Error: LSDELVALUE requires 1 argument." << endl;
        }
    }

    // Двусвязный список (Doubly Linked List)
   else if (tokens[0] == "LDADDHEAD") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            add_to_head_doublylist(doublyListH, doublyListT, value);
        } else {
            cout << "Error: LDADDHEAD requires 1 argument." << endl;
        }
    } else if (tokens[0] == "LDADDTAIL") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            add_to_tail_doublylist(doublyListH, doublyListT, value);
        } else {
            cout << "Error: LDADDTAIL requires 1 argument." << endl;
        }
    }else if (tokens[0] == "LDSEARCH") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            int index=0;
            if (search_doublylist(doublyListH, doublyListT, value, index)!=nullptr){
                cout<<"index is "<<index << endl;
            }
        } else {
            cout << "Error: LDSEARCH requires 1 argument." << endl;
        }
    } else if (tokens[0] == "LDDELHEAD") {
        remove_from_head_doublylist(doublyListH, doublyListT);
    } else if (tokens[0] == "LDDELTAIL") {
        remove_from_tail_doublylist(doublyListH, doublyListT);
    } else if (tokens[0] == "LDDELVALUE"){
        if  (tokens.size() == 2) {
            string value = tokens[1];
            remove_by_value_doublylist(doublyListH, doublyListT, value);
        } else {
            cout << "Error: LDDELVALUE requires 1 argument." << endl;
        }
    }
    // Хэш-таблица (HashTable)
    else if (tokens[0] == "HPUSH") {
        if (tokens.size() == 3) {
            string key = tokens[1];
            string value = tokens[2];
            push_hash(hashTable, key, value);
        } else {
            cout << "Error: HSET command requires 2 arguments." << endl;
        }
    } else if (tokens[0] == "HSEARCH") {
        if (tokens.size() == 2) {
            string key = tokens[1];
            search_hash(hashTable, key);
        }
    } else if (tokens[0] == "HDEL") {
        if (tokens.size() == 2) {
            string key = tokens[1];
            pop_hash(hashTable, key);
        } else {
            cout << "Error: HDEL command requires 1 argument." << endl;
        }
    }

    // Полное бинарное дерево (CBTree)
    else if (tokens[0] == "TPUSH") {
        if (tokens.size() == 2) {
            int digit = stoi(tokens[1]);
            push_tree(tree, digit);
        } else {
            cout << "Error: TPUSH command requires 1 argument." << endl;
        }
    } else if (tokens[0] == "TISCBT") {
        if (is_complete(tree)) {
            cout << "The tree is a complete binary tree." << endl;
        } else {
            cout << "The tree is not a complete binary tree." << endl;
        }
    } else if (tokens[0] == "TFIND") {
        if (tokens.size() == 2) {
            int value = stoi(tokens[1]);
            if (search_tree(tree, value)) {
                cout << "Value " << value << " found in the tree." << endl;
            } else {
                cout << "Value " << value << " not found in the tree." << endl;
            }
        } else {
            cout << "Error: CBFIND command requires 1 argument." << endl;
        }
    } else if (tokens[0] == "TDISPLAY") {
        print_tree(tree);
    }

    //Общая операция PRINT для всех структур данных
    else if (tokens[0] == "PRINT") {
        cout<<"The structure is deduced."<<endl;
    } else {
        cout << "Unknown command: " << tokens[0] << endl;
    }
}


int main(int argc, char* argv[]){
    string query;
    string filename;
    ofstream file(filename);

    // Инициализация структур данных
    DynamicArray arr; // Инициализация массива
    
    Stack* stack = new Stack();  // Инициализация указателя на стек
    Queue* queue = new Queue();             // Очередь
    NodeL* head = nullptr;   // Односвязный список
    NodeD* dhead = nullptr;  // Двусвязный список
    NodeD* dtail = nullptr; 
    // Выделение памяти для хэш-таблицы (например, на 10 элементов)
    NodeH** hashTable = new NodeH*[10];  

    treeNode* cbTree = nullptr;       

    // Чтение аргументов командной строки
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--file" && i + 1 < argc) {
            filename = argv[++i];
        }
        if (arg == "--query" && i + 1 < argc) {
            query = argv[++i];
        }
    }

    // Логика загрузки данных для конкретной структуры данных
    if (!filename.empty() && !query.empty()) {
        stringstream ss(query);
        string command;
        ss >> command;

        // Проверка команд для массива
        if (command[0] == 'A') {
            load_from_file_array(arr, filename);
        }
        // Проверка команд для стека
        else if (command[0] == 'S') {
            load_from_file_stack(stack, filename);
        }
        // Проверка команд для очереди
        else if (command[0] == 'Q') {
            load_from_file_queue(queue, filename);
        }
        // Проверка команд для односвязного списка
        else if (command[0] == 'L' && command[1] == 'S') {
            load_from_file_list(head, filename);
        }
        // Проверка команд для двусвязного списка
        else if (command[0] == 'L' && command[1] == 'D') {
            load_from_file_doublylist(dhead, dtail, filename);
        }
        // Проверка команд для хэш-таблицы
        else if (command[0] == 'H') {
            load_from_file_hash(hashTable, filename);
        }
        // Проверка команд для полного бинарного дерева
        else if (command[0] == 'T') {
            load_from_file_tree(cbTree, filename);
        }
        else if (command == "PRINT") {
            ifstream file(filename);
            if (!file.is_open()) {
            cerr << "Error: could not open file " << filename << std::endl;
            return 1;}
            string line;
            while (getline(file, line)) {
            cout << line << endl;}
            file.close(); // Закрытие файла
        } else {
            cout << "Error: unrecognized command type." << endl;
            return 1;
        }
    }

    if (!query.empty()) {
        processQuery(query, arr, stack, queue, head, dhead, dtail, hashTable, cbTree);
    } else {
        cout << "Error: query not specified." << endl;
        return 1;
    }

    // Логика сохранения данных для конкретной структуры данных
    if (!filename.empty() && !query.empty()) {
        stringstream ss(query);
        string command;
        ss >> command;

        // Проверка команд для массива
        if (command[0] == 'A') {
            upload_to_file_array(arr, filename);
        }
        // Проверка команд для стека
        else if (command[0] == 'S') {
            upload_to_file_stack(stack, filename);
        }
        // Проверка команд для очереди
        else if (command[0] == 'Q') {
            upload_to_file_queue(queue, filename);
        }
        // Проверка команд для односвязного списка
        else if (command[0] == 'L' && command[1] == 'S') {
            upload_to_file_list(head, filename);
        }
        // Проверка команд для двусвязного списка
        else if (command[0] == 'L' && command[1] == 'D') {
            upload_to_file_doublylist(dhead, dtail, filename);
        }
        // Проверка команд для хэш-таблицы
        else if (command[0] == 'H') {
            upload_to_file_hash(hashTable, filename);
        }
        // Проверка команд для полного бинарного дерева
        else if (command[0] == 'T') {
            upload_to_file_tree(cbTree, filename);
        }
    }

    return 0;
}
