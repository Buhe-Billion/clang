;DESCRIPTION                : Hello world using C fns in asm
;                           :
;                           :
;Architecture               : X86-64
;CPU                        : Intel® Core™2 Duo CPU T6570 @ 2.10GHz × 2
;NASM                       : 2.14.02
;GCC                        : gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
;
;
;------------------------------------------------------------------------------------------------------------------

[SECTION .data]

SYS_WRITE_CALL_VAL EQU 1
STDERR_FD          EQU 2
SYS_READ_CALL_VAL  EQU 0
STDIN_FD           EQU 0
STDOUT_FD          EQU 1
EXIT_SYSCALL       EQU 60
OK_RET_VAL         EQU 0
EOF_VAL						 EQU 0
EOL                EQU 10

BEGRUESSUNG DB "Guten Tag! Wie geht's? Ich hoffe alles laeuft gut bei dir! Bis dann, Servus",EOL,EOF_VAL

[SECTION .text]

EXTERN printf
GLOBAL main

main:
PUSH RBP            ;Alignment prolog
MOV RBP,RSP         ;Set up stack frame

MOV RDI,BEGRUESSUNG
XOR RAX,RAX
CALL printf

MOV RBP,RSP         ;Destroy stack frame before returning
POP RBP

RET
