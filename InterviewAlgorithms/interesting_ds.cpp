//
// Created by Riton on 2019/9/24.
//

/*
 * 一个栈，包括三个方法：
 * push
 * pop
 * min
 * push和pop的操作都为O（1）
 * min在最好的情况下是O（1)
 * 最坏的情况下是O（n）
 * 当然，这是以额外的空间为代价的
 */

class stack {
private:
    int *data_p;
    int top;
    int *min_p;
    int top_min;
public:
    explicit stack(int size) {
        data_p = new int[size];
        min_p = new int[size];
        top = -1;
        top_min = -1;
    }

    ~stack() {
        delete [] data_p;
        delete [] min_p;
    }

    void push(int data) {
        top++;
        data_p[top] = data;
        if (top_min == -1) {
            top_min++;
            min_p[top_min] = data;
        } else if (min_p[top_min] > data){
            min_p[++top_min] = data;
        }
    }

    int pop() {
        int temp = data_p[top];
        if (data_p[top] == min_p[top_min]) {
            top_min --;
        }
        top--;
        return temp;
    }

    int min() {
        return min_p[top_min--];
    }
};