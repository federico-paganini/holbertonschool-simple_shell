# 🎰 Simple Shell

Simple Shell is a minimal command-line interpreter developed by **Federico Paganini** and **Bruno Barrera**.

## 🧰 Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [File Structure](#file-structure)
- [How It Works](#how-it-works)
- [Authors](#authors)
- [License](#license)

---

## ✨ Features

- **Interactive Mode** with a custom prompt (`#cisfun$`).
- Handling of extra spaces and empty commands.
- Tokenization of command and arguments.
- Search for executables in the `$PATH` environment variable.
- Support for absolute and relative paths.
- Clear error messages when a command is not found or cannot be executed.

## 🧪 Requirements

- POSIX-compliant operating system (e.g., Linux, macOS).
- **GCC** (or any C-compatible compiler).

## 🛠 Installation

Clone the repository and navigate into it:

```bash
$ git clone https://github.com/yourusername/simple_shell.git
$ cd simple_shell
```

Compile the project with recommended flags:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

## 👩‍💻 Usage

Launch the shell executable:

```bash
$ ./simple_shell
```

You will see the prompt:

```bash
#cisfun$
```

To exit the shell, you can:

- Type `exit` and press **Enter**.
- Press **Ctrl+D** (EOF).

---

## 🧠 Project Logic

Below is a diagram that explains the main flow of the application:

![Beige Colorful Minimal Flowchart Infographic Graph](https://github.com/user-attachments/assets/89af0e7d-b67d-4079-8b6c-6144a9db987a)

## 📋 Examples

### Running a command with a full path

```bash
#cisfun$ /bin/ls
Path: /bin/ls
```

### 🗃 Running a command by searching `$PATH`

```bash
#cisfun$ ls
Path: /usr/bin/ls
```

---

## 🧱 File Structure

- **gates_of_shell.c**: Contains `main()`, which runs the shell loop.
- **input_handler.c**: Displays the prompt, reads the input line, and splits it into tokens.
- **interpreter.c**: Determines if the command includes a path or needs to be searched in `$PATH`, and validates it.
- **utils.c**: Helper functions to count words and free allocated memory.
- **shell.h**: Header file with library includes and function prototypes.

---

## 🎡 How It Works

1. **Initialization**: `main()` sets up structures and enters an infinite loop.
2. **Prompt**: If in interactive mode, displays `#cisfun$`.
3. **Read Input**: `get_line()` reads the entire input line.
4. **Tokenize**: `tokenize_line()` trims extra spaces and creates an array of arguments.
5. **Interpret**: `interpreter()` checks for a provided path or searches directories in `$PATH`.
6. **Result**: Prints the absolute path of the executable or an error message.
7. **Loop**: Continues until receiving `exit` or EOF.

---

## ✒ Authors

- **Federico Paganini**
- **Bruno Barrera**

---


