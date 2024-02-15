// #include <iostream>
// #include <map>
// #include <random>

// // Your interval_map implementation here...
// #include <map>
// template<typename K, typename V>
// class interval_map {
// 	friend void IntervalMapTest();
// 	V m_valBegin;
// 	std::map<K,V> m_map;
// public:
// 	// constructor associates whole range of K with val
// 	interval_map(V const& val)
// 	: m_valBegin(val)
// 	{}

// 	// Assign value val to interval [keyBegin, keyEnd).
// 	// Overwrite previous values in this interval.
// 	// Conforming to the C++ Standard Library conventions, the interval
// 	// includes keyBegin, but excludes keyEnd.
// 	// If !( keyBegin < keyEnd ), this designates an empty interval,
// 	// and assign must do nothing.
// 	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
// 		if (!(keyBegin < keyEnd)) {
// 			return; // Empty interval, do nothing
// 		}

// 		// Remove entries in the interval [keyBegin, keyEnd) from m_map
// 		auto itBegin = m_map.lower_bound(keyBegin);
// 		auto itEnd = m_map.lower_bound(keyEnd);

// 		m_map.erase(itBegin, itEnd);

// 		// Insert the new value for the interval [keyBegin, keyEnd)
// 		m_map[keyBegin] = val;
// 		m_map[keyEnd] = m_valBegin;

// 		// Check and fix canonicity
// 		auto it = m_map.begin();
// 		auto prevIt = it++;

// 		while (it != m_map.end()) {
// 			if (prevIt->second == it->second) {
// 				it = m_map.erase(it);
// 			} else {
// 				prevIt = it;
// 				++it;
// 			}
// 		}

// 	}

// 	// look-up of the value associated with key
// 	V const& operator[]( K const& key ) const {
// 		auto it=m_map.upper_bound(key);
// 		if(it==m_map.begin()) {
// 			return m_valBegin;
// 		} else {
// 			return (--it)->second;
// 		}
// 	}
// };

// // Test function
// void testIntervalMap() {
//     // Seed for random number generation
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(-100, 100);

//     // Create interval_map
//     interval_map<int, char> testMap('A');

//     // Ground truth using std::map
//     std::map<int, char> groundTruth;

//     // Perform random assignments and update ground truth
//     for (int i = 0; i < 1000; ++i) {
//         int keyBegin = dis(gen);
//         int keyEnd = keyBegin + dis(gen) + 1;  // Ensure keyEnd > keyBegin
//         char value = 'A' + dis(gen) % 26;  // Random character

//         // Update interval_map
//         testMap.assign(keyBegin, keyEnd, value);

//         // Update ground truth
//         for (int key = keyBegin; key < keyEnd; ++key) {
//             groundTruth[key] = value;
//         }
//     }

//     // Verify correctness using operator[]
//     for (const auto& kv : groundTruth) {
//         int key = kv.first;
//         char expectedValue = kv.second;

//         char actualValue = testMap[key];

//         if (actualValue != expectedValue) {
//             std::cerr << "Test failed at key " << key << ": Expected '" << expectedValue
//                       << "', got '" << actualValue << "'" << std::endl;
//         }
//     }

//     std::cout << "Test completed." << std::endl;
// }

// int main() {
//     // Run the test
//     testIntervalMap();

//     return 0;
// }
