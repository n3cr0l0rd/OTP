#include "main.h"

/* TODO:
	1. Добавить поддержку русского языка для открытого текста
	2. Добваить поддержку шифрования файлов 
*/

int main(int argc, char *argv[])
{
	FILE *pad;

	if(argc < 3)
	{
		if(argv[1] && !strncmp(argv[1], "help", strlen("help")))
			print_usage_and_exit(argv[0], EXIT_SUCCESS);
		
		print_usage_and_exit(argv[0], EXIT_FAILURE);
	}

	if(!strncmp(argv[1], "encrypt", strlen("encrypt")))
	{
		if(argv[2])
		{
			generate_pad(strlen(argv[2]));
			pad = fopen("pad.txt", "r");
			pad_handler(pad);

			encrypt(argv[2], pad);
			fclose(pad);
			return EXIT_SUCCESS;
		}

		else
			print_usage_and_exit(argv[0], EXIT_FAILURE);
	}

	if(!strncmp(argv[1], "decrypt", strlen("decrypt")))
	{
		if(argv[2])
		{	
			pad = fopen("pad.txt", "r");
			pad_handler(pad);

			decrypt(argv[2], pad);
			fclose(pad);
			return EXIT_SUCCESS;
		}

		else
			print_usage_and_exit(argv[0], EXIT_FAILURE);
	}
	print_usage_and_exit(argv[0], EXIT_FAILURE);
}

void generate_pad(const size_t message_len)
{
	srandom(getpid() + time(NULL));
	char rand_char;

	FILE *pad = fopen("pad.txt", "w");
	pad_handler(pad);

	for(size_t i = 0; i < message_len; i++)
	{
		rand_char = random() % 26 + 65;
		fputc(rand_char, pad);
	}
	fclose(pad);
}

void pad_handler(FILE *pad)
{
	if(pad == NULL)
	{
		fprintf(stderr, "Ошибка при открытии блокнота!\nЗавершение...\n");
		exit(EXIT_FAILURE);
	}
}

void print_usage_and_exit(const char *program_name, const unsigned exit_code)
{
	printf("Использование: %s <опция> <текст>\n", program_name);
	puts("Опции:");
	puts(" help....................Вызвать данное меню");
	puts(" encrypt <сообщение>.....Зашифровать сообщение");
	puts(" decrypt <шифртекст>.....Расшифровать шифртекст");

	exit(exit_code);
}