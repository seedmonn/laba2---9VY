#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define YES 1
#define NO 0

int main()
{
	char c;
	char arr[100];
	int cnt=0;
	int flag = NO;
	int found = NO;
	char* j = arr; // позиция начала слова
	char* in_ptr = arr; // (i) - позиция текущего символа
	char* out_ptr = arr; // (pos) - позиция символа выхода
	char* word_ptr = arr; // (start) - позиция начала слова

	FILE* in;
	in = fopen("text.txt", "r");
	if (in == NULL)
	{
		printf("File doesn't exist\n");
		return 1;
	}
	FILE* out;
	out = fopen("result.txt", "w");

		fgets(arr, 100, in);
		do
		{
			c = *in_ptr; // взять текущий символ из буфера
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != ' ' && c != '.' && c != ',' && c != '\n' && c != '\0' && c != '\t')) // проверка на не слово
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
						if ((c1 == 'o' && c2 == 'e') && (found != YES) && (c3 == ' ' || c3 == '.' || c3 == ',' || c3 == '\0' || c3 == '\n'))
						{// проверка на: 1)заглавные буквы и условие задачи. 2) условие является ли слово "словом".
							printf("strt:->");
							for (j = word_ptr; j < in_ptr; j++)
								printf("%c", *j);
							break;
						}
					}
				}
				flag = NO;
				found = NO;
				printf("%c", *in_ptr); //пробелы для "нормальных слов" (по условию задачи)
			}
			else
			{
				if (flag == NO) // найдена буква
					word_ptr = in_ptr;// запомнить позицию начала слова
				flag = YES; //признак слова
			}
			in_ptr++; //переход к следующей ячейке буфера
		} while (c != '\0');	
	fclose(in);
	fclose(out);
	return 0;
	}
	