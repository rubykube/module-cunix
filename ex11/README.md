## Mini Shell

### Objectives
* Learn about shell
* Implement a shell prompt '$> '
* Implement a shell built in : `echo`, `cd`, `pwd`, `env`, `export`, `exit`

### Actions
* Go to the course directory `cd cep/courses/cunix/ex11/`
* Read all files in include/ and the Makefile before starting anything
* Create a file called src/minishell.c. It should implement the functions above
* Use hash table from previous exercise to save your environment variable
##### Example
-----------------------------
| KEY      | VALUE           |
| ---      | ---             |
| PATH     | /usr/local/bin:/usr/bin:/bin:/usr/local/sbin |
| LANG     | en US.UTF-8     |
------------------------------


 * Use `make debug` to test your program for memory leaks and errors
 * Enter `make test` and see if your program works properly
 * After building the source, run `./minishell` from the project root to run your program
 * parse PATH by exploding ":" and build a tree or hash table to index all binary names with it's absolute path
 hash["date"] => '/usr/bin/date'
 * fork and exec('/usr/bin/date') wait and return prompt
 
 ```
1├─bash─┬
2       └─bash───exec───date
3├─bash─>
 ```
 
```
#### Example of minishell
$> export HELLO="world"
$> echo $HELLO
world
$> env
PATH: /usr/local/bin:/usr/bin:/bin:/usr/local/sbin
HELLO: world
$> cd /etc
$> ls
passwd ...
$> pwd
/etc
$> date
Thu 08 Aug 2019 06:18:11 PM EEST
$> /usr/bin/date
Thu 08 Aug 2019 06:18:11 PM EEST
$> exit
```

### Bonus
* Use `|`, `>`,`<` in your own minishell
* Alias

### Docs
* [Unix system calls](https://www.youtube.com/watch?v=xHu7qI1gDPA)
* [Tutorial - Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
* [Implementation of redirection and pipe operators in shell](http://www.sarathlakshman.com/2012/09/24/implementation-overview-of-redirection-and-pipe-operators-in-shell)
