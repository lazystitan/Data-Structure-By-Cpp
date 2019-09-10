//
// Created by Riton on 2019/9/4.
//

#include <iostream>
#include <thread>
#include <mutex>

struct Person {
    std::string name;
    int age;
    int gender;
};

//data race
void test1() {
    using namespace std;
    using namespace chrono_literals;
    using namespace chrono;

    Person person{string("lalala"), 15, 0};

    mutex mt;
    thread thread_a([&]() {
//        this_thread::sleep_for(10ns);
        mt.lock();
        cout << person.name << endl;
        person.name = "Dio Brando";
        cout << person.age << endl;
        person.age = 171;
        cout << person.gender << endl;
        person.gender = 0;
        mt.unlock();
    });

    thread thread_b([&]() {
//       this_thread::sleep_for(10ns);
        mt.lock();
        cout << person.name << endl
             << person.age << endl
             << person.gender << endl;
        mt.unlock();
    });

    thread_a.join();
    thread_b.join();
}

//deadlock
void test2() {
    std::mutex mutex_m;
    std::mutex mutex_n;

    std::thread thread_a([&]() {
        mutex_m.lock();
        mutex_n.lock();

        std::cout <<"thread a" <<std::endl;

        mutex_m.unlock();
        mutex_n.unlock();
    });

    std::thread thread_b([&]() {
        mutex_n.lock();
        mutex_m.lock();

        std::cout <<"thread b" <<std::endl;

        mutex_n.unlock();
        mutex_m.unlock();
    });

    thread_a.join();
    thread_b.join();
}


//lock_guard and unique_lock test
void test3() {
    Person person{"abc", 12, 1};
    std::mutex mutex;

    std::thread thread_a([&]() {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ns);

//        std::lock_guard<std::mutex> lg(mutex);
        std::unique_lock<std::mutex> ul(mutex);x
        person.name = "def";
        person.age = 21;
        person.gender = 0;

    });

    std::thread thread_b([&]() {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ns);

//        std::lock_guard<std::mutex> lg(mutex);
        std::unique_lock<std::mutex> ul(mutex);
        std::cout << person.name << std::endl
             << person.age << std::endl
             << person.gender << std::endl;
    });

    thread_a.join();
    thread_b.join();
}

int main() {
//    test1();
//    test2();
    test3();
    return 0;

}
