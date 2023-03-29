#include "./main.h"

void encrypt(const char *message, FILE *pad)
{	
	const size_t m_len = strlen(message);

	for(size_t i = 0; i < m_len; i++)
	{
		printf("%d%c", message[i] ^ (char)fgetc(pad), i == m_len-1 ? '\n' : ' ');
	}
}