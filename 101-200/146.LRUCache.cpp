#include <list>
#include <unordered_map>


using namespace std;

// (key) (pointer-> )

// pointer --> value
typedef int keyt;
typedef int valt;
class LRUCache
{
  public:
    LRUCache(int capacity)
    {
        buff2 = list<pair<int, int>>();
        cap = capacity;
        cache = unordered_map<int, list<pair<keyt, valt>>::iterator>();
    }
    list<pair<keyt, valt>> buff2;
    int cap;
    unordered_map<int, list<pair<keyt, valt>>::iterator> cache;

    int get(int key)
    {
        auto it = cache.find(key);

        if (it == cache.end())
            return -1;
        else
        {
            list<pair<keyt, valt>>::iterator valueref = it->second;
            int v = (*valueref).second;
            int k = (*valueref).first;
            buff2.erase(valueref);
            buff2.push_front(make_pair(k, v));
            it->second = buff2.begin();
            return v;
        }
    }

    void put(int key, int value)
    {
        if (get(key) != -1)
        {
            buff2.begin()->second = value;
        }
        else
        {
            if (buff2.size() == cap)
            {

                keyt oldk = buff2.back().first;
                buff2.pop_back();
                cache.erase(cache.find(oldk));
            }
            buff2.push_front(make_pair(key, value));
            cache[key] = buff2.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
    LRUCache cache = LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);    // returns 1
    cache.put(3, 3); // evicts key 2
    cache.get(2);    // returns -1 (not found)
    cache.put(4, 4); // evicts key 1
    cache.get(1);    // returns -1 (not found)
    cache.get(3);    // returns 3
    cache.get(4);    // returns 4

    return 0;
}