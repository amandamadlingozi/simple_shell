# Simple_Shell

## Overview

Simple_Shell is a minimalist Unix-like command-line shell, implemented in C. It offers basic features for executing shell commands and managing processes. This README.md file provides an introduction to the Simple_Shell project, its features, and usage instructions.

## Table of Contents

1. [Features](#features)
2. [Usage](#usage)
3. [Building Simple_Shell](#building-simple_shell)


## Features

Simple_Shell provides essential functionalities:

- Command Execution: Execute shell commands via the command prompt.
- Path Resolution: Locate executables in directories specified in the PATH environment variable.
- Input and Output Redirection: Support input and output redirection using the '<' and '>' operators.
- Piping: Chain multiple commands together using the '|' operator.
- Background Processes: Run processes in the background using the '&' operator.

## Usage

1. **Running Simple_Shell**:

   Compile Simple_Shell, and then run it in your terminal. To compile, follow the instructions in the "Building Simple_Shell" section below.

2. **Basic Shell Commands**:

   Run basic shell commands like `ls`, `cat`, `pwd`, and more just as you would in a regular shell.

3. **Input and Output Redirection**:

   Redirect input from a file or output to a file using the '<' and '>' operators:

   ```shell
   $ cat < input.txt > output.txt
