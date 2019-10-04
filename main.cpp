//
// Created by Riton on 2019/6/29.
//

#include <iostream>
#include <regex>

using namespace std;

void regex_find_page() {
//    string pattern(R"(GET.*)");
    string pattern(R"(GET\s.+\sHTTP/1.1\r\n)");
    regex reg_pattern(pattern);
    match_results<string::const_iterator> results;
//    string str_value = "https://hello.html HTTP/1.1\r\n";
    string str_value = "GET /hello.html HTTP/1.1\r\n";
//    string str_value = "https://www.baidu.com";
    bool flag = regex_match(str_value, results, reg_pattern);
    cout << flag << endl;
    for (auto &ch : results) {
        cout << ch << endl;
    }
}

int main() {
//    cout << "hello, here is main at root directory"<<endl;
    regex_find_page();
    return 0;
}