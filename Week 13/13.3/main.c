#include <stdio.h>
#include "functions.h"
#include "string.h"
#include "ctype.h"

/// Counts the number of occurrences of each character in the given string.
/// @param string the string to count the characters in
/// @param counts an array of 26 integers, where the counts of the characters
///   'a' through 'z' will be stored.
void count_characters(const char *string, int counts[static 26]){
    for (int i = 0; i < 128; ++i) {
        if(string[i] != '\0' && isalpha(string[i])){
            counts[string[i] - 'a']++;
        }
    }
}

/// Returns true if the two given strings are anagrams of each other.
/// @param string1 the first string
/// @param string2 the second string
/// @returns true if the two strings are anagrams of each other, false otherwise.
bool are_anagrams(const char *string1, const char *string2){
    int count_string1[26] = {0};
    int count_string2[26] = {0};

    count_characters(string1, count_string1);
    count_characters(string2, count_string2);

    for (int i = 0; i < 26; ++i) {
        if(count_string1[i] != count_string2[i]){
            return false;
        }
    }

    return true;
}

int main() {
    char * string1[128];
    strncpy(string1, read_string("Enter the first string: "), 128);

    char * string2[128];
    strncpy(string2, read_string("Enter the second string: "), 128);

    if(are_anagrams(string1, string2)){
        printf("\"%s\" and \"%s\" are anagrams", string1, string2);
    } else{
        printf("\"%s\" and \"%s\" are NOT anagrams", string1, string2);
    }


    return 0;
}
