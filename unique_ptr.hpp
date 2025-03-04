#pragma once

template <class T>
class unique_ptr {
private:
    T* m_ptr;
public:
    constexpr unique_ptr() noexcept : m_ptr{nullptr} { }
    constexpr unique_ptr(T* ptr) noexcept : m_ptr{ptr} { }

    unique_ptr(unique_ptr<T>&& obj) noexcept : m_ptr{obj.m_ptr} {
        obj.m_ptr = nullptr;
    }

    unique_ptr<T>& operator=(unique_ptr<T>&& obj) noexcept {
        if (this != &obj) {
            delete m_ptr;
            m_ptr = obj.m_ptr;
            obj.m_ptr = nullptr;
        }
        return *this;
    }

    unique_ptr(const unique_ptr<T>&) = delete;
    unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;


    ~unique_ptr() { 
        delete m_ptr; 
    }

    void swap(unique_ptr& obj ) noexcept {
        T* tmp = m_ptr;
        m_ptr = obj.m_ptr;
        obj.m_ptr = tmp;
    }

    T* get() const noexcept {
        return m_ptr;
    }

    T& operator*() const {
        return *m_ptr;
    }
    T* operator->() const {
        return m_ptr;
    }
    
    // T& operator[](int index) const {
    //     return m_ptr[index];
    // }
    
    void reset(T* ptr = nullptr) noexcept {
        delete m_ptr;
        m_ptr = ptr;
    }
    
    T* release() noexcept {
        T* tmp = m_ptr;
        m_ptr = nullptr;
        return tmp;
    }
    
};
