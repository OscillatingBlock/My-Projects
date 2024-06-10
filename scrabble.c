#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);

int main(void) {
  // get user input
  string word1 = get_string("Player 1: ");
  string word2 = get_string("Player 2: ");

  // Compute the score of each word
  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  // Print the winner
  if (score1 < score2) {
    printf("Player 2 wins!\n");
  } else if (score2 < score1) {
    printf("player 1 wins!\n");
  } else {
    printf("Tie!\n");
  }
}

int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word) {

  int length = strlen(word);
  int totalpoints = 0;
  for (int i = 0; i < length; i++) {
    if (isupper(word[i])) {
      totalpoints += POINTS[word[i] - 'A'];
    } else if (islower(word[i])) {
      totalpoints += POINTS[word[i] - 'a'];
    }
  }
  return (int)totalpoints;
}
