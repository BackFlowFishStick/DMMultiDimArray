//
// Created by Danmeng on 2024/6/30.
//

#ifndef DMMULTIDIMARRAY_DM_ARRAY_H
#define DMMULTIDIMARRAY_DM_ARRAY_H

#include <stdint.h>
#include <cstdlib>

template <class T> class DM_Array{
private:
    T* p_arr;
    uint32_t size;
    uint32_t dim_0_size;
    uint32_t dim_1_size;
    bool is_multi_dim;

public:
    DM_Array(uint32_t size);
    DM_Array(uint32_t size_0, uint32_t size_1);
    ~DM_Array();
    void swap(const uint32_t index_0, const uint32_t index_1, bool& is_success);
    void swap(const uint32_t x, const uint32_t y, const uint32_t x_1, const uint32_t y_1, bool& is_success);
    void set(const uint32_t index, const T value, bool& is_success);
    void set(const uint32_t index_0, const uint32_t index_1, const T value, bool& is_success);
    void get(const uint32_t index_0, const uint32_t index_1, T& result, bool& is_success);

    T operator[](uint32_t const& index);
    T operator[](uint32_t const& index_0, uint32_t const& index_1);
};


template<class T>
DM_Array<T>::DM_Array(uint32_t size) {
    this->p_arr = (T*)malloc(size * sizeof(T));
    if(this->p_arr != nullptr)
    {
        this->size = size;
        this->is_multi_dim = false;
        this->dim_0_size = size;
        this->dim_1_size = 0;
    }
    else
    {
        this->size = 0;
    }
}

template<class T>
DM_Array<T>::DM_Array(uint32_t size_0, uint32_t size_1) {
    this->p_arr = (T*)malloc((size_0 * size_1) * sizeof(T));
    if(this->p_arr != nullptr)
    {
        this->dim_0_size = size_0;
        this->dim_1_size = size_1;
        this->size = this->dim_0_size * this->dim_1_size;
        this->is_multi_dim = true;
    }
    else
    {
        this->size = 0;
        this->dim_0_size = 0;
        this->dim_1_size = 0;
    }
}

template<class T>
DM_Array<T>::~DM_Array() {
    free(this->p_arr);
}

template<class T>
void DM_Array<T>::swap(const uint32_t index_0, const uint32_t index_1, bool &is_success) {
    if(index_0 >= this->size || index_1 > this->size)
    {
        is_success = false;
        return;
    }

    auto temp = *(this->p_arr + index_0);

    *(this->p_arr + index_0) = *(this->p_arr + index_1);

    *(this->p_arr + index_1) = temp;

    is_success = true;
}

template<class T>
void DM_Array<T>::swap(const uint32_t x, const uint32_t y, const uint32_t x_1, const uint32_t y_1, bool& is_success) {

    if(x >= this->dim_0_size || y >= this->dim_1_size || x_1 >= this->dim_0_size || y_1 >= this->dim_1_size)
    {
        is_success = false;
        return;
    }

    auto temp = *(this->p_arr + (y * this->dim_1_size + x));

    *(this->p_arr + (y * this->dim_1_size + x)) = *(this->p_arr + (y_1 * this->dim_1_size + x_1));

    *(this->p_arr + (y_1 * this->dim_1_size + x_1)) = temp;

    is_success = true;
}


template<class T>
void DM_Array<T>::set(const uint32_t index, const T value, bool& is_success) {

    if(index <= this->size - 1)
    {
        *(this->p_arr + index) = value;
        is_success = true;
    }
    else
    {
        is_success = false;
    }
}

template<class T>
void DM_Array<T>::set(const uint32_t index_0, const uint32_t index_1, const T value, bool &is_success) {

    if((index_0 > this->dim_0_size - 1) || (index_1 > this->dim_1_size - 1))
    {
        is_success = false;
        return;
    }

    *(p_arr + (index_1 * this->dim_0_size + index_0)) = value;

    is_success = true;

}

template<class T>
void DM_Array<T>::get(const uint32_t index_0, const uint32_t index_1, T& result, bool& is_success) {
    if(this->size <= 0)
    {
        is_success = false;
        return;
    };
    if(index_0 > this->size - 1 || index_1 > this->size - 1)
    {
        is_success = false;
        return;
    }

    result = *(p_arr + (index_1 * this->dim_0_size + index_0));

}

template<class T>
T DM_Array<T>::operator[](uint32_t const& index) {
    if(this->size <= 0) return -1;
    if(index > this->size - 1) return -2;

    return *(p_arr + index);
}

template<class T>
T DM_Array<T>::operator[](const uint32_t &index_0, const uint32_t &index_1) {

    return *(p_arr + (index_1 * this->dim_0_size + index_0));
}



#endif //DMMULTIDIMARRAY_DM_ARRAY_H