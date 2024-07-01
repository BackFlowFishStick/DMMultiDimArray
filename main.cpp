#include <iostream>
#include "DM_Array.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    DM_Array<int> my_arr = DM_Array<int>(15, 15);

    for(int i = 0; i < 15; ++i)
    {
        for(int j = 0; j < 15; ++j)
        {
            bool is_success = false;
            my_arr.set(i, j, j, is_success);


            if(!is_success)
            {
                std::cout << "Set value failed." << std::endl;
            }

        }
    }

    bool is_swap_done = false;
    my_arr.swap(1, 13, 14, 11, is_swap_done);

    if(!is_swap_done)
    {
        std::cout << "Swapping is failed" << std::endl;
        return -1;
    }


    for(int i = 0; i < 15; ++i)
    {
        for(int j = 0; j < 15; ++j)
        {
            std::cout << "The value: " << my_arr[i, j] << std::endl;
        }
    }
    return 0;
}
