#ifndef MAIN_H
#define MAIN_H
int shell(char **envi, int prompt, char *prog);
int shell_exec(char **envi, char *prog, int prompt);
int exe(char **comand, char **envi, char *prog);
#endif
