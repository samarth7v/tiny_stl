#pragma once
template<typename T>
class Iterator{
    public:
        Iterator(T *p):ptr(p){}
        virtual ~Iterator()=default;
        T& operator*(){
            return *ptr;
        }
        Iterator& operator++(){
            ++ptr;
            return *this;
        }
        Iterator& operator--(){
            --ptr;
            return *this;
        }
        Iterator operator++(int){
            Iterator temp = *this;
            ++ptr;
            return temp;
        }
        Iterator operator--(int){
            Iterator temp = *this;
            --ptr;
            return temp;
        }
        Iterator operator+(size_t a){
            return Iterator(ptr + a);
        }
        Iterator operator-(size_t a){
            return Iterator(ptr - a);
        }
        bool operator!=(const Iterator&other){
            return ptr!=other.ptr;
        }
        bool operator==(const Iterator&other){
            return ptr==other.ptr;
        }
        bool operator<(const Iterator&other){
            return ptr<other.ptr;
        }
        bool operator<=(const Iterator&other){
            return ptr<=other.ptr;
        }
        bool operator>(const Iterator&other){
            return ptr>other.ptr;
        }
        bool operator>=(const Iterator&other){
            return ptr>=other.ptr;
        }
    private:
        T* ptr;
};