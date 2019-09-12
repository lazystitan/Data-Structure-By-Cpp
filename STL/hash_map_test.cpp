//
// Created by Riton on 2019/9/12.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char,int> mymap;
    mymap['a'] = 1;
    mymap['5'] = 2;
    mymap['u'] = 4;
    mymap['c'] = 3;
    mymap['q'] = 1;
    mymap['o'] = 6;

    if (mymap.find('c') == mymap.end())
        cout << "error" << endl;
    else
        cout << mymap['c'] <<endl;

    mymap.erase('c');

    if (mymap.find('c') == mymap.end())
        cout << "has erased" << endl;
    else
        cout << mymap['c'] <<endl;


}


