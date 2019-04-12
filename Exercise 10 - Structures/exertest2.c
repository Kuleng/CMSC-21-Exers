#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_tag{
	char title[50];
	char singer[50];
	char album[50];
} song;

typedef struct playlist_tag{
	int id;
	char playlist_name[50];
	song songlist[10];
	int songCount;
} playlist;


void printMenu(){
	printf("[1]       Add Playlist       [1]\n");
	printf("[2]    Add Song to Playlist  [2]\n");
	printf("[3]  Remove Song to Playlist [3]\n");
	printf("[4]           Exit           [4]\n");
}

void viewSong(song S){
	printf("Songtitle: %s\n", S.title);
	printf("Singer: %s\n", S.singer);
	printf("Album name: %s\n", S.album);
}

void addPlaylist(playlist *P, int listID){
	printf("Enter playlist name:  ");
	scanf("%s", P->playlist_name);
	P->id = listID;
	P->songCount = 0;
	printf("Playlist ID of %s: %d \n\n", P->playlist_name, listID + 1);
}

void viewPlaylistInfo(playlist P){
	printf("Playlist ID: %d \n", P.id+1);
	printf("Playlist name: %s \n", P.playlist_name);
	if (P.songCount == 0){
		printf("Playlist empty.\n");
	}
	else {
		printf("Current songs: \n");
	}
	for (int i = 0; i < P.songCount; i++){
		viewSong(P.songlist[i]);
	}

	printf("\n\n\n\n\n");
}

void addSongtoPlaylist(playlist *P){
	printf("%d \n", P.songCount1);
	printf("Enter song title:");
	scanf("%s", P->songlist[P.songCount]->title);
	printf("Enter singer:");
	scanf("%s", P->songlist[P.songCount]->singer);
	printf("Enter album name:");
	scanf("%s", P->songlist[P.songCount]->album);

	P->songCount += 1;

	printf("Song count: %d\n", P->songCount);
}

void deleteSonginPlaylist(playlist *P){
	viewPlaylistInfo(*P);
}

int main(){
	playlist songplaylist[10];
	int choice = 0, plSize = 0, plAccess;

	while (choice != 4){

		printMenu();
		printf("Enter your choice:  ");
		scanf("%d", &choice);

		if (choice == 1){
			addPlaylist(&songplaylist[plSize], plSize);
			plSize ++;
			continue;
		}

		else if (choice == 2){
			for (int i = 0; i < plSize; i++){
				viewPlaylistInfo(songplaylist[i]);
			}
			printf("[!] Enter the ID of playlist: ");
			scanf("%d", &plAccess);

			addSongtoPlaylist(&songplaylist[plAccess-1]);z
			continue;
		}

		else if (choice == 3){
			for (int i = 0; i < plSize; i++){
				viewPlaylistInfo(songplaylist[i]);
			}
		printf("[!] Enter the ID of playlist: ");
		scanf("%d", &plAccess); //Sets the access to the input of the user

		deleteSonginPlaylist(&songplaylist[plAccess-1]);
		}

		else if (choice == 4){
			printf("[!] Program exit [!]\n");
			break;
		}
		else{
			printf("[!] Invalid input [!]\n");
			continue;
		}
	}

	return 0;
}