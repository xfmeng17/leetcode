/*
class MinStack {
private:
    const int N = 10;
    int *array = NULL;
    int capacity = 0;
    int size = 0;
    int minElem = 0;
public:
    // ** initialize your data structure here.
    MinStack() {
        array = new int[N];
        capacity = N;
        size = 0;
        minElem = 0;
    }
    void push(int x) {
        array[size] = x;
        size++;
        if (size == 1) {
            minElem = x;
        } else {
            minElem = min(minElem, x);
        }
        if (size == capacity) {
            capacity = 2 * capacity;
            int *aux = new int[capacity];
            for (int i = 0; i < size; i++) {
                aux[i] = array[i];
            }
            delete[] array;
            array = aux;
            aux = NULL;
        }
    }

    void pop() {
        if (size == capacity / 2) {
            capacity /= 2;
            int *aux = new int[capacity];
            for (int i = 0; i < size; i++) {
                aux[i] = array[i];
            }
            delete[] array;
            array = aux;
            aux = NULL;
        }
        size--;
        if (size > 0) {
            minElem = array[0];
            for (int i = 0; i < size; i++) {
                minElem = min(minElem, array[i]);
            }
        }
    }

    int top() {
        if (size > 0) {
            return array[size-1];
        } else {
            // ** dummy, should throw exception
            return -1;
        }
    }

    int getMin() {
        if (size > 0) {
            return minElem;
        } else {
            return -1;
        }
    }
};
*/

// ** Referece, Just store difference
class MinStack {
private:
  stack<long> myStack;
  long minElem;

public:
  MinStack() {
    myStack = stack<long>();
    minElem = 0;
  }
  void push(int x) {
    if (myStack.empty()) {
      myStack.push(0);
      minElem = x;
    } else {
      myStack.push(x - minElem);
      if (x < minElem) {
        minElem = x;
      }
    }
  }

  void pop() {
    if (myStack.empty()) {
      return;
    }
    long p = myStack.top();
    if (p < 0) {
      minElem -= p;
    }
    myStack.pop();
  }

  int top() {
    long p = myStack.top();
    if (p > 0) {
      return p + minElem;
    } else {
      return minElem;
    }
  }

  int getMin() { return minElem; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
