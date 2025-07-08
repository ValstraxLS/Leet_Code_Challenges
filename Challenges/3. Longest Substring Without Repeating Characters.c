/**************************************************************************************************
 * Given a string s, find the length of the longest substring without duplicate characters.
 *  
 *
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * 
 * Constraints:
 * 
 *     0 <= s.length <= 5 * 10E4
 *     s consists of English letters, digits, symbols and spaces.
 *
 ***************************************************************************************************/


#include <stdio.h>


int lengthOfLongestSubstring(char* s) {
	int indx1 = 0;
	int indx2 = 0;
	int alphabet[127] = {}; /*alphabet the size of the unicode table to be compatable with any unicode character*/
	int max = 0;

	alphabet[s[indx1]] = 1;
	
/*	printf("alphabet: ");
	int i;
	for (i=0; i<127; i++) {
		if (alphabet[i]) {
			printf("%c", i);
		}
	}
	printf("\n");

*/	while (s[indx2] != '\0') {
		if (indx1 == indx2) {
			indx2++;
		}
		else if (s[indx1] == s[indx2]) {
			indx1++;
		}
		else if (alphabet[s[indx2]] == 1) {
			alphabet[s[indx1]] = 0;
			indx1++;	
		}
		else {
			alphabet[s[indx2]] = 1;
			indx2++;
		}

		int size = indx2 - indx1;
		if (max < size) {
			max = size;
		}
/*		printf("indx1: %d, indx2: %d \n", indx1, indx2);

		int i;
		printf("alphabet: ");
		for (i=0; i<127; i++) {
			if (alphabet[i]) {
				printf("%c", i);
			}
		}
		printf("\n");
		printf("max: %d \n", max);
*/	}
	return max;
}


int main() {
	/* test cases 1*/
	char s1[9]  = "abcabcbb";
	printf("Example 1: %s \n", s1);
	int r1 = lengthOfLongestSubstring(s1);
	printf("Output: %d \n", r1);
	printf("Result: %s \n", r1==3 ?"true":"false");

	/* test cases 2*/
	char s2[6]  = "bbbbb";
	printf("Example 2: %s \n", s2);
	int r2 = lengthOfLongestSubstring(s2);
	printf("Output: %d \n", r2);
	printf("Result: %s \n", r2==1 ?"true":"false");

	/* test cases 3*/
	char s3[7]  = "pwwkew";
	printf("Example 3: %s \n", s3);
	int r3 = lengthOfLongestSubstring(s3);
	printf("Output: %d \n", r3);
	printf("Result: %s \n", r3==3 ?"true":"false");

	return 0;
}
