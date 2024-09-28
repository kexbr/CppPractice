#pragma once
#include <iostream>
#include <cstring>

class String{
public:
    std::size_t size(){
        return size_;
    }

    String() = default;
    
    explicit String(std::size_t len, char c): size_{len}, data_{new char[size_]}{
        for(int i = 0; i < size_; i++){
            data_[i] = c;
        }
    }
    
    String(const char* c){
        size_ = strlen(c);
        delete[] data_;
        data_ = new char[size_];
        for(int i = 0; i < size_; i++){
            data_[i] = c[i];
        }
    }
    
    String (String &str){
        size_ = str.size_;
        delete[] data_;
        data_ = new char[size_];
        for(int i = 0; i < size_; i++){
            data_[i] = str.data_[i];
        }
    }
    
    String& operator= (const char* str){
        size_ = std::strlen(str);
        delete[] data_;
        data_ = new char[size_];
        for(int i = 0; i < size_; i++){
            data_[i] = str[i];
        }
        return *this;
    }
    
    char& operator[] (std::size_t x){
        return data_[x];
    }
    
    friend std::ostream& operator<<(std::ostream& out, const String& cur);
    
    friend String operator+(const String &a, const String &b);
    
    friend String operator+(const String &a, const char* b);

private:
    std::size_t size_ = 0;
    char* data_ = nullptr;
};  

inline std::ostream& operator<<(std::ostream& out, const String& cur){
        for(std::size_t i = 0; i < cur.size_; i++){
            out << cur.data_[i];
        }
        return out;
}

inline String operator+(const String &a, const String &b){
    String ans;
    ans.size_ = a.size_ + b.size_;
    ans.data_ = new char[ans.size_];
    for(std::size_t i = 0; i < a.size_; i++){
        ans.data_[i] = a.data_[i];
    }
    for(std::size_t i = a.size_; i < a.size_ + b.size_; i++){
        ans.data_[i] = b.data_[i - a.size_];
    }
    return ans;
}

inline String operator+(const String &a, const char* b){
    String ans;
    std::size_t b_len = std::strlen(b);
    ans.size_ = a.size_ + b_len;
    ans.data_ = new char[ans.size_];
    for(int i = 0; i < a.size_; i++){
        ans.data_[i] = a.data_[i];
    }
    for(int i = a.size_; i < a.size_ + b_len; i++){
        ans.data_[i] = b[i - a.size_];
    }
    return ans;
}