#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

int main() {
    // Vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // List (Doubly Linked List)
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // Stack
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    
    // Queue
    std::queue<int> que;
    que.push(1);
    que.push(2);
    
    // Deque
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_front(2);
    
    // Set
    std::set<int> s = {1, 2, 3, 4, 5};
    
    // Unordered Set
    std::unordered_set<int> us = {1, 2, 3, 4, 5};
    
    // Map
    std::map<int, std::string> m = {{1, "one"}, {2, "two"}};
    
    // Unordered Map
    std::unordered_map<int, std::string> um = {{1, "one"}, {2, "two"}};
    
    // Bitset
    std::bitset<8> bs(std::string("1101"));
    
    return 0;
}
