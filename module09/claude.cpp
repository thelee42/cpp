#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

class PmergeMe {
private:
    std::vector<int> vec;
    
    // Jacobsthal 수열 생성
    std::vector<size_t> generateJacobsthal(size_t n) {
        std::vector<size_t> jacobsthal;
        jacobsthal.push_back(0);
        jacobsthal.push_back(1);
        
        size_t i = 2;
        while (jacobsthal[jacobsthal.size() - 1] < n) {
            size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
            jacobsthal.push_back(next);
            i++;
        }
        return jacobsthal;
    }
    
    // 이진 탐색으로 삽입 위치 찾기
    std::vector<int>::iterator binarySearch(std::vector<int>::iterator begin,
                                           std::vector<int>::iterator end,
                                           int value) {
        return std::lower_bound(begin, end, value);
    }
    
    // 두 값 중 작은 값 반환
    size_t min(size_t a, size_t b) {
        return (a < b) ? a : b;
    }
    
    // Ford-Johnson 알고리즘 구현
    void fordJohnson(std::vector<int>& arr) {
        if (arr.size() <= 1) return;
        
        // 1. 페어 만들기: (value, pair_index)
        std::vector<std::pair<int, int> > smaller;  // (작은값, 페어인덱스)
        std::vector<std::pair<int, int> > larger;   // (큰값, 페어인덱스)
        int straggler = -1;
        bool hasStraggler = false;
        
        for (size_t i = 0; i + 1 < arr.size(); i += 2) {
            int a = arr[i];
            int b = arr[i + 1];
            if (a > b) std::swap(a, b);
            
            int pairIndex = static_cast<int>(i / 2);
            smaller.push_back(std::make_pair(a, pairIndex));
            larger.push_back(std::make_pair(b, pairIndex));
        }
        
        if (arr.size() % 2 == 1) {
            straggler = arr[arr.size() - 1];
            hasStraggler = true;
        }
        
        // 2. 큰 값들로 재귀적으로 정렬
        std::vector<std::pair<int, int> > mainChain;
        std::vector<std::pair<int, int> > pending;
        
        if (larger.size() == 1) {
            mainChain.push_back(larger[0]);
            pending.push_back(smaller[0]);
        } else {
            // 큰 값들만 추출하여 재귀 정렬
            std::vector<int> largerValues;
            for (size_t i = 0; i < larger.size(); i++) {
                largerValues.push_back(larger[i].first);
            }
            
            fordJohnson(largerValues);
            
            // 정렬된 순서대로 mainChain 구성 (인덱스 유지)
            std::vector<bool> used(larger.size(), false);
            for (size_t i = 0; i < largerValues.size(); i++) {
                for (size_t j = 0; j < larger.size(); j++) {
                    if (!used[j] && largerValues[i] == larger[j].first) {
                        mainChain.push_back(larger[j]);
                        used[j] = true;
                        break;
                    }
                }
            }
            
            // mainChain의 인덱스 순서대로 pending 구성
            for (size_t i = 0; i < mainChain.size(); i++) {
                int pairIdx = mainChain[i].second;
                for (size_t j = 0; j < smaller.size(); j++) {
                    if (smaller[j].second == pairIdx) {
                        pending.push_back(smaller[j]);
                        break;
                    }
                }
            }
        }
        
        // 2-1. Straggler 추가
        if (hasStraggler) {
            pending.push_back(std::make_pair(straggler, -1));
        }
        
        // 3. 첫 번째 pending 원소는 맨 앞에 삽입
        if (!pending.empty()) {
            mainChain.insert(mainChain.begin(), pending[0]);
            pending.erase(pending.begin());
        }
        
        // 4. Jacobsthal 순서로 나머지 원소들 삽입
        if (!pending.empty()) {
            std::vector<size_t> jacobsthal = generateJacobsthal(pending.size());
            std::vector<bool> inserted(pending.size(), false);
            
            for (size_t i = 2; i < jacobsthal.size(); i++) {
                size_t current = jacobsthal[i];
                size_t prev = jacobsthal[i - 1];
                
                for (size_t j = min(current, pending.size()); j > prev && j > 0; j--) {
                    size_t idx = j - 1;
                    if (idx < pending.size() && !inserted[idx]) {
                        int valueToInsert = pending[idx].first;
                        int pairIndex = pending[idx].second;
                        
                        std::vector<std::pair<int, int> >::iterator searchEnd = mainChain.end();
                        
                        // 같은 페어 인덱스를 가진 큰 값의 위치 찾기
                        if (pairIndex != -1) {
                            for (std::vector<std::pair<int, int> >::iterator it = mainChain.begin(); 
                                 it != mainChain.end(); ++it) {
                                if (it->second == pairIndex) {
                                    searchEnd = it + 1;
                                    break;
                                }
                            }
                        }
                        
                        // 값만 추출하여 이진 탐색
                        std::vector<int> values;
                        for (std::vector<std::pair<int, int> >::iterator it = mainChain.begin();
                             it != searchEnd; ++it) {
                            values.push_back(it->first);
                        }
                        
                        std::vector<int>::iterator pos = binarySearch(values.begin(),
                                                                      values.end(),
                                                                      valueToInsert);
                        size_t insertPos = pos - values.begin();
                        
                        mainChain.insert(mainChain.begin() + insertPos, pending[idx]);
                        inserted[idx] = true;
                    }
                }
            }
            
            // 남은 원소들 삽입
            for (size_t i = 0; i < pending.size(); i++) {
                if (!inserted[i]) {
                    int valueToInsert = pending[i].first;
                    int pairIndex = pending[i].second;
                    
                    std::vector<std::pair<int, int> >::iterator searchEnd = mainChain.end();
                    
                    if (pairIndex != -1) {
                        for (std::vector<std::pair<int, int> >::iterator it = mainChain.begin(); 
                             it != mainChain.end(); ++it) {
                            if (it->second == pairIndex) {
                                searchEnd = it + 1;
                                break;
                            }
                        }
                    }
                    
                    std::vector<int> values;
                    for (std::vector<std::pair<int, int> >::iterator it = mainChain.begin();
                         it != searchEnd; ++it) {
                        values.push_back(it->first);
                    }
                    
                    std::vector<int>::iterator pos = binarySearch(values.begin(),
                                                                  values.end(),
                                                                  valueToInsert);
                    size_t insertPos = pos - values.begin();
                    
                    mainChain.insert(mainChain.begin() + insertPos, pending[i]);
                }
            }
        }
        
        // 5. 최종 결과를 arr에 복사 (값만)
        arr.clear();
        for (size_t i = 0; i < mainChain.size(); i++) {
            arr.push_back(mainChain[i].first);
        }
    }

public:
    PmergeMe(const std::vector<int>& input) : vec(input) {}
    
    void sort() {
        fordJohnson(vec);
    }
    
    void display() const {
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }
    
    const std::vector<int>& getVector() const {
        return vec;
    }
};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }
    
    std::vector<int> numbers;
    for (int i = 1; i < argc; i++) {
        int num = std::atoi(argv[i]);
        if (num < 0) {
            std::cerr << "Error: Negative number not allowed" << std::endl;
            return 1;
        }
        numbers.push_back(num);
    }
    
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    PmergeMe sorter(numbers);
    sorter.sort();
    
    std::cout << "After:  ";
    sorter.display();
    
    return 0;
}