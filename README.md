```
███╗   ███╗██╗███╗  ██╗██╗  ████████╗ █████╗ ██╗     ██╗  ██╗
████╗ ████║██║████╗ ██║██║  ╚══██╔══╝██╔══██╗██║     ██║ ██╔╝
██╔████╔██║██║██╔██╗██║██║     ██║   ███████║██║     █████═╝
██║╚██╔╝██║██║██║╚████║██║     ██║   ██╔══██║██║     ██╔═██╗
██║ ╚═╝ ██║██║██║ ╚███║██║     ██║   ██║  ██║███████╗██║ ╚██╗
╚═╝     ╚═╝╚═╝╚═╝  ╚══╝╚═╝     ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝
```

# Minitalk

Minitalk is a project from the 42cursus that consists in creating a communication program between two processes. The goal is to create a client and a server that can communicate with each other using Unix signals.

## How to use

To use minitalk, you need to compile both the client and the server programs. Then, you can run the server program and get its PID. Finally, you can run the client program with the PID of the server as an argument, followed by the string you want to send.

Example:
```sh
$ ./server
██████╗███████╗██████╗ ██╗   ██╗███████╗██████╗
██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗
╚█████╗ █████╗  ██████╔╝╚██╗ ██╔╝█████╗  ██████╔╝
╚ ═══██╗██╔══╝  ██╔══██╗ ╚████╔╝ ██╔══╝  ██╔══██╗
██████╔╝███████╗██║  ██║  ╚██╔╝  ███████╗██║  ██║
╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
Server PID: 1234
```
```c
$ ./client 1234 "Hello, world!"
Sent	 :		14
Received :		14
```
