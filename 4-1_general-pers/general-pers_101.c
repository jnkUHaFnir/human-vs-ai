#include <stdarg.h>
#include <stddef.h>

#ifdef _WIN32
	#include <windows.h>
#else
	#include <stdio.h>
#endif

// Define the thunk function
void thunk(void* funcPtr, int numArgs, ...) {
#ifdef _WIN32
	// Windows x86 calling convention: __stdcall
	__asm {
		mov eax, numArgs
		push eax
		mov ebx, funcPtr

		// Loop to push arguments onto the stack in reverse order
		mov edx, esp
		mov ecx, [esp+8] // Retrieve the first argument (variadic arguments start at the 2nd parameter)
		push ecx
		dec eax

		add edx, 12 // Move stack pointer past numArgs and funcPtr
	thunk_loop:
		test eax, eax
		jz thunk_call // Jump to the function call when all arguments have been pushed
		mov ecx, [edx+eax*4]
		push ecx
		dec eax
		jmp thunk_loop
	thunk_call:
		call ebx
	}
#else
	// Unix x64 calling convention: System V AMD64 ABI
	__asm__ __volatile__(
	"mov %0, %%rax;"
	"mov %1, %%rdi;"
	"mov %2, %%rsi;"
	"mov %3, %%rdx;"
	"mov %4, %%rcx;"
	"call *%5;" 
	:
	: "g" (numArgs), "g" (va_arg(args, int)), "g" (va_arg(args, int)), "g" (va_arg(args, int)), "g" (va_arg(args, int)), "g" (funcPtr)
	: "rax", "rdi", "rsi", "rdx", "rcx"
	);
#endif
}

// Example usage
void exampleFunction(int a, int b) {
#ifdef _WIN32
	OutputDebugStringA("Example thunked function called on Windows");
#else
	printf("Example thunked function called on Unix\n");
#endif
}

int main() {
	thunk(exampleFunction, 2, 10, 20); // Thunking exampleFunction with 2 arguments
	return 0;
}
