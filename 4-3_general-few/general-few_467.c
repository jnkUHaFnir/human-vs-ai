
Additionally, I noticed you have incorrect memory deallocation in your cleaning section. You should not delete the pointers that point to memory allocated with `calloc`. Instead of using `delete`, you should use `free` to properly deallocate memory allocated with `calloc`.

Here is the corrected cleaning section:

```c++
free(m_d3ddm);
m_d3ddev->Release();
m_d3d->Release();
