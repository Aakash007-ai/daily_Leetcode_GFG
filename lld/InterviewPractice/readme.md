LRU Cache

least recently used cache
value which used last will removed first

so we have to initialize cache with a capacity
put will put that value to corresponding key
get will return ,

both must be done in
O(1)

when we do get , in order to get in o(1) we must use a hash list to get that value
when we do put,
new element must be reorderd in o(1), so update of an element and insertion of element , deletion of old element must be happen in o(1) space , so we use double linked list
