#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <cmath>
using namespace std;

string Addition(string a, string b, int Base)
{
	// make sure larger one is behind
	if (a.length() > b.length())
		swap(a, b);

	string str = "";

	int n1 = a.length(), n2 = b.length();

	// Reverse string a and b
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0;
	for (int i = 0; i < n1; i++)
	{
		int sum = ((a[i]-'0')+(b[i]-'0')+carry);
		str.push_back(sum%Base + '0');

		carry = sum/Base;
	}

	for (int i = n1; i < n2; i++)
	{
		int sum = ((b[i]-'0')+carry);
		str.push_back(sum%Base + '0');

		carry = sum/Base;
	}

	// remain carry
	if (carry)
		str.push_back(carry+'0');

	reverse(str.begin(), str.end());

	return str;
}

string sub(string a,string b,int Base){
    if(b.size() > a.size()) {
        int diff = b.size() - a.size();
        a = string(diff,'0').append(a);
    }
    if(a.size() > b.size()) {
        int diff = a.size() - b.size();
        b = string(diff,'0').append(b);
    }
    
    int c = 0;
    int d;
    string diff;
    
    for(int i = a.size() - 1; i >= 0 ;i--){
        int i1 = a[i]-'0'-c;
        int i2 = b[i]-'0';
        if(i2 > i1){
            d = i1 + Base - i2;
            c = 1;
            diff = diff + to_string(d);
		}
		else{
            d = i1 - i2;
            c = 0;
            diff = diff + to_string(d);
		}
    }
    reverse(diff.begin(), diff.end());
    return diff;
}


string Karatsuba(string a, string b, int Base)
{
    int n = max(a.size(), b.size());

	while (a.size() < n)
		a.insert(0, "0");

	while (b.size() < n)
		b.insert(0, "0");

	if (n == 1)
		return to_string((a[0]-'0') * (b[0]-'0'));

    int k = n/2;

    string a0 = a.substr(0, k);     // left one
    string a1 = a.substr(k, n-a0.size());   // right one
    string b0 = b.substr(0, k);     // left one
    string b1 = b.substr(k, n-b0.size());   // right one

    string p0 = Karatsuba(a0, b0, Base);
    string p1 = Karatsuba(a1, b1, Base);
    string p2 = Karatsuba(Addition(a0, a1, Base), Addition(b0, b1, Base), Base);
	string p3 = sub(p2, Addition(p0, p1, Base), Base);

	for (int i = 0; i < 2*(n-k); i++)
        p0.append("0");
    for (int i = 0; i < n-k; i++)
        p3.append("0");

	string result = Addition(Addition(p0, p1, Base), p3, Base);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

int main()
{
	string a, b;
	int Base;
	cin >> a >> b >> Base;

	cout << Addition(a, b, Base) << " " << Karatsuba(a, b, Base) << endl;
	// cout << sub(a, b, Base) << endl;
	return 0;
}
