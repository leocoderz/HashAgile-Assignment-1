#include <stdio.h>
#include <string.h>

// Function to check if a given substring is a palindrome
int isPalindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}

// Function to find the longest palindromic substring
void longestPalindromicSubstring(char str[]) {
    int maxLength = 1;  // At least one character is always a palindrome
    int start = 0;      // Starting index of the longest palindrome
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (isPalindrome(str, i, j)) {
                int palLength = j - i + 1;
                if (palLength > maxLength) {
                    maxLength = palLength;
                    start = i;
                }
            }
        }
    }

    // Print the longest palindromic substring
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLength; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    // Sample input 1
    char str1[] = "babad";
    printf("Input: %s\n", str1);
    longestPalindromicSubstring(str1);

    // Sample input 2
    char str2[] = "cbbd";
    printf("\nInput: %s\n", str2);
    longestPalindromicSubstring(str2);

    // Sample input 3
    char str3[] = "forgeeksskeegfor";
    printf("\nInput: %s\n", str3);
    longestPalindromicSubstring(str3);

    return 0;
}
