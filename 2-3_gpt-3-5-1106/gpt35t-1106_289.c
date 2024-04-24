
In this corrected version, we are using `std::remove_if` to move all the elements we want to delete to the end of the vector, and then using `v->erase` to remove them all at once. This way, we avoid the issue with invalidating the iterator.
