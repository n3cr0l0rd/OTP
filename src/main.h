#ifndef MAIN_H
#define MAIN_H

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void print_usage_and_exit(const char *program_name, const unsigned exit_code);
void encrypt(const char *message, FILE *pad);
void decrypt(const char *cipher, FILE *pad);
void generate_pad(const size_t message_len);
void pad_handler(FILE *pad);

#endif
