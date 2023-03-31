// 栈
template <class T>
class Stack{
    int top;
    int maxSize;
    T* arr;
public:
    Stack() {
        top = 0;
        maxSize = 10;
        arr = (T*)malloc(maxSize * sizeof(T));
        this->maxSize = maxSize;
    }
    Stack(int maxSize) {
        top = 0;
        arr = (T*)malloc(maxSize * sizeof(T));
        this->maxSize = maxSize;
    }
    void push(T elem){
        if(top >= maxSize){
            // 扩容到1.5倍
            int oldCapacity = maxSize;
            int newCapacity = oldCapacity + (oldCapacity >> 1);
            arr = (T*)realloc(arr, newCapacity);
            maxSize = newCapacity;
            return;
        }
        arr[top++] = elem;
    }
    bool isEmpty(){
        return top == 0;
    }
    bool isFull(){
        return top >= maxSize;
    }
    T pop(){
        if(!isEmpty()) {
            return arr[--top];
        }
        // cout << "stack has no element" << endl;
    }
    T peek(){
        if(!isEmpty())
            return arr[top-1];
    }
};