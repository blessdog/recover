---

## About This Code

This code is a recovery tool, specifically designed for extracting and saving JPEG images from a raw file (often representing a digital memory card's raw data). The program takes advantage of the distinct header pattern that JPEG files possess.

## Key Features:

1. ### Error Handling: The tool is equipped with functions (`inputError` and `fileError`) that provide user-friendly error messages when an incorrect input is given or there's a failure in opening a file.

2. ### JPEG Header Identification: The function `isJpgHeader` checks if a block of data starts with a signature specific to JPEG files. This allows the program to identify the beginning of each JPEG image.

3. ### Sequential Image Saving: As the program identifies JPEG images within the raw data, it saves them with a filename that increments sequentially (e.g., 000.jpg, 001.jpg, ...).

## Usage:
To utilize this recovery tool, you run it with the raw file as an argument:
```
./recover image.raw
```
Upon successful recovery, you'll find the JPEG files in the same directory as the tool.

# Dependencies:
The program uses the CS50 library, known for educational purposes, to simplify some common C programming tasks.

### Note: 
This tool assumes that once a JPEG header is found, the following blocks will constitute the JPEG file until another JPEG header is found or the end of the raw file is reached.

---
