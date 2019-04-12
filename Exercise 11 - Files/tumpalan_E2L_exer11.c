/*
TUMPALAN, JOHN KARL B.
CMSC 21 - E-2L
EXERCISE 10 - STRUCTURES
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filetest.h"

int main(){
	playlist songplaylist[10];
	int choice = 0, plSize = 0, plAccess;
	FILE *mainfp;

	if (mainfp = fopen("filetest.txt", "r")){
		loadPlaylists(mainfp, songplaylist, &plSize);
		printf("[!]  Saved playlist loaded.  [!]\n");
	}
	else{
		printf("[!]  Saved playlist not found  [!]\n");
	}

	while (choice != 4){

		printMenu();
		printf("Enter your choice:  ");
		scanf("%d", &choice);

		if (choice == 1){
			//Add playlist
			addPlaylist(&songplaylist[plSize], plSize);

			//Increment playlist size
			plSize ++;
			continue;
		}

		else if (choice == 2){
			//Prints all the playlists
			printf("Playlists:\n");
			for (int i = 0; i < plSize; i++){
				printf("[%d] ", i+1);
				printf("       %s        [%d]\n", songplaylist[i].playlist_name, i+1);
				printf("\n\n");
			}

			//Ask user
			printf("[!] Enter the ID of playlist: ");
			scanf("%d", &plAccess);

			//Add
			addSongtoPlaylist(&songplaylist[plAccess-1]);
			
			//Prompt
			printf("\n\n[!] Song successfully added [!]\n\n");
			continue;
		}

		else if (choice == 3){
			//Prints all the playlists
			printf("Playlists:\n");
			for (int i = 0; i < plSize; i++){
				printf("[%d] ", i+1);
				printf("      %s        [%d]\n", songplaylist[i].playlist_name, i+1);
				printf("\n\n");
			}

			//Ask for input
			printf("[!] Enter the ID of playlist: ");
			scanf("%d", &plAccess); //Sets the access to the input of the user

			//Delete Song based from user input
			deleteSonginPlaylist(&songplaylist[plAccess-1]);

			//Sort all playlists after deletion
			sortDeleted(&songplaylist[plAccess-1]);
			}

			else if (choice == 4){
				mainfp = fopen("filetest.txt", "w");

				savePlaylists(mainfp, songplaylist, plSize);
				printf("\n\n\n[!] Program exit [!]\n");
				fclose(mainfp);
				break;
			}
		else{
			printf("[!] Invalid input [!]\n");
			continue;
		}
	}

	return 0;
}