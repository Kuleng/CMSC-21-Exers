/*
TUMPALAN, JOHN KARL B.
CMSC 21 - E-2L
EXERCISE 10 - STRUCTURES
*/

typedef struct song_tag{
	char title[50];
	char singer[50];
	char album[50];
	int songFlag;
} song;
	
typedef struct playlist_tag{
	int id;
	char playlist_name[50];
	int songCount;
	int deletedCount;
	song songlist[10];
} playlist;


void printMenu(){
	printf("[1]       Add Playlist       [1]\n");
	printf("[2]    Add Song to Playlist  [2]\n");
	printf("[3]  Remove Song to Playlist [3]\n");
	printf("[4]           Exit           [4]\n");
}

void viewSong(song S){ //View all details of a song.
	if (S.songFlag != 0){
	printf("Songtitle: %s\n", S.title);
	printf("    Singer: %s\n", S.singer);
	printf("    Album name: %s\n", S.album);
	}
	else
		printf("Song deleted.\n");
}

void addPlaylist(playlist *P, int listID){
	//Ask for playlist name
	printf("Enter playlist name:  ");
	scanf("%s", P->playlist_name);

	//Playlist ID based from order
	P->id = listID;

	//Sets 0 to counter of added songs and deleted songs
	P->songCount = 0;
	P->deletedCount = 0;
	printf("Playlist ID of %s: %d \n\n", P->playlist_name, listID + 1);
}

void viewPlaylistInfo(playlist P){
	printf("Playlist ID: %d \n", P.id+1);
	printf("Playlist name: %s \n\n", P.playlist_name);

	//If empty (Song counter minus deleted counter)
	if (P.deletedCount == P.songCount || P.songCount == 0){
		printf("[!] Playlist empty [!]\n\n");
	}
	else{
		printf("Current songs: \n");
		
		//View all songs
		for (int i = 0; i < P.songCount; i++){
			if (P.songlist[i].songFlag == 0){
				continue;
			}
			else{
				printf("%d.  ", i+1);
				viewSong(P.songlist[i]);
				printf("\n\n");
			}
		}
		//View all songs
		printf("\n\n\n\n\n");
	}
}
void addSongtoPlaylist(playlist *P){
	int songAccess = P->songCount;

	for (int i = 0; i < P->songCount; i++)
	{
		if ((*P).songlist[i].songFlag == 0){ //Finds a deleted Song
			songAccess = i;	//Changes the access integer to the index of the deleted song
			// P->songCount--; //Negates the increment of the song counter on the function
		}
	}

	//Ask user
	printf("Enter song title:");
	scanf("%s", (*P).songlist[songAccess].title);
	printf("Enter singer:");
	scanf("%s", (*P).songlist[songAccess].singer);
	printf("Enter album name:");
	scanf("%s", (*P).songlist[songAccess].album);

	//Increment to song counter
	P->songCount += 1;

	//Sets the deletion flag to 1
	(*P).songlist[songAccess].songFlag = 1;

}

void deleteSong(song *toDelete){
	toDelete->songFlag = 0; //Flags the song as deleted
}

void deleteSonginPlaylist(playlist *P){
	int songAccess;
	viewPlaylistInfo(*P);

	//If playlist is empty, prompt
	if ((*P).songCount == (*P).deletedCount){
		//If empty, display that the playlist is empty then continue with the loop
	}
	else{
		//Ask user
		printf("Enter which song number do you want to delete?"); //If Playlist is valid
		scanf("%d", &songAccess);					//Ask which Song to delete

		//Delete song and increment deleted songs count
		deleteSong(&P->songlist[songAccess-1]);
		P->deletedCount ++;
		printf("[!] Song successfully deleted [!]\n\n");
	}
}

void swap(song *S1, song *S2){
	//Swap values of 2 songs
	song temp = *S1;
	*S1 = *S2;
	*S2 = temp;
	//printf("Swap success!\n");
}

void sortDeleted(playlist *P){
	//Sorting algorithm
	for (int i = 0; i < (*P).songCount-1; i++)
	{
		for (int j = i+1; j < (*P).songCount; j++)
		{
			if ((*P).songlist[i].songFlag == 0 && (*P).songlist[j].songFlag == 0){
				continue;
			}
			else if ((*P).songlist[i].songFlag < (*P).songlist[j].songFlag){
				swap(&P->songlist[i],&P->songlist[j]);
				break;
			}
			break;
		}
	}
}
