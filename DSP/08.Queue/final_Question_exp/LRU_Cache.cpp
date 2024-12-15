//캐시 교체 알고리즘(LRU Cache)
#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cache; // {key, value}
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;

        // Move accessed element to the front
        auto it = cacheMap[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        cacheMap[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update existing key
            auto it = cacheMap[key];
            cache.erase(it);
            cache.push_front({key, value});
            cacheMap[key] = cache.begin();
        } else {
            if (cache.size() == capacity) {
                // Remove the least recently used element
                auto last = cache.back();
                cacheMap.erase(last.first);
                cache.pop_back();
            }
            // Add new element
            cache.push_front({key, value});
            cacheMap[key] = cache.begin();
        }
    }
};

int main() {
    LRUCache cache(2); // Capacity: 2
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << "\n"; // 1
    cache.put(3, 3); // Removes key 2
    std::cout << cache.get(2) << "\n"; // -1
    cache.put(4, 4); // Removes key 1
    std::cout << cache.get(1) << "\n"; // -1
    std::cout << cache.get(3) << "\n"; // 3
    std::cout << cache.get(4) << "\n"; // 4
    return 0;
}