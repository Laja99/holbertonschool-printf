# holbertonschool-printf

A custom implementation of the C standard library **printf** function.

## Table of Contents
- [Description](#description)
- [Requirements](#requirements)
- [Features](#features)
- [File Overview](#file-overview)
- [Usage](#usage)
- [Output Example](#output-example)
- [Flowchart](#flowchart)
- [Testing](#testing)
- [Contributors](#contributors)

## Description
`_printf` is a recreation of the standard `printf` function in C.

This project demonstrates handling of:
- variadic functions using `va_list`, `va_start`, `va_end`
- format string parsing
- output formatting for multiple data types


## Requirements

- **Ubuntu 20.04 LTS**
- **GCC compiler**
- Compilation flags:
  ```
  -Wall -Werror -Wextra -pedantic -std=gnu89
  ```
- **Betty coding style**
- **No global variables**
- **Include guards** in all header files
It prints characters, strings, integers, and percent signs to **stdout**.

## Features
Currently supported format specifiers:

| Specifier | Description |
|-----------|-------------|
| `%c`      | Prints a character |
| `%s`      | Prints a string |
| `%%`      | Prints a percent sign |
| `%d`, `%i`| Prints a signed integer |

## File Overview

| File | Description |
|------|-------------|
| `README.md`     | Project documentation |
| `_printf.c`     | Core printf logic and format parsing |
| `functions.c`   | Helper functions for printing characters, strings, and integers |
| `main.h`        | Function prototypes, macros, include guards |
| `man_3_printf`  | Manual page for the `_printf` function |



---

## Usage

Example `main.c`:

```c
#include "main.h"

int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello");
    _printf("Integer: %d\n", 123);
    _printf("Percent: %%\n");

    return (0);
}
```


## Output Example

```
Character: A
String: Hello
Integer: 123
Percent: %
```

---
## Flowchart


## Testing

Run Betty:

```bash
betty *.c
```

Compile:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o _printf
$ ._printf

```

## Contributors

- **Layla**  
  GitHub: [@Laja99](https://github.com/Laja99)

- **Mohammed**  
  GitHub: [@MohammedError](https://github.com/MohammedError)
