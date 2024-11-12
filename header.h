#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;
//_____________________________________________________________________________________
 
struct DynamicArray{
    string* data = nullptr; 
    size_t size = 0;
    size_t capacity = 1;
};

 
void increase_array(DynamicArray& array);

 
void push_back_array(DynamicArray& array, const  string& value);

 
void push_in_array(DynamicArray& array, const string& value, const int index);

 
void pop_back_array(DynamicArray& array);

 
void pop_at_array(DynamicArray& array, const int index);

 
void search_array(DynamicArray& array, const string& value);

 
void search_by_index_array(DynamicArray& array, const int index); 

 
void set_array (DynamicArray& array, const string& value, const int index);

 
void print_array (DynamicArray& array);

 
void free_array(DynamicArray& array);

 
void load_from_file_array(DynamicArray& array, const string& filename);

 
void upload_to_file_array(DynamicArray& array, const string& filename);

//_____________________________________________________________________________________

 
struct NodeH {
    string key;
    string value;
    NodeH* next;
};

 
int hash_function(const string& key);

 
void push_hash(NodeH* table[], const string& key, const string& value);

 
int search_hash(NodeH* table[], const string& value);

 
void pop_hash(NodeH* table[], const string& key);

 
void print_hash(NodeH* table[]);

 
void clear_hash(NodeH* table[]);

 
void load_from_file_hash(NodeH* table[], const string& filename);

 
void upload_to_file_hash(NodeH* table[], const string& filename);

//_____________________________________________________________________________________

 
struct NodeL{
    string data;
    NodeL* next;
};

 
void add_to_head_list(NodeL*& head, string value);

 
void add_to_tail_list(NodeL*& head, string value);

 
void remove_from_head_list(NodeL*& head);

 
void remove_from_tail_list(NodeL*& head);

 
void remove_by_value_list(NodeL*& head, const string& value);

 
NodeL* search_list(NodeL*& head, const string& value, int& index);

 
void print_list(NodeL* head);

 
void free_list(NodeL* head);

 
void load_from_file_list(NodeL*& head, const string& filename);

 
void upload_to_file_list(NodeL* head, const string& filename);

 
struct NodeD{
    string data;
    NodeD* next;
    NodeD* prev;
};

 
void add_to_head_doublylist(NodeD*& head, const string& value);

 
void add_to_tail_doublylist(NodeD*& head, const string& value);

 
void remove_from_head_doublylist(NodeD*& head);
 
void remove_from_tail_doublylist(NodeD*& head);

 
void remove_by_value_doublylist(NodeD*& head, const string& value);

 
NodeD* search_doublylist(NodeD*& head, const string& value, int& index);

 
void print_doublylist(NodeD* head);

 
void free_doublylist(NodeD*& head);

 
void load_from_file_doublylist(NodeD*& head, const string& filename);

 
void upload_to_file_doublylist(NodeD* head, const string& filename);

//_____________________________________________________________________________________

 
struct NodeQ {
    string data;
    NodeQ* next;
};

 
struct Queue {
    NodeQ* head;
    NodeQ* tail;
};

 
bool is_queue_empty(const Queue* queue);

 
void push_queue(Queue* queue, string value);

 
string pop_queue(Queue* queue);

 
void print_queue(const Queue* queue);

 
void clear_queue(Queue* queue);

 
void upload_to_file_queue(const Queue* queue, const string& filename);

 
void load_from_file_queue(Queue* queue, const string& filename);

//_____________________________________________________________________________________

 
struct NodeS {
    string data;
    NodeS* next = nullptr;
};

 
struct Stack {
    NodeS* head = nullptr; 
};

 
void push_stack(Stack* stack, const string& data);

 
void pop_stack(Stack* stack);

 
void print_stack(Stack* stack);

 
void free_stack(Stack* stack);

 
void load_from_file_stack(Stack* stack, const string& filename);

 
void upload_to_file_stack(Stack* stack, const string& filename);

//_____________________________________________________________________________________

struct treeNode {
    int value;
    treeNode* left;
    treeNode* right;

    treeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

struct NodeQT {
    treeNode* data; // Теперь хранится указатель на узел дерева
    NodeQT* next;
};

struct QueueT {
    NodeQT* head;
    NodeQT* tail;
};

treeNode* pop_queueT(QueueT& queue);

bool is_queueT_empty(const QueueT& queue);

void push_queueT(QueueT& queue, treeNode* value);

int count_of_nodes_tree(treeNode* root);

int height_tree(treeNode* node);

bool is_complete (treeNode*& root);

bool is_full_tree (treeNode*& root);

void push_tree(treeNode*& root, int value);

void print_pre_order(treeNode* node);

bool search_tree(treeNode* node, int val);

void clear_tree(treeNode*& root);

void load_from_file_tree(treeNode*& root, const string& file);

void upload_node_tree(treeNode* node, ofstream& file, int len);

void upload_to_file_tree(treeNode* root, const string& filename);

#endif