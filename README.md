

# Pipex

<p align="center">
  <a href="">
    <img src="img/PIPEX.png" alt="pipex">
  </a>
</p>

# Table of Contents
- [Table of Contents](#table-of-contents)
- [0. Description](#0-description)
- [1. Requirements](#1-requirements)
- [2. How to execute the program](#2-How-to-execute-the-program)
- [3. Running Makefile](#3-running-makefile)

# 0. Description 

What is Pipex?

• This symbol redirects the standard output of one process to the standard input of another

• The Unix/Linux systems allow stdout of a command to be connected to stdin of another command. You can make it do so by using the pipe character ‘|’.

• The Pipe is a command in Linux that lets you use two or more commands such that output of one command serves as input to the next. In short, the output of each process directly as input to the next one like a pipeline. The symbol ‘|’ denotes a pipe

• Run 2 commands consecutively

# 1. Requirements

• You have to turn in a Makefile which will compile your source files. It must not relink.

• You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).

• Your program mustn’t have memory leaks.

• If you have any doubt, handle the errors like the shell command:
< cmd1 file1 | cmd2 > file2


# 2. How to execute the program


```sh
# Samples of commands
$> ./bin/pipex ./infile "cat" "wc -l" ./outfile

$> ./bin/pipex ./infile "cat" "grep a" ./outfile

$> ./bin/pipex ./infile "tr a X" "tr i o" ./outfile

# Command by terminal
$> < ./infile cat | wc -l > ./outfile

$> < ./infile cat | grep a > ./outfile

$> < ./infile tr a X | tr i o > ./outfile

```



# 3. Running Makefile

```sh
# Will generate a executable
$> make all

# Execute valgrind. Will check memory leaks
$> make leak

# will run norminette 
$> make norma

```

