#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include<string.h>
#include <signal.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Defining Tokens and Buffsizes */
#define TOKEN_BUFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"
#define BUFSIZE 1024

/* Points to array of ptrs to strings called "environment" */
extern char **environ;

/**
 * struct data - contains all relevant data on runtime
 * @argv: the argument vector
 * @input: command line from the user
 * @args: tokens of the command line
 * @state: last state of the shell
 * @counter: lines counter
 * @my_environ: the environment variable
 * @pid: process ID of the shell
 */

typedef struct data
{
	char **argv;
	char *input;
	char **args;
	int state;
	int counter;
	char **my_environ;
	char *pid;
} data_myshell;

/**
 * struct seperator_list - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: this single linked list stores separators
 */

typedef struct seperator_list
{
	char separator;
	struct seperator_list *next;
} seperators;

/**
 * struct line_list - single linked line list
 * @line: command line
 * @next: next node
 * Description: this single linked list stores command lines
 */

typedef struct line_list
{
	char *line;
	struct line_list *next;
} fline_list;

/**
 * struct var_list1 - variable single linked list
 * @len_variable: length of the variable
 * @value: value of the variable
 * @len_value: length of the value
 * @next: next node
 * Description: this single linked list stores variables
 */

typedef struct var_list1
{
	int len_variable;
	char *value;
	int len_value;
	struct var_list1 *next;
} var_list;

/**
 * struct builtin_str - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @fp: data type function pointer.
 */

typedef struct builtin_str
{
	char *name;
	int (*fp)(data_myshell *datash);
} builtin_t;


/* Declaring all files and prototypes used in the simple shell project */

/* pry_lists.c */
seperators *add_sep_node(seperators **head, char sep);
void free_sep_list(seperators **head);
fline_list *add_line_node(fline_list **head, char *line);
void free_line_list(fline_list  **head);

/* sec_lists.c */
var_list *add_rvar_node(var_list **head, int lvar, char *val, int lval);
void free_var_list(var_list **head);

/* structure_functions.c */
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
int _strspn(char *s, char *accept);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);


/* memloc.c */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(void *new_ptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* 0_string.c */
char *_strdup(const char *s);
int _isdigit(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);


/* 1_string.c */
void string_rev(char *s);

/* syntax_error.c */
int char_repetitions(char *input, int i);
int error_sep(char *input, int i, char last);
int check_syntax_error(data_myshell *datash, char *input);
int first_char(char *input, int *i);
void print_syntax_error(data_myshell *datash, char *input, int i, int bool);


/* myshell_loop.c */
char *no_comment(char *in);
void myshell_loop(data_myshell *datash);

/* read_input_line.c */
char *read_input_line(int *n_eof);

/* spliter.c */
char *swap_char(char *input, int bool);
void add_nodes(seperators **head_s, fline_list **head_l, char *input);
void go_next(seperators **list_s, fline_list **list_l, data_myshell *datash);
int spliter_commands(data_myshell *datash, char *input);
char **split_line(char *input);

/* var_rep.c */
void check_env(var_list **h, char *in, data_myshell *data);
int check_vars(var_list **h, char *in, char *st, data_myshell *data);
char *replaced_input(var_list **head, char *input, char *new_input, int nlen);
char *var_rep(char *input, data_myshell *datash);

/* getline.c */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void bringline(char **lineptr, size_t *n, char *buffer, size_t j);


/* c_directory.c */
int c_directory(data_myshell *datash);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
int is_executable(data_myshell *datash);
int check_cmd_error(char *dir, data_myshell *datash);
char *_which(char *cmd, char **_envir);
int cmd_exec(data_myshell *datash);

/* 0_environ.c */
char *_getenv(const char *name, char **_environ);
int _env(data_myshell *datash);

/* 1_environ.c */
char *copy_info(char *name, char *value);
int _setenv(data_myshell *datash);
int _unsetenv(data_myshell *datash);
void set_env(char *name, char *value, data_myshell *datash);

/* c_dir.c */
void cd_dot(data_myshell *datash);
void cd_to(data_myshell *datash);
void cd_prev(data_myshell *datash);
void cd_home(data_myshell *datash);

/* cmd_line.c */
int cmd_line(data_myshell *datash);

/* get_builtin.c */
int (*get_builtin(char *cmd))(data_myshell *datash);

/* exit_myshell.c */
int exit_myshell(data_myshell *datash);

/* simple_stdlib.c */
int get_len(int n);
char *a_itoa(int n);
int _atoi(char *s);

/* 0_error.c */
char *strcat_cd(data_myshell *, char *, char *, char *);
char *error_not_found(data_myshell *datash);
char *error_exit_shell(data_myshell *datash);
char *get_error_cd(data_myshell *datash);

/* 1_error.c */
char *error_get_alias(char **args);
char *error_env(data_myshell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path(data_myshell *datash);

/* get_error.c */
int get_error(data_myshell *datash, int eval);

/* get_sigint.c */
void get_sigint(int sig);

/* 0_help.c */
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_general(void);
void help_exit(void);

/* 1_help.c */
void help(void);
void help_alias(void);
void help_cd(void);

/* get_help.c */
int get_help(data_myshell *datash);

#endif /* End of SHELL_H */

