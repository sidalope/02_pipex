# Pipex

A 42 School project that recreates the Unix pipe mechanism by implementing shell pipeline behavior using system calls.

## Description

**pipex** mimics the behavior of shell pipelines by connecting two commands through a pipe, reading from an input file and writing to an output file.

```bash
./pipex file1 cmd1 cmd2 file2
```

This behaves exactly like the shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

## How Pipes Work

Unix pipes are a fundamental inter-process communication (IPC) mechanism that allows the output of one process to flow directly into the input of another.

**Key concepts:**
- **Pipe**: A unidirectional data channel with a read end and write end
- **Fork**: Creates child processes that inherit file descriptors from the parent
- **Dup2**: Redirects standard input/output to different file descriptors
- **Execve**: Replaces a process image with a new program

**Process flow:**
1. Parent creates a pipe (two file descriptors: read and write ends)
2. Parent forks two child processes
3. First child redirects stdin from file1, stdout to pipe write end, executes cmd1
4. Second child redirects stdin from pipe read end, stdout to file2, executes cmd2
5. Parent waits for both children to complete

## Installation

```bash
# Compile
make

# Clean object files
make clean

# Remove all generated files
make fclean

# Recompile from scratch
make re
```

## Usage

### Basic Examples

```bash
./pipex infile "cat" "wc -l" outfile
# Equivalent to: < infile cat | wc -l > outfile

./pipex infile "grep test" "wc -w" outfile
# Equivalent to: < infile grep test | wc -w > outfile

./pipex infile "ls -l" "grep pipex" outfile
# Equivalent to: < infile ls -l | grep pipex > outfile
```

## Implementation Details

### File Descriptor Management

Critical to avoid deadlocks and resource leaks:
- Each process closes unused pipe ends
- Parent closes both pipe ends after forking
- Children close pipe ends they don't use before `execve`

### PATH Resolution

Since `execve` requires absolute paths:
1. Extract PATH environment variable
2. Split by `:` delimiter
3. For each directory, test if `directory/command` exists and is executable
4. Return first valid path or error if command not found

### Process Synchronization

- Use `waitpid` to wait for both child processes
- Parent collects exit statuses to determine overall result
- Prevents zombie processes
- Final exit code reflects last command's exit status (shell behavior)


## Resources

### Use of AI
- Generating an initial README
- Repeating the given test pattern for given test cases

### Known Tutorials On The Topic
- [Handling a File by its Descriptor in C - Codequoi](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Pipe: an Inter-Process Communication Method - Codequoi](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/)
- [Unix Pipes Explained](https://www.rozmichelle.com/pipes-forks-dups/)

### Man Pages
- `man pipe` - Create pipe
- `man fork` - Create child process
- `man execve` - Execute program
- `man dup2` - Duplicate file descriptor
- `man waitpid` - Wait for process to change state
- `man access` - Check file accessibility



---

*42 School Project - pipex*
