#include <stdio.h>
#include <string.h>

typedef enum {
    LEFT,
    RIGHT
} overlap_mode_t;

void merge(char word1[], char word2[], int overlap_length, overlap_mode_t overlap_mode, char result[]) {
    char* left;
    char* right;

    if (overlap_mode == LEFT) {
        left = word1;
        right = word2;
    } else {
        left = word2;
        right = word1;
    }

    strcpy(result, left);
    strcat(result, right + overlap_length);
}

char equals(char left_word[], char right_word[], int overlap_start_index) {
    int index = overlap_start_index;

    while (left_word[index] != 0) {
        if (left_word[index] != right_word[index - overlap_start_index]) {
            return 0;
        }

        ++index;
    }

    return 1;
}

int find_overlap_length(char left_word[], char right_word[], int left_word_length) {
    for (int i = 0; i < left_word_length; ++i) {
        if (equals(left_word, right_word, i)) {
            return left_word_length - i;
        }
    }

    return 0;
}

void find_overlap(char word1[], char word2[], int* overlap_length, overlap_mode_t* overlap_mode) {
    int word1_length = strlen(word1);
    int word2_length = strlen(word2);

    int overlap_length1 = find_overlap_length(word1, word2, word1_length);
    int overlap_length2 = find_overlap_length(word2, word1, word2_length);

    if (overlap_length1 > overlap_length2) {
        *overlap_length = overlap_length1;
        *overlap_mode = LEFT;
    } else {
        *overlap_length = overlap_length2;
        *overlap_mode = RIGHT;
    }
}

void perform_test_case() {
    const int max_number_of_words = 100;
    const int max_length_of_words = 16;

    char words[max_number_of_words][max_number_of_words * max_length_of_words];
    int number_of_words;

    scanf("%d", &number_of_words);

    for (int i = 0; i < number_of_words; ++i) {
        scanf("%s", words[i]);
    }

    char tmp_words[max_number_of_words][max_number_of_words * max_length_of_words];

    for (int i = 0; i < number_of_words; ++i) {
        strcpy(tmp_words[i], words[i]);
    }

    int tmp_number_of_words = number_of_words;

    while (tmp_number_of_words > 1) {
        int maximum_overlap_length = 0;
        overlap_mode_t maximum_overlap_mode;
        int maximum_overlap_left;
        int maximum_overlap_right;

        for (int i = 0; i < tmp_number_of_words - 1; ++i) {
            for (int j = i + 1; j < tmp_number_of_words; ++j) {
                int overlap_length;
                overlap_mode_t overlap_mode;

                find_overlap(tmp_words[i], tmp_words[j], &overlap_length, &overlap_mode);

                if (overlap_length > maximum_overlap_length) {
                    maximum_overlap_length = overlap_length;
                    maximum_overlap_mode = overlap_mode;
                    maximum_overlap_left = i;
                    maximum_overlap_right = j;
                }
            }
        }

        if (maximum_overlap_length == 0) {
            strcat(tmp_words[0], tmp_words[tmp_number_of_words - 1]);
        } else {
            char result[max_number_of_words * max_length_of_words];
            merge(tmp_words[maximum_overlap_left], tmp_words[maximum_overlap_right], maximum_overlap_length, maximum_overlap_mode, result);
            strcpy(tmp_words[maximum_overlap_left], result);
            strcpy(tmp_words[maximum_overlap_right], tmp_words[tmp_number_of_words - 1]);
        }

        --tmp_number_of_words;
    }

    printf("%s\n", tmp_words[0]);

    for (int i = 0; i < number_of_words; ++i) {
        printf("%d\n", strstr(tmp_words[0], words[i]) - tmp_words[0] + 1);
    }
}

int main() {
    int number_of_test_cases;

    scanf("%d", &number_of_test_cases);

    for (int i = 0; i < number_of_test_cases; ++i) {
        printf("case %d Y\n", i + 1);
        perform_test_case();
    }
}
