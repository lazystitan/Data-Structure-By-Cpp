//
// Created by Riton on 2019/9/3.
//

#include <iostream>
#include <thread>
#include <vector>
#include <queue>

using namespace std;

void do_work() {
    cout << "work done" <<endl;
}

void test1() {
    thread worker(do_work);
    worker.detach();
}

void test2() {
    thread worker0([]() {
       cout << "lambda call" <<endl;
    });

    worker0.detach();
}

//传进重载调用运算符的类
class Work {
public:
    void operator()() {
        cout << "callable object" <<endl;
    }
};

void test3() {
    thread worker1(Work{});
    worker1.detach();
}

class Work2 {
public:
    void operator()(int id) {
        cout << "work_id: "<<id<<endl;
    }
};

//传入重载调用运算符且带参数时，第一个参数是实例，其次是参数
void test4() {
    thread worker(Work2{}, 12);
    worker.detach();
}

class Sampler {
public:
    void sample(int random) {
        cout << "sample with" << random <<endl;
    }
};

//传进类的成员函数时，第一个参数是成员函数的地址， 第二个是实例的地址
void test5() {
    Sampler obj;
    thread worker(&Sampler::sample, &obj, 13);
    worker.detach();
}

//eg6 无法理解，为什么输出的id会是32642，32689， 32528……
void test6() {
    int work_id = 1;

    thread worker([](int &id){
        cout << "do work:" << id << endl;
    }, ref(work_id));
    work_id = 2;
    worker.detach();
}

class ThreadGuard {
private:
    thread &m_thread;
public:
    explicit ThreadGuard(thread &t) : m_thread(t) {}
    ~ThreadGuard() {
//        joinable返回false
//        1.空线程(在构造没有附加任何运行任务)
//        2.已经被调用join方法的线程
//        3.已经被调用detach方法的线程
//        4.已经被move的线程
        if (m_thread.joinable())
            m_thread.join();
    }
//    不懂这是在干什么
    ThreadGuard(ThreadGuard const&) = delete;
    ThreadGuard &operator=(ThreadGuard const&) = delete;
};

void test7() {
    {
        thread worker(do_work);
        ThreadGuard guard(worker);
    }
}

void test8()
{
    size_t length = 10;
    int *value = new int [length];
    for (size_t i = 0; i < length; i++)
    {
        value[i] = i;
    }

    std::thread worker([&]() {
        using namespace chrono_literals;
        this_thread::sleep_for(5s);
        for (size_t i = 0; i < length; i++)
        {
            //会出现悬空指针
            cout << value[i] << endl;
        }
    });
    worker.detach();
    //局部变量已经被释放
    delete[] value;
    this_thread::sleep_for(10s);
    cout << "test exit" << endl;
}

void test9() {
    thread thread0(do_work);
    thread thread1 = std::move(thread0);
    thread thread2;

    thread2 = thread(do_work);
    thread1.join();
    thread2.join();
//    error1
//    thread0.join();
//
//    error2
//    caused by:
//    ...
//    public:
//        thread() noexcept = default;
//        thread(thread&) = delete;
//        thread(const thread&) = delete;
//        thread(const thread&&) = delete;
//    ...
//    thread thread0(do_work);
//    thread thread1(thread0);
}

void test10() {
    vector<thread> workers;
    workers.reserve(4);
    for (int i = 0; i < 4; ++i) {
        workers.emplace_back(thread(do_work));
    }

    for (auto &t: workers) {
        t.join();
    }
    
}

void test11() {
    using namespace chrono_literals;
    thread thread_a([]() {
        this_thread::sleep_for(2s);
        cout << "thread_a"<<endl;
    });

    auto time_point = chrono::steady_clock::now() + 10s;
    thread thread_b([=]() {
        this_thread::sleep_until(time_point);
        cout << "thread_b"<<endl;
    });

    thread_a.join();
    thread_b.join();
}

struct PU {
    void operator() (queue<int> &q) {
        while (!q.empty()) {
            cout << q.front() << endl;
            q.pop();
        }
    }
};

void test12() {
    auto *q = new queue<int>();
    q->push(1);
    q->push(3);
    q->push(5);
    q->push(8);
    q->push(2);
    q->push(3);
    q->push(0);
    q->push(9);

//  important : std::thread takes its arguments by value.
            thread t(PU{}, ref(*q));
    t.join();
}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
//    test9();
//    test10();
//    test11();
    test12();
    cout << "main thread" <<endl;
    return 0;
}
