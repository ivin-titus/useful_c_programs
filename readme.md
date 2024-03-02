Description

* This C program implements a simple Caesar cipher algorithm to encrypt and decrypt text.
* The user can choose between encryption or decryption and provides the key to perform the operation. 
* It accepts input either from command-line arguments or through user prompts during runtime.
* The program first checks if the correct number of command-line arguments is provided. 
* If not, it prompts the user to input the operation (encrypt or decrypt), the key, and the text to be processed. 
* It validates the key and the operation provided by the user and terminates if the input is invalid.
* After obtaining valid input, the program proceeds to perform either encryption or decryption based on the user's choice. 
* The encryption/decryption process involves shifting each letter in the input text by the specified key value, wrapping around the alphabet if necessary. 
* Non-alphabetic characters remain unchanged. The encrypted or decrypted text is stored in a global variable.
* Finally, the program displays the encrypted or decrypted text to the user. If the input text contains spaces or special characters, it will be correctly processed without causing errors or crashes
