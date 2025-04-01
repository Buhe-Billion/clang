;DESCRIPTION		:	This is a trivial program that greets the user in German upon invocation
;
;Architecture : X86-64
;CPU          : Intel® Core™2 Duo CPU T6570 @ 2.10GHz × 2
;NASM         : 2.14.02
;

SECTION .data

SYS_WRITE_CALL_VAL EQU 1
STDERR_FD          EQU 2
SYS_READ_CALL_VAL  EQU 0
STDIN_FD           EQU 0
STDOUT_FD          EQU 1
EXIT_SYSCALL       EQU 60
OK_RET_VAL         EQU 0
EOF_VAL						 EQU 0
EOL                EQU 10

BEGRUESSUNG DB "Guten Tag! Wie geht's? Ich hoffe alles laeuft gut bei dir! Bis dann, Servus",EOL
BEGRUESSUNGLENGTH EQU $-BEGRUESSUNG

SECTION .text

GLOBAL _start

_start:

PUSH RBP
MOV RBP,RSP
AND RSP,-16		;	Prolog and stack frame set up

NOP   ;i have nested the program between NOP intructions for asthetic reasons

MOV RAX,SYS_WRITE_CALL_VAL
MOV RDI,STDOUT_FD
MOV RSI,BEGRUESSUNG
MOV RDX,BEGRUESSUNGLENGTH
SYSCALL

NOP

MOV RSP,RBP
POP RBP

MOV RAX,EXIT_SYSCALL
MOV RDI,OK_RET_VAL
SYSCALL                     ;Auf Wiedersehen
