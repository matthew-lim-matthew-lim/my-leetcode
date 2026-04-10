// Last updated: 4/10/2026, 6:46:07 PM
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define BMI2 __attribute__((target("bmi2")))
#define INL_ATTR noexcept INL HOT
#define OUTL_ATTR noexcept HOT
#define LAM_ATTR INL HOT noexcept

#pragma GCC optimize("fast-math","no-stack-protector")

#pragma GCC diagnostic ignored "-Wshift-op-parentheses"
#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wvla-cxx-extension"
#pragma GCC diagnostic ignored "-Wunqualified-std-cast-call"

template <class K, class T, size_t max_size, uint8_t bucket_bits, class KeyHash = std::hash<K>>
class static_flat_hash_map {
public:
    typedef pair<K, T> value_type;
    typedef value_type *iterator;

    static constexpr K ZERO_VAL = K(1) << (sizeof(K) * 8 - 1);
    // static constexpr K ZERO_VAL { 0, 0, 0, 0, 1ull << 63 };
    static constexpr K RM_VAL = __builtin_constant_p((K)0xdeadbeefdeadbeefull) ? (K)0xdeadbeefdeadbeefull : (K)0xdeadbeefdeadbeefull;
    // static constexpr K RM_VAL { 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull, 0xdeadbeefdeadbeefull };

    static bool equal(const K &km, const K &ku) INL_ATTR {
        return km && (km == ZERO_VAL ? K(0) : km) == ku;
    }

    static bool equal_or_free(const K &km, const K &ku) INL_ATTR {
        return !km || (km == ZERO_VAL ? K(0) : km) == ku;
    }

    static bool valid(const K &km) INL {
        return km && km != RM_VAL;
    }

    static K unmask(const K &km) INL {
        return km == ZERO_VAL ? 0 : km;
    }

    static constexpr size_t min_cap = 16u;

    static constexpr size_t getcap(size_t size) INL_ATTR {
        return size <= min_cap ? min_cap : 1ull << (64u - __builtin_clzll(size - 1u));
    }

    static constexpr size_t cap = getcap(max_size);

private:
    value_type storage[cap];
    size_t limit;
    size_t count;

    static size_t hash(const K &k) INL_ATTR {
        return KeyHash()(k);
    }

    value_type *locate(const K &k) OUTL_ATTR {
        const size_t h = (hash(k) << bucket_bits) & (limit - 1);
        size_t i = h;
        while (i < limit && !equal_or_free(storage[i].first, k)) i++;
        if (i >= limit) {
            i = 0;
            while (i < h && !equal_or_free(storage[i].first, k)) i++;
        }
        return storage + i;
    }

public:

    value_type *locate_ins(const K &k) OUTL_ATTR {
        const size_t h = (hash(k) << bucket_bits) & (limit - 1);
        size_t i = h;
        size_t f = h;
        while (i < limit && !equal_or_free(storage[i].first, k)) {
            if (f == h && storage[i].first == RM_VAL) f = i;
            i++;
        }
        if (i >= limit) i = 0;
        while (i < h && !equal_or_free(storage[i].first, k)) {
            if (f == h && storage[i].first == RM_VAL) f = i;
            i++;
        }
        return storage + (f == h | equal(storage[i].first, k) ? i : f);
    }

    static_flat_hash_map() INL_ATTR: limit(cap), count(0) {}

    bool contains(const K &k) INL_ATTR {
        value_type *p = locate(k);
        return equal(p->first, k);
    }

    iterator find(const K &k) INL_ATTR {
        value_type *p = locate(k);
        return p;
    }

    iterator insert(iterator p, const value_type &v) INL_ATTR {
        p->first = v.first ? v.first : ZERO_VAL;
        p->second = v.second;
        count++;
        return p;
    }

    iterator insert(const value_type &v) INL_ATTR {
        auto p = locate_ins(v.first);
        return equal(p->first, v.first) ? p : insert(p, v);
    }

    T &operator[](const K &k) INL_ATTR {
        auto p = locate_ins(k);
        if (!equal(p->first, k))
            insert(p, pair(k, T()));
        return p->second;
    }

    bool erase(iterator p) INL_ATTR {
        auto n = p + 1 < storage + limit ? p + 1 : storage;
        p->first = n->first ? RM_VAL : 0;
        count--;
        return true;
    }

