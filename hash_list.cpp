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
        if (current->next->value == key)
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
        delete current;
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

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
