class LRUCache {
public:
    int capacity;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> LRU;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(LRU.find(key)==LRU.end()) return -1;

        auto it=LRU[key];
        l.splice(l.end(),l,it); //dest,list,src
        return it->second;
    }
    
    void put(int key, int value) {
        if(LRU.find(key)!=LRU.end()){
            auto it=LRU[key];
            it->second=value;
            l.splice(l.end(),l,it);
            return;
        }

        l.push_back({key,value});
        LRU[key]=prev(l.end());

        if(l.size()>capacity){
            LRU.erase(l.begin()->first);
            l.pop_front();
        }
    }
};
