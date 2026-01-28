#pragma once

#include <iostream>
#include <memory>
#include <initializer_list>
#include "iterator.h"

template<typename T>
class vector{
    public:

    //constructors for vector
        vector(size_t size, T _value):capacity_(size),size_(size),data_(std::make_unique<T[]>(capacity_))
        {
            for(int i=0;i<size_;i++){
                data_[i] = _value;
            }
        }
        vector():capacity_(0), size_(0), data_(std::make_unique<T[]>(0)) {}
        vector(std::initializer_list<T> _list)
        {
            int size = std::distance(_list.begin(),_list.end());
            capacity_ = size;
            size_ = size;
            data_  = std::make_unique<T[]>(capacity_);
            for(int i=0;i<size_;i++){
                data_[i] = *(_list.begin()+i);
            }
        }
    //copy constructor
        vector(const vector<T>& other)
        {
            capacity_ = other.capacity_;
            size_ = other.size_;
            data_ = std::make_unique<T[]>(capacity_);
            for(int i=0;i<size_;i++){
                data_[i] = other.data_[i];
            }

        }
    //move constructor
        vector(vector<T>&& other) noexcept : capacity_(other.capacity_),size_(other.size_),data_(std::move(other.data_))
        {
            other.capacity_=0;
            other.size_=0;
        }
    //iterator
        class iota:public Iterator<T>{
            using Iterator<T>::Iterator;
        };
        iota begin(){
            iota I(&data_[0]);
            return I;
        }
        iota end(){
            iota I(&data_[size_]);
            return I;
        }
    //copy assignment
        vector<T>& operator=(const vector<T>& other)
        {
            capacity_ = other.capacity_;
            size_ = other.size_;
            data_ = std::make_unique<T[]>(capacity_);
            for(int i=0;i<size_;i++){
                data_[i] = other.data_[i];
            }
            return *this;
        }
    //move assignment
        vector<T>& operator=(vector<T>&& other) noexcept
        {
            capacity_ = other.capacity_;
            size_ = other.size_;
            data_ = std::move(other.data_);
            other.capacity_ = 0;
            other.size_ = 0;
            return *this;
        }
    //push back
        T& front() 
        {
            return data_[0];
        }
        T& back()
        {
            return data_[size_-1];
        }
        const T& front() const
        {
            return data_[0];
        }
        const T& back() const
        {
            return data_[size_-1];
        }
        void push_back(const T& value)
        {
            if(size_+1>capacity_){
                grow();
            }
            data_[size_] = value;
            size_ ++;
        }
        void pop_back()
        {
            if (size_>0)
                --size_;
        }
        size_t size() const {
            return size_;
        }
        T& operator[](size_t index){
            return data_[index];
        }
        T& at(size_t index){
            if(index >= size_) throw std::out_of_range("vector::at");
            return data_[index];
        }
        const T& operator[](size_t index) const{
            return data_[index];
        }
    private:
        size_t capacity_;
        size_t size_;
        std::unique_ptr<T[]> data_;

        void grow()
        {
            size_t new_capacity = (capacity_==0)? 1 : (2 * capacity_);
            auto newdata = std::make_unique<T[]>(new_capacity);
            for(int i=0; i<size_ ; i++){
                newdata[i] = std::move(data_[i]);
            }
            data_ = std::move(newdata);
            capacity_ = new_capacity;
        }
        T none;
};