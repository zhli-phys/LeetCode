/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        root = &nestedList;
        it = nestedList.begin();
        if (it != root->end() && !it->isInteger())
            nit = new NestedIterator(it->getList());
        else
            nit = NULL;
    }
    
    ~NestedIterator() {
        if (nit)
            delete nit;
    }
    
    int next() {
        while (nit && !nit->hasNext()) {
            delete nit;
            it++;
            if (it != root->end() && !it->isInteger())
                nit = new NestedIterator(it->getList());
            else 
                nit = NULL;
        }
        if (nit)
            return nit->next();
        else {
            int temp = it->getInteger();
            it++;
            if (it != root->end() && !it->isInteger())
                nit = new NestedIterator(it->getList());
            return temp;
        }
    }
    
    bool hasNext() {
        while (it != root->end() && nit && !nit->hasNext()) {
            delete nit;
            it++;
            if (it != root->end() && !it->isInteger())
                nit = new NestedIterator(it->getList());
            else 
                nit = NULL;
        }
        if (it == root->end())
            return false;
        else
            return true;
    }
    
private:
    vector<NestedInteger>* root;
    vector<NestedInteger>::iterator it;
    NestedIterator* nit;    //When it->isInterger() == true, nit = NULL
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */