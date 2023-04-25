class SmallestInfiniteSet {
public:
    int i;
    set<int> s;
    SmallestInfiniteSet() {
        i = 1;
    }
    
    int popSmallest() {
        if(s.size() == 0){
            i++;
            return i - 1;
        }
        auto it = s.begin();
        int x = *it;
        if(x < i){
            s.erase(it);
            return x;
        } else if(x > i){
            i++;
            return i - 1;
        } 
        s.erase(it);
        i++;
        return x;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */