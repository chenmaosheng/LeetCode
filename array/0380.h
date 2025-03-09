#include <vector>
using namespace std;

/*
插入，删除和随机都要O(1)，那么插入删除都使用unordered_map，记录值和vector内的索引
随机O(1)必然是vector，删除vector如果要O(1)，只能把值swap后删除末尾值才能做到
swap之后要记录原索引，这样保持vector内的索引是不变的
*/
class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int index = m[val];
        m.erase(val);
        if (index != v.size() - 1) 
        {
            m[v[v.size()-1]] = index;
            swap(v[index], v[v.size()-1]);
        }
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        int index = rand() % v.size();
        return v[index];
    }

    unordered_map<int, int> m;
    vector<int> v;
};