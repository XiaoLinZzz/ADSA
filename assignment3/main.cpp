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
        bool repeat = false;
        // get order insert ("A")
        if (v[i][0] == 'A')
        {   
            // remove the "A"
            v[i] = v[i].erase(0,1);

            int check = 0;

            // check repeat
            for (int j = 0; j < 26; j++)
            {   
                if (v[i] == slot[j]) {   
                    repeat = true;
                }
            }
            
            if (repeat == false)
            {   
                // do insert
                char c = v[i][v[i].length()-1];
                for (int j = 0; j < 26; j++)
                {   
                    if (c - 97 + j <= 25)
                    {   
                        if (slot[c - 97 + j].size() == 0)
                        {   
                            slot[c - 97 + j] = v[i];
                            statues[c - 97 + j] = "occupied";
                            break;
                        }
                    }
                    else
                    {   
                        if (slot[check].size() == 0)
                        {   
                            slot[check] = v[i];
                            statues[check] = "occupied";
                            break;
                        }
                        else
                        {   
                            check++;
                        }
                    }
                }
            }
            // test: Aaaa Accc Abbb
        }

        // get order delete ("D")
        else if (v[i][0] == 'D')
        {
            // remove the "D"
            v[i] = v[i].erase(0,1);

            // get the last letter
            char a = v[i][v[i].size()-1];
            
            // delete
            for (int j = 0; j < 26; j++)
            {   
                if (a - 97 + j <= 25)
                {   
                    if (slot[a - 97 + j] == v[i])
                    {   
                        slot[a - 97 + j] = "";
                        statues[a - 97 + j] = "tombstone";
                        break;
                    }
                }
            }
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
// test: Aaaa Accc Abbb