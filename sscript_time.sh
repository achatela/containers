c++ -Wall -Werror -Wextra main.cpp; time ./a.out > ft; c++ -Wall -Werror -Wextra main_std.cpp; time ./a.out > std; diff ft std > diff_file; rm ft std; cat diff_file; rm diff_file;

