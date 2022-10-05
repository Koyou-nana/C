#include <stdio.h>
#include <stdlib.h>
void main()
{
	int a, i;
	printf("4桁以内で数字を決めてください。\n");
	scanf("%d", &a);
	if (a > 9999) {
		printf("範囲を超えています。\n");
		exit(1);
	}
	for (i = 0; i < 10000; i++) {
		if (a == i) {
			printf("%04d = %04d true\n数値が一致しました。\nあなたのパスワードは%04dです。\n", a, i, i);
			exit(0);
		}
		else {
			printf("%04d = %04d false\n", a, i);
		}
	}
}
