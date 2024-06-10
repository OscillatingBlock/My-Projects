#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digit(string s);
char rotate(char c, int n);

int main(int argc, string argv[]) {

  // Make sure program was run with just one command-line argument
  if (argc != 2) {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  // Make sure every character in argv[1] is a digit
  if (!only_digit(argv[1])) {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  // Convert argv[1] from a string to an int
  int key = atoi(argv[1]);

  // Get plaintext
  string plaintext = get_string("Plaintext: ");

  // Loop through each character in the plaintext and rotate
  for (int i = 0; i < strlen(plaintext); i++) {
    plaintext[i] =
        rotate(plaintext[i], key); // Modify the character in the string
  }

  // Print the ciphertext
  printf("ciphertext: %s\n", plaintext);

  return 0;
}

bool only_digit(string s) {

  for (int i = 0; i < strlen(s); i++) {
    if (!isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

char rotate(char c, int n) {
  if (isalpha(c)) {
    if (isupper(c)) {
      return ((c) - 'A' + n) % 26 + 'A';
    } else {
      return ((c) - 'a' + n) % 26 + 'a';
    }
  }
  return c; // Keep non-letters unchanged
}
