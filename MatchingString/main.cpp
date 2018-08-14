#include<stdio.h>
#include<Windows.h>


//ÆÓËØ×Ö·û´®Æ¥ÅäËã·¨
bool Fun(char *str, char *pattern) {
	for (int i = 0; str[i] != '\0'; i++) {
		for (int j = 0, k = i; pattern[j] != '\0'; j++, k++) {
			if (str[k] != pattern[j]) {
				goto next;
			}
		}
		return true;
	next:
		continue;
	}
	return false;
}

//RSËã·¨
bool isMatching(char *str,char *pattern) {
	for (int i = 0; pattern[i] != '\0'; i++) {
		if (pattern[i] != str[i]) {
			return false;
		}
	}
	return true;
}

bool Fun2(char *str, char *pattern) {
	int size1 = strlen(str);
	int size2 = strlen(pattern);

	int d = 26;
	int q = 144451;

	int s_code = str[0]-'A';
	int p_code = pattern[0]-'A';
	int h = 1;

	for (int i = 1; i < size2; i++) {
		p_code = (d*p_code + pattern[i]-'A') % q;
		s_code = (d*s_code + str[i]-'A') % q;
		h = (h*d)%q;
	}

	for (int i = 0; i < size1 - size2+1; i++) {
		if (s_code == p_code&&isMatching(str+i,pattern)) {
			return true;
		}

		s_code = ((s_code - h * (str[i] - 'A'))*d + str[i + size2] - 'A') % q;
	}
	return false;
}

void main() {
	char str1[] = { "ABCABDABDABC" };
	char str2[] = { "ABDABDABC" };
	if (Fun2(str1, str2)) {
		printf("Matching!\n");
	}
	else {
		printf("No matching!\n");
	}
	system("pause");
}