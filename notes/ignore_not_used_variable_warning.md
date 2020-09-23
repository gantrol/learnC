https://stackoverflow.com/questions/8071579/hide-gcc-warning-set-but-not-used

- a file: `#pragma GCC diagnostic ignored "-Wunused-but-set-variable"`
- a variable: `(void)list;` or `__attribute__((unused))`