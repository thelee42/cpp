#include <vector>
#include <algorithm>
#include <iostream>

struct element
{
    int valeur;
    std::vector<element*> loser;

    element(int v) : valeur(v){}
    ~element() {}
    void add_loser(element *l) {
        loser.push_back(l);
    }
    bool operator<(const element &other) const {
        return valeur < other.valeur;
    }
};

std::vector<int> jacobsthal_order(int n)
{
    std::vector<int> order;
    if (n < 1)
        return order;
    if (n == 1) 
    {
        order.push_back(0);
        return order;
    }
    std::vector<int> j;
    j.push_back(0);
    j.push_back(1);
    while (j.back() < n)
        j.push_back(j.back() + 2 * j[j.size() - 2]); //Jn = J[n - 1] + (2 * J[n - 2])
    int last = 0;
    for (size_t i = 1; i < j.size(); i++)
    {
        int current = std::min(j[i], n);
        for (int k = current; k > last; k--)
            order.push_back(k-1);
        last = current;
    }
    return order;    
}

// C++98 포인터 비교용 구조체
struct CompareElements {
    bool operator()(const element* a, const element* b) const {
        return a->valeur < b->valeur;
    }
};


void ford_johnson(std::vector<element*>& elements) {
    int single = 0;
    int n = elements.size();
    if (n < 2) 
        return;
    std::vector<element*> winners;
    for (int i = 0; i + 1 < n; i += 2) {
        if (elements[i]->valeur > elements[i + 1]->valeur)
            std::swap(elements[i], elements[i + 1]);
        elements[i + 1]->add_loser(elements[i]);
        winners.push_back(elements[i + 1]);
    }
    if (n % 2 == 1) // 따로 관리
        single = 1;

    // 3. winners 재귀 정렬
    ford_johnson(winners);

    std::vector<element*> mainChain;
    // 4. main chain 정렬
    element *b1 = winners[0]->loser.back();
    winners[0]->loser.pop_back();
    mainChain.push_back(b1);

    for(size_t i = 0; i < winners.size(); i++)
        mainChain.push_back(winners[i]);
    //5. Jacobsthal 순서로 나머지 losers 삽입
    std::vector<int> order = jacobsthal_order(winners.size() + single);
    for (size_t i = 0; i < order.size(); i++)
    {
        int pendingInd = order[i];
        if (pendingInd == 0)
            continue;
        element* pendingelement = NULL;
        std::vector<element*>::iterator searchEnd = mainChain.end();
        if (pendingInd < (int)winners.size())
        {
            pendingelement = winners[pendingInd]->loser.back();
            winners[pendingInd]->loser.pop_back();
            std::vector<element*>::iterator it = std::find(mainChain.begin(), mainChain.end(), winners[pendingInd]);
            if (it != mainChain.end())
                searchEnd = it;
        }
        else
            pendingelement = elements.back(); // single

        std::vector<element*>::iterator insert_pos = std::lower_bound(mainChain.begin(), searchEnd, pendingelement, CompareElements());
        mainChain.insert(insert_pos, pendingelement);
    }
    elements = mainChain; // 최종 정렬된 mainChain을 elements로 복사
}

/* 외부 인터페이스 */
void ford_johnson_element(std::vector<int>& v) {
    std::vector<element> pool;
    pool.reserve(v.size());
    for (size_t i = 0; i < v.size(); i++)
        pool.push_back(element(v[i]));

    std::vector<element*> elements;
    for (size_t i = 0; i < pool.size(); i++)
        elements.push_back(&pool[i]);

    ford_johnson(elements);

    //최종 정렬된 vector<int> 생성
    v.clear();
    for (size_t i = 0; i < elements.size(); ++i) {
        v.push_back(elements[i]->valeur);
    }
}


/* 테스트 */
int main(int argc, char* argv[]) {
    (void)argc; // argc는 사용하지 않음
    std::vector<int> data;
    for(int i = 1; argv[i]; i++)
    {
        for(size_t j = 0; j < std::strlen(argv[i]); j++)
        {
            if (!std::isdigit(argv[i][j]))
                throw std::runtime_error("Only positive integers are allowed");
        }
        long num = std::atol(argv[i]); //atoi is not safe -> use strtol to handle MAX/MIN_INT
        if (num > 2147483647)
            throw std::runtime_error("Number out of int range");
        data.push_back(static_cast<int>(num));
    }
    std::cout << "Size Before sorting:" << data.size() << std::endl;
    ford_johnson_element(data);
    std::cout << "Size After sorting:" << data.size() << std::endl;
    for (size_t i = 0; i < data.size(); ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}