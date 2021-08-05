#include <stdio.h>

void number16ToChar(char s1, char s2, char* symb) {
	if (s1 >= 'A' && s1 <= 'F') {
		*symb = (s1 - 55) * 16;
	} else {
	   	*symb = (s1 - '0') * 16;
	}
    if (s2 >= 'A' && s2 <= 'F') {
		*symb += (s2 - 55);
    } else {
		*symb += s2 - '0';
    }
}

void charToNumber16(char symb, char* s1, char* s2) {
	int a = (int) symb, tmp;
	*s1 = '0';
	while (a > 0) {
		tmp = a % 16;
		if (tmp > 9) {
			if (*s2 == ' ')
			  	*s2 = (char)(tmp + 55);
			else
			   	*s1 = (char)(tmp + 55);
		} else {
			if (*s2 == ' ')
			   	*s2 =(char)tmp + '0';
			else
			   	*s1 = (char)tmp + '0';
		}
		a/=16;
	}
}

void encrypt(char* str, int size) {
	for (int i = 0; i < size; i++) {
		if ((str[i] == ' ' && str[i+1] == ' ') || (str[i] != ' ' && (str[i+1] != ' ' && str[i+1] != '\0'))) {
			printf("n/a");
			return;
		}
	}
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ')	continue;
		char s1 = ' ', s2 = ' ';
		charToNumber16(str[i], &s1, &s2);
		printf("%c%c", s1, s2);
		if (i != size - 1) printf(" ");
	}
}

void decicipher(char* str, int size) {
	for (int i = 0; i < size; i++) {
		if (str[0] != ' ' && str[1] == ' ') {
			printf("n/a");
			return;
		}
		if (str[i] == ' ' && str[i+1] == ' ') {
			printf("n/a");
			return;
		}
		if (i != 0 && str[i] != ' ' && str[i-1] == ' ' && str[i+1] == ' ') {
			printf("n/a");
			return;
		}
	}
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ') continue;
		char sym;
		number16ToChar(str[i], str[i+1], &sym);
		printf("%c", sym);
		if (i != size - 2) printf(" ");
		i++;
	}
}

int main(int argc, char* argv[]) {
	char str[100];
	char c = ' ';
	int size = 0;
	while (c != '\n') {
		scanf("%c", &c);
		str[size] = c;
		size++;
	}
	str[--size] = '\0';
	for (int i = 0; i < size; i++) {
	printf("%c", str[i]);
	}
	printf("\n size = %d\n", size);
	if ((argv[1][0] != '1' && argv[1][0] != '0')|| (argc > 2)) {
		printf("n/a");
		return 1;
	}
	if (argv[1][0] == '0')
	   	encrypt(str, size);
	else
	   decicipher(str, size);
	return 0;
}

