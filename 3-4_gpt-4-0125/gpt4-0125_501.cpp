delete pSomeObject;  // Safe even if pSomeObject is NULL
delete pSomeObject;
pSomeObject = NULL;  // or nullptr in C++11 and beyond

if (pSomeObject) {  // This will now safely evaluate to false.
    // Attempt to use pSomeObject would have been dangerous.
}
