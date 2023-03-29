#include "./main.h"

void decrypt(const char *cipher, FILE *pad)
{
	char encrypted_symbol[3];
	const size_t cipher_len = strlen(cipher);

	for(size_t i = 0, j = 0; i < cipher_len; j = 0, memset(encrypted_symbol, 0, 3))
	{
		while(cipher[i] != ' ' && j < 3)
		{
			encrypted_symbol[j++] = cipher[i++];
		}
		
		i++;

		printf("%c", atoi(encrypted_symbol) ^ (char)fgetc(pad));
	}

	putchar('\n');
}