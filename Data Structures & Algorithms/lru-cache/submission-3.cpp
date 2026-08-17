class LRUCache {
public:
// the main signature of this problem is using of list along with list or doubly linkedlist

    int capacity;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;

    LRUCache(int capacity) {
        this->capacity=capacity;    
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;

        auto it=m[key];
        l.splice(l.end(),l,it);
        return it->second;
    }
    
    void put(int key, int value) {
       if(m.find(key)!=m.end()){
        auto it=m[key];
        it->second=value;
        l.splice(l.end(),l,it);
        return;
       }

       l.push_back({key,value});
       m[key]=prev(l.end());

       if(l.size()>capacity){
        m.erase(l.begin()->first);
        l.pop_front();
       }
    }
};
