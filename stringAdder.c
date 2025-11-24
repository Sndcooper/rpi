#include <stdio.h>
#include <string.h>

int chartoInt(char a){
	return a-'0';
}

int main(){

	char num1[1001];
	char num2[1001];
	char result[1002];
	printf("Enter num1 num2: \n");
	scanf("%s", num1);
	scanf("%s", num2);

	int l = strlen(num1)- 1;
	int h = strlen(num2)- 1;
	int index = 0;
	int carry = 0;
	while(index < 1005){
		if(h < 0 && l < 0){
			break;
		}
		int tmp = carry;
		carry = 0;
		if(l >= 0){
			tmp = tmp + chartoInt(num1[l]);
		}
		if(h >= 0){
			tmp = tmp + chartoInt(num2[h]);
		}

		if(tmp > 9){
			carry = 1;
			tmp = tmp - 10;
		}
		result[index] = tmp+'0';	
		index++;
		l--;
		h--;
	}

	if(carry == 1){
		result[index] = carry+'0';
		index++;
	}
	result[index] = '\0';
	
	int leng = strlen(result);
	l = 0;
	h = leng-1;
	while(l < h){
		char tmp2 = result[l];
		result[l] = result[h];
		result[h] = tmp2;
		l++;
		h--;
	}

		
	printf("%s\n", result);
	
	return 0;
}
