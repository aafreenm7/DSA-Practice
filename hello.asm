section .data
    msg db"Hello World!",10;Define the message and new line
    len equ $-msg;Calculate the lenghth of the message
section .text
    global _start
_start:
mov rax,1 ;syscall number for write 1
mov rdi,1 ;file descriptor 1=stdout
mov rsi,msg   ;pointer to message
mov rdx,len    ;number of bytes to write 
syscall
;System call to exit the program
mov rax,60    ;syscall number for exit
mov rdi,0    ;exit status 0=success
syscall
