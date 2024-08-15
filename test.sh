rm -f out*
make
ls -la Makefile | ls -la > out
#valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all ./pipex Makefile "ls" "ls" outfile
./pipex Makefile "ls -la" "ls -la" outfile
echo '\n'
echo "RESULTAT: SHELL"
cat out
echo '\n'
echo "RESULTAT: PIPEX"
cat outfile