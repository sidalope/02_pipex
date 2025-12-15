#!/bin/bash

# Setup test files
cat > infile << 'EOF'
hello world
this is a test
multiple lines here
testing pipex
more content
EOF

touch empty_file

echo "Simple cat | wc -l"
./pipex infile "cat" "wc -l" outfile
< infile cat | wc -l > expected
diff outfile expected

echo "Cat | wc -c (character count)"
./pipex infile "cat" "wc -c" outfile
< infile cat | wc -c > expected
diff outfile expected

echo "grep 1"
./pipex infile "cat" "grep test" outfile
< infile cat | grep test > expected
diff outfile expected

echo "Grep case insensitive"
./pipex infile "cat" "grep -i TESTING" outfile
< infile cat | grep -i TESTING > expected
diff outfile expected

echo "Grep | wc -l (count matches)"
./pipex infile "grep test" "wc -l" outfile
< infile grep test | wc -l > expected
diff outfile expected

echo "Cat | head -n 2"
./pipex infile "cat" "head -n 2" outfile
< infile cat | head -n 2 > expected
diff outfile expected

echo "Empty file | cat | wc -l"
./pipex empty_file "cat" "wc -l" outfile
< empty_file cat | wc -l > expected
diff outfile expected

echo "Wc with multiple flags"
./pipex infile "cat" "wc -lwc" outfile
< infile cat | wc -lwc > expected
diff outfile expected

echo "Grep no matches"
./pipex infile "cat" "grep nonexistent_pattern" outfile
< infile cat | grep nonexistent_pattern > expected
diff outfile expected

echo ""
echo "--- ERRORS ---"
echo

echo "Non-existent input file"
./pipex no_such_file "cat" "wc" outfile
< no_such_file cat | wc > expected
echo

echo "First command not found"
./pipex infile "invalid_cmd_first" "wc -l" outfile
< infile invalid_cmd_first | wc -l > expected
echo

echo "Permission denied file"
touch deny_file
chmod 000 deny_file
./pipex deny_file "cat" "wc" outfile
< deny_file cat | wc > expected
chmod 600 deny_file
rm -f deny_file
echo

echo "Successful execution"
./pipex infile "cat" "wc -l" outfile >/dev/null
echo "Exit code: $?"
echo

echo "Command not found as last command"
./pipex infile "cat" "invalid_command_xyz" outfile >/dev/null
echo "Exit code: $?"
echo

echo "Wrong number of arguments"
./pipex infile "cat" 2>/dev/null
echo "Exit code: $?"
echo
