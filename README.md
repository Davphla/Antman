```
  ____  ____   ______ 
 /    ||    \ |      |
|  o  ||  _  ||      |
|     ||  |  ||_|  |_| _ __ ___   __ _ _ __  
|  _  ||  |  |  |  |  | '_ ` _ \ / _` | '_ \ 
|  |  ||  |  |  |  |  | | | | | | (_| | | | |
|__|__||__|__|  |__|  |_| |_| |_|\__,_|_| |_|
```
# Antman - Lossless file compression 

Antman is a data compression project written in C. It consists of two programs:

- Antman - Compresses a given file.
- Giantman - Decompresses a previously compressed file.

This project implements lossless compression, ensuring that decompressed files match the original exactly.
We implemented **Huffman algorithm** (Bytecode) and **LZ77** (Repetition).

It can reduce size of song file by 40%, average files by 50%, and images by 80%.

# Compilation
```
make - Compiles both binaries (antman and giantman).
make clean - Removes object files.
make fclean - Removes binaries and object files.
make re - Cleans and recompiles the project.
```

# Usage

## Antman (Compression)

`./antman/antman <input_file> <file_type>`

<input_file>: Path to the file to be compressed.

<file_type>: A number indicating the type of file:

- 1 - Text files (e.g., song lyrics)
- 2 - HTML files
- 3 - P3 PPM images

### Example:

`./antman/antman file.txt 1 > compressed.data`

## Giantman (Decompression)

`./giantman/giantman <compressed_file> <file_type>`

<compressed_file>: Path to the compressed file.

<file_type>: The same number used during compression.

### Example:

`./giantman/giantman compressed.data 1 > uncompressed.txt`

# Requirements

The program must only use the following system calls:

- open, read, write, close
- malloc, free, stat

Compression should work efficiently, even for large files.

# Project Structure

```
.
├── antman
│   ├── antman.c
│   ├── Makefile
│   ├── ... (other source files)
├── giantman
│   ├── giantman.c
│   ├── Makefile
│   ├── ... (other source files)
├── Makefile (root Makefile to compile both binaries)
└── README.md
```
## Authors 🚀
 - [David Gozlan](https://github.com/Davphla)
 - [Mikaël Vallenet](https://github.com/Mikatech)


