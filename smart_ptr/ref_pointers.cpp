// placeholder for different kinds of pointers.
class IRefBase{
public:
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

template<typename T>
class RefPointer{
public:
    RefPointer(T* ptr = nullptr){
        if(ptr){
            m_ptr = ptr;
        }
    }
private:
    T* m_ptr{nullptr};
};