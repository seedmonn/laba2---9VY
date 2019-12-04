#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#define YES 1
#define NO 0
#define LENGTH 100

int main()
{
	char c;
	char str[LENGTH];
	int cnt=0;
	int flag = NO;
	int found = NO;
	char *p = str;

	FILE* in;
	in = fopen("text.txt", "r");
	if (in == NULL)
	{
		printf("File doesn't exist\n");
		return 1;
	}
	FILE* out;
	out = fopen("result.txt", "w");
	while(!feof(in))
	{
		memset(str, 0, LENGTH * sizeof(str[0]));
		fgets(str, LENGTH, in);
		char* j = str; // позиция начала слова
		char* in_ptr = str; //  позиция текущего символа
		char* word_ptr = str; // позиция начала слова
		do
		{
			c = *in_ptr; // взять текущий символ 
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t' && c != '>' )) // проверка на не слово
			{
				found = YES;
			}
			if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
			{
				// найден разделитель
				if (flag == YES)
				{
					for (j = word_ptr; j < in_ptr - 1; j++)
					{
						char c1 = *j;
						char c2 = *(j + 1);  
						char c3 = *(j + 2); 
						if (((c1 == 'o' && c2 == 'e') || (c1 == 'o' && c2 == 'E') || (c1 == 'O' && c2 == 'e') || (c1 == 'O' && c2 == 'E')) && (found != YES) && (c3 == ' ' || c3 == '.' || c3 == ',' || c3 == '\0' || c3 == '\n'))
						{// проверка на: 1)заглавные буквы и условие задачи. 2) условие является ли слово "словом".
							for (j = word_ptr; j < in_ptr; j++)
							{
								printf("%c", *j); fputc(*j, out);
							}
							break;
						}
					}
				}
				flag = NO;
				found = NO;
				if (*in_ptr == '.' || *in_ptr == ',') // для нормального отображения в консоли
					*in_ptr = ' ';
				printf("%c", *in_ptr); fputc(*in_ptr, out); //пробелы для "нормальных слов" (по условию задачи)
			}
			else
			{
				if (flag == NO) // найдена буква
					word_ptr = in_ptr;// запомнить позицию начала слова
				flag = YES; //признак слова
			}
			in_ptr++; //переход к следующей ячейке буфера
		} while (c != '\0');
	}
	printf("\n");
	fclose(in);
	fclose(out);
	return 0;
	}
	