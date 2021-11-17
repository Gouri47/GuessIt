#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
int getRandomNumber(int minVal, int maxVal)
{
	return (rand() % (maxVal - minVal)) + minVal;
}

void showData(char* word, int size)
{
	int i = 0, j = 0;
	char tempBuff[21] = { 0 };
	for (i = 0; i < size * 2; i++)
	{
		if (word[j] != NULL)
		{
			tempBuff[i] = word[j];
		}
		else
		{
			tempBuff[i] = '_';
		}
		tempBuff[++i] = ' ';
		j++;

	}
	printf("\t\t%s\n", tempBuff);
}

void main()
{
	int attemptcounter = 5, buffIndexnum = 0, positionCounter = 0, initialFlag = 0;
	int playAgainFlag = 0, userChoice = 0, attemptCheckFlag = 0, i = 0;
	char userData[10] = { 0 };
	char inputData[20] = { 0 };
	char tempChar;
	char buff[10][10] = {
							"apple",
							"mango",
							"grapes",
							"guava",
							"leeche",
							"orange",
							"pinapple",
							"banana",
							"custurd",
							"lemon",
	};
	printf("\t\t********************** Welcome to the Guess It Game ******************************* \n");
	srand(time(NULL));
	do
	{
		buffIndexnum = getRandomNumber(0, 10);
		//printf("\t\tbuffIndexnum : %d, and value : %s\n", buffIndexnum, buff[buffIndexnum]);
		printf("\t\tTotal attempts you had : %d\n", attemptcounter);
		showData(userData, strlen(buff[buffIndexnum]));
		while ((attemptcounter > 0) && (strlen(buff[buffIndexnum]) != strlen(userData)))
		{
			if (initialFlag == 0)
			{
				printf("\t\tEnter your Character : ");
			}
			else
			{
				printf("\t\tEnter your Next Character : ");
			}
			//scanf(" %c", &tempChar);
			scanf(" %s", inputData);
			while(strlen(inputData)!= 1)
			{
				printf("\t\tPlease Enter only one character not more than that\n");
				break;
			}
			tempChar = inputData[0];
			while (!isalpha(tempChar))
			{
				printf("\t\tInvalid Character!!!\n");
				printf("\t\tPlease Enter Aplha Character Only : ");
				scanf(" %s", inputData);
				while (strlen(inputData) != 1)
				{
					printf("\t\tPlease Enter only one character not more than that\n");
				}
				tempChar = inputData[0];
			}
			for (i = 0; i < strlen(buff[buffIndexnum]); i++)
			{
				if (tempChar == buff[buffIndexnum][i])
				{
					//printf("\t\tvalue of i = %d\n", i);
					userData[i] = tempChar;
					initialFlag = 1;
					attemptCheckFlag = 1;
				}
				else if (tempChar + 32 == buff[buffIndexnum][i])
				{
					//printf("\t\tvalue of i = %d\n", i);
					userData[i] = tempChar + 32;
					initialFlag = 1;
					attemptCheckFlag = 1;
				}
			}
			system("cls");		// Clears the screen at this point every time
			if (attemptCheckFlag == 1)
			{
				printf("\t\tYou Entered Right Character.\n");
				printf("\t\tAttempts Left : %d\n", attemptcounter);
			}
			else
			{
				printf("\t\tYou Entered Wrong Character!!!\n");
				attemptcounter--;
				printf("\t\tAttempts Left : %d\n", attemptcounter);
			}
			showData(userData, strlen(buff[buffIndexnum]));
			attemptCheckFlag = 0;
		}
		system("cls");		// clears the screen here also
		if (strcmp(buff[buffIndexnum], userData) == 0)
		{
			printf("\t\tCongrats You won The Game!!!!!!!!!!!!!!!!!!!!\n");
			printf("\t\tYour Word : ");
			showData(userData, strlen(buff[buffIndexnum]));
		}
		else
		{
			printf("\t\tYou loose The Game!!!!!!!!!!!!!!!!!!!!\n");
			printf("\t\tRight Word : ");
			showData(buff[buffIndexnum], strlen(buff[buffIndexnum]));
			printf("\t\tYour Word : ");
			showData(userData, strlen(buff[buffIndexnum]));
		}
		printf("\t\tDo you want to play again?\n");
		printf("\t\t<1.> Yes\n");
		printf("\t\t<2.> No\n\t\t");
		scanf(" %d", &userChoice);
		if (userChoice == 1)
		{
			attemptcounter = 5;
			buffIndexnum = 0;
			positionCounter = 0;
			initialFlag = 0;
			playAgainFlag = 0;
			attemptCheckFlag = 0;
			userChoice = 0;
			memset(userData, 0, 10);
		}
		else
		{
			playAgainFlag = 1;
		}
		system("cls");		// clears the screen here also
	} while (!playAgainFlag);

}



















