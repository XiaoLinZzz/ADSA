#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int hash_function(char c)
{
    return c - 'a';
}

void insert(char element)
{
    int i = hash_function(element);
    if (slot[i] == NULL) {
        slot[i] = element;
        status[i] = "occupied";
    } else {
        i++;
        insert(element);
    }
}

void remove(char element)
{
    int i = hash_function(element);
    if (slot[i] == NULL)
        return;
    else if (slot[i] != element) {
        i++;
        remove(element);
    } else {
        slot[i] = NULL;
        status[i] = "tombstone";
    }
}

void repair(char a, int i)
{
    // set index
    int j = i + 1;
    while (slot[j] != NULL) {
        if (a-97+j >= index) {
            j++;
        } else {
            slot[i] = slot[j];
            slot[j] = NULL;
            i = j;
            repair(a, i);
        }
    }
}

int main()
{
    string statues[26];
    string slot[26];
    string S, T;
    getline(cin, S); 
    stringstream X(S); 

    // initialize the statues
    for(int i = 0; i < 26; i++){
        statues[i] = "never used";
    }

    // read the input
    vector<string> v;

    while (getline(X, T, ' ')) {  
        v.push_back(T);
    }  

    // order the input --> v[i][0]
    for (int i = 0; i < v.size(); i++)
    {
        // get order insert ("A")
        if (v[i][0] == 'A')
        {   
            // remove the "A"
            v[i] = v[i].erase(0,1);

            // get the last letter
            char a = v[i][v[i].size()-1];

            // get the index
            int index = hash_function(a);

            // do insert
            insert(a);
        }
        if (v[i][0] == 'D')
        {
            // remove the "D"
            v[i] = v[i].erase(0,1);

            // get the last letter
            char a = v[i][v[i].size()-1];

            // get the index
            int index = hash_function(a);

            // do remove
            remove(a);

            // repair
            repair(a, index);
        }
    }

    // print the output
    for(int i = 0; i < 26; i++){
        if(slot[i].size() != 0){
            cout<<slot[i]<<" ";
        }
    }

    return 0;
}