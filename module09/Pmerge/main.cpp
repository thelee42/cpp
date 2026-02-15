#include    "PmergeMe.hpp"
#include    <iostream>
#include    <ctime>

//int comp = 0;

int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cerr << "Error: need at least one number" << std::endl;
        return 1;
    }
    try {
        PmergeMe sort(av);
        std::cout << "    <Before>\nsequence: ";
        for (int i = 1; i < ac; i++) {
            if (i != 1)
                std::cout << " ";
            std::cout << av[i];
        }
        std::cout << std::endl;

        clock_t start_vec = clock();
        sort.fordJohnsonPair(sort.vec);
        clock_t end_vec = clock();

        //std::cout << "Number of comparisons: " << comp << std::endl;

        clock_t start_deq = clock();
        sort.fordJohnsonPair(sort.deq);
        clock_t end_deq = clock();

        double time_vec = static_cast<double>(end_vec - start_vec) * 1000000.0 / CLOCKS_PER_SEC;
        double time_deq = static_cast<double>(end_deq - start_deq) * 1000000.0 / CLOCKS_PER_SEC;
        std::cout << "    <After>" << std::endl;
        sort.printVec();
        sort.printDeq();
        std::cout << "Time to process a range of " << sort.vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
        std::cout << "Time to process a range of " << sort.deq.size() << " elements with std::deque : " << time_deq << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

//./PmergeMe $(jot -r 3000 1 100000)