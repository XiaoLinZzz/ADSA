#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

// hash table
class HashTable
{
    public:
    int size;
    vector<string> *table;
    HashTable(int size)
    {
        this->size = size;
        table = new vector<string>[size];
    }
    int hash_key(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
            hash = (hash * 31 + key[i]) % size;
        return hash;
    }
    void insert(string key)
    {
        int hash = hash_key(key);
        table[hash].push_back(key);
    }
    void remove(string key)
    {
        int hash = hash_key(key);
        vector<string>::iterator it;
        for (it = table[hash].begin(); it != table[hash].end(); it++)
            if (*it == key)
                break;
        table[hash].erase(it);
    }
    bool search(string key)
    {
        int hash = hash_key(key);
        vector<string>::iterator it;
        for (it = table[hash].begin(); it != table[hash].end(); it++)
            if (*it == key)
                return true;
        return false;
    }
};

int main() {
    // insert hash table
    HashTable *hash_table = new HashTable(26);
    hash_table->insert("hello");
    hash_table->insert("world");

    // search hash table
    if (hash_table->search("hello"))
        cout << "hello is in the hash table" << endl;
    else
        cout << "hello is not in the hash table" << endl;
}