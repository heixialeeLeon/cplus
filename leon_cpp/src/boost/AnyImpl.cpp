#include <iostream>
#include <typeinfo>

class placeholder
{
public:
    virtual ~placeholder() {}
public:
    virtual const std::type_info& type_info() const = 0;
    virtual placeholder* clone() const = 0;
};

template<typename value_type>
class holder : public placeholder
{
public:
    holder(const value_type& value) : held(value) {}
    virtual const std::type_info& type_info() const { return typeid(value_type); }
    virtual placeholder* clone() const { return new holder(held); }
    const value_type held;
};

class Any
{
public:
    Any():content(0) {}
    Any(const Any& other):content(other.content? other.content->clone():0) {}
    //Any(const Any&& other):content(other.content? other.content->clone():0) {}
    ~Any() { delete content; }

    const std::type_info& type_info() const { return content ? content->type_info() : typeid(void); }

    template<typename value_type>
    Any(const value_type& value):content(new holder<value_type>(value)) {}

    Any& swap(Any& other) {
        std::swap(content, other.content);
        return *this;
    }

    Any& operator=(const Any& other) {
        Any tmp(other);
        swap(tmp);
    }

    template<typename value_type>
    Any &operator =(value_type other) {
        Any tmp(other);
        swap(tmp);
    }

    operator const void*() const { return content; }

    template<typename value_type>
    const value_type* to_ptr() const {
        return type_info() == typeid(value_type)? &static_cast<holder<value_type>*>(content)->held :0;
    }

    placeholder* content;
};

template<typename value_type>
value_type Any_cast(const Any& value){
    const value_type* result = value.to_ptr<value_type>();
    if(result)
        return *result;
    throw std::bad_cast();
}

template<typename value_type>
value_type* Any_cast(const Any* value){
    const value_type* result = value->to_ptr<value_type>();
    if(result)
        return const_cast<value_type*>(result);
    throw std::bad_cast();
}

class Customer
{
public:
    int aa;
    float bb;
};

int main()
{
    std::cout<<"hello world"<<std::endl;
    Any a = 10;
    Any b = a;
    std::cout<<"a type: "<<a.type_info().name()<<std::endl;
    Any c = Customer();
    std::cout<<"c type: "<<c.type_info().name()<<std::endl;
    int aa = Any_cast<int>(a);
    int* aaptr = Any_cast<int>(&a);
}
