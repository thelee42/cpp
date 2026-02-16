#include    "PmergeMe.hpp"
#include    <iostream>
#include    <sys/time.h>

int comp = 0;

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

        struct timeval start_vec, end_vec, start_deq, end_deq;
        gettimeofday(&start_vec, NULL);
        sort.fordJohnsonPair(sort.vec);
        gettimeofday(&end_vec, NULL);

        //std::cout << "Number of comparisons: " << comp << std::endl;

        gettimeofday(&start_deq, NULL);
        sort.fordJohnsonPair(sort.deq);
        gettimeofday(&end_deq, NULL);

        long time_vec = (end_vec.tv_sec - start_vec.tv_sec) * 1000000L + (end_vec.tv_usec - start_vec.tv_usec);
        long time_deq = (end_deq.tv_sec - start_deq.tv_sec) * 1000000L + (end_deq.tv_usec - start_deq.tv_usec);
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