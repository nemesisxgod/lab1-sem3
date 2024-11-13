#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "header.h"

using namespace std;

// struct NodeQT {
//     treeNode* data; // Теперь хранится указатель на узел дерева
//     NodeQT* next;
// };

// // Структура для очереди, работающая с treeNode*
// struct QueueT {
//     NodeQT* head;
//     NodeQT* tail;
// };

bool is_queueT_empty(const QueueT& queue) {
    return queue.head == nullptr;
}

 
void push_queueT(QueueT& queue, treeNode* value) {
    NodeQT* newNode = new NodeQT;
    newNode->data = value;
    newNode->next = nullptr;

    if (!queue.tail) { // Если очередь пустая
        queue.head = newNode;
        queue.tail = newNode;
    } else {
        queue.tail->next = newNode; // Добавляем новый узел в конецНе удалось открыть файл для записи!
        queue.tail = newNode; // Обновляем указатель на хвост
    }
}

//  struct treeNode {
//     int value;
//     treeNode* left;
//     treeNode* right;

//     treeNode(int val) : value(val), left(nullptr), right(nullptr) {}
// };

treeNode* pop_queueT(QueueT& queue) {
    if (!queue.head) {
        cout << "Очередь пуста!" << endl;
        return nullptr;
    }

    NodeQT* temp = queue.head;
    treeNode* value = temp->data;
    queue.head = queue.head->next; // Убираем элемент с головы

    if (!queue.head) { // Если очередь стала пустой
        queue.tail = nullptr;
    }

    delete temp; // Освобождаем память
    return value; // Возвращаем значение удаленного элемента
}

int count_of_nodes_tree(treeNode* root) {
    if (root == nullptr)
        return 0;
    return 1 + count_of_nodes_tree(root->left) + count_of_nodes_tree(root->right);
}

// Функция для определения высоты дерева
int height_tree(treeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(height_tree(node->left), height_tree(node->right)) + 1;
}

// заполнен ли последний уровень
bool is_complete(treeNode*& root) {
    if (!root) return true;

    QueueT queue;
    push_queueT(queue, root);
    bool mustBeLeaf = false; // Флаг, который указывает, что все следующие узлы должны быть листьями

    while (!is_queueT_empty(queue)) {
        treeNode* current = pop_queueT(queue);

        // Проверяем левый узел
        if (current->left) {
            if (mustBeLeaf) return false; // Если флаг выставлен, но узел имеет потомков
            push_queueT(queue, current->left);
        } else {
            mustBeLeaf = true; // Если нет левого ребенка, выставляем флаг
        }

        // Проверяем правый узел
        if (current->right) {
            if (mustBeLeaf) return false; // Если флаг выставлен, но узел имеет потомков
            push_queueT(queue, current->right);
        } else {
            mustBeLeaf = true;
        }
    }
    return true;
}



bool is_full_tree (treeNode*& root) {
    int height = height_tree(root);
    int countIfComplete = pow(2, height) - 1;
    return count_of_nodes_tree(root) == countIfComplete;
}

void push_tree(treeNode*& root, int value) {
    if (root == nullptr) { // Если дерево пустое, создаем корень
        root = new treeNode(value);
        return;
    }

    QueueT nodeQueue = {nullptr, nullptr}; // Инициализация очереди для обхода дерева по уровням
    push_queueT(nodeQueue, root);

    while (!is_queueT_empty(nodeQueue)) {
        treeNode* current = pop_queueT(nodeQueue);

        // Проверка левого узла
        if (current->left == nullptr) {
            current->left = new treeNode(value); // Вставляем значение в левый узел
            return;
        } else {
            push_queueT(nodeQueue, current->left); // Добавляем левый узел в очередь для проверки
        }

        // Проверка правого узла
        if (current->right == nullptr) {
            current->right = new treeNode(value); // Вставляем значение в правый узел
            return;
        } else {
            push_queueT(nodeQueue, current->right); // Добавляем правый узел в очередь для проверки
        }
    }
}

void print_lvl(treeNode* root, int level) {
    if (root == nullptr) {
        return;
    }
    
    int width = pow(2, height_tree(root)) - 1;
    int spacesCnt = width / 2;
    string spacesBefore(spacesCnt, ' ');
    string spacesAfter(spacesCnt + 1, ' ');
    
    
    if (level == 1) {
        cout << spacesBefore << root->value << spacesAfter; // Вывод значения узла
    } else {
        print_lvl(root->left, level - 1);  // Обход левого поддерева
        print_lvl(root->right, level - 1); // Обход правого поддерева
    }
}


 
// Функция для вывода дерева в виде "змейки"
void print_tree(treeNode* root) {
    int height = height_tree(root); // Определяем высоту дерева

    for (int i = 1; i <= height; i++) {
        print_lvl(root, i); // Выводим узлы на текущем уровне
        cout << endl; // Переход на новую строку после каждого уровня
    }
}

// Поиск элемента в дереве
bool search_tree(treeNode* node, int val) {
    if (node == nullptr) {
        return false;
    }
    if (node->value == val) {
        return true;
    }
    return search_tree(node->left, val) or search_tree(node->right, val); 
}

// Функция для очистки дерева и освобождения памяти
void clear_tree(treeNode*& root) {
    if (root == nullptr) return;

    clear_tree(root->left);
    clear_tree(root->right);

    delete root;
    root = nullptr; 
}

void load_from_file_tree(treeNode*& root, const string& file) {
    clear_tree(root);
    ifstream load(file);
    if (!load.is_open()) {
        cout << "Failed to open file.\n";
        return;
    }

    int value;
    while (load >> value) {
        push_tree(root, value);
    }
    load.close();
}

void upload_to_file_tree(treeNode* root, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "file is not found" << endl;
        return;
    }

    if (!root) {
        file << "tree is empty" << endl;
    } else {
        QueueT queue = {nullptr, nullptr};
        push_queueT(queue, root);

        // Обход дерева по уровням и запись значений в файл
        while (!is_queueT_empty(queue)) {
            treeNode* current = pop_queueT(queue);
            file << current->value << endl; // Запись каждого значения на новой строке

            // Добавляем потомков текущего узла в очередь
            if (current->left != nullptr) {
                push_queueT(queue, current->left);
            }
            if (current->right != nullptr) {
                push_queueT(queue, current->right);
            }
        }
    }
    file.close();
}