
This code creates a new dynamic array `tmp` that's one element larger than the existing one. It then copies the existing elements into `tmp` and adds the new element. It finishes by freeing the original dynamic array and returning `tmp`. 

Another important point is you cannot directly return `tmp->data`, because the returned address may be deallocated when `tmp` is destructed. This is because the destructor function `~Array2()` in `tmp` will call `free(this->data)`.

So I directly copy the memory from `this->data` to `tmp->data` and then free `this->data`, and return `tmp`. The memory `tmp->data` is still exist until `tmp` itself is deleted.
