// Last updated: 3/4/2026, 1:09:42 AM
1public class LRUCache {
2    public class Entry {
3        public int key;
4        public int val;
5        public Entry(int k, int v) { key=k; val=v; }
6    }
7
8    public LinkedList<Entry> ll_;
9    public Dictionary<int, LinkedListNode<Entry>> dict_ = new Dictionary<int, LinkedListNode<Entry>>();
10    public int capacity_;
11
12    public LRUCache(int capacity) {
13        ll_ = new LinkedList<Entry>();
14        capacity_ = capacity;
15    }
16    
17    public int Get(int key) {
18        if (!dict_.ContainsKey(key)) {
19            return -1;
20        }
21
22        int value = dict_[key].Value.val;
23        ll_.Remove(dict_[key]);
24        dict_.Remove(key);
25
26        ll_.AddFirst(new Entry(key, value));
27        dict_[key] = ll_.First;
28
29        return value;
30    }
31    
32    public void Put(int key, int value) {
33        if (dict_.ContainsKey(key)) {
34            ll_.Remove(dict_[key]);
35            dict_.Remove(key);
36        } else if (!dict_.ContainsKey(key)) {
37            if (capacity_ == 0) {
38                dict_.Remove(ll_.Last.Value.key);
39                ll_.RemoveLast();
40            } else {
41                capacity_--;
42            }
43        }
44        
45        ll_.AddFirst(new Entry(key, value));
46        dict_[key] = ll_.First;
47    }
48}
49
50/**
51 * Your LRUCache object will be instantiated and called as such:
52 * LRUCache obj = new LRUCache(capacity);
53 * int param_1 = obj.Get(key);
54 * obj.Put(key,value);
55 */