#include "sumpr1.h"
//-a -a -m1 20 -m2 50
//-a -c25    -n 25 -c 25
void instruction()
{
	int n = 0;

	//-------------------------------------------------
	char symb = getchar();

	if (symb == 32)
		printf(OK);
	else
	{
		printf(NO);
		exit(1);
	}

	//-------------------------------------------------

	while (1)
	{
		char symb = getchar();
		if (n < 1)
		{
			printf("                                      Генерация пароля\n"
				   "инструкция:\n"
				   "-m1 - минимальная длина пароля\n"
				   "-m2 - максимальная длина  пароля\n"
				   "-n - длина пароля\n"
				   "-c - количество паролей\n"
				   "-a - алфавит символов\n"
				   "-C [aADS] - набор символов, где a - маленькие латинские символы, A - большие латинскиесимволы\n"
				   "D - цифры, S - спецсимволы\n"
				   "\nЛюбые иные опции игнорируются.\n\n"
				   "Нажмите q для продолжения\n");

			n++;
		}
		else
		{
			if (symb == 'q')
			{
				system("cls");
				break;
			}
			else
				printf("Нажмите q для продолжения\n");
			system("cls");
		}
	}
}

void checkFlags(int argc, char *argv[])
{

	int countm1 = 0, countm2 = 0, countn = 0, countc = 0, countA = 0, countC = 0;

	int flags[6] = {countm1, countm2, countn, countc, countA, countC};

	int repetA = 0;

	int counta = 0;
	/////// повтор а
	for (int j = 1; j < argc; j++)
	{
		if (strcmp(argv[j], "-a") == 0)
		{
			counta++;
			if (strcmp(argv[j - 1], "-a") != 0)
			{
				repetA++;
			}
		}
	}
	if (counta > 2 || repetA > 1)
	{
		printf("опции повторяются\n");
		exit(1);
	}
	repetA = 0;
	///
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-a") == 0)
		{
			if ((strcmp(argv[i - 1], "-a") == 0) && counta < 2)
			{
				continue;
			}
			countA++;
		}
		if ((strcmp(argv[i], "-m1") == 0))
		{

			if ((strcmp(argv[i - 1], "-a") == 0) && counta < 2)
			{
				continue;
			}

			countm1++;
		}

		if (strcmp(argv[i], "-m2") == 0)
		{

			if (strcmp(argv[i - 1], "-a") == 0 && counta < 2)
			{
				continue;
			}
			countm2++;
		}

		if (strcmp(argv[i], "-n") == 0)
		{

			if ((strcmp(argv[i - 1], "-a") == 0))
			{
				if (counta == 1)
					continue; // было просто continue

				else
					countn++;
			}
			else
				countn++;
		}

		if ((strcmp(argv[i], "-c") == 0) && counta < 2)
		{

			if (strcmp(argv[i - 1], "-a") == 0)
			{
				continue;
			}
			countc++;
		}

		if (countc > 1 || countm1 > 1 || countm2 > 1 || countn > 1 || countC > 1 || countA > 2)
		{
			printf("Одни и те же опции не должны повторяться.\n");
			exit(1);
		}

		if (strcmp(argv[i], "-C") == 0)
		{
			if (strcmp(argv[i - 1], "-a") == 0)
			{
				continue;
			}
			else
				countC++;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (flags[i] > 1)
		{
			printf("Введены повторяющие опции.Опцию можно записать только 1 раз\n");
			break;
		}
		if ((countm1 == 1 && countm2 == 0) || (countm1 == 0 && countm2 == 1))
		{
			printf("Опции '-m1' и '-m2 должны быть вместе\n");
			exit(1);
		}
		if ((countm1 == 1 && countm2 == 1) && countn == 1)
		{
			printf("Опции '-m1','-m2' и '-n' несовместимы.Выберите либо '-m1' с '-m2', либо только '-n'\n");
			exit(1);
		}
		if (counta == 1 && countC == 1)
		{
			printf("Опции '-a' и '-C' несовместимы.Выберите что - то одно.\n");
			exit(1);
		}
		if (countm1 == 0 && countm2 == 0 && countn == 0)
		{
			printf("Опции '-m1' и -'m2', либо '-n' должны быть обязательно.\n");
			exit(1);
		}
		if (counta == 0 && countC == 0)
		{
			printf("Опции '-a' либо '-C' должны быть обязательно.\n");
			exit(1);
		}
	}
}

