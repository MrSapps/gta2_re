.386 
.MODEL FLAT
.STACK

 
.DATA 

flt_5FE3BC      dd 0.000015258789


.CODE 

 ;  5409948
;org 5000000H

PUBLIC _clear
PUBLIC _Class_0x2C__ctor_4018A0

_clear PROC
	xor eax, eax
	xor ebx, ebx
	ret
_clear ENDP


_Class_0x2C__ctor_4018A0 proc
 arg_0 = dword ptr  4
	mov     eax, ecx
	push    esi
	mov     ecx, [esp+4+arg_0]
	xor     esi, esi
	mov     dx, [ecx+2]
	mov     [eax], dx
	mov     dx, [ecx+4]
	mov     [eax+2], dx
	mov     dx, [ecx+6]
	mov     [eax+4], dx
	mov     dx, [ecx+8]
	mov     [eax+6], dx
	mov     dx, [ecx+0Ah]
	mov     [eax+8], dx
	mov     dx, [ecx+0Ch]
	mov     [eax+0Ah], dx
	mov     dx, [ecx+0Eh]
	mov     [eax+0Ch], dx
	mov     edx, [ecx+10h]
	cmp     edx, esi
	jz      short loc_40194F

	fild    dword ptr [edx]
	pop     esi
	fmul    ds:flt_5FE3BC
	fstp    dword ptr [eax+10h]
	mov     edx, [ecx+10h]
	fild    dword ptr [edx+4]
	fmul    ds:flt_5FE3BC
	fstp    dword ptr [eax+14h]
	mov     edx, [ecx+10h]
	fild    dword ptr [edx+8]
	fmul    ds:flt_5FE3BC
	fstp    dword ptr [eax+18h]
	mov     edx, [ecx+10h]
	fild    dword ptr [edx+0Ch]
	fmul    ds:flt_5FE3BC
	fstp    dword ptr [eax+1Ch]
	mov     edx, [ecx+10h]
	fild    dword ptr [edx+10h]
	fmul    ds:flt_5FE3BC
	fstp    dword ptr [eax+20h]
	mov     edx, [ecx+10h]
	fild    dword ptr [edx+14h]
	fmul    ds:flt_5FE3BC
	fstp    dword ptr [eax+24h]
	mov     dx, [ecx+14h]
	mov     [eax+0Eh], dx
	mov     ecx, [ecx+1Ch]
	mov     [eax+28h], ecx
	retn    4
; ---------------------------------------------------------------------------
loc_40194F:
	mov     [eax+24h], esi
	mov     [eax+20h], esi
	mov     [eax+1Ch], esi
	mov     [eax+18h], esi
	mov     [eax+14h], esi
	mov     [eax+10h], esi
	mov     dx, [ecx+14h]
	pop     esi
	mov     [eax+0Eh], dx
	mov     ecx, [ecx+1Ch]
	mov     [eax+28h], ecx
	retn    4
_Class_0x2C__ctor_4018A0 endp

END
