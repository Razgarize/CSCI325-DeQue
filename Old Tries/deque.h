#ifndef DEQUE_H
#define DEQUE_H

class Deque {
    private:
        Deque **blockmap;
        Deque front;
        Deque rear;
        int map_capacity;
        int map_size;
    public:
        Deque();
        ~Deque();
        void push_front();
        void pop_front();
        void push_back();
        void pop_back();
        Deque get_front();
        Deque get_back();
        void set_blockmap(Deque **blockmap);
        bool is_empty();
        int get_size();
        Deque& operator[](Deque& index);
        Deque& operator[](int index);
};

#endif