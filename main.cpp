#include <iostream>
#include <fstream>
#include <iomanip>
#include "header.h"
#include <sstream>
#include <vector>

using namespace std;

void processQuery(const string& query, DynamicArray& array, Stack* stack, Queue& queue, NodeL*& singlyList, NodeD*& doublyList, NodeH** hashTable, treeNode*& tree) {
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
            initial_array(array, 2);
            push_back_array(array, value);
        } else {
            cout << "Error: APUSHBACK command requires 1 arguments." << endl;
        }
    }
    else if (tokens[0] == "APUSHIN") {
        if (tokens.size() == 3) {
            int index = stoi(tokens[1]);
            string value = tokens[2];
            initial_array(array, 2);
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
            search_list(singlyList, value);
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
            add_to_head_doublylist(doublyList, value);
        } else {
            cout << "Error: LDADDHEAD requires 1 argument." << endl;
        }
    } else if (tokens[0] == "LDADDTAIL") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            add_to_tail_doublylist(doublyList, value);
        } else {
            cout << "Error: LDADDTAIL requires 1 argument." << endl;
        }
    }else if (tokens[0] == "LDSEARCH") {
        if (tokens.size() == 2) {
            string value = tokens[1];
            search_doublylist(doublyList, value);
        } else {
            cout << "Error: LDSEARCH requires 1 argument." << endl;
        }
    } else if (tokens[0] == "LDDELHEAD") {
        remove_from_head_doublylist(doublyList);
    } else if (tokens[0] == "LDDELTAIL") {
        remove_from_tail_doublylist(doublyList);
    } else if (tokens[0] == "LDDELVALUE"){
        if  (tokens.size() == 2) {
            string value = tokens[1];
            remove_by_value_doublylist(doublyList, value);
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
        print_pre_order(tree);
    }

    // Общая операция PRINT для всех структур данных
    else if (tokens[0] == "PRINT") {
        print_array(array);
        print_stack(stack);
        print_queue(queue);
        print_list(singlyList);
        print_doublylist(doublyList);
        print_hash(hashTable);
    } else {
        cout << "Unknown command: " << tokens[0] << endl;
    }
}

int main(int argc, char* argv[]){
    string query;
    string filename;
    ofstream file(filename);
    DynamicArray arr;
    initial_array(arr, 10); // Массив
    Stack* stack;       // Стек
    Queue queue;       // Очередь
    NodeL* head;   // Односвязный список
    NodeD* dhead;   // Двусвязный список
    NodeH** hashTable; // Хэш-таблица
    treeNode* cbTree;          

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
            load_from_file_doublylist(dhead, filename);
        }
        // Проверка команд для хэш-таблицы
        else if (command[0] == 'H') {
            load_from_file_hash(hashTable, filename);
        }
        // Проверка команд для полного бинарного дерева
        else if (command[0] == 'T') {
            upload_node_tree(cbTree, file, 0);
        }
        else if (command == "PRINT") {
            std::ifstream file(filename);
            if (!file.is_open()) {
            std::cerr << "Error: could not open file " << filename << std::endl;
            return 1;}
            std::string line;
            while (std::getline(file, line)) {
            std::cout << line << std::endl;}
            file.close(); // Закрытие файла
        } else {
            cout << "Error: unrecognized command type." << endl;
            return 1;
        }
    }
}
