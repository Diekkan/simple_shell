# A simple shell.

## hsh 
hsh is a really simple implementation for a shell, for this shell we design somefunctions like, ls(to print list), env(to print the enviroment root), exit (to leave th shell), and some others.

## Usage
all the files need being compiled with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
after compile, write 
```
./hsh 
```
to excute.

to exit write .... command 

## builts - in
```
env
```
Print the environment.
``` 
exit
```
exit the shell, closing the programm.

## functions used

* read_input
* tokenizer
* tokenize_path
* find_exec
* pathtokens_to_list
* inputtoken_to_list
* exec_identifier
* run_exec
* env_builtin
* verify_builtin
* exit_builtin
