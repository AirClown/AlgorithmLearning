#include<stdio.h>
#include<Windows.h>


//朴素字符串匹配算法
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

//RS算法
//验证两个字符串是否相同
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

	//str子串的映射值
	int s_code = str[0]-'A';    
	//pattern的映射值
	int p_code = pattern[0]-'A';
	//h为d的size2-1次幂
	int h=1;

	//计算 s_code、p_code、h
	for (int i = 1; i < size2; i++) {
		p_code = (d*p_code + pattern[i]-'A') % q;
		s_code = (d*s_code + str[i]-'A') % q;
		h = (h*d)%q;
	}

	//字符串开始匹配，对p_code和s_code 进行比较，并更新s_code的值
	for (int i = 0; i < size1 - size2+1; i++) {
		if (s_code == p_code&&isMatching(str+i,pattern)) {
			return true;
		}

		//更新s_code，去掉开头的值str[i],加上str[i+size2]
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
