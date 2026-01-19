#pragma once

#include <iostream>
#include <memory>
#include <initializer_list>
#include <iterator>

template<typename T>
class vector{
    public:

    //constructors for vector
        vector(size_t size, T _value):size_(size),csize_(size),data_(std::make_unique<T[]>(size_))
        {
            for(int i=0;i<csize_;i++){
                data_[i] = _value;
            }
        }
        vector():size_(2), csize_(0), data_(std::make_unique<T[]>(2)) {}
        vector(std::initializer_list<T> _list)
        {
            int size = std::distance(_list.begin(),_list.end());
            size_ = size;
            csize_ = size;
            data_  = std::make_unique<T[]>(size_);
            for(int i=0;i<csize_;i++){
                data_[i] = *(_list.begin()+i);
            }
        }
        class Iterator{
            public:
                Iterator(T *p):ptr(p){}
                T& operator*(){
                    return *ptr;
                }
                Iterator& operator++(){
                    ++ptr;
                    return *this;
                }
                Iterator& operator++(int){
                    ++ptr;
                    return *this;
                }
                Iterator& operator+(size_t a){
                    ptr+a;
                    return *this;
                }
                bool operator!=(const Iterator&other){
                    return ptr!=other.ptr;
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
        Iterator begin(){
            Iterator I(&data_[0]);
            return I;
        }
        Iterator end(){
            Iterator I(&data_[csize_]);
            return I;
        }
    
    //push back
        void push_back(const T& value)
        {
            if(csize_+1>size_){
                nsize(2);
            }
            data_[csize_] = value;
            csize_ ++;
        }
        T back()
        {
            return data_[csize_-1];
        }
        void pop_back()
        {
            csize_--;
            data_[csize_]=none;
        }
        size_t size(){
            return csize_;
        }
        T& operator[](size_t index){
            if(index>=csize_){
                std::cout<<"Index exceeded size of vector\n";
                return none;
            }
            return data_[index];
        }
    private:
        size_t size_;
        size_t csize_;
        std::unique_ptr<T[]> data_;

        void nsize(int n){
            auto newdata = std::make_unique<T[]>(n*size_);
            for(int i=0; i<csize_ ; i++){
                newdata[i] = std::move(data_[i]);
            }
            data_ = std::move(newdata);
            size_ = n*size_;
        }
        T none;
};