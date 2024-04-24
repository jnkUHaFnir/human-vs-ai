	#include <stddef.h>
	
	size_t vbind(
		void *(/* cdecl, stdcall, or thiscall */ *f)(), size_t param_count,
		unsigned char buffer[/* >= 128 + n * (5 + sizeof(int) + sizeof(void*)) */],
		size_t const i, void *const bound[], unsigned int const n)
	{
		unsigned char *p = buffer;
		unsigned char s = sizeof(void *);
		unsigned char const b = sizeof(int) == sizeof(void *) ? 2 : 3;  // log2(sizeof(void *))
		*p++ = 0x55;                                                                          // push     rbp
		if (b > 2) { *p++ = 0x48; } *p++ = 0x8B; *p++ = 0xEC;                                 // mov      rbp, rsp
		if (b > 2)
		{
		    *p++ = 0x48; *p++ = 0x89; *p++ = 0x4C; *p++ = 0x24; *p++ = 2 * s;                 // mov      [rsp + 2 * s], rcx
		    *p++ = 0x48; *p++ = 0x89; *p++ = 0x54; *p++ = 0x24; *p++ = 3 * s;                 // mov      [rsp + 3 * s], rdx
		    *p++ = 0x4C; *p++ = 0x89; *p++ = 0x44; *p++ = 0x24; *p++ = 4 * s;                 // mov      [rsp + 4 * s], r8
		    *p++ = 0x4C; *p++ = 0x89; *p++ = 0x4C; *p++ = 0x24; *p++ = 5 * s;                 // mov      [rsp + 5 * s], r9
		}
		if (b > 2) { *p++ = 0x48; } *p++ = 0xBA; *(*(size_t **)&p)++ = param_count;           // mov      rdx, <param_count>
		if (b > 2) { *p++ = 0x48; } *p++ = 0x8B; *p++ = 0xC2;                                 // mov      rax, rdx
		if (b > 2) { *p++ = 0x48; } *p++ = 0xC1; *p++ = 0xE0; *p++ = b;                       // shl      rax, log2(sizeof(void *))
		if (b > 2) { *p++ = 0x48; } *p++ = 0x2B; *p++ = 0xE0;                                 // sub      rsp, rax
		*p++ = 0x57;                                                                          // push     rdi
		*p++ = 0x56;                                                                          // push     rsi
		*p++ = 0x51;                                                                          // push     rcx
		*p++ = 0x9C;                                                                          // pushfq
		if (b > 2) { *p++ = 0x48; } *p++ = 0xF7; *p++ = 0xD8;                                 // neg      rax
		if (b > 2) { *p++ = 0x48; } *p++ = 0x8D; *p++ = 0x7C; *p++ = 0x05; *p++ = 0x00;       // lea      rdi, [rbp + rax]
		if (b > 2) { *p++ = 0x48; } *p++ = 0x8D; *p++ = 0x75; *p++ = 2 * s;                   // lea      rsi, [rbp + 10h]
		if (b > 2) { *p++ = 0x48; } *p++ = 0xB9; *(*(size_t **)&p)++ = i;                     // mov      rcx, <i>
		if (b > 2) { *p++ = 0x48; } *p++ = 0x2B; *p++ = 0xD1;                                 // sub      rdx, rcx
		*p++ = 0xFC;                                                                          // cld
		*p++ = 0xF3; if (b > 2) { *p++ = 0x48; } *p++ = 0xA5;                                 // rep movs [rdi], [rsi]
		for (unsigned int j = 0; j < n; j++)
		{
		    unsigned int const o = j * sizeof(p);
		    if (b > 2) { *p++ = 0x48; } *p++ = 0xB8; *(*(void ***)&p)++ = bound[j];           // mov      rax, <arg>
		    if (b > 2) { *p++ = 0x48; } *p++ = 0x89; *p++ = 0x87; *(*(int **)&p)++ = o;       // mov      [rdi + <iArg>], rax
		}
		if (b > 2) { *p++ = 0x48; } *p++ = 0xB8; *(*(size_t **)&p)++ = n;                     // mov      rax, <count>
		if (b > 2) { *p++ = 0x48; } *p++ = 0x2B; *p++ = 0xD0;                                 // sub      rdx, rax
		if (b > 2) { *p++ = 0x48; } *p++ = 0xC1; *p++ = 0xE0; *p++ = b;                       // shl      rax, log2(sizeof(void *))
		if (b > 2) { *p++ = 0x48; } *p++ = 0x03; *p++ = 0xF8;                                 // add      rdi, rax
		if (b > 2) { *p++ = 0x48; } *p++ = 0x8B; *p++ = 0xCA;                                 // mov      rcx, rdx
		*p++ = 0xF3; if (b > 2) { *p++ = 0x48; } *p++ = 0xA5;                                 // rep movs [rdi], [rsi]
		*p++ = 0x9D;                                                                          // popfq
		*p++ = 0x59;                                                                          // pop      rcx
		*p++ = 0x5E;                                                                          // pop      rsi
		*p++ = 0x5F;                                                                          // pop      rdi
		if (b > 2)
		{
		    *p++ = 0x48; *p++ = 0x8B; *p++ = 0x4C; *p++ = 0x24; *p++ = 0 * s;                 // mov      rcx, [rsp + 0 * s]
		    *p++ = 0x48; *p++ = 0x8B; *p++ = 0x54; *p++ = 0x24; *p++ = 1 * s;                 // mov      rdx, [rsp + 1 * s]
		    *p++ = 0x4C; *p++ = 0x8B; *p++ = 0x44; *p++ = 0x24; *p++ = 2 * s;                 // mov      r8 , [rsp + 2 * s]
		    *p++ = 0x4C; *p++ = 0x8B; *p++ = 0x4C; *p++ = 0x24; *p++ = 3 * s;                 // mov      r9 , [rsp + 3 * s]
		    *p++ = 0x48; *p++ = 0xB8; *(*(void *(***)())&p)++ = f;                            // mov      rax, <target_ptr>
		    *p++ = 0xFF; *p++ = 0xD0;                                                         // call     rax
		}
		else
		{
		    *p++ = 0xE8; *(*(ptrdiff_t **)&p)++ = (unsigned char *)f - (p + s);               // call     <fn_rel>
		}
		if (b > 2) { *p++ = 0x48; } *p++ = 0x8B; *p++ = 0xE5;                                            // mov      rsp, rbp
		*p++ = 0x5D;                                                                          // pop      rbp
		*p++ = 0xC3;                                                                          // ret
		return p - &buffer[0];
	}