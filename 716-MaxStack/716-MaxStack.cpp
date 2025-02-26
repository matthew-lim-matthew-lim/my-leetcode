using Pair = std::pair<int, size_t>;  // <num, timestamp>
class MaxStack {
  size_t timestamp;
  std::list<Pair> lst;  // grows up, front
  std::map<Pair, std::list<Pair>::iterator> tree;
public:
    MaxStack():timestamp(0) {}
    
    void push(int x) {  // O(log n)
      Pair pair = {x, timestamp++};
      lst.push_front(pair);
      tree.emplace(pair, lst.begin());
    }
    
    int pop() {  // O(log n)
      auto top = lst.front();
      tree.erase(top);
      lst.pop_front();
      return top.first;
    }
    
    int top() {  // O(1)
      return lst.front().first;
    }
    
    int peekMax() {  // O(1)
      return tree.rbegin()->first.first;
    }
    
    int popMax() {  // O(1)
      auto it = tree.rbegin()->second;
      int num = it->first;
      lst.erase(it);
      tree.erase(std::prev(tree.end()));
      return num;
    }
};