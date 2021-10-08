//
// Created by Riton on 2021/9/29.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>

std::string even_or_odd(int number) {
    return number % 2 == 0 ? "Even" : "Odd";
}

std::string number_to_string(int num) {
    return std::to_string(num);
}

class Printer {
public:
    static std::string printerError_my_method(const std::string &s) {
        int error = 0;
        for (char i : s) {
            if (i > 'm' || i < 'a') {
                error++;
            }
        }
        return std::to_string(error).append("/").append(std::to_string(s.length()));
    }

    static std::string printerError(std::string const &s) {
        auto const denum = s.length();
        auto const numer = std::count_if(
                s.cbegin(), s.cend(),
                [](char c) { return c > 'm'; });

        return std::to_string(numer) + "/" + std::to_string(denum);
    }
};

std::string createPhoneNumber_my_method(const int arr[10]) {
    auto phone_number = std::string("");
    for (int i = 0; i < 10; ++i) {
        switch (i) {
            case 0:
                phone_number += "(";
                phone_number += std::to_string(arr[i]);
                break;
            case 2:
                phone_number += std::to_string(arr[i]);
                phone_number += ") ";
                break;
            case 6:
                phone_number += "-";
                phone_number += std::to_string(arr[i]);
                break;
            default:
                phone_number += std::to_string(arr[i]);
                break;
        }
    }
    return phone_number;
}

std::string createPhoneNumber(const int arr[10]) {
    char buf[15];
    snprintf(buf, sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6],
             arr[7], arr[8], arr[9]);
    return buf;
}

template<typename T>
void print_vector(std::vector<T> &v) {
    for (auto const& item : v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


class Same {
public :
    static bool comp_my_method(std::vector<int> &a, std::vector<int> &b) {
        if (a.size() != b.size())
            return false;
        for (auto number : a) {
            auto p = std::find(b.begin(), b.end(), number * number);
            if (p != b.end()) {
                b.erase(p);
            } else {
                return false;
            }
        }
        return true;
    }


    static bool comp(std::vector<int> a, std::vector<int> b) {
        for (auto &v : a) {
            v = v * v;
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        return a == b;
    }
};

template<typename T>
void show(T t) {
    std::cout << t << std::endl;
}

class WhichAreIn {
public:
    static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2);
};

std::vector<std::string> inArray_my_method(std::vector<std::string> &array1, std::vector<std::string> &array2) {
    std::vector<std::string> res = {};
    for (const auto &item : array1) {
        auto c = std::count_if(array2.begin(), array2.end(), [item](const std::string &s) {
            return s.find(item) < s.length();
        });
        if (c > 0) {
            res.push_back(item);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string> &array1, std::vector<std::string> &array2) {
    std::vector<std::string> results;

    std::copy_if(array1.begin(), array1.end(), std::back_inserter(results),
                 [&](const std::string &item1) {
                     return std::any_of(array2.begin(), array2.end(),
                                        [&](const std::string &item2) {
                                            return item2.find(item1) != std::string::npos;
                                        }
                     );
                 }
    );

    std::sort(results.begin(), results.end());

    return results;
}


std::string spinWords(const std::string &str)
{
    auto s = std::string(str);
    std::smatch m;
    std::regex e("\\w{5,}");

    while (std::regex_search( s, m, e)) {
        for (auto x: m) {
            show(x);
        }
        s = m.suffix().str();
    }

    return "pizza";
}

int main() {
//    int a = 111, b = 222;
//    std::cout << number_to_string(a) << std::endl;
//    std::cout << number_to_string(b) << std::endl;
//    int a = 22, b = 23;
//    std::cout << even_or_odd(a) << std::endl;
//    std::cout << even_or_odd(b) << std::endl;
//    std::string s = "aaaxbbbbyyhwawiwjjjwwm";
//    std::cout << Printer::printerError(s) << std::endl;
//    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    std::cout << createPhoneNumber(numbers) << std::endl;

//    std::vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
//    show(*a.begin());
//    show(*(a.begin() + 1));
//    show(*(a.begin() + 2));
//    std::vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
//    std::cout << (Same::comp(a, b) ? "pass" : "error") << std::endl;
//    a = {121, 144, 19, 161, 19, 144, 19, 11};
//    b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
//    std::cout << (!Same::comp(a, b) ? "pass" : "error") << std::endl;

//    std::vector<std::string> arr1 = {"live", "strong", "arp"};
//    std::sort(arr1.begin(), arr1.end());
//    print_vector(arr1);
//    std::vector<std::string> arr2 = {"lively", "alive", "harp", "sharp", "armstrong"};
//    std::vector<std::string> sol1 = {"arp", "live", "strong"};
//    std::vector<std::string> ans1 = WhichAreIn::inArray(arr1, arr2);
//    show(ans1 == sol1);
//
//    arr1 = {"tarp", "mice", "bull"};
//    arr2 = {"lively", "alive", "harp", "sharp", "armstrong"};
//    sol1 = {};
//    ans1 = WhichAreIn::inArray(arr1, arr2);
//    show(ans1 == sol1);

    show(spinWords("Hey fellow warriors") == "Hey wollef sroirraw");


}