# vscode-try-hiredis-gcc-9-ubuntu

Container for VS Code Remote (https://aka.ms/vscode-remote) for development using the hiredis library (https://github.com/redis/hiredis)

## Compile the original example

You can see the original examples at https://github.com/redis/hiredis/blob/master/examples

Download one of them 

```bash
wget https://raw.githubusercontent.com/redis/hiredis/master/examples/example.c
```

Fix `#include <hiredis.h>`

```bash
sed -i 's%<hiredis.h>%<hiredis/hiredis.h>%g' example.c
```

Compile the example

```bash
gcc example.c -lhiredis
```

Run it.

```bash
./a.out redis
```

## Working with github

Look at [Using SSH keys](https://code.visualstudio.com/docs/remote/containers#_using-ssh-keys)

You need to execute the git command in the terminal to add github.com to the list of known hosts in the container. For example, you can run git fetch.

```bash
git fetch
```


