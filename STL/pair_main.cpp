//
// Created by Riton on 2019/9/4.
//

#include <iostream>
#include <utility>
#include <tuple>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream &os, const std::pair<T1,T2> &pair) {
    return os << "[" << pair.first << "," << pair.second << "]" <<endl;
}

class Foo {
public:
    explicit Foo(std::tuple<int, float>) {
        cout << "Foo::Foo(tuple)"<<endl;
    }

    template <typename... Args>
    explicit Foo(Args... args) {
        cout << "Foo::Foo(args...)"<<endl;
    }
};

int main() {
    std::pair<int, double> pair(1, 2.3);

    cout << pair.first <<"," <<pair.second <<endl;
    cout <<pair <<endl;

    std::tuple<int, float> tuple(1,2.22);
    std::pair<int, Foo> p1(42, tuple);
    std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(42), tuple);

//    cout << p1 << endl;
//    cout << p2 << endl;
    std::pair<char, char> p3 = std::make_pair('a', 'c');
    cout << p3;
    char c;
    std::tie(std::ignore, c) = p3;

    cout << c << endl;



}

