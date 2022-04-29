#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

bool test (int num) {
            if (num == 2)
                return false;
            if (num % 2 == 0 || num < 2)
                return false;
            else {
                for (int i = 3; i*i <= num; i += 2) {
                    if (num%i == 0)
                        return false;
                }
            }
            return true;
        }
        
int getNumber(vector<int>& a) {
    // write code here
    while ( a.size() > 1) {
        for (int i = 0; i < a.size(); i++)
        {
            int num = a[i];
            if (test(num) == false) {
                a.erase(i);
            }
        }
    }
    return a[0];
}


int main() {
    getNumber([1,2,3,4]);
}