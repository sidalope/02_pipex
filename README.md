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
# Clone and navigate to project directory
cd 02_pipex

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
# Count lines in a file
./pipex infile "cat" "wc -l" outfile
# Equivalent to: < infile cat | wc -l > outfile

# Search and count
./pipex infile "grep test" "wc -w" outfile
# Equivalent to: < infile grep test | wc -w > outfile

# List files and filter
./pipex infile "ls -l" "grep pipex" outfile
# Equivalent to: < infile ls -l | grep pipex > outfile
```

### Command Parsing

Commands are parsed to handle arguments correctly:
- Input: `"ls -l"` → Executable: `/bin/ls`, Args: `["ls", "-l", NULL]`
- Input: `"grep -i test"` → Executable: `/usr/bin/grep`, Args: `["grep", "-i", "test", NULL]`

PATH resolution is performed automatically to find executables.

## Testing

### Automated Testing

Run the test suite to compare pipex output with shell behavior:

```bash
./tests.sh
```

The test script:
- Creates test input files
- Runs pipex and shell equivalents side-by-side
- Uses `diff` to verify outputs match
- Tests basic operations, error handling, edge cases, and exit codes

### Manual Testing

```bash
# Create test input
echo -e "hello world\nthis is a test\ntesting pipex" > infile

# Run pipex
./pipex infile "cat" "wc -l" outfile

# Compare with shell equivalent
< infile cat | wc -l > expected
diff outfile expected

# Should produce no output if identical
```

### Memory Leak Testing

```bash
valgrind --leak-check=full --show-leak-kinds=all \
    ./pipex infile "cat" "wc -l" outfile
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

### Error Handling

Behavior matches shell pipelines:
- **Non-existent input file**: Error message to stderr, second command still runs
- **Command not found**: Exit code 127, error message to stderr
- **Permission denied**: Error message to stderr, appropriate exit code
- **Invalid arguments**: Usage message and non-zero exit code

### Process Synchronization

- Use `waitpid` to wait for both child processes
- Parent collects exit statuses to determine overall result
- Prevents zombie processes
- Final exit code reflects last command's exit status (shell behavior)

## Project Structure

```
02_pipex/
├── Makefile              # Build configuration
├── pipex.h               # Header file with function prototypes
├── pipex.c               # Main program logic
├── *.c                   # Implementation files
├── tests.sh              # Automated test suite
├── tests_2.sh            # Comprehensive test suite with detailed output
└── README.md             # This file
```

## Technical Challenges

1. **File descriptor management**: Ensuring all unused FDs are closed to prevent deadlocks
2. **PATH resolution**: Finding executables in PATH while handling edge cases
3. **Error handling**: Matching shell behavior precisely in all error scenarios
4. **Memory management**: Proper cleanup in both success and error paths
5. **Process lifecycle**: Correct fork/exec/wait patterns to avoid zombies

## Bonus Features

### Multiple Pipes

Handle any number of commands:
```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
# Equivalent to: < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

### Here-doc Support

Support heredoc syntax with append mode:
```bash
./pipex here_doc LIMITER cmd1 cmd2 file
# Equivalent to: cmd1 << LIMITER | cmd2 >> file
```

## Resources

### Man Pages
- `man pipe` - Create pipe
- `man fork` - Create child process
- `man execve` - Execute program
- `man dup2` - Duplicate file descriptor
- `man waitpid` - Wait for process to change state
- `man access` - Check file accessibility

### Concepts
- [Unix Pipes Explained](https://www.rozmichelle.com/pipes-forks-dups/)
- Process creation and IPC in Unix
- File descriptor redirection
- Shell pipeline mechanics

## Notes

- Must compile with `-Wall -Wextra -Werror`
- Must follow 42 School norm (The Norm)
- No memory leaks tolerated
- No unexpected crashes (segfault, bus error, etc.)
- Handles errors same way as shell equivalent command

---

*42 School Project - pipex*
