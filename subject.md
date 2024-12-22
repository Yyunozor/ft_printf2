# **Subject_ft_printf**

> Because ft_putnbr() and ft_putstr() aren’t enough.
> 

---

### **Summary**

The goal of this project is simple but impactful: **recreate the `printf()` function**. Through this project, you’ll explore the use of **variadic functions** in C, which allows functions to accept a variable number of arguments. This is a powerful feature, and learning it will significantly expand your C programming skills.

**Version**: 10

---

## **Contents**

- **I. Introduction**
- **II. Common Instructions**
- **III. Mandatory Part**
- **IV. Bonus Part**
- **V. Submission and Peer Evaluation**

---

## **Chapter I: Introduction**

In this project, you’ll implement one of the most popular and versatile C functions: `printf()`. This exercise provides an excellent opportunity to sharpen your programming abilities. It has a **moderate difficulty** level.

Through this project, you’ll:

- Learn about **variadic functions** in C.
- Focus on building **well-structured and extensible code** for maximum functionality.

Upon completion, you can incorporate your `ft_printf()` function into your `libft` library, making it reusable for future school projects.

---

## **Chapter II: Common Instructions**

- **Language**: Your project must be written in **C**.
- **Norm Compliance**: Your code must adhere to the **Norm**. Any errors, including in bonus files, will result in a score of zero.
- **Error Handling**: Functions must not crash (segmentation faults, bus errors, etc.). Any such errors during evaluation will result in a zero score.
- **Memory Management**: All **heap-allocated memory** must be freed appropriately. **No memory leaks** are allowed.
- **Makefile Requirements**:
    - Must compile your source files with flags `Wall`, `Wextra`, and `Werror`.
    - Should contain the rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
    - Bonuses must be managed in separate files (`_bonus.c/h`) if not otherwise specified and compiled with a `bonus` rule in the Makefile.
- **Library Requirement**: If you’re allowed to use `libft`, copy its source files and Makefile into a `libft` folder.
- **Testing**: While not required for submission, creating test programs is highly recommended to verify your code’s functionality. These tests will be beneficial during your defense.
- **Git Submission**: Submit your code via your assigned Git repository. Only the code in the Git repository will be evaluated.

---

## **Chapter III: Mandatory Part**

- **Program Name**: `libftprintf.a`
- **Required Files**: `Makefile`, `.h`, `.c`
- **Required Makefile Rules**: `NAME`, `all`, `clean`, `fclean`, `re`
- **Authorized Functions**:
    - `malloc`, `free`, `write`
    - `va_start`, `va_arg`, `va_copy`, `va_end` (for handling variadic arguments)
- **Libft Integration**: **Yes**, you can use your `libft` library.

### **Objective**

Create a library that includes `ft_printf()`, a function mimicking the original `printf()`.

### **Prototype**

```c
int ft_printf(const char *, ...);

```

### **Requirements**

- Do not implement **buffer management** like the original `printf`.
- Support the following **conversions**:
    - `%c`: Prints a single character.
    - `%s`: Prints a string.
    - `%p`: Prints a pointer in hexadecimal format.
    - `%d` and `%i`: Print a decimal (base 10) integer.
    - `%u`: Prints an unsigned decimal (base 10) number.
    - `%x` and `%X`: Print a hexadecimal number in lowercase and uppercase.
    - `%%`: Prints a literal `%` sign.
- Use **`ar`** to create your library (using `libtool` is prohibited).
- The `libftprintf.a` file should be located at the root of your repository.

---

## **Chapter IV: Bonus Part**

While you are not required to implement the bonuses, here’s what they entail if you choose to take on the challenge:

### **Bonus Features**

- **Flags**: Handle any combination of these flags: `'-'`, `'0'`, `'.'`, and **field minimum width** for all conversions.
- **Additional Flags**: Manage `'#'`, `' '`, and `'+'`.

> Note: It’s highly recommended to plan for these bonuses from the beginning to ensure a smooth integration. A “naive” approach may lead to difficulties if you add them later.
> 

### **Evaluation Criteria**

The bonus part will only be assessed if the **mandatory part is perfect**. This means:

- All mandatory requirements are fully implemented.
- The program operates without any issues.

---

## **Chapter V: Submission and Peer Evaluation**

Submit your project in your Git repository as usual. Only the work within your repository will be graded. Double-check file names and other requirements before submission.

Once you pass this project, you’re allowed to add `ft_printf()` to your `libft`, making it reusable in other school projects.

---
