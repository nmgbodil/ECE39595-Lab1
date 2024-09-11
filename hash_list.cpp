#include "hash_list.h"

hash_list::hash_list() {
    this->head = nullptr;
    this->size = 0;
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {
    
    // Make new node if list is empty
    if (this->head == nullptr) {
        this->head = create_node(key, value);
        this->size++;
        return;
    }

    // Check if node already exists
    node* current = this->head;
    while (current != nullptr) {
        if (key == current->key) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    // Initializing the new node to be inserted at head of list
    node* new_node = create_node(key, value);
    this->size++;
    new_node->next = this->head;
    this->head = new_node;

}

node* create_node(int key, float value) {
    node* new_node = new node;
    new_node->key = key;
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}

std::optional<float> hash_list::get_value(int key) const {
    node* current = this->head;

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return std::nullopt;
}

bool hash_list::remove(int key) { 
    node* current = head;
    if(!head)
    {
        return false;
    }
    if (head->key == key)
    {
        node* exnode = head;
        head = head->next;
        delete exnode;
        size--;
        return true;
    }
    while (current->next != nullptr)
    {
        if (current->next->key == key)
        {
            node* exnode = current->next;
            current->next = current->next->next;
            delete exnode;
            size--;
            return true;
        }
        current = current->next;
    };
    return false; }

size_t hash_list::get_size() const { 
    if (!head)
    {
    return 0;
    }
    return size;
      }

hash_list::~hash_list() {
    node* current = head;
    if(head)
    {
        while (current->next != nullptr)
        {
            node* exnode = current;
            current = current->next;
            delete exnode;
        }
        delete current; //edited code
    }
    head = nullptr;
    size = 0;
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) : size(0), head(nullptr) {
    node* current = other.head;
    node* new_node = nullptr;
    if (current) {
        this->head = create_node(current->key, current->value);
        this->size++;
        current = current->next;
    }

    this->iter_ptr = this->head;
    while (current) {
        new_node = create_node(current->key, current->value);
        this->size++;
        this->iter_ptr->next = new_node;
        this->iter_ptr = this->iter_ptr->next; // Use increment_iter to do;
        current = current->next;
    }
    this->iter_ptr = this->iter_ptr->next;
}

hash_list &hash_list::operator=(const hash_list &other) { 
    if (this == &other) return *this; 
    hash_list temp = other;
    std::swap(head, temp.head);
    std::swap(size, temp.size);
    std::swap(iter_ptr, temp.iter_ptr);
    return *this;
    }

void hash_list::reset_iter() {
    this->iter_ptr = this->head;
}


void hash_list::increment_iter() {
    if (this->iter_ptr != nullptr){
        this->iter_ptr = this->iter_ptr->next;
    }
}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { 
    if (this->iter_ptr != nullptr) {
        return std::optional<std::pair<const int *, float *>>{{&this->iter_ptr->key, &this->iter_ptr->value}};
    }
    return std::nullopt;
}


bool hash_list::iter_at_end() {
    return !this->iter_ptr;
}
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
