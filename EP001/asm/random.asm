section .note.GNU-stack noalloc noexec nowrite

;;  This function generates a pseudo-random number between 0 and the number passed in rdi (first parameter).

section .data 
; We can think of structs as just data organized into a contiguous chunk of memory, so in order to generate the random number, let's make space for the struct timeval, which is 16 bytes long. After labeling these 16 bytes as the space for the timeval struct, we can call the syscall 96 to take the current time and place it into this space.
; struct timeval {long tv_sec; long tv_usec;} 

timeval: times 16 db 0
 
section .text
    global randomD

; input rdi
; output em rax
randomD:
    mov r9, rdi
    
    mov rax, 96
    mov rdi, timeval
    mov rsi, 0
    syscall

    mov rax, [timeval + 8]
    xor rdx, rdx
    mov ebx, r9d
    div ebx
    mov eax, edx
    ret
