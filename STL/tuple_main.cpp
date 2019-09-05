//
// Created by Riton on 2019/9/5.
//

#include <iostream>
#include <tuple>
#include <complex>
#include <string>
#include <functional>

using namespace std;

int main() {
    tuple<string, int, int, complex<double>> t;
    tuple<int, float, string> t1(41, 6.4, "nico");

    cout << get<0>(t1) <<endl;
    cout << get<1>(t1) <<endl;
    cout << get<2>(t1) <<endl;

    auto t2 = make_tuple(22, 44, "nico");

    get<1>(t1) = get<1>(t2);

    if (t1 < t2)
        t1 = t2;

    string s = "some";
    auto x = make_tuple(s);
    get<0>(x) = "my value";

    cout << get<0>(x) <<endl;
    cout << s << endl;

    auto y = make_tuple(ref(s));
    get<0>(y) = "my value";
    cout << s << endl;

    tuple<int, float, string> t3(77, 1.1, "more");
    int i;
    float f;
    string str;

//    make_tuple(ref(i), ref(f), ref(str)) = t3;
    tie(i, f, str) = t3;

    cout << i << "," << f << "," << str << endl;

    cout << tuple_size<decltype(t3)>::value << endl;

    auto tt = tuple_cat(t1, t2, t3);

    cout << tuple_size<decltype(tt)>::value << endl;

    return 0;
}
