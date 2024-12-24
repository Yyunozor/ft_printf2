# ft_printf - A Custom Printf Implementation

A buffered, modular implementation of printf with support for essential format specifiers.

## 📋 Features

- Buffered output for improved performance
- Supports format specifiers: %c, %s, %p, %d, %i, %u, %x, %X, %%
- Modular design with separate handlers for different format types
- Error handling and buffer overflow protection

## 🔧 Technical Details

### Core Structure

```c
typedef struct s_printf
{
    va_list args;        // Variable arguments list
    char    buffer[128]; // Internal buffer for output
    int     buf_index;   // Current position in buffer
    int     total_len;   // Total characters printed
    char    type;        // Current format specifier
} t_printf;
```

### Buffer Management

The implementation uses a 128-byte buffer to minimize system calls:

- `init_printf()`: Initializes buffer and counters
- `flush_buffer()`: Writes buffer contents to stdout
- `add_to_buffer()`: Manages buffer filling with overflow protection

### Format Handlers

#### Character and String (`%c`, `%s`)
- Direct character output
- String output with null pointer protection

#### Pointer Address (`%p`)
- Outputs "0x" prefix
- Converts address to hexadecimal
- Special handling for null pointers

#### Integer Types (`%d`, `%i`, `%u`)
- Signed integer support
- Unsigned integer support
- Negative number handling

#### Hexadecimal (`%x`, `%X`)
- Lowercase hex output
- Uppercase hex output
- Uses custom base conversion

## 🛠️ Function Reference

### Main Function
```c
int ft_printf(const char *format, ...);
```
- Returns: Total characters printed or -1 on error
- Thread-safe: No
- Buffered: Yes

### Core Utilities
```c
void init_printf(t_printf *p);
int flush_buffer(t_printf *p);
int add_to_buffer(t_printf *p, const char *str, int len);
```

### Format Handlers
```c
int handle_format(t_printf *p, char type);
int handle_numbers(t_printf *p, char type);
int convert_nb(unsigned long n, const char *base, int blen, t_printf *p);
```

## 🔍 Implementation Details

### Buffer System
The buffering system improves performance by:
1. Reducing system calls
2. Grouping multiple characters
3. Handling overflow automatically

### Number Conversion
- Uses recursive base conversion
- Supports bases up to 16
- Handles edge cases (MIN_INT, null pointers)

### Error Handling
- Buffer overflow protection
- NULL pointer checks
- Write error detection

## 🚀 Usage

```c
#include "ft_printf.h"

int main(void)
{
    // Basic string
    ft_printf("Hello, %s!\n", "world");
    
    // Numbers
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    
    // Pointers
    int *ptr = NULL;
    ft_printf("Pointer: %p\n", ptr);
    
    return (0);
}
```

## 🏗️ Building

```bash
make        # Compile library
make clean  # Remove objects
make fclean # Full clean
make re     # Rebuild
```

## ⚠️ Limitations

- No floating point support
- No field width or precision
- No flags (#, 0, -, +, space)

## 📚 Dependencies

- libft (custom C library)
- Standard C libraries
