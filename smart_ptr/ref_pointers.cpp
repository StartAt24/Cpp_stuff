// placeholder for different kinds of pointers.

template<type T>
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