//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<conio.h>
//#pragma warning(disable:4996)
//int getRandomNumber(int minVal, int maxVal)
//{
//	return (rand() % (maxVal - minVal)) + minVal;
//}
//
//void showData(char* word, int size)
//{
//	int i = 0, j = 0;
//	char tempBuff[21] = { 0 };
//	for (i = 0; i < size * 2; i++)
//	{
//		if (word[j] != NULL)
//		{
//			tempBuff[i] = word[j];
//		}
//		else
//		{
//			tempBuff[i] = '_';
//		}
//		tempBuff[++i] = ' ';
//		j++;
//
//	}
//	printf("\t\t%s\n", tempBuff);
//}
//
//void main()
//{
//	int attemptcounter = 5, buffIndexnum = 0, positionCounter = 0, initialFlag = 0;
//	int playAgainFlag = 0, userChoice = 0, attemptCheckFlag = 0, i = 0;
//	char userData[10] = { 0 };
//	char tempChar;
//	char buff[10][10] = {
//							"apple"
//							"mango",
//							"grapes",
//							"guava",
//							"leeche",
//							"orange",
//							"pinapple",
//							"banana",
//							"custurd",
//							"lemon",
//	};
//	printf("\t\t********************** Welcome to the Guess It Game ******************************* \n");
//	srand(time(NULL));
//	do
//	{
//		buffIndexnum = getRandomNumber(0, 10);
//		//printf("\t\tbuffIndexnum : %d, and value : %s\n", buffIndexnum, buff[buffIndexnum]);
//		printf("\t\tTotal attempts you Have : %d\n", attemptcounter);
//		showData(userData, strlen(buff[buffIndexnum]));
//		while ((attemptcounter > 0) && (strlen(buff[buffIndexnum]) != strlen(userData)))
//		{
//			if (initialFlag == 0)
//			{
//				printf("\t\tEnter your Character : ");
//				tempChar = getchar(); // get a single character  
//				printf(" You have passed ");
//				putchar(tempChar); // print a single character using putchar
//				
//			}
//			else
//			{
//				printf("\t\tEnter your Next Character : ");
//			}
//			scanf(" %c", &tempChar);
//
//			while (!isalpha(tempChar))
//			{
//				printf("\t\tInvalid Character!!!\n");
//				printf("\t\tPlease Enter Aplha Character Only : ");
//				scanf(" %c", &tempChar);
//			}
//			for (i = 0; i<strlen(buff[buffIndexnum]); i++)
//			{
//				if (tempChar == buff[buffIndexnum][i])
//				{
//					//printf("\t\tvalue of i = %d\n", i);
//					userData[i] = tempChar;
//					initialFlag = 1;
//					attemptCheckFlag = 1;
//				}
//				else if (tempChar + 32 == buff[buffIndexnum][i])
//				{
//					//printf("\t\tvalue of i = %d\n", i);
//					userData[i] = tempChar + 32;
//					initialFlag = 1;
//					attemptCheckFlag = 1;
//				}
//			}
//			system("cls");		// Clears the screen at this point every time
//			if (attemptCheckFlag == 1)
//			{
//				printf("\t\tYou Entered Right Character.\n");
//				printf("\t\tAttempts Left : %d\n", attemptcounter);
//			}
//			else
//			{
//				printf("\t\tYou Entered Wrong Character!!!\n");
//				attemptcounter--;
//				printf("\t\tAttempts Left : %d\n", attemptcounter);
//			}
//			showData(userData, strlen(buff[buffIndexnum]));
//			attemptCheckFlag = 0;
//		}
//		system("cls");		// clears the screen here also
//		if (strcmp(buff[buffIndexnum], userData) == 0)
//		{
//			printf("\t\tCongrats You won The Game!!!!!!!!!!!!!!!!!!!!\n");
//			printf("\t\tYour Word : ");
//			showData(userData, strlen(buff[buffIndexnum]));
//		}
//		else
//		{
//			printf("\t\tYou loose The Game!!!!!!!!!!!!!!!!!!!!\n");
//			printf("\t\tRight Word : ");
//			showData(buff[buffIndexnum], strlen(buff[buffIndexnum]));
//			printf("\t\tYour Word : ");
//			showData(userData, strlen(buff[buffIndexnum]));
//		}
//		printf("\t\tDo you want to play again?\n");
//		printf("\t\t<1.> Yes\n");
//		printf("\t\t<2.> No\n\t\t");
//		scanf(" %d", &userChoice);
//		if (userChoice == 1)
//		{
//			attemptcounter = 5;
//			buffIndexnum = 0;
//			positionCounter = 0;
//			initialFlag = 0;
//			playAgainFlag = 0;
//			attemptCheckFlag = 0;
//			userChoice = 0;
//			memset(userData, 0, 10);
//		}
//		else
//		{
//			playAgainFlag = 1;
//		}
//		system("cls");		// clears the screen here also
//	} while (!playAgainFlag);
//
//}