	lddqu	xmm1, XMMWORD PTR [rcx]
	psubb	xmm1, xmm6
	pmovmskb ecx, xmm1
	mov	ecx, ecx               //useless, see @PeterCordes and @IwillnotexistIdonotexist
	add	rcx, rcx               //can be removed, see @EvgenyKluev
	pshufb	xmm1, XMMWORD PTR [r13+rcx*8]
	movdqa	xmm0, xmm8
	pmaddubsw xmm0, xmm1
	phaddw	xmm0, xmm0
	pshufb	xmm0, xmm7
	pextrd	eax, xmm0, 0