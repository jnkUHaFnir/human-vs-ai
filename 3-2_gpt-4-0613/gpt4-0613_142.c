
In this code, we are adding elements 0 to 5 in priority queue and then we are following the logic to serve smallest element first, add it up with next smallest one and keep pushing it back to queue. If the elements are {0,1,2,3,4,5}, then after first run, priority queue will have {1,2,3,4,5,0} and result = 0. In the next run, priority queue will have {2,3,4,5,1} and result = 1, and so on.

This way you don't need to manage memory in c++ like we do in c.
This algorithm follows Heap sort approach and the time complexity will be O(n log(n)) where n is the number of elements.
