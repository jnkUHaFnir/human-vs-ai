#include <memory>

std::unique_ptr<SomeObject> pSomeObject(new SomeObject);
// No need to manually delete or set to NULL
// When pSomeObject goes out of scope, SomeObject will be automatically deleted
