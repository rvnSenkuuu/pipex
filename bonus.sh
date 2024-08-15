rm -f out*
make bonus
ls Makefile | ls | ls | ls >> out
#valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all ./pipex Makefile "ls" "ls" outfile
./pipex_bonus here_doc test "ls" "ls" "ls" "ls" outfile
echo '\n'
echo "RESULTAT: SHELL"
cat out
echo '\n'
echo "RESULTAT: PIPEX"
cat outfile