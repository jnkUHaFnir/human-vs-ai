if (pSomeObject != nullptr) 
{
    delete pSomeObject;
    pSomeObject = nullptr;
}
``` 

By setting the pointer to nullptr after deletion, you ensure that any accidental access to the pointer will result in a clear indication of invalid memory access.
