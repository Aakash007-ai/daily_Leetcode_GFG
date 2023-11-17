## points to remember

always think louder , first think how code flow
<br>then speak louder and code with it with repect to code flow

## coding learning

make_pair(x,y) or {x,y} is equivalent <br>
we can push_back in a vector which is initialized with no size, vector<int> v , c.push_back(0)<br>
sort(v.begin(),v.end()) \*\* sort in ascending order by default

## sorting and custom sort

<br>if we have vector of pair and we just sort it by default
<br> sort(p.begin(),p.end()); **sort vector of pairs first by first then by second **

<br> sort(p.begin(),p.end(),comp) , <i> comp </i> is just a normal function return bool with argument type of p[0]
<br> **\***first index ascending then descending
if(a.first<b.first) return true;
else if( a.first == b.first) return b.second < a.second;
return false;

<br> \*\*\*first index ascending other also ascending
//first index ascending then descending
if(a.first<b.first) return true;
else if( a.first == b.first) return b.second > a.second;
return false;

## priority queue

it is implementation of heap data structure <a href="https://www.geeksforgeeks.org/introduction-to-max-heap-data-structure/">more about heap data structure</a>
Max heap :-
In a Max-Heap the key present at the root node must be greater than or equal to among the keys present at all of its children.In a Max-Heap, the largest element is the first to be popped from the heap.<br>
Min Heap :-In a Min-Heap the key present at the root node must be less than or equal to among the keys present at all of its children.
In a Min-Heap, the smallest element is the first to be popped from the heap.<br>
priority_queue<int> qu; //priority queue with greater element at top by default so it is maxHeap

priority_queue <int, vector<int>, greater<int>> gq; //min heap as minimum element get pop out on top

‘int’ is the type of elements you want to store in the priority queue. In this case, it’s an integer. You can replace int with any other data type you need.

‘vector<int>’ is the type of internal container used to store these elements. std::priority_queue is not a container in itself but a container adopter. It wraps other containers. In this example, we’re using a vector, but you could choose a different container that supports front(), push_back(), and pop_back() methods.

‘greater<int>‘ is a custom comparison function. This determines how the elements are ordered within the priority queue. In this specific example,

greater<int> sets up a min-heap. It means that the smallest element will be at the top of the queue

## binary search stl

stl to binary_search
upper_bound
lower_bound

binary search with increasing or decreasing elements