    bool erase(const K &k) INL_ATTR {
        auto p = locate(k);
        const bool er = equal(p->first, k) ? erase(p) : false;
        return er;
    }

    void clear() INL_ATTR {
        fill(storage, storage + limit, value_type());
        count = 0;
    }

    void setlimit(const size_t l) INL_ATTR {
        limit = getcap(l);
    }

    size_t getlimit() const INL_ATTR {
        return limit;
    }

    size_t size() const INL_ATTR {
        return count;
    }

    const value_type *data() INL_ATTR {
        return storage;
    }
};

class EventManager {
private:
    static constexpr uint M = 1'000'000'000, N = 100'000, INF = N * 2, SH = 30;

    struct shift_hasher {
        static uint operator()(const uint k) INL_ATTR {
            const uint64_t p = k * 0xcc9e2d51ull;
            return p >> 23;
        }
    };

    typedef static_flat_hash_map<uint,uint,N,1,shift_hasher> map_t;
    typedef uint64_t T;

    static T prievt[N];
    static map_t evtpri;
    static uint n;

    template <class T>
    static T iif(const bool cond, const T x, const T y) noexcept __attribute__((always_inline, hot)) {
        return cond ? x : y;
    }

    static uint64_t pack(const uint p, const uint e) INL_ATTR {
        return (uint64_t(M - p) << SH) + e;
    }

    // push to min-4-ary-heap
    static void push(const uint m) OUTL_ATTR {
        using T = remove_reference<decltype(*prievt)>::type;
        for (uint i = m - 1, j = i - 1 >> 2; i; i = j, j = i - 1 >> 2) {
            const T u = prievt[i], v = prievt[j];
            prievt[j] = min(u, v);
            prievt[i] = max(u, v);
        }
    }

    // sift an element one level down
    static uint sift(const uint i, uint j, const uint m) OUTL_ATTR {
        const T u = prievt[i];
        T z = prievt[j];
        uint k = j;
        if (const T fit = ++j < m, v = prievt[iif(fit, j, i)]; fit & v < z) {
            z = v;
            k = j;
        }
        if (const T fit = ++j < m, v = prievt[iif(fit, j, i)]; fit & v < z) {
            z = v;
            k = j;
        }
        if (const T fit = ++j < m, v = prievt[iif(fit, j, i)]; fit & v < z) {
            z = v;
            k = j;
        }
        prievt[i] = min(u, z);
        prievt[k] = max(u, z);
        return u > z ? k : INF;
    }

    // pop from a min-4-ary-heap
    static void pop(uint m) OUTL_ATTR {
        *prievt = prievt[--m];
        for (uint i = 0, j = (i << 2) + 1; j < m; j = (i << 2) + 1)
            i = sift(i, j, m);
    }

    static void heapify(const uint m) OUTL_ATTR {
        for (uint k = m + 2 >> 2; k--; )
            for (uint i = k, j = (i << 2) + 1; j < m; j = (i << 2) + 1)
                i = sift(i, j, m);
    }

    static void purge() OUTL_ATTR {
        while (n) {
            const uint e = *prievt & (1u << SH) - 1,
                       p = M - (*prievt >> SH);
            const auto it = evtpri.find(e);
            if (map_t::equal(it->first, e) & it->second == p)
                break;
            pop(n--);
        }
    }

public:
    EventManager(const vector<vector<int>> &events) INL_ATTR {
        evtpri.setlimit(events.size());
        uint n = 0;
        for (const auto &e : events) {
            prievt[n++] = pack(e[1], e[0]);
            evtpri[e[0]] = e[1];
        }
        heapify(n);
        EventManager::n = n;
    }
    
    static void updatePriority(const uint eventId, const uint newPriority) INL_ATTR {
        const auto pit = evtpri.find(eventId);
        const uint oldp = pit->second;
        prievt[n++] = pack(newPriority, eventId);
        push(n);
        pit->second = newPriority;
        purge();
    }
    
    static int pollHighest() INL_ATTR {
        purge();
        if (!n)
            return -1;
        const uint e = *prievt & (1u << SH) - 1,
                   p = M - (*prievt >> SH);
        pop(n--);
        evtpri.erase(e);
        purge();
        return e;
    }

    ~EventManager() INL_ATTR {
        evtpri.clear();
        n = 0;
    }
};

EventManager::T EventManager::prievt[N];
EventManager::map_t EventManager::evtpri;
uint EventManager::n;

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */

static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();