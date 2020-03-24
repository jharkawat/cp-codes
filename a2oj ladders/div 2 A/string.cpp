#include <bits/stdc++.h>

using namespace std;

void work(string& str)
{
    string rem = "AEIOUYaeiouy";
    //cout << "In work" << endl;
    for(char c : rem)
    {
        str.erase(remove(str.begin(), str.end(), c), str.end());
    }

    int x = str.size();
    for(int i=0 ; i<x; i++)
    {
        if(isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }

    string str1 = ".";
    for(int i = 0; i < 2*x ; i = i+2)
    {
        str.insert(i, str1);
    }

}

int main()
{
    string s;
    getline(cin, s);
    work(s);
    cout << s << endl;
    return 0;
}