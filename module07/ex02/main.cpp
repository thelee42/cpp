// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

#include <iostream>
#include "Array.hpp"

int main() {
    try {
        std::cout << "=== Test 1: Default constructor (empty array) ===" << std::endl;
        Array<int> emptyArray;
        std::cout << "Size: " << emptyArray.size() << std::endl;
        try {
            emptyArray[0] = 10; // 예외 기대
        } catch (std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test 2: Size constructor ===" << std::endl;
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 10;
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        }

        std::cout << "\n=== Test 3: Copy constructor and independence ===" << std::endl;
        Array<int> copyArr(arr);
        copyArr[0] = 999;
        std::cout << "copyArr[0]: " << copyArr[0] << std::endl;
        std::cout << "arr[0]: " << arr[0] << " (should not be 999)" << std::endl;

        std::cout << "\n=== Test 4: Assignment operator and independence ===" << std::endl;
        Array<int> assignArr;
        assignArr = arr;
        assignArr[1] = 888;
        std::cout << "assignArr[1]: " << assignArr[1] << std::endl;
        std::cout << "arr[1]: " << arr[1] << " (should not be 888)" << std::endl;

        std::cout << "\n=== Test 5: Out of bounds access (negative index) ===" << std::endl;
        try {
            arr[-1] = 5;
        } catch (std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test 6: Out of bounds access (index too large) ===" << std::endl;
        try {
            arr[10] = 5;
        } catch (std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test 7: Modify original and verify copies remain unchanged ===" << std::endl;
        arr[2] = 555;
        std::cout << "arr[2]: " << arr[2] << std::endl;
        std::cout << "copyArr[2]: " << copyArr[2] << " (should be old value)" << std::endl;
        std::cout << "assignArr[2]: " << assignArr[2] << " (should be old value)" << std::endl;

        std::cout << "\n=== Test 8: Size consistency check ===" << std::endl;
        std::cout << "arr.size(): " << arr.size() << std::endl;
        std::cout << "copyArr.size(): " << copyArr.size() << std::endl;
        std::cout << "assignArr.size(): " << assignArr.size() << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    return 0;
}