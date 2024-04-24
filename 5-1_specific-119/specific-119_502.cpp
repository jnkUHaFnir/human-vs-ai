// Delete a pointer without NULL check
delete pSomeObject;
pSomeObject = NULL; // Set the pointer to NULL to avoid double deletion and avoid dangling pointers
