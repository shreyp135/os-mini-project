# Basic Shell – Operating System Mini Project

This project is a very simple implementation of a UNIX-like shell (command interpreter) written in C. It demonstrates how real shells like bash, zsh, and sh internally work at the OS-level using system calls.

The purpose of this project is educational:
- Understanding process creation using `fork()`
- Executing programs using `execvp()`
- Synchronizing using `wait()`
- Parsing user commands
- Using low-level operating system concepts

This shell supports:
- Running any Linux command
- Multiple arguments
- Exit command
- Simple looping shell prompt
