#include <map>
#include <iostream>
#include <random>

template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K, V> m_map;

public:
    // constructor associates whole range of K with val
    interval_map(V const& val) : m_valBegin(val) {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.

    void assign(K const& keyBegin, K const& keyEnd, V const& val) {
        if (!(keyBegin < keyEnd)) {
            return; // Empty interval, do nothing
        }

        // Remove entries in the interval [keyBegin, keyEnd) from m_map
        auto itBegin = m_map.lower_bound(keyBegin);
        auto itEnd = m_map.lower_bound(keyEnd);

        m_map.erase(itBegin, itEnd);

        // Insert the new value for the interval [keyBegin, keyEnd)
        m_map[keyBegin] = val;
        m_map[keyEnd] = m_valBegin;

        // Check and fix canonicity
        auto it = m_map.begin();
        auto prevIt = it++;

        while (it != m_map.end()) {
            if (prevIt->second == it->second) {
                it = m_map.erase(it);
            } else {
                prevIt = it;
                ++it;
            }
        }
    }

    void assign1(K const& keyBegin, K const& keyEnd, V const& val) {
    if (!(keyBegin < keyEnd)) { // Handle empty interval
        return;
    }

    // Find the lower bound iterator for keyBegin
    auto it_lower = m_map.lower_bound(keyBegin);

    // Handle cases involving m_valBegin
    if (it_lower == m_map.begin() && val == m_valBegin) {
        // Extend the initial interval
        return;
    } else if (it_lower == m_map.begin()) {
        // Update m_valBegin and erase any overlapping entries
        m_valBegin = val;
        m_map.erase(m_map.begin(), it_lower);
    } else {
        // Adjust the value of the preceding interval if needed
        if (val == (--it_lower)->second) {
            ++it_lower;
        } else {
            it_lower->second = val;
        }
    }

    // Find the upper bound iterator for keyEnd
    auto it_upper = m_map.upper_bound(keyEnd);

    // Erase any existing overlapping intervals
    m_map.erase(it_lower, it_upper);

    // Insert the new interval if necessary
    if (keyEnd != it_upper->first) {
        m_map.insert({keyEnd, it_upper->second});
    }
}

    // look-up of the value associated with key
    V const& operator[](K const& key) const {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin()) {
            return m_valBegin;
        } else {
            return (--it)->second;
        }
    }
};

// Test function
void IntervalMapTest() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-100, 100);

    interval_map<int, char> M('A');

    std::map<int, char> groundTruth;

    for (int i = 0; i < 1000; ++i) {
        int keyBegin = dis(gen);
        int keyEnd = keyBegin + dis(gen) + 1;
        char value = 'A' + dis(gen) % 26;

        M.assign(keyBegin, keyEnd, value);

        for (int key = keyBegin; key < keyEnd; ++key) {
            groundTruth[key] = value;
        }
    }

    for (const auto& kv : groundTruth) {
        int key = kv.first;
        char expectedValue = kv.second;

        char actualValue = M[key];

        if (actualValue != expectedValue) {
            std::cerr << "Test failed at key " << key << ": Expected '" << expectedValue
                      << "', got '" << actualValue << "'" << std::endl;
        }
    }

    std::cout << "Test completed." << std::endl;
}

int main() {
    IntervalMapTest();

    return 0;
}
