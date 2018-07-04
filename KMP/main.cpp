#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//next 是从0（无任一字符匹配）开始的，不包括L，因为当字符串匹配到L时直接输出，故不需要求其next
int *Next(char str[],int L) {
	int *next = (int *)calloc(L , sizeof(int));

	int i = 0;
	int j = -1;
	next[0] = -1;

	while (i < L-1) {
		if (j == -1 || str[i] == str[j]) {
			next[++i] = ++j;
		}
		else {
			j = next[j];
		}
	}

	return next;
}

void main() {
	char str1[] = { "CADDBDABDABC" };
	char str2[] = { "ABDABDABC" };

	int L1 = strlen(str1);
	int L2 = strlen(str2);
	int *next = Next(str2, L2);

	printf("%d,%d\n",L1,L2);
	for (int i = 0; i < L2; i++) {
		for (int j = 0; j < i;j++) {
			printf("%c",str2[j]);
		}
		printf(":%d\n", next[i]);
	}

	int i = 0;
	int j = 0;
	while (i < L1) {
		if (j==-1||str1[i] == str2[j]) {
			i++;
			j++;

			if (j == L2) {
				printf("end:%d\n", i - L2);
				goto end;
			}
		}
		else {
			j = next[j];
		}
	}

	printf("NULL MATCH\n");

end:
	free(next);
	system("pause");
}