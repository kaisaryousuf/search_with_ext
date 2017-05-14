#include<Windows.h>
#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include "listing.h"



using namespace std;



int main()
//{
//ListDriveletters();
//return 0;
//}
//void ListDriveLetters()
{
	
	CHAR cDriveLetter = 'A';
	DWORD dwDrivemap = GetLogicalDrives();

	printf("List of drives\n");

	while (cDriveLetter <= 'Z')
	{

		if (0 < (dwDrivemap & 0x00000001L))
		{
			//if (cDriveLetter != 'C'){

			////\\\\\  Adding a ":" after drivename char \\\\//////

			char a = cDriveLetter;
			char cmd[50] = { a };
			char *v[] = { ":" };
			strcat(cmd, v[0]);

			printf("%s\n", cmd);
			listdir(cmd, 0);
			//}
		}
		cDriveLetter++;
		dwDrivemap = dwDrivemap >> 1;
	}
}


