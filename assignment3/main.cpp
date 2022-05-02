#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int hash_function(string s)
{   
    // get last elememnt of string
    char c = s[s.length()-1];
    return c - 97;
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
            int out = 0;
            // remove the "A"
            v[i] = v[i].erase(0,1);

            // get the letter
            char a = v[i][v[i].size()-1];
            
            // check if the letter is already in the slot
            bool repeat = false;
            for(int j = 0; j < 26; j++){
                if(slot[j] == v[i]){
                    repeat = true;
                }
            }

            // if the letter is not in the slot
            if(repeat == false){
                // find the first empty slot
                int check = 0;
                for(int j = 0; j < 26; j++){
                    if(slot[j].size() == 0){
                        check = j;
                        break;
                    }
                }

                // add the letter in the slot
                slot[check] = v[i];
                statues[check] = "occupied";
            }
        }

        // get order delete ("D")
        else if (v[i][0] == 'D')
        {
            // remove the "D"
            v[i] = v[i].erase(0,1);

            // get the last letter
            char a = v[i][v[i].size()-1];
            
            // get index
            int index = hash_function(v[i]);
            
            // find the slot of the letter
            int check = 0;
            for(int j = 0; j < 26; j++){
                if(slot[j] == v[i]){
                    check = j;
                    break;
                }
            }

            // remove the letter in the slot
            slot[check] = "";
            statues[check] = "tombstone";
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

// test: Aboa Acobra Aabba Aclassic Abee Abed Dcobra