void checkSymbolFlags(int argc, char *argv[])
{
	int flag = 0, countzero = 0, q = 0, ind = 0;

	int rea2 = 0;
	for (int j = 1; j < argc; j++)
	{
		if (strcmp(argv[j], "-a") == 0)
			rea2++;
	}
	for (int i = 1; i < argc; i++)
	{
		if (((strcmp(argv[i], "-m1") == 0) || (strcmp(argv[i], "-m2") == 0) || (strcmp(argv[i], "-n") == 0) || (strcmp(argv[i], "-c") == 0)))
		{
			if ((strcmp(argv[i - 1], "-a") == 0) && rea2 <= 2)
			{
				ind = 1;
				continue;
			}
			if (argv[i + 1] == (void *)0 && ind == 0)
			{
				q = 1;
				printf("Ошибка, %s - пустая опция\n", argv[i]);
				exit(1);
			}
			// if (q == 0 && atoi(argv[i + 1]) == 0 ) {
			// printf("%s не может иметь нулевую длину.\n", argv[i]);
			// exit(1);
			//}
			int check = 0;
			for (int j = 1; j < argc; j++)
			{
				if ((strcmp(argv[j - 1], "-a") == 0))
				{

					check++;
					continue;
				}
				if (check > 2)
				{
					printf("опции повторяются\n");
					exit(1);
				}
			}

			for (int j = 0; j < strlen(argv[i + 1]); j++)
			{
				if (argv[i + 1][j] == 48)
					countzero++;
				else
					break;
			}

			for (int j = countzero; j < strlen(argv[i + 1]); j++)
			{

				if ((argv[i + 1][j] < 48 || (argv[i + 1][j] > 57)))
				{
					printf("У опции %s символ - '%c' Недопустимое значение.Допустимы только числовые значения.\n", argv[i], argv[i + 1][j]);
					exit(1);
				}

				if (j == 10 + countzero - 1)
				{
					char intMax[] = "2147483647";
					int countMax = 0;

					for (int k = countzero; k < 10 + countzero; k++)
					{

						if (argv[i + 1][k] <= intMax[k - countzero])
						{
							countMax++;
						}
					}
					if (countMax == 10)
						continue;
					else
					{
						printf("Превышен лимит Int Max\n");

						exit(1);
					}
				}
				if (j > 10 + countzero)
				{
					printf("Превышен лимит Int Max\n");
					exit(1);
				}
			}
		}
	}
	countzero = 0;

	int statusAlpha = 0;
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-C") == 0)
		{
			if (argv[i + 1] == (void *)0)
			{
				printf("Ошибка.%s - пустая опция\n", argv[i]);
				exit(1);
			}
			if (strcmp(argv[i - 1], "-a") == 0)
			{
				continue;
			}

			int counta = 0, countA = 0, countD = 0, countS = 0;

			for (int j = 0; j < strlen(argv[i + 1]); j++)
			{

				if (argv[i + 1][j] != 97 && argv[i + 1][j] != 65 && argv[i + 1][j] != 68 && argv[i + 1][j] != 83)
				{
					printf("Неизвестный символ. Введите один или несколько символов из множества{ a,A,D,S }\n");
					exit(1);
				}

				if (argv[i + 1][j] == 97)
				{
					counta++;
				}

				if (argv[i + 1][j] == 65)
				{
					countA++;
				}

				if (argv[i + 1][j] == 68)
				{
					countD++;
				}

				if (argv[i + 1][j] == 83)
				{
					countS++;
				}
				if (counta > 1 || countA > 1 || countD > 1 || countS > 1)
				{
					printf("Одни и те же опции не должны повторяться.\n");
					exit(1);
				}
			}
			printf("a - %d\n", counta);
			printf("A - %d\n", countA);
			printf("D - %d\n", countD);
			printf("S - %d\n", countS);
		}
		else if (strcmp(argv[i], "-a") == 0 && statusAlpha == 0)
		{
			statusAlpha = 1;
			char *alpha = argv[i + 1];
			printf("Набор символов алфавита:\n");
			for (int j = 0; alpha[j] != '\0'; j++)
				printf("{%c}", alpha[j]);
		}
	}
	printf("\n");
}
void checkSizeFlags(int argc, char **argv)
{
	int varm1 = 0, varm2 = 0, counta = 0;

	for (int j = 1; j < argc; j++)
	{
		if (strcmp(argv[j], "-a") == 0)
			counta++;
	}
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-m1") == 0)
		{
			if (((strcmp(argv[i - 1], "-a") == 0) || (i + 1 == argc)) && counta != 2)
			{
				continue;
			}
			else
			{
				varm1 = atoi(argv[i + 1]);
				if (varm1 == 0)
				{
					printf("Длина не может быть нулевой4\n");
					exit(1);
				}
			}
		}
		if (strcmp(argv[i], "-m2") == 0)
		{
			if (((strcmp(argv[i - 1], "-a") == 0) || (i + 1 == argc)) && counta != 2)
			{
				continue;
			}
			else
			{
				varm2 = atoi(argv[i + 1]);
				if (varm2 == 0)
				{
					printf("Длина не может быть нулевой!\n");
					exit(1);
				}
			}
		}
	}

	if (varm1 > varm2)
	{
		printf(" Значение у -m1 не может быть больше, чем у -m2");
		exit(1);
	}
}

