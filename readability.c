#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_words(string s);
int count_sentances(string s);
int count_letters(string s);

int main(void) {
  // Prompt the user for some text

  string text = get_string("Text: ");

  // Count the number of letters, words, and sentences in the text

  float w = count_words(text);
  float s = count_sentances(text);
  float l = count_letters(text);

  // Compute the Coleman-Liau index

  float L1 = (l / w) * 100;
  int L = round(L1);
  float S1 = (s / w) * 100;
  int S = round(S1);

  // Print the grade level

  int grade_level = round(0.0588 * L1 - 0.296 * S1 - 15.8);
  if (grade_level < 1) {
    printf("Before Grade 1\n");
  } else if (grade_level > 16)
    printf("Grade 16+\n");
  else {
    printf("Grade %i\n", grade_level);
  }
}

int count_letters(string s) {

  int n = 0;
  for (int i = 0; i < strlen(s); i++) {
    char c = s[i];
    if (c == ' ' || c == '.' || c == '!' || c == '?' || c == ',' || c == '\'') {
      n++;
    }
  }
  return strlen(s) - n;
}

int count_words(string s) {
  int n = 0;
  for (int i = 0; i < strlen(s); i++) {
    char c = s[i];
    if (c == ' ') {
      n++;
    }
  }
  return n + 1;
}

int count_sentances(string s) {
  int n = 0;
  for (int i = 0; i < strlen(s); i++) {
    char c = s[i];
    if (c == '.' || c == '?' || c == '\0') {
      n++;
    }
  }
  return n;
}
