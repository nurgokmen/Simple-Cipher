**Simple Cipher Program**

**Author
Nurberat Gökmen**

**Project Overview**

This project is a simple cipher application for **encryption** and **decryption** of text. The program implements a two-phase encryption and decryption process using **polyalphabetic substitution** and **transposition techniques**.

Developed in C to leverage its low-level capabilities and efficient memory handling, this program provides a console interface for users to encrypt, decrypt, or exit. It was built using the CLion IDE with support for the C11 standard.

**Features**

Two-Phase Encryption/Decryption: Includes polyalphabetic substitution and transposition for secure data transformation.
Console Interface: User-friendly text-based interface for ease of use.
Custom Key Input: Users can input their own keys to control encryption and decryption.

**Prerequisites**

CLion IDE (or other compatible C/C++ development environment).
C/C++ compiler (GCC or Clang) that supports the C11 standard.

**Setup Instructions**

Clone the Repository:

```bash
Copy code
git clone https://github.com/username/repository-name.git
cd repository-name

Open Project in CLion:

Start CLion and select Open from the welcome screen (or use File > Open... if already in the IDE).
Locate and select the project directory, then click OK.
Set the C11 Standard:

Navigate to File > Settings (or CLion > Preferences on macOS).
Go to Build, Execution, Deployment > CMake.
In the CMake options field, add:
bash
Copy code
-DCMAKE_C_STANDARD=11
Apply and save the changes.
Build the Project:

Go to Build > Build Project (or press Ctrl+F9 on Windows/Linux, Cmd+F9 on macOS).
Ensure there are no compilation errors before proceeding.
Run the Program:

Click the green play button in the toolbar, or right-click main.c and select Run 'main'.
Follow the on-screen prompts to navigate through the options (encryption, decryption, or exit).
Usage Guide
Encryption:
Select option [1] to encrypt text.
Enter the plaintext and the encryption key when prompted.
Decryption:
Select option [2] to decrypt text.
Enter the ciphertext and the decryption key when prompted.
Exit:
Select option [3] to terminate the program.
Implementation Details
Conversion Table: The program uses a predefined conversion table for encryption and decryption as per assignment specifications.
Data Security: The two-phase encryption process enhances security by combining polyalphabetic substitution with transposition, making it more resilient to common cryptographic attacks.
Example
Encryption:
vbnet
Copy code
Input: HelloWorld
Key: Secret
Output: (Encrypted Text)
Decryption:
vbnet
Copy code
Input: (Encrypted Text)
Key: Secret
Output: HelloWorld
Notes
Please ensure inputs match the specified format to avoid errors.
This program is a console-based application and requires basic understanding of cryptography to use effectively.
