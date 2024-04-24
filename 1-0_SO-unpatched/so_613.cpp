	#include <assert.h>
	#include <stdio.h>
	#include <Windows.h>
	void *__cdecl test(void *value, void *x, void *y, void *z, void *w, void *u)
	{
		if (u > 0) { test(value, x, y, z, w, (void *)((size_t)u - 1)); }
		printf("Test called! %p %p %p %p %p %p\n", value, x, y, z, w, u);
		return value;
	}
	struct Test
	{
		void *local;
		void *operator()(void *value, void *x, void *y, void *z, void *w, void *u)
		{
		    if (u > 0) { (*this)(value, x, y, z, w, (void *)((size_t)u - 1)); }
		    printf("Test::operator() called! %p %p %p %p %p %p %p\n", local, value, x, y, z, w, u);
		    return value;
		}
	};
	int main()
	{
		unsigned char thunk[1024]; unsigned long old;
		VirtualProtect(&thunk, sizeof(thunk), PAGE_EXECUTE_READWRITE, &old);
		void *args[] = { (void *)0xBAADF00DBAADF001, (void *)0xBAADF00DBAADF002 };
		void *(Test::*f)(void *value, void *x, void *y, void *z, void *w, void *u) = &Test::operator();
		Test obj = { (void *)0x1234 };
		assert(sizeof(f) == sizeof(void (*)()));  // virtual function are too big, they're not supported :(
		vbind(*(void *(**)())&f, 1 + 6, thunk, 1 + 1, args, sizeof(args) / sizeof(*args), true);
		((void *(*)(void *, int, int, int, int))&thunk)(&obj, 3, 4, 5, 6);
		vbind((void *(*)())test, 6, thunk, 1, args, sizeof(args) / sizeof(*args), false);
		((void *(*)(int, int, int, int))&thunk)(3, 4, 5, 6);
	}