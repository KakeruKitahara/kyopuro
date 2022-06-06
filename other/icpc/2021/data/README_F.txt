Problem F has multiple answers for a single input dataset.  The provided
answer files are examples of correct answers.  A program to judge if an
answer is correct or not (validator program) is also provided.  

F_validator.c is the source code of a validator.
This validator takes one command line arguments: the input dataset, such as F1.
It inputs the solution of the program from the standard input.
The judge result is returned as the exit status of the program; 0 means
correct and 1 means wrong answer.

Example:
(Assume your program is solve_F.py, and F_validator.c is compiled
to F_validator.)
$ python solve_F.py F1 | ./F_validator F1
$ echo $?
(If the answer is correct, 0 is printed. Otherwise 1 is printed.)