char *createAlphabet(int argc, char **argv)
{

	char symbLow[] = "abcdefghijklmnopqrstuvwxyz";
	char symbHigh[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char numbers[] = "0123456789";
	char symbSpec[] = "!@#$%^&*()-_=+[]{}<>?,.";

	int countS = 0, counta = 0, countA = 0, countD = 0;

	int sizeS = strlen(symbSpec), sizea = strlen(symbLow), sizeA = strlen(symbHigh), sizeD = strlen(numbers);

	int size = 0;

	char *array = (char *)malloc(sizeof(char));

	int status = 0;
	for (int j = 1; j < argc; j++)
	{

		if (strcmp(argv[j], "-C") == 0 && status == 0)
		{
			status = 1;
			for (int index = 0; index < strlen(argv[j + 1]); index++)
			{

				if (argv[j + 1][index] == 97)
				{
					counta++;
					size += sizea;
				}

				if (argv[j + 1][index] == 65)
				{
					countA++;
					size += sizeA;
				}

				if (argv[j + 1][index] == 68)
				{
					countD++;
					size += sizeD;
				}

				if (argv[j + 1][index] == 83)
				{
					countS++;
					size += sizeS;
				}
			}

			array = (char *)malloc(sizeof(char) * size);
			array[size] = '\0';
			int index = 0;
			for (int i = 0; i < strlen(argv[j + 1]); i++)
			{
				if (argv[j + 1][i] == 97)
				{
					for (int k = 0; k < strlen(symbLow); k++)
					{

						array[index] = symbLow[k];
						index++;
					}
				}

				if (argv[j + 1][i] == 65)
				{
					for (int k = 0; k < strlen(symbHigh); k++)
					{

						array[index] = symbHigh[k];
						index++;
					}
				}

				if (argv[j + 1][i] == 68)
				{
					for (int k = 0; k < strlen(numbers); k++)
					{

						array[index] = numbers[k];
						index++;
					}
				}

				if (argv[j + 1][i] == 83)
				{
					for (int k = 0; k < strlen(symbSpec); k++)
					{

						array[index] = symbSpec[k];
						index++;
					}
				}
			}
		}
		if (strcmp(argv[j], "-a") == 0 && status == 0)
		{
			status = 1;

			array = argv[j + 1];
			break;
		}
	}
	return array;
}

//-n длина пароля -c  количество паролей -m1 минимальная длина пароля     - m2 максимальная

void genPass(int argc, char **argv)
{
	char *kit = createAlphabet(argc, argv);

	int min = 0, max = 0, count = 0;

	int countmin = 0, countmax = 0;

	int counta = 0, countC = 0, doublec = 0;
	for (int j = 1; j < argc; j++)
	{
		if (strcmp(argv[j], "-a") == 0)
		{
			counta++;
			if (counta > 2)
			{
				printf("Опции повторяются\n");
				exit(1);
			}
		}
		if (strcmp(argv[j], "-C") == 0)
		{
			countC++;
		}
		if (strcmp(argv[j], "-c") == 0 && strcmp(argv[j - 1], "-a") != 0)
		{
			doublec++;
		}
		if (doublec > 1)
		{
			printf("Опции не должны повторяться\n");
			exit(1);
		}
		if (counta == 2 && countC == 1)
		{
			printf("Опции -a и -C несовместимы\n");
			exit(1);
		}
	}
	int countc = 0;
	for (int j = 1; j < argc; j++)
	{
		if ((strcmp(argv[j], "-c") == 0) && counta <= 2)
		{
			if (counta == 2)
			{
				count = atoi(argv[j + 1]);
			}
			else if (strcmp(argv[j], "-c") == 0 && strcmp(argv[j - 1], "-a") != 0)
			{
				count = atoi(argv[j + 1]);
				break;
			}
			else if (countc < 1 && strcmp(argv[j - 1], "-a") == 0)
			{
				countc++;
				count = 1;
			}
			else if (countc == 1 && strcmp(argv[j - 1], "-a") != 0)
			{
				count = atoi(argv[j + 1]);
				break;
			}
			if (countc >= 2)
			{
				break;
			}
		}
		else
			count = 1;
	}

	int n = 0;

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-n") == 0)
		{
			if ((strcmp(argv[i - 1], "-a") != 0) || counta == 2) //||counta == 2)
			{
				if (i + 1 == argc)
				{
					printf("Пустая опция\n");
					exit(1);
				}

				for (int k = 0; k < count; k++) //+1; k++)
				{
					for (int j = 0; j < atoi(argv[i + 1]); j++)
					{

						printf("%c", kit[rand() % strlen(kit)]);
					}
					printf("\n");
				}
			}
		}
		if (strcmp(argv[i], "-m1") == 0)
		{
			if ((strcmp(argv[i - 1], "-a") != 0) || counta == 2)
			{
				min = atoi(argv[i + 1]);
				countmin++;
			}
		}
		if (strcmp(argv[i], "-m2") == 0)
		{
			if ((strcmp(argv[i - 1], "-a") != 0) || counta == 2)
			{
				max = atoi(argv[i + 1]);
				countmax++;
			}
		}

		if (countmin == 1 && countmax == 1)
		{

			srand(time(0));

			for (int d = 0; d < count; d++)
			{
				if (max == min)
				{
					for (int f = 0; f < max; f++)
					{
						printf("%c", kit[rand() % strlen(kit)]);
					}
				}
				else
				{
					int randomNumber = (rand() % (max - min)) + min;

					for (int f = 0; f < randomNumber; f++)
					{
						printf("%c", kit[rand() % strlen(kit)]);
					}
					printf("\n");
				}
				printf("\n");
			}
			break;
		}
	}
}

void countFlags(int argc, char **argv)
{
	int count = 0;
	for (int i = 1; argv[i] != (void *)0; i++)
	{
		printf("%s ", argv[i]);
		count++;
	}
	printf("Введено %d аргументов\n", count);
}

void checkArguments(int argc, char **argv)
{

	if (argc < 2)
	{
		printf("Отсутствуют аргументы командной строки");
		exit(1);
	}
}