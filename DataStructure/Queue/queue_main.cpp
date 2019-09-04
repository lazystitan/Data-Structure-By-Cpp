//
// Created by Riton on 2019/8/31.
//

#include <iostream>

#include "queue.h"

using namespace std;

struct Customer {
    int window;
    unsigned int time;
};

int best_window(Queue<Customer> windows[], int n_win) {
    int min_size = windows[0].size(), option_win = 0;
    for (int i = 0; i < n_win; ++i) {
        if ( min_size > windows[i].size() ) {
            min_size = windows[i].size();
            option_win = i;
        }
    }
    return option_win;
}

void simulate(int n_win, int serve_time) {
    auto* windows = new Queue<Customer>[n_win];
    int * count_windows = new int[n_win];
    for (int now = 0; now < serve_time; ++now) {
        if (rand() % (1 + n_win)) {
            cout << "a customer coming in ..." << endl;
            Customer c;
            c.time = 1 + rand() % 98;
            c.window = best_window(windows, n_win);
            windows[c.window].enqueue(c);
            cout << "customer arranged in "<<c.window<<" window ..." << endl;
            count_windows[c.window]++;
        }

        cout << "start serve" <<endl;
        for (int i = 0; i < n_win; ++i) {
            if (!windows[i].empty())
                if ( -- windows[i].front().time <= 0)
                    windows[i].dequeue();
        }

    }
    delete [] windows;
    for (int j = 0; j < n_win; ++j) {
        cout << count_windows[j] <<endl;
    }

}

int main() {
    simulate(10, 200);
    return 0;
}