# ifndef UTILS_QOWINFOISDNFV
#define UTILS_QOWINFOISDNFV

extern const int ERROR_CODE;
extern const char END;

// Quits with the exit code, and prints a formatted error message to the command line
void quit(int code, char *message);

// Returns the next token from standard input, along with
char *nexttok(int *c, int *size);

#endif
