// Safely delete the pointer using the null pointer pattern
if (pSomeObject != nullptr) {
    delete pSomeObject;
    pSomeObject = nullptr;
}
