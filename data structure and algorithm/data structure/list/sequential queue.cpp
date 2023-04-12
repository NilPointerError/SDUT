// 顺序队列
template <class T>
class Queue {
    T* data;
    int front;
    int rear;
    const int DEFAULT_SIZE = 10;
    int size;//队列中实际元素个数
    int length;//数组长度
public:
    Queue() {
        data = new T[DEFAULT_SIZE];
        front = rear = 0;
        length = DEFAULT_SIZE;
        size = 0;
    }
    Queue(int maxSize) {
        data = new T[maxSize];
        front = rear = 0;
        length = maxSize;
        size = 0;
    }
    
    int size1() {
        return size;
    }
    
    bool isEmpty() {
        if(front==rear) 
            return true;
        return false;
    }
    //入队
    bool offer(T data) {
        // 队满
        if(front == (rear+1)%length) {
            // 扩容
            ensureCapacity(length*2+1);
        }
        this->data[rear] = data;
        rear = (rear+1)%length;
        size++;
        return true;
    }
    //出队
    T poll() {
        if(!isEmpty()) {
            int temp = front;
            front = (front+1)%length;
            size--;
            return data[temp];
        }
    }
    //返回队头元素
    T peek() {
        return data[front];
    }
    void ensureCapacity(int capacity) {
        T* old = data;
        data = new T[capacity];
        int j = 0;
        // 复制元素到新数组中
        for (int i = front; i != rear; i=(i+1)%length) {
            /* code */
            data[j++] = old[i];
        }
        front = 0;
        rear = j;
        length = capacity;
    }
    //清空队列
    //void clearQueue();
};