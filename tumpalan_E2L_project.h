#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// STRUCTURE DEFINITIONS
typedef struct birthdayTag{
	int year;
	int month;
	int day;
}DATE;

typedef struct timeTag{
	int hour;
	int min;
}TIME;

typedef struct passengerTag{
	char firstName[60];
	char lastName[40];
	DATE birthday;
	int passportNum;
	int miles;
	struct passengerTag *nextPassenger;
}PASSENGERS;

typedef struct flightTag{
	int flightID;
	char destination[50];
	char origin[50];
	DATE departureDate;
	DATE arrivalDate;
	TIME departureTime;
	TIME arrivalTime;
	int passengerNum;
	int passengerMax;
	int bonusMiles;
	struct flightTag *nextFlight;
	PASSENGERS *headPassenger;
}FLIGHT;

int getInt(int *intVar, char tempInput[]){
	int size, i;

	size = strlen(tempInput);

	if (size <= 6){
		for (i = 0; i < size; i ++){
			if (isdigit(tempInput[i]) == 0){
				printf("\t+-------------------------------------------+\n");
				printf("\t|             Wrong input format            |\n");
				printf("\t|               Not an integer              |\n");
				printf("\t+-------------------------------------------+\n");
				return 0;
			}
		}
	} else{
		printf("\t+-------------------------------------------+\n");
		printf("\t|             Wrong input format            |\n");
		printf("\t|            or input very large            |\n");
		printf("\t+-------------------------------------------+\n");
		return 0;
	}

	(*intVar) = atoi(tempInput);

    return 1;
}

//PRINT MENU

int isEmpty(FLIGHT **headFlight){
	if ((*headFlight) == NULL){
			printf("\t+-------------------------------------------+\n");
			printf("\t|          There are no flights yet.        |\n");
			printf("\t|          Please add flights first.        |\n");
			printf("\t+-------------------------------------------+\n");	
			return 1;
	}

	return 0;
}

void printMenu(int menuID){
	if (menuID == 1){ //Main menu
		printf("\n\n\n\t+--------------------------------------+\n");
		printf("\t| [1]         Add Flight            [1] |\n");
		printf("\t| [2]         Edit Flight           [2] |\n");
		printf("\t| [3]        View Flights           [3] |\n");
		printf("\t| [4]        Delete Flight          [4] |\n");
		printf("\t| [5]       Add a Passenger         [5] |\n");
		printf("\t| [6]    Edit Passenger details     [6] |\n");
		printf("\t| [7]   Book a Flight Reservation   [7] |\n");
		printf("\t| [8]   Remove Flight Reservation   [8] |\n");
		printf("\t| [9]       View Reservations       [9] |\n");
		printf("\t| [10]           Exit              [10] |\n");
		printf("\t+---------------------------------------+\n");
	}
	else if (menuID ==2){ //Main 3
		printf("\t+--------------------------------------------+\n");
		printf("\t| [1]       View Specific Flight         [1] |\n");
		printf("\t| [2]     View All Available Flights     [2] |\n");
		printf("\t| [3]    View All Fully-booked Flights   [3] |\n");
		printf("\t| [4]          View All Flights          [4] |\n");
		printf("\t+--------------------------------------------+\n");		
	}

	printf("\n\n\n\tEnter your choice:  ");
}


/*
This function collects a string in a specific format,
checks the format if it is correct, then
check the strings if they were digits,  and then compares
them to common changes within the month, years, days, and possible
leap years
*/

int dateCheck(DATE *dateVariable, char tempDate[]){
	int size = strlen(tempDate);
	int year, month, day;
	if (tempDate[4] != '/' && tempDate[6] != '/'){
		//Format check
		printf("\t+-------------------------------------------+\n");
		printf("\t|             Wrong input format            |\n");
		printf("\t|  Input shall be in the format YYYY/MM/DD  |\n");
		printf("\t|       Fill single digits with 0           |\n");
		printf("\t+-------------------------------------------+\n");
		return 0;
	}
	else{
		//Integer check
		for (int i = 0; i < size - 1; i ++){
			if (i != 4 && i != 7){ //If the indexes are not a number
				if (isdigit(tempDate[i]) == 0){
					printf("\t+-------------------------------------------+\n");
					printf("\t|             Wrong input format            |\n");
					printf("\t|  Input shall be in the format YYYY/MM/DD  |\n");
					printf("\t|       Fill single digits with 0           |\n");
					printf("\t+-------------------------------------------+\n");
					return 0;
				}
			}
		}
		

		year = atoi(tempDate);
		month = atoi(tempDate + 5);
		day = atoi(tempDate + 8);

		if (year < 1903){
			printf("\n\t[!]   The first powered aircraft was built in 1903   [!]\n\n");
			return 0;
		}
		if (month == 2){
			if (year % 4 != 0){
				if (day < 0 || day > 28){
					printf("\t[!]   Invalid input   [!]\n");
					return 0;
				}
			}
			else{
				if (day < 0 || day > 29){
					printf("\t[!]   Invalid input   [!]\n");
					return 0;
					}
				}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			if (day < 0 || day > 31) return 0;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11){
			if (day < 0 || day > 30) return 0;
		}
		else{
			printf("\t+---------------------------+\n");
			printf("\t| [!]   Invalid month   [!] |\n");
			printf("\t+---------------------------+\n");
			return 0;
		}
	}

	dateVariable->year = year;
	dateVariable->month = month;
	dateVariable->day = day;

	return 1;
}

int timeCheck(TIME *timeVariable, char tempTime[]){
	int tempHour, tempMin;

	int size = strlen(tempTime);
	if (size > 5 || tempTime[2] != ':'){
		printf("\t[!]   Invalid time format   [!]\n");
		return 0;
	}
	else{
		for (int i = 0; i < size - 1; i ++){
			if (i != 2 ){ //If the indexes are not a number
				if (isdigit(tempTime[i]) == 0){
					printf("\t+----------------------------------+\n");
					printf("\t| [!]      Not an integer      [!] |\n");
					printf("\t| [!]    Invalid time format   [!] |\n");
					printf("\t| [!]     Format:   hh:mm      [!] |\n");
					printf("\t+----------------------------------+\n");

					return 0;
				}
			}
		}
	}

	tempHour = atoi(tempTime);
	tempMin = atoi(tempTime+3);

	if (tempHour > 24){
		printf("\t[!]   Invalid hour   [!]\n");
		return 0;
	}
	else if (tempMin > 59){
		printf("\t[!]   Invalid minute   [!]\n");
		return 0;
	}

	timeVariable->hour = tempHour;
	timeVariable->min = tempMin;

	return 1;
}

int arrivalOverDepature(DATE *dateVariable1, DATE *dateVariable2, TIME *timeVariable1, TIME *timeVariable2){
	if (dateVariable1->year < dateVariable2->year) return 1;
	else if (dateVariable1->year == dateVariable2->year){
		if (dateVariable1->month < dateVariable2->month) return 1;
		else if (dateVariable1->month == dateVariable2->month){
			if (dateVariable1->day < dateVariable2->day) return 1;
			else if(dateVariable1->day == dateVariable2->day){
				if (timeVariable1->hour < timeVariable2->hour) return 1;
				else if (timeVariable1->hour == timeVariable2->hour){
					if (timeVariable1->min < timeVariable2->min) return 1;
					else return 0;
				}
			}
		}
	}

	return 0;
}

/*
These functions deallocates the memory used by the program after saving it to the textfiles.
*/
void freePassengers(PASSENGERS **pssgrHead){
	PASSENGERS *delPtr = (*pssgrHead);

	while ((*pssgrHead) != NULL){
		delPtr = (*pssgrHead);
		(*pssgrHead) = delPtr->nextPassenger;
		free(delPtr);
	}
}

void freeFlights(FLIGHT **flightHead){
	FLIGHT *flightDel = (*flightHead);

	while ((*flightHead) != NULL){
		flightDel = (*flightHead);
		freePassengers(&flightDel->headPassenger);
		(*flightHead) = flightDel->nextFlight;
		free(flightDel);
	}
}


//View flight information
void viewFlightInfo(FLIGHT *viewPtr){
	printf("==============================================\n");
	printf("[Flight ID]: %d\n", viewPtr->flightID);
	printf(" ---->           %s   TO    %s\n", viewPtr->origin, viewPtr->destination);
	printf("\t--------------------------------------\n");
	printf("\t*  Departure   : %02d / %02d / %02d \n", viewPtr->departureDate.year,viewPtr->departureDate.month, viewPtr->departureDate.day);
	printf("\t*   [Time]     : %2d : %02d\n", viewPtr->departureTime.hour, viewPtr->departureTime.min);
	printf("\t--------------------------------------\n");
	printf("\t*  Arrival     : %02d / %02d / %02d \n", viewPtr->arrivalDate.year, viewPtr->arrivalDate.month, viewPtr->arrivalDate.day);
	printf("\t*   [Time]     : %2d : %02d\n", viewPtr->arrivalTime.hour, viewPtr->arrivalTime.min);
	printf("\t--------------------------------------\n");
	printf("\t*Current number of passengers:    %d\n", viewPtr->passengerNum);
	printf("\t*Maximum passengers:              %d\n", viewPtr->passengerMax);
	printf("\t*Bonus miles       :              %d\n", viewPtr->bonusMiles);
	printf("==============================================\n");
}


/* CONFLICT CHECKER
This function checks the current flight of the passenger and loops through
flight linked list and checks his/her current flights. If there are
same departure date and time, returns 1. returns 0 if no conflicts.
*/
int conflictCheck(FLIGHT **headFlight, PASSENGERS *pssgrPtr, FLIGHT *comparePtr, int x){
	FLIGHT *flightPtr = (*headFlight);

	//Compare ptr is the flight to be booked

	while (flightPtr != NULL){
		PASSENGERS *passengerFinder = flightPtr->headPassenger;
		while (passengerFinder != NULL){
			if (passengerFinder->passportNum == pssgrPtr->passportNum){
				if (x == 0 && flightPtr->flightID == comparePtr->flightID){
					printf("\n\t[!]   Flight already booked   [!}\n");
					return 1;
				}
				else if (x != 0 &&  flightPtr->flightID == comparePtr->flightID) break;

				if ((flightPtr->departureDate.year == comparePtr->departureDate.year && flightPtr->arrivalDate.year == comparePtr->departureDate.year) || (flightPtr->departureDate.year == comparePtr->arrivalDate.year && flightPtr->arrivalDate.year == comparePtr->arrivalDate.year)){
					if ((flightPtr->departureDate.month == comparePtr->departureDate.month && flightPtr->arrivalDate.month == comparePtr->departureDate.month) || (flightPtr->departureDate.month == comparePtr->arrivalDate.month && flightPtr->arrivalDate.month == comparePtr->arrivalDate.month)){
						if ((flightPtr->departureDate.day == comparePtr->departureDate.day && flightPtr->arrivalDate.day == comparePtr->departureDate.day)||(flightPtr->departureDate.day == comparePtr->arrivalDate.day && flightPtr->arrivalDate.day == comparePtr->arrivalDate.day)){
							if ((flightPtr->departureTime.hour == comparePtr->departureTime.hour && flightPtr->arrivalTime.hour == comparePtr->arrivalTime.hour) || flightPtr->departureTime.hour == comparePtr->departureTime.hour && flightPtr->departureTime.hour == comparePtr->arrivalTime.hour || flightPtr->arrivalTime.hour == comparePtr->departureTime.hour && flightPtr->arrivalTime.hour == comparePtr->arrivalTime.hour){
								if ((flightPtr->departureTime.hour == comparePtr->departureTime.hour && flightPtr->arrivalTime.hour == comparePtr->arrivalTime.hour) || (flightPtr->departureTime.min <= comparePtr->departureTime.min && flightPtr->arrivalTime.min >= comparePtr->departureTime.min) || flightPtr->departureTime.min <= comparePtr->arrivalTime.min && flightPtr->arrivalTime.min >= comparePtr->arrivalTime.min || (comparePtr->departureTime.min <= flightPtr->departureTime.min && comparePtr->arrivalTime.min >= flightPtr->arrivalTime.min)){
									printf("\n\n[!]   Date and time overlapped with another flight.   [!] \n\n");
									return 1;
								}
							}
							else if ((flightPtr->departureTime.hour < comparePtr->departureTime.hour && flightPtr->arrivalTime.hour > comparePtr->departureTime.hour) || flightPtr->departureTime.hour < comparePtr->arrivalTime.hour && flightPtr->arrivalTime.hour > comparePtr->arrivalTime.hour || (comparePtr->departureTime.hour < flightPtr->departureTime.hour && comparePtr->arrivalTime.hour > flightPtr->arrivalTime.hour)){
								printf("\n\n[!]   Date and time overlapped with another flight.   [!] \n\n");
								return 1;
							}
						}
						else if ((flightPtr->departureDate.day < comparePtr->departureDate.day && flightPtr->arrivalDate.day > comparePtr->departureDate.day) || (flightPtr->departureDate.day < comparePtr->arrivalDate.day && flightPtr->arrivalDate.day > comparePtr->arrivalDate.day) || (comparePtr->departureDate.day < flightPtr->departureDate.day && comparePtr->arrivalDate.day > flightPtr->arrivalDate.day)){
							printf("Date and time overlapped with another flight.\n");
							return 1;
						}
					}
					else if ((flightPtr->departureDate.month < comparePtr->departureDate.month && flightPtr->arrivalDate.month > comparePtr->departureDate.month) || (flightPtr->departureDate.month < comparePtr->arrivalDate.month && flightPtr->arrivalDate.month > comparePtr->arrivalDate.month) || (comparePtr->departureDate.month < flightPtr->departureDate.month && comparePtr->arrivalDate.month > flightPtr->arrivalDate.month)){
						printf("Date and time overlapped with another flight.\n");
						return 1;
					}
				}
				else if ((flightPtr->departureDate.year < comparePtr->departureDate.year && flightPtr->arrivalDate.year > comparePtr->departureDate.year) || (flightPtr->departureDate.year < comparePtr->arrivalDate.year && flightPtr->arrivalDate.year > comparePtr->arrivalDate.year) || (comparePtr->departureDate.year < flightPtr->departureDate.year && comparePtr->arrivalDate.year > flightPtr->arrivalDate.year)){
					printf("Date and time overlapped with another flight.\n");
					return 1;
				}
			}
			passengerFinder = passengerFinder->nextPassenger;
		}
		flightPtr = flightPtr->nextFlight;
	}

	return 0;
}

//ADD DATA TO THE FLIGHT NODE
void addInfo_flight(FLIGHT *newFlight, FLIGHT **headFlight, int *flightCount){
	int idUniqueness, departureValidity, arrivalValidity, timeValidity1, timeValidity2, timeDateValidity = 0 , maxValidity,mileValidity;
	char dateVar1[20], dateVar2[20], timeVar[10], timeVar2[10], tempMax[20], tempMiles[20];
	int size;

	do {
		size = 0;
		printf("\tEnter new flight's destination:   ");
		scanf("%[^\n]s", newFlight->destination);
		getchar();
		size = strlen(newFlight->destination);
		if (size == 0) printf("\n\t[!]  You entered an empty string   [!]\n");
	} while (size == 0);

	do{
		size = 0;
		printf("\tEnter new flight's origin:   ");
		scanf("%[^\n]s", newFlight->origin);
		getchar();
		size = strlen(newFlight->origin);
		printf("%d\n", size);
		if (size == 0) printf("\n\t[!]  You entered an empty string   [!]\n");
	} while (size == 0);

	while(timeDateValidity == 0){
		do {
			departureValidity = 2;
			printf("\tEnter the date of departure (YYYY/MM/DD):   ");
			scanf("%[^\n]s", dateVar1);
			getchar();
			departureValidity = dateCheck(&newFlight->departureDate, dateVar1);
			if (departureValidity == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
		} while (departureValidity != 1);
	
	
		do{
			printf("\tEnter time of departure (HH:MM [Military time]):   ");
			scanf("%[^\n]s", timeVar);
			getchar();
			timeValidity1 = timeCheck(&newFlight->departureTime, timeVar);
			if (timeValidity1 == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
		} while (timeValidity1 != 1);
	
		do {
			arrivalValidity = 2;
			printf("\tEnter the date of arrival (YYYY/MM/DD):   ");
			scanf("%[^\n]s", dateVar2);
			getchar();
			arrivalValidity = dateCheck(&newFlight->arrivalDate, dateVar2);
			if (arrivalValidity == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
		} while (arrivalValidity != 1);
	
	
		do{
			printf("\tEnter time of arrival  (HH:MM [Military time]):   ");
			scanf("%[^\n]s", timeVar2);
			getchar();
			timeValidity2 = timeCheck(&newFlight->arrivalTime, timeVar2);
			if (timeValidity2 == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
		} while (timeValidity2 != 1);

		timeDateValidity = arrivalOverDepature(&newFlight->departureDate, &newFlight->arrivalDate, &newFlight->departureTime, &newFlight->arrivalTime);
		if (timeDateValidity == 0){
			printf("\t+-------------------------------------------+\n");
			printf("\t|    Arrival must be set after departure    |\n");
			printf("\t|     Please re-enter time and dates        |\n");
			printf("\t+-------------------------------------------+\n");
		}
	}

	do{
		printf("\tEnter maximum passengers of this flight:   ");
		scanf("%[^\n]s", tempMax);
		getchar();
		maxValidity = getInt(&newFlight->passengerMax, tempMax);
	} while (maxValidity != 1);

	newFlight->passengerNum = 0;

	do{
		printf("\tEnter bonus miles this flight:   ");
		scanf("%[^\n]s", tempMiles);
		getchar();
		mileValidity = getInt(&newFlight->bonusMiles, tempMiles);
	} while (mileValidity != 1);
	
	newFlight->nextFlight = NULL;

	newFlight->headPassenger = NULL;
	newFlight->flightID = (*flightCount);
	
	printf("==============================================\n");
	printf("[Flight ID]: %d\n", newFlight->flightID);
	printf(" ---->           %s   TO    %s\n", newFlight->origin, newFlight->destination);
	printf("\t--------------------------------------\n");
	printf("\t*  Departure   : %02d / %02d / %02d \n", newFlight->departureDate.year,newFlight->departureDate.month, newFlight->departureDate.day);
	printf("\t*   [Time]     : %02d : %02d \n", newFlight->departureTime.hour, newFlight->departureTime.min);
	printf("\t--------------------------------------\n");
	printf("\t*  Arrival     : %02d / %02d / %02d \n", newFlight->arrivalDate.year, newFlight->arrivalDate.month, newFlight->arrivalDate.day);
	printf("\t*   [Time]     : %02d : %02d \n", newFlight->arrivalTime.hour, newFlight->arrivalTime.min);
	printf("\t--------------------------------------\n");
	printf("\t*Current number of passengers:    %d\n", newFlight->passengerNum);
	printf("\t*Maximum passengers:              %d\n", newFlight->passengerMax);
	printf("\t*Bonus miles       :              %d\n", newFlight->bonusMiles);
	printf("==============================================\n");

}

void insertAtHead(FLIGHT **headFlight, FLIGHT *newFlight){
	newFlight->nextFlight = (*headFlight);
	(*headFlight) = newFlight; 
	//Insert an allocated node to the head of the linked list
}

void insertAtMiddle(FLIGHT *stalker, FLIGHT *newFlight, FLIGHT *mainFlightPtr){
	newFlight->nextFlight = mainFlightPtr;
	stalker->nextFlight = newFlight;
 		//Insert an allocated node to the middle of the linked list
}

void traverseFlightPtr(FLIGHT **stalker, FLIGHT **mainFlightPtr){
	(*stalker) = (*mainFlightPtr);
	(*mainFlightPtr) = (*mainFlightPtr)->nextFlight; 
		//A stalker pointer takes the position of the main pointer as the main pointer traverses
}

//ADD FLIGHT
/*The function checks if the ID is unique by calling the isUnique function, and voids it if it's not.
It checks for the possibility of an overlapping flight thru multiple conditional statements and
loops through it until NULL or until it points to the proper sorted position in the linked list
considering the hierarchy of sorting given by the specifications*/
void addFlight(FLIGHT **headFlight, int *flightCount){
	FLIGHT *newFlight = (FLIGHT*) malloc(sizeof(FLIGHT));
	addInfo_flight(newFlight, &(*headFlight), flightCount);	
	FLIGHT *flightPtr = (*headFlight);
	FLIGHT *stalker = NULL;

	while (flightPtr != NULL){
		if (newFlight->departureDate.year == flightPtr->departureDate.year) {
			if ((newFlight->departureDate.month == flightPtr->departureDate.month)){
				if ((newFlight->departureDate.day == flightPtr->departureDate.day)){
					if ((newFlight->departureTime.hour == flightPtr->departureTime.hour)){
						if ((newFlight->departureTime.min) == flightPtr->departureTime.min){
							if (strcasecmp(newFlight->origin, flightPtr->origin) == 0){
								if (strcasecmp(newFlight->destination, flightPtr->destination) <= 0){
									if (stalker == NULL){
										insertAtHead(&(*headFlight), newFlight);
										return;
									}
									else{
										break; //break to insert at middle
									}
								}
								else {
									traverseFlightPtr(&stalker, &flightPtr);
								}
							}
							else if (strcasecmp(newFlight->origin, flightPtr->origin) < 0){
								if (stalker == NULL){
									insertAtHead(&(*headFlight), newFlight);
									return;
								}
								else{
									break;
								}
							}
							else {
								traverseFlightPtr(&stalker, &flightPtr);
							}
						}
						else if ((newFlight->departureTime.min) < flightPtr->departureTime.min){
							if (stalker == NULL){
							insertAtHead(&(*headFlight), newFlight);
							return;
							}
							else{
								break;
							}
						}
						else{
							traverseFlightPtr(&stalker, &flightPtr);
						}
					}
					else if ((newFlight->departureTime.hour < flightPtr->departureTime.hour)){
						if (stalker == NULL){
							insertAtHead(&(*headFlight), newFlight);
							return;
						}
						else{
							break;
						}
					}
					else{
						traverseFlightPtr(&stalker, &flightPtr);
					}
				}
				else if (newFlight->departureDate.day < flightPtr->departureDate.day){
						if (stalker == NULL){
							//insert at head
							insertAtHead(&(*headFlight), newFlight);
							return;
						}
						else{
							break;
						}
					}
				else{
					traverseFlightPtr(&stalker, &flightPtr);
				}
			}
			else if(newFlight->departureDate.month < flightPtr->departureDate.month){
				if (stalker == NULL){
					insertAtHead(&(*headFlight), newFlight);
					return;
				}
				else{
					break;
				}
			}
			else{
				traverseFlightPtr(&stalker, &flightPtr);
			}
		}
		else if(newFlight->departureDate.year < flightPtr->departureDate.year){
			if (stalker == NULL){
				insertAtHead(&(*headFlight), newFlight);
				return;
			}
			else{
				break;
			}
		}
		else{
			traverseFlightPtr(&stalker, &flightPtr);
		}
	}

	insertAtMiddle(stalker, newFlight, flightPtr);
} 

/* //View flights
This function asks the classification of the flight that they want to view.
The function loops the flight linked list and if the node satisfies the
choice of the user, view flight information is called on that specific node.
*/
void viewFlights(FLIGHT **headFlight, int userChoice){
	FLIGHT *viewPtr = (*headFlight);
	int toView,viewValidity, promptVar = 0;
	char viewInput[20];

	if (userChoice == 1){
		do{
			printf("What is the ID of the flight that you want to view?\n");
			scanf("%[^\n]s", viewInput);
			getchar();
			viewValidity = getInt(&toView, viewInput);
		} while (viewValidity != 1);

		while(viewPtr != NULL){
			if (toView == viewPtr->flightID){
				printf("\n\n [!]   FLIGHT FOUND   [!]\n\n");
				viewFlightInfo(viewPtr);
				promptVar ++;
				break;
			}
			else{
				viewPtr = viewPtr->nextFlight;
			}
		}

		if (promptVar == 0) printf("\n\n [!]   Flight not found   [!]\n\n");
	}
	else if (userChoice == 2){
		while(viewPtr!= NULL){
			if (viewPtr->passengerNum != viewPtr->passengerMax){
				viewFlightInfo(viewPtr);
				promptVar++;
			}
			viewPtr = viewPtr->nextFlight;
		}

		if (promptVar == 0) printf("\n\n [!]   There are no available flights   [!]\n\n");
	}
	else if (userChoice == 3){
		while(viewPtr!= NULL){
			if (viewPtr->passengerNum == viewPtr->passengerMax){
				viewFlightInfo(viewPtr);
				promptVar++;	
			}
			viewPtr = viewPtr->nextFlight;
		}
		if (promptVar == 0) printf("\n\n [!]   There are no Fully-booked flights   [!]\n\n");
	}
	else if (userChoice == 4){
		while(viewPtr != NULL){
			viewFlightInfo(viewPtr);
			viewPtr = viewPtr->nextFlight;
			promptVar ++;
		}

		if (promptVar == 0) printf("\n\n [!]   Flight not found   [!]\n\n");
	}
	else{
		printf("\n\n [!]   Invalid input   [!]\n\n");
	}
}

int isBorn(FLIGHT *flightPtr, PASSENGERS *pssgrPtr){
	if (flightPtr->departureDate.year == pssgrPtr->birthday.year){
		if (flightPtr->departureDate.month == pssgrPtr->birthday.month){
			if (flightPtr->departureDate.day < pssgrPtr->birthday.day) return 0;
		}else if (flightPtr->departureDate.month < pssgrPtr->birthday.month) return 0;
	} else if (flightPtr->departureDate.year < pssgrPtr->birthday.year) return 0;

	return 1;
}

/* //Edit flights
The function asks for the flight ID on the user and loops the linked list to find that specific flight
It displays the current information of the flight and then enables
the user to edit the information of the flight
*/
void editFlight(FLIGHT **headFlight){
	int tempID, bornVar = 0, conflict = 1, promptVar = 0, flightIDaccess, fAccessValidity, maxValidity;
	FLIGHT *editPtr = (*headFlight);

	char dateVar1[20], dateVar2[20], timeVar[10], timeVar2[10], tempInput[20], tempInput2[20], tempMax[20];
	int departureValidity, arrivalValidity, timeValidity1, timeValidity2, timeDateValidity = 0;

	//					Search algorithm
	if (editPtr == NULL) {
		printf("\t[!]  No flights yet   [!]\n");
	}
	else{
		do{
			printf("Enter the flight ID of the flight you want to edit:  ");
			scanf("%[^\n]s", tempInput);
			getchar();
			fAccessValidity = getInt(&flightIDaccess, tempInput);
		} while (fAccessValidity != 1);


		while(editPtr != NULL){
			if (flightIDaccess == editPtr->flightID){
				printf("\n\t      [!]  Flight found  [!]\n\n");
				promptVar++;
				break;
			}
			editPtr = editPtr->nextFlight;
		}
		if (promptVar == 0){
			printf("\n\t     [!]  Flight not found   [!]\n\n");
			return;
		}
	}
	//				End of search algorithm

	PASSENGERS *pssgrPtr;

	//				Display current information
	printf("\t  Current editable Information of the flight:  \n\n");
	printf("\t+----------------------------------------------+\n");
	printf("\t| Departure date:     %02d / %02d / %02d\n", editPtr->departureDate.year,editPtr->departureDate.month, editPtr->departureDate.day);
	printf("\t| Departure time:     %02d : %02d\n", editPtr->departureTime.hour, editPtr->departureTime.min);
	printf("\t| Arrival date:       %02d / %02d / %02d\n", editPtr->arrivalDate.year,editPtr->arrivalDate.month, editPtr->arrivalDate.day);
	printf("\t| Arrival time:       %02d : %02d\n", editPtr->arrivalTime.hour, editPtr->arrivalTime.min);
	printf("\t| Max passengers:     %02d\n", editPtr->passengerMax);
	printf("\t+----------------------------------------------+\n");

	//				Edit information block
	while (timeDateValidity == 0 || bornVar == 0 || conflict == 1){
		pssgrPtr = editPtr->headPassenger;
		
		do {
			printf("\tEnter new date of departure (YYYY/MM/DD):   ");
			scanf("%[^\n]s", dateVar1);
			getchar();
			departureValidity = dateCheck(&editPtr->departureDate, dateVar1);
			if (departureValidity == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
		} while (departureValidity != 1);

		do{
			printf("\tEnter time of arrival (HH:MM [Military time]):   ");
			scanf("%[^\n]s", timeVar);
			getchar();
			timeValidity1 = timeCheck(&editPtr->arrivalTime, timeVar);
			if (timeValidity1 == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
		} while (timeValidity1 != 1);

		do {
			printf("\tEnter new date of arrival (YYYY/MM/DD):   ");
			scanf("%[^\n]s", dateVar2);
			getchar();
			arrivalValidity = dateCheck(&editPtr->arrivalDate, dateVar2);
			if (arrivalValidity == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
		} while (arrivalValidity != 1);

		do{
			printf("\tEnter time of arrival:   ");
			scanf("%[^\n]s", timeVar2);
			getchar();
			timeValidity2 = timeCheck(&editPtr->arrivalTime, timeVar2);
			if (timeValidity2 == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
		} while (timeValidity2 != 1);

		while (pssgrPtr != NULL){
			bornVar = isBorn(editPtr, pssgrPtr);
			if (bornVar == 0){
				printf("\t+---------------------------------------------+\n");
				printf("\t|   There will be a conflict on a passenger   |\n");
				printf("\t| Passenger %02d is not yet born on this date   |\n", pssgrPtr->passportNum);
				printf("\t|     Please re-enter time and dates          |\n");
				printf("\t+---------------------------------------------+\n");
				break;
			}

			conflict = conflictCheck(headFlight, pssgrPtr, editPtr, 1);
			if (conflict == 1){
				printf("\t+---------------------------------------------+\n");
				printf("\t|   There will be a conflict on a passenger   |\n");
				printf("\t|   Passenger %02d has an overlapping flight   |\n", pssgrPtr->passportNum);
				printf("\t|     Please re-enter time and dates          |\n");
				printf("\t+---------------------------------------------+\n");
				break;
			}

			pssgrPtr = pssgrPtr->nextPassenger;
		}

		if (pssgrPtr == NULL){
			conflict = 0;
			bornVar = 1;
		}

		timeDateValidity = arrivalOverDepature(&editPtr->departureDate, &editPtr->arrivalDate, &editPtr->departureTime, &editPtr->arrivalTime);
		if (timeDateValidity == 0){
			printf("\t+-------------------------------------------+\n");
			printf("\t|    Arrival must be set after departure    |\n");
			printf("\t|     Please re-enter time and dates        |\n");
			printf("\t+-------------------------------------------+\n");
		}
	}

	do{
		printf("\tEnter maximum passengers of this flight:   ");
		scanf("%[^\n]s", tempMax);
		getchar();
		maxValidity = getInt(&editPtr->passengerMax, tempMax);
		
		if (editPtr->passengerMax < editPtr->passengerNum){
			printf("\t+-------------------------------------------+\n");
			printf("\t|       Invalid. The max passengers         |\n");
			printf("\t|  will conflict current num of passengers  |\n");
			printf("\t+-------------------------------------------+\n");			
			maxValidity = 0;
		}

	} while (maxValidity != 1);

	printf("\n\t        [!]   Successfully Edited   [!]\n\n");
	
	//				Display new information
	printf("\t         New Information of the flight:  \n\n");
	printf("\t+----------------------------------------------+\n");
	printf("\t| Departure date:     %02d / %02d / %02d\n", editPtr->departureDate.year,editPtr->departureDate.month, editPtr->departureDate.day);
	printf("\t| Departure time:     %02d : %02d\n", editPtr->departureTime.hour, editPtr->departureTime.min);
	printf("\t| Arrival date:       %02d / %02d / %02d\n", editPtr->arrivalDate.year,editPtr->arrivalDate.month, editPtr->arrivalDate.day);
	printf("\t| Arrival time:       %02d : %02d\n", editPtr->arrivalTime.hour, editPtr->arrivalTime.min);
	printf("\t| Max passengers:     %02d\n", editPtr->passengerMax);
	printf("\t+----------------------------------------------+\n");

}



/* //DELETE FLIGHTS
The function searches for the flight ID given by the user.
If the flight ID exists, it checks if the flight have no passengers.
Displays double confirmation for deletion if the flight have 0 passengers.
*/
int deleteFlight(FLIGHT **headFlight){
	int tempID, fAccessValidity, flightIDaccess, confirmValidity;
	char tempInput[20], tempConfirm[20];

	FLIGHT *delPtr = (*headFlight);
	FLIGHT *stalker = (*headFlight);

	int promptVar = 0, doubleConfirm;

	//Search algorithm
	if (delPtr == NULL) {
		printf("No flights yet.\n");
	}
	else{
		do{
			printf("Enter the flight ID of the flight you want to delete:  ");
			scanf("%[^\n]s", tempInput);
			getchar();
			fAccessValidity = getInt(&flightIDaccess, tempInput);
		} while (fAccessValidity != 1);


		while(delPtr != NULL){
			if (flightIDaccess == delPtr->flightID){
				printf("\t[!]   Flight found   [!]\n");
				promptVar++;
				break;
			}
			delPtr = delPtr->nextFlight;
		}

		//If the loop does not find a match
		if (promptVar == 0){
			printf("\t[!]   Flight not found   [!]\n");
			return 0;
		}
	}

	//If there are no passengers, initiate delete.
	if (delPtr->passengerNum == 0){
		printf("\t      Flight has no passengers.\n");
		printf("\tDo you really want to delete this flight?\n\n");
		viewFlightInfo(delPtr);

		do{
			printf("\n\n[1] YES\n[2] NO\t\nChoice:   ");
			scanf("%[^\n]s", tempConfirm);
			getchar();
			confirmValidity = getInt(&doubleConfirm, tempConfirm);
		} while (confirmValidity != 1);

		if (doubleConfirm == 1){
			//Initialize stalker position
			while (stalker->nextFlight != NULL && stalker->nextFlight != delPtr){
				stalker = stalker->nextFlight;
			}

			//Delete algorithm
			if (delPtr == (*headFlight)){
				(*headFlight) = delPtr->nextFlight;
			}
			else{
				stalker->nextFlight = delPtr->nextFlight;
			}
			free(delPtr);
			printf("\t[!]   Successfully deleted   [!]\n");
			return 1;
		}
		else{
			printf("\n\t[!]   Deletion aborted   [!]\n");
			return 0;
		}
	}
	else{
		printf("\t+----------------------------------------------+\n");
		printf("\t|          The flight is not yet empty         |\n");
		printf("\t| Please delete all reservations in the flight |\n");
		printf("\t+----------------------------------------------+\n");
		return 0;
	}
}


//Passenger insert at head
void insertAtHead_P(PASSENGERS **passengerHead, PASSENGERS *newPassenger){
	newPassenger->nextPassenger = (*passengerHead);
	(*passengerHead) = newPassenger;
}

//ADD PASSENGER INFORMATION
void addPassengerInformation(PASSENGERS *newPassenger){

	char tempBday[20], tempInput[20];
	int bdayValidity, accessValidity, size;

	do{
		size = 0;
		printf("\n \tEnter passenger's first name:  ");
		scanf("%[^\n]s" , newPassenger->firstName);
		getchar();
		size = strlen(newPassenger->firstName);
		if (size == 0) printf("\n\t[!]  You entered an empty string   [!]\n");
	} while (size == 0);

	do{
		size = 0;
		printf("\n \tEnter passenger's last name:  ");
		scanf("%[^\n]s" , newPassenger->lastName);
		getchar();
		size = strlen(newPassenger->lastName);
		if (size == 0) printf("\n\t[!]  You entered an empty string   [!]\n");
	} while (size == 0);

	do {
		printf("\n \tEnter passenger's birthday (YYYY/MM/DD):   ");
		scanf("%[^\n]s", tempBday);
		getchar();
		bdayValidity = dateCheck(&newPassenger->birthday, tempBday);
		if (bdayValidity == 0) printf("\n\t[!]   Invalid input   [!]\n\n");
	} while (bdayValidity != 1);

	do{
		printf("\n\tEnter passenger's passport number:  ");
		scanf("%[^\n]s", tempInput);
		getchar();
		accessValidity = getInt(&newPassenger->passportNum, tempInput);
	} while (accessValidity != 1);

	newPassenger->miles = 0;

	newPassenger->nextPassenger = NULL;
}



/* //ADD PASSENGER
The function adds passenger nodes to the main passenger linked list.
It checks if the passenger added has duplicate passport number and 
voids the information if the passport number already exists.
*/
void addPassenger(PASSENGERS **passengerHead){

	PASSENGERS *newPassenger = (PASSENGERS *) malloc(sizeof(PASSENGERS));
	PASSENGERS *stalkerP = NULL;
	PASSENGERS *pssgrPtr = (*passengerHead);

	addPassengerInformation(newPassenger);

	//use stalker to find duplicate passenger number
	stalkerP = (*passengerHead);
	while (stalkerP != NULL){
		if(stalkerP->passportNum == newPassenger->passportNum){
			printf("\t+----------------------------------------------+\n");
			printf("\t|        Passenger number is not unique        |\n");
			printf("\t|         Passenger Information voided         |\n");	
			printf("\t+----------------------------------------------+\n");	
			return;
		}
		stalkerP = stalkerP->nextPassenger;
	}

	stalkerP = NULL;

	while (pssgrPtr != NULL){
		if (strcasecmp(newPassenger->lastName, pssgrPtr->lastName) == 0){
			if (strcasecmp(newPassenger->firstName, pssgrPtr->firstName) <= 0){
				if (stalkerP == NULL){
					//insert at head
					insertAtHead_P(&(*passengerHead), newPassenger);
					return;
				}
				else{
					//Stop traversal and insert between stalker and pssgr pointer
					break;
				}
			}
			else{
				stalkerP = pssgrPtr;
				pssgrPtr = pssgrPtr->nextPassenger; //Traverse
			}
		}
		else if (strcasecmp(newPassenger->lastName, pssgrPtr->lastName) < 0){
			if (stalkerP == NULL){
				//insert at head
				insertAtHead_P(&(*passengerHead), newPassenger);
				return;
			}
			else{
				//Stop traversal and insert between stalker and pssgr pointer
				break;
			}
		}
		else{
			//traversal
			stalkerP = pssgrPtr;
			pssgrPtr = pssgrPtr->nextPassenger;
		}
	}
	newPassenger->nextPassenger = pssgrPtr;
	stalkerP->nextPassenger = newPassenger;
}


//View passenger information
void viewPassengerInfo(PASSENGERS *passenger){
	printf("+---------------------------------------------------------------------+\n");
	printf("|\tPassenger Name:       %s, %s\n",passenger->lastName, passenger->firstName);
	printf("|\tPassenger birthday:   %02d / %02d / %02d\n", passenger->birthday.year, passenger->birthday.month, passenger->birthday.day);
	printf("|\tPassport number:      %02d \n", passenger->passportNum);
	printf("|\tMile points:          %02d\n", passenger->miles);
	printf("+---------------------------------------------------------------------+\n");
}

//View passengers in the linked list
void viewAirlinePassengers(PASSENGERS **headPassenger){
	PASSENGERS *viewPtr = (*headPassenger);
	while(viewPtr != NULL){
		viewPassengerInfo(viewPtr);
		viewPtr = viewPtr->nextPassenger;
	}
}

/* UPDATE SORT
This function updates the linked list's sorting of passengers.
*/
void updateSort(PASSENGERS **headPassenger){
	PASSENGERS *endOfSort = NULL;
	PASSENGERS *mainPtr = NULL;
	PASSENGERS *stalkerPtr = NULL;
	PASSENGERS *finderPtr = NULL;

	while ((*headPassenger) != endOfSort){
		mainPtr = (*headPassenger);
		stalkerPtr = NULL;
		while (mainPtr->nextPassenger != endOfSort){
			finderPtr = mainPtr->nextPassenger;

			if (finderPtr == NULL) return;

			if (strcasecmp(mainPtr->lastName, mainPtr->nextPassenger->lastName) > 0){
				if (stalkerPtr == NULL){
					mainPtr->nextPassenger = finderPtr->nextPassenger;
					(*headPassenger) = finderPtr;
					finderPtr->nextPassenger = mainPtr;
				}
				else{
					stalkerPtr->nextPassenger = mainPtr->nextPassenger;
					mainPtr->nextPassenger = finderPtr->nextPassenger;
					finderPtr->nextPassenger = mainPtr;
				}
			}
			else if (strcasecmp(mainPtr->lastName, mainPtr->nextPassenger->lastName) == 0){
				if (strcasecmp(mainPtr->firstName, mainPtr->nextPassenger->firstName) > 0){
					if (stalkerPtr == NULL){
						mainPtr->nextPassenger = finderPtr->nextPassenger;
						(*headPassenger) = finderPtr;
						finderPtr->nextPassenger = mainPtr;
					}
					else{
						stalkerPtr->nextPassenger = mainPtr->nextPassenger;
						mainPtr->nextPassenger = finderPtr->nextPassenger;
						finderPtr->nextPassenger = mainPtr;
					}
				}
				else{
					mainPtr = mainPtr->nextPassenger;
				}
			}
			else{
				mainPtr = mainPtr->nextPassenger;
			}

			if (stalkerPtr == NULL){
				stalkerPtr = (*headPassenger);
			}
			else{
				stalkerPtr = stalkerPtr->nextPassenger;
			}
		}
		endOfSort = mainPtr;
	}
}

/* UPDATE SORT
This function updates the linked list's sorting of flights.
*/
void updateSortF(FLIGHT **headFlight){
	FLIGHT *endOfSort = NULL;
	FLIGHT *mainPtr = NULL;
	FLIGHT *stalkerPtr = NULL;
	FLIGHT *finderPtr = NULL;

	while ((*headFlight) != endOfSort){
		mainPtr = (*headFlight);
		stalkerPtr = NULL;
		while (mainPtr->nextFlight != endOfSort){
			finderPtr = mainPtr->nextFlight;

			if (finderPtr == NULL) return;

			if (mainPtr->departureDate.year > mainPtr->nextFlight->departureDate.year){
				if (stalkerPtr == NULL){
					mainPtr->nextFlight = finderPtr->nextFlight;
					(*headFlight) = finderPtr;
					finderPtr->nextFlight = mainPtr;
				}
				else{
					stalkerPtr->nextFlight = mainPtr->nextFlight;
					mainPtr->nextFlight = finderPtr->nextFlight;
					finderPtr->nextFlight = mainPtr;
				}
			}
			else if (mainPtr->departureDate.year == mainPtr->nextFlight->departureDate.year){
				if (mainPtr->departureDate.month > mainPtr->nextFlight->departureDate.month){
					if (stalkerPtr == NULL){
						mainPtr->nextFlight = finderPtr->nextFlight;
						(*headFlight) = finderPtr;
						finderPtr->nextFlight = mainPtr;
					}
					else{
						stalkerPtr->nextFlight = mainPtr->nextFlight;
						mainPtr->nextFlight = finderPtr->nextFlight;
						finderPtr->nextFlight = mainPtr;
					}
				}
				else if (mainPtr->departureDate.month == mainPtr->nextFlight->departureDate.month){
					if (mainPtr->departureDate.day > mainPtr->nextFlight->departureDate.day){
						if (stalkerPtr == NULL){
							mainPtr->nextFlight = finderPtr->nextFlight;
							(*headFlight) = finderPtr;
							finderPtr->nextFlight = mainPtr;
						}
						else{
							stalkerPtr->nextFlight = mainPtr->nextFlight;
							mainPtr->nextFlight = finderPtr->nextFlight;
							finderPtr->nextFlight = mainPtr;
							}
					}
					else if (mainPtr->departureDate.day == mainPtr->nextFlight->departureDate.day){
						if (mainPtr->departureTime.hour > mainPtr->nextFlight->departureTime.hour){
							if (stalkerPtr == NULL){
								mainPtr->nextFlight = finderPtr->nextFlight;
								(*headFlight) = finderPtr;
								finderPtr->nextFlight = mainPtr;
							}
							else{
								stalkerPtr->nextFlight = mainPtr->nextFlight;
								mainPtr->nextFlight = finderPtr->nextFlight;
								finderPtr->nextFlight = mainPtr;
								}
						}
						else if (mainPtr->departureTime.hour == mainPtr->nextFlight->departureTime.hour){
							if (mainPtr->departureTime.min > mainPtr->nextFlight->departureTime.min){
								if (stalkerPtr == NULL){
									mainPtr->nextFlight = finderPtr->nextFlight;
									(*headFlight) = finderPtr;
									finderPtr->nextFlight = mainPtr;
								}
								else{
									stalkerPtr->nextFlight = mainPtr->nextFlight;
									mainPtr->nextFlight = finderPtr->nextFlight;
									finderPtr->nextFlight = mainPtr;
									}
							}
							else if (mainPtr->departureTime.min == mainPtr->nextFlight->departureTime.min){
								if (strcasecmp(mainPtr->destination, mainPtr->nextFlight->destination) > 0){
									if (stalkerPtr == NULL){
										mainPtr->nextFlight = finderPtr->nextFlight;
										(*headFlight) = finderPtr;
										finderPtr->nextFlight = mainPtr;
									}
									else{
										stalkerPtr->nextFlight = mainPtr->nextFlight;
										mainPtr->nextFlight = finderPtr->nextFlight;
										finderPtr->nextFlight = mainPtr;
										}
								}
								else if (strcasecmp(mainPtr->destination, mainPtr->nextFlight->destination) == 0){
									if (strcasecmp(mainPtr->origin, mainPtr->nextFlight->origin) >= 0){
										if (stalkerPtr == NULL){
											mainPtr->nextFlight = finderPtr->nextFlight;
											(*headFlight) = finderPtr;
											finderPtr->nextFlight = mainPtr;
										}
										else{
											stalkerPtr->nextFlight = mainPtr->nextFlight;
											mainPtr->nextFlight = finderPtr->nextFlight;
											finderPtr->nextFlight = mainPtr;
											}
									}
									else{
										mainPtr = mainPtr->nextFlight;
									}
								}
								else{
									mainPtr = mainPtr->nextFlight;
								}
							}
							else{
								mainPtr = mainPtr->nextFlight;
							}
						}
						else{
							mainPtr = mainPtr->nextFlight;
						}
					}
					else{
						mainPtr = mainPtr->nextFlight;
					}
				}
				else{
					mainPtr = mainPtr->nextFlight;
				}
			}
			else{
				mainPtr = mainPtr->nextFlight;
			}

			if (stalkerPtr == NULL){
				stalkerPtr = (*headFlight);
			}
			else{
				stalkerPtr = stalkerPtr->nextFlight;
			}
		}
		endOfSort = mainPtr;
	}
}


/* EDIT PASSENGER DETAILS
This function edits the passenger's new information.
After editin the passenger's information, it loops throught the flight linked list 
and updates the passenger information in every booked flights
*/
void editPassengerDetails(PASSENGERS **mainPssgrPtr, FLIGHT **headFlight){
	int passportAccess, promptVar1 = 0, bdayValidity, bornVar = 0, conflict = 1, accessValidity,tempYear, tempMonth, tempDay;
	char tempBday[20], tempAccess[20];

	PASSENGERS *editPtr = (*mainPssgrPtr);
	FLIGHT *flightEditPtr = (*headFlight);

	do{
		printf("Enter the passport number of the passenger:  ");
		scanf("%[^\n]s", tempAccess);
		getchar();
		accessValidity = getInt(&passportAccess, tempAccess);
	} while (accessValidity != 1);

	while(editPtr->passportNum != passportAccess){
		editPtr = editPtr->nextPassenger;
	}

	if (editPtr == NULL){
		printf("\t[!]  Passenger not found  [!]\n");
		return;
	}
	else{
		/*   Reserve birthday for revertion  */
		tempYear = editPtr->birthday.year;
		tempMonth = editPtr->birthday.month;
		tempDay = editPtr->birthday.day;

		viewPassengerInfo(editPtr);
		printf("\nEnter passenger's new last name:  ");
		scanf("%[^\n]s", editPtr->lastName);
		getchar();

		do {
		printf("Enter passenger's new birthday (YYYY/MM/DD):   ");
		scanf("%[^\n]s", tempBday);
		getchar();
		bdayValidity = dateCheck(&editPtr->birthday, tempBday);
		if (bdayValidity == 0) printf("\n\t[!]   Invalid input   [!]\n\n");

		} while (bdayValidity != 1);

	}

	//		Edit passenger's detail in all booked flght reservations
	while (flightEditPtr != NULL){
		PASSENGERS *pssgrInFlightPtr = flightEditPtr->headPassenger;
		PASSENGERS *stalker = NULL;
		while (pssgrInFlightPtr != NULL){
			if (editPtr->passportNum == pssgrInFlightPtr->passportNum){

//
				bornVar = isBorn(flightEditPtr, editPtr);
				if (bornVar == 0){

					// Revert the changed birthday in the passenger linked list.
					editPtr->birthday.year = tempYear;
					editPtr->birthday.month = tempMonth;
					editPtr->birthday.day = tempDay;

					printf("+-----------------------------------------------------------+\n");
					printf("|   The passenger will have a conflict on his/her flights   |\n");
					printf("|              Birthdate is not changed                     |\n");
					printf("+-----------------------------------------------------------+\n");

					return;
				}
//
				strcpy(pssgrInFlightPtr->lastName, editPtr->lastName);
				(pssgrInFlightPtr->birthday.year) = (editPtr->birthday.year);
				(pssgrInFlightPtr->birthday.month) = (editPtr->birthday.month);
				(pssgrInFlightPtr->birthday.day) = (editPtr->birthday.day);
				promptVar1 ++;
			}
			pssgrInFlightPtr = pssgrInFlightPtr->nextPassenger;
		}
		updateSort(&(flightEditPtr->headPassenger)); // Updates sorting of the passenger linked list inside the flight
		flightEditPtr = flightEditPtr->nextFlight;
	}

		printf("\t+-----------------------------------------------------+\n");
		printf("\t|           Successfully edited passenger %02d          |\n", editPtr->passportNum);
	if (promptVar1 > 0){
		printf("\t|  Updated passenger's details in all booked flights  |\n");
	}
		printf("\t+-----------------------------------------------------+\n");
}

/* ADD PASSENGERS TO FLIGHT
This function adds a passenger linked list inside the nodes of the flight linked list
It asks the user for passenger identification and flight identification then checks if the passenger is already
an airline passenger. If it is, it calls the conflict checker function to know if it will continue.
If there are no conflicts, it copies the node and then adds it to the passenger linked list
inside the flight node.
*/
void addPassengersToFlight(FLIGHT **headFlight, PASSENGERS **passengerHead){
	FLIGHT *flightPtr = (*headFlight);
	PASSENGERS *pssgrPtr = (*passengerHead);
	PASSENGERS *pssgrCopy = (PASSENGERS*) malloc(sizeof(PASSENGERS));
	int conflict = 0, promptVar1 = 0, bornVar;

	int passportAccess, ppAccessValidity;
	int flightIDaccess, fAccessValidity;
	char tempInput1[20], tempInput2[20];

	do{
		printf("Enter the passport number of the passenger:  ");
		scanf("%[^\n]s", tempInput1);
		getchar();
		ppAccessValidity = getInt(&passportAccess, tempInput1);
	} while (ppAccessValidity != 1);

	do{
		printf("Enter the Flight ID of the flight you want to book:  ");
		scanf("%[^\n]s", tempInput2);
		getchar();
		fAccessValidity = getInt(&flightIDaccess, tempInput2);
	} while (fAccessValidity != 1);

	while (flightPtr != NULL && flightPtr->flightID != flightIDaccess){
		flightPtr = flightPtr->nextFlight;
	}

	while (pssgrPtr != NULL && pssgrPtr->passportNum != passportAccess){
		pssgrPtr = pssgrPtr->nextPassenger;
	}
	if (pssgrPtr == NULL) {
		printf("\t[!]   Passenger not found   [!]\n");
		return;
	}
	else{
		//this part checks if the flight exists

		if (flightPtr == NULL){
			printf("\n\t[!]   Flight ID not found   [!]\n");
			return;
		}
		else if(flightPtr->passengerNum == flightPtr->passengerMax || flightPtr->passengerMax == 0){
			printf("+-----------------------------------------------------------+\n");
			printf("|               The flight is Fully-booked                  |\n");
			printf("|          or is not accepting more reservations            |\n");
			printf("+-----------------------------------------------------------+\n");
			return;
		}
		else flightPtr->passengerNum++; //Update passenger count


		/*      This part checks the flight if it is booked before the passenger's birthday*/
		bornVar = isBorn(flightPtr, pssgrPtr);
		if (bornVar == 0){
			printf("+-----------------------------------------------------------+\n");
			printf("|   The flight is booked before the passenger's birthday    |\n");
			printf("|               Invalid flight reservation                  |\n");
			printf("+-----------------------------------------------------------+\n");

			flightPtr->passengerNum--; //Negate increment
			return;
		}



		/*      This part checks passenger's conflict with other flights.    */
		conflict = conflictCheck(headFlight, pssgrPtr, flightPtr, 0);

		if (conflict == 1){
			printf("\n\t[!]   Conflict found   [!]\n");
			flightPtr->passengerNum--; //Negate increment
			printf("Flight details of the overlapped flight: \n");
			viewFlightInfo(flightPtr);
			return; //Stop the function if there is overlapping
		}
		else{
			pssgrPtr->miles = pssgrPtr->miles + flightPtr->bonusMiles; //Update passeneger's bonus miles
		}


		//		Edit passenger's bonus miles in all booked flght reservations
		FLIGHT *flightEditPtr = (*headFlight);
		while (flightEditPtr != NULL){
			PASSENGERS *pssgrInFlightPtr = flightEditPtr->headPassenger;
			while (pssgrInFlightPtr != NULL){
				if (pssgrPtr->passportNum == pssgrInFlightPtr->passportNum){
					pssgrInFlightPtr->miles = pssgrPtr->miles;
					promptVar1 ++;
				}
				pssgrInFlightPtr = pssgrInFlightPtr->nextPassenger;
			}
			flightEditPtr = flightEditPtr->nextFlight;
		}

		if (promptVar1 > 0){
			printf("\n\n[!]   Updated passenger's bonus miles in all booked flights   [!]\n\n");
		}
	}

	strcpy(pssgrCopy->firstName,pssgrPtr->firstName);
	strcpy(pssgrCopy->lastName, pssgrPtr->lastName);
	pssgrCopy->birthday.year = pssgrPtr->birthday.year;
	pssgrCopy->birthday.month = pssgrPtr->birthday.month;
	pssgrCopy->birthday.day =pssgrPtr->birthday.day;
	pssgrCopy->passportNum = pssgrPtr->passportNum;
	pssgrCopy->miles = pssgrPtr->miles;

	pssgrCopy->nextPassenger = NULL;


	PASSENGERS *stalkerPinF = NULL;

	printf("\n\n [!]   Passenger Successfully booked   [!]\n\n");

	if (flightPtr->headPassenger == NULL){
		flightPtr->headPassenger = pssgrCopy;
	}
	else{
		PASSENGERS *pssgrInFlightPtr = flightPtr->headPassenger;
		//Insert algorithm for insert passenger
		while (pssgrInFlightPtr != NULL){
			if (strcasecmp(pssgrCopy->lastName, pssgrInFlightPtr->lastName) == 0){
				if (strcasecmp(pssgrCopy->firstName, pssgrInFlightPtr->firstName) <= 0){
					if (stalkerPinF == NULL){
						//insert at head
						insertAtHead_P(&(flightPtr->headPassenger), pssgrCopy);
						return;
					}
					else{
						//Stop traversal and insert between stalker and pssgr pointer
						break;
					}
				}
				else{
					stalkerPinF = pssgrInFlightPtr;
					pssgrInFlightPtr = pssgrInFlightPtr->nextPassenger; //Traverse
				}
			}
			else if (strcasecmp(pssgrCopy->lastName, pssgrInFlightPtr->lastName) < 0){
				if (stalkerPinF == NULL){
					//insert at head

					insertAtHead_P(&(flightPtr->headPassenger), pssgrCopy);
					return;
				}
				else{
					//Stop traversal and insert between stalker and pssgr pointer
					break;
				}
			}
			else{
				//traversal
				stalkerPinF = pssgrInFlightPtr;
				pssgrInFlightPtr = pssgrInFlightPtr->nextPassenger;
			}
		}
		pssgrCopy->nextPassenger = pssgrInFlightPtr;
		stalkerPinF->nextPassenger = pssgrCopy;
	}

}

/* View Flight reservations
This function loops the flight linked list and the passenger linked list inside it. If passenger is found
inside the flight linked list, it prints the flight information.
*/
void viewFlightReservations(FLIGHT **headFlight, PASSENGERS **passengerHead){
	int passportAccess, promptVar1 = 0, promptVar2 = 0, ppAccessValidity;
	char tempInput1[20];

	FLIGHT *flightPtr = (*headFlight);
	PASSENGERS *viewPssgr = (*passengerHead);

	do{
		printf("Enter the passport number of the passenger:  ");
		scanf("%[^\n]s", tempInput1);
		getchar();
		ppAccessValidity = getInt(&passportAccess, tempInput1);
	} while (ppAccessValidity != 1);

	while (viewPssgr != NULL){
		if (viewPssgr->passportNum == passportAccess){
			viewPassengerInfo(viewPssgr);
			promptVar2 ++;
		}
		viewPssgr = viewPssgr->nextPassenger;
	}

	while (flightPtr != NULL){
		PASSENGERS *reservationPtr = flightPtr->headPassenger;
		while (reservationPtr != NULL){
			if (reservationPtr->passportNum == passportAccess){
				viewFlightInfo(flightPtr);
				promptVar1++;
			}
			reservationPtr = reservationPtr->nextPassenger;
		}
		flightPtr = flightPtr->nextFlight;
	}
	if (promptVar2 == 0){
		printf("\t+---------------------------------------------+\n");
		printf("\t|          Passenger does not exist           |\n");
		printf("\t+---------------------------------------------+\n");
	}
	
	else{
		if (promptVar1 == 0){
			printf("\t+---------------------------------------------+\n");
			printf("\t|   Passenger has no flight reservations      |\n");
			printf("\t+---------------------------------------------+\n");
		}
	}
}

/* Delete flight reservations
This function asks the user for flight ID and passport number then executes a
searching algorithm for the flight, and the passport number inside that flight node.
It also displays double confirmation for the deletion.
*/
void deleteFlightReservations(FLIGHT **headFlight, PASSENGERS **passengerHead){
	FLIGHT *flightPtr = (*headFlight);
	PASSENGERS *pssgrPtr = (*passengerHead);

	int passportAccess, ppAccessValidity, promptVar1, doubleConfirm = 0;
	int flightIDaccess, fAccessValidity, confirmValidity;
	char tempInput1[20], tempInput2[20], tempConfirm[20];

	do{
		printf("Enter the passport number of the passenger:  ");
		scanf("%[^\n]s", tempInput1);
		getchar();
		ppAccessValidity = getInt(&passportAccess, tempInput1);
	} while (ppAccessValidity != 1);


	do{
		printf("Enter the flight ID of the flight:  ");
		scanf("%[^\n]s", tempInput2);
		getchar();
		fAccessValidity = getInt(&flightIDaccess, tempInput2);
	} while (fAccessValidity != 1);

	//		SEARCH ALGORITHM FOR THE FLIGHT
	while (flightPtr != NULL && flightPtr->flightID != flightIDaccess){
		flightPtr = flightPtr->nextFlight;
	}
	if (flightPtr == NULL){
		printf("\n\t[!]   Flight ID not found   [!}\n");
		return;
	}
	//		END OF SEARCH ALGORITHM

	// 					DELETE ALGORITHM FOR DELETE
	PASSENGERS *deleteFlightPassenger = flightPtr->headPassenger;

	// 					SEARCH ALGO FOR PASSENGER
	while (deleteFlightPassenger != NULL && deleteFlightPassenger->passportNum != passportAccess){
		deleteFlightPassenger = deleteFlightPassenger->nextPassenger;
	}

	if (deleteFlightPassenger == NULL){
		printf("\n\n[!]   Flight reservation not found   [!]\n\n");
		return;
	}
	else{
		while (doubleConfirm <= 3 || doubleConfirm <= 0){
			printf("\tDo you really want to delete this Flight Reservation?\n");
			viewFlightInfo(flightPtr);
			do{
				printf("\n\n[1] YES\n[2] NO\t\nChoice:   ");
				scanf("%[^\n]s", tempConfirm);
				getchar();
				confirmValidity = getInt(&doubleConfirm, tempConfirm);
			} while (confirmValidity != 1);

			if (doubleConfirm == 1){
			//Initialize stalker pointer
				PASSENGERS *stalkerPinF = flightPtr->headPassenger;
				if (stalkerPinF == deleteFlightPassenger){
					flightPtr->headPassenger = deleteFlightPassenger->nextPassenger;
					free(deleteFlightPassenger);
					flightPtr->passengerNum --;
				}
				else{
					while (stalkerPinF->nextPassenger != deleteFlightPassenger){
						stalkerPinF = stalkerPinF->nextPassenger;
					}

					stalkerPinF->nextPassenger = deleteFlightPassenger->nextPassenger;
					free(deleteFlightPassenger);
					flightPtr->passengerNum --;
				}

			//Decrement mile points of the passenger based on the cancelled flight reservation
				while (pssgrPtr != NULL && pssgrPtr->passportNum != passportAccess){
					pssgrPtr = pssgrPtr->nextPassenger;
				}
				pssgrPtr->miles -= flightPtr->bonusMiles;

				//		Edit passenger's bonus miles in all booked flght reservations
				FLIGHT *flightEditPtr = (*headFlight);
				while (flightEditPtr != NULL){
					PASSENGERS *pssgrInFlightPtr = flightEditPtr->headPassenger;
					while (pssgrInFlightPtr != NULL){
						if (pssgrPtr->passportNum == pssgrInFlightPtr->passportNum){
							pssgrInFlightPtr->miles = pssgrPtr->miles;
						}
						pssgrInFlightPtr = pssgrInFlightPtr->nextPassenger;
					}
					flightEditPtr = flightEditPtr->nextFlight;
				}
				//

			//
				printf("\t+---------------------------------------------+\n");
				printf("\t|         Removed a flight reservations       |\n");
				printf("\t+---------------------------------------------+\n");

				break;
			}
			else if (doubleConfirm == 2){
				return;
			}
			else{
				printf("\n\n[!]   Invalid input   [!]\n\n");
				continue;
			}
		}
	}
}


/*
Saves the flight data and it's passengers in a text file
*/
void saveFlights(FILE *mainFlight, FLIGHT **headFlight, int *flightCount){
	FLIGHT *flightPtr = (*headFlight);

	fprintf(mainFlight, "%d\n", (*flightCount));
	while (flightPtr != NULL){
		PASSENGERS *flightPassengers = flightPtr->headPassenger;
		fprintf(mainFlight, "%d\n", flightPtr->flightID);
		fprintf(mainFlight, "%s\n", flightPtr->origin);
		fprintf(mainFlight, "%s\n",flightPtr->destination);
		fprintf(mainFlight, "%d/%d/%d\n", flightPtr->departureDate.year, flightPtr->departureDate.month,flightPtr->departureDate.day);
		fprintf(mainFlight, "%d/%d/%d\n", flightPtr->arrivalDate.year, flightPtr->arrivalDate.month, flightPtr->arrivalDate.day);
		fprintf(mainFlight, "%d:%d\n", flightPtr->departureTime.hour, flightPtr->departureTime.min);
		fprintf(mainFlight, "%d:%d\n", flightPtr->arrivalTime.hour, flightPtr->arrivalTime.min);
		fprintf(mainFlight, "%d\n", flightPtr->passengerNum);
		fprintf(mainFlight, "%d\n", flightPtr->passengerMax);
		fprintf(mainFlight, "%d\n", flightPtr->bonusMiles);
		while (flightPassengers != NULL){
			fprintf(mainFlight, "%s\n", flightPassengers->firstName);
			fprintf(mainFlight, "%s\n", flightPassengers->lastName);
			fprintf(mainFlight, "%d/%d/%d\n", flightPassengers->birthday.year, flightPassengers->birthday.month,flightPassengers->birthday.day);
			fprintf(mainFlight, "%d\n", flightPassengers->passportNum);
			fprintf(mainFlight, "%d\n", flightPassengers->miles);
			fprintf(mainFlight, "-\n");
			flightPassengers = flightPassengers->nextPassenger;
		}	
		flightPtr = flightPtr->nextFlight;
	}
}

/*
Loads the text file and then creates a linked list based on the data inside the file
*/
void loadFlights(FILE *mainFlight, FLIGHT **headFlight, int *flightCount){
	FLIGHT *flightPtr = (*headFlight);
	int i = 0;

	if (fscanf(mainFlight, "%d\n", flightCount) == EOF) return;

	while (1){

		FLIGHT *newFlight = (FLIGHT*) malloc(sizeof(FLIGHT));

		if (fscanf(mainFlight, "%d\n", &newFlight->flightID) == EOF) break;

		fgets(newFlight->origin, 50, mainFlight);
		int size = strlen(newFlight->origin);
		newFlight->origin[size-1] = '\0';
		fgets(newFlight->destination, 50, mainFlight);
		size = strlen(newFlight->destination);
		newFlight->destination[size-1] = '\0';

		fscanf(mainFlight, "%d/%d/%d\n", &newFlight->departureDate.year, &newFlight->departureDate.month,&newFlight->departureDate.day);
		fscanf(mainFlight, "%d/%d/%d\n", &newFlight->arrivalDate.year, &newFlight->arrivalDate.month,&newFlight->arrivalDate.day);
		fscanf(mainFlight, "%d:%d\n", &newFlight->departureTime.hour, &newFlight->departureTime.min);
		fscanf(mainFlight, "%d:%d\n", &newFlight->arrivalTime.hour, &newFlight->arrivalTime.min);
		fscanf(mainFlight, "%d\n", &newFlight->passengerNum);
		fscanf(mainFlight, "%d\n", &newFlight->passengerMax);
		fscanf(mainFlight, "%d\n", &newFlight->bonusMiles);
		newFlight->nextFlight = NULL;
		newFlight->headPassenger = NULL;

		PASSENGERS *flightPassengers = newFlight->headPassenger;

		if (newFlight->passengerNum != 0){
			for (int passengers = 0; passengers < newFlight->passengerNum; passengers++){
				PASSENGERS *newPassenger = (PASSENGERS*) malloc (sizeof(PASSENGERS));
				fgets(newPassenger->firstName, 49, mainFlight);
				int size = strlen(newPassenger->firstName);
				newPassenger->firstName[size-1] = '\0';
				fgets(newPassenger->lastName, 49, mainFlight);
				size = strlen(newPassenger->lastName);
				newPassenger->lastName[size-1] = '\0';
				fscanf(mainFlight, "%d/%d/%d\n", &newPassenger->birthday.year, &newPassenger->birthday.month, &newPassenger->birthday.day);
				fscanf(mainFlight, "%d\n", &newPassenger->passportNum);
				fscanf(mainFlight, "%d\n", &newPassenger->miles);
				newPassenger->nextPassenger = NULL;

				if (flightPassengers == NULL){
					newFlight->headPassenger = newPassenger;
					flightPassengers = newFlight->headPassenger;
				}
				else{
					flightPassengers->nextPassenger = newPassenger;
					flightPassengers = flightPassengers->nextPassenger;
				}

				fscanf(mainFlight, "-\n");

			
			}
		}
		if (flightPtr == NULL){
			(*headFlight) = newFlight;
			flightPtr = (*headFlight);
		}
		else{
			flightPtr->nextFlight = newFlight;
			flightPtr = flightPtr->nextFlight;

		}
	}
}

/*
Saves the airline passengers linked list
*/
void savePassengers(FILE *mainPassengers, PASSENGERS **headPassenger){
	PASSENGERS *pssgrPtr = (*headPassenger);

	while (pssgrPtr != NULL){
		fprintf(mainPassengers, "%s\n", pssgrPtr->firstName);
		fprintf(mainPassengers, "%s\n", pssgrPtr->lastName);
		fprintf(mainPassengers, "%d/%d/%d\n", pssgrPtr->birthday.year,pssgrPtr->birthday.month,pssgrPtr->birthday.day);
		fprintf(mainPassengers, "%d\n", pssgrPtr->passportNum);
		fprintf(mainPassengers, "%d\n", pssgrPtr->miles);
		fprintf(mainPassengers, "-\n");
		pssgrPtr = pssgrPtr->nextPassenger;	
	}
}

/*
Loads the airline passenger linked list
*/
void loadPassengers(FILE *mainPassengers, PASSENGERS **passengerHead){
	PASSENGERS *pssgrPtr = (*passengerHead);

	while (1){
			PASSENGERS *newPassenger = (PASSENGERS*) malloc(sizeof(PASSENGERS));

		if ( fgets(newPassenger->firstName, 49, mainPassengers) == NULL ) break;
		int size = strlen(newPassenger->firstName);
		newPassenger->firstName[size-1] = '\0';
		fgets(newPassenger->lastName, 49, mainPassengers);
		size = strlen(newPassenger->lastName);
		newPassenger->lastName[size-1] = '\0';
		fscanf(mainPassengers, "%d/%d/%d\n", &newPassenger->birthday.year,  &newPassenger->birthday.month, &newPassenger->birthday.day);
		fscanf(mainPassengers, "%d\n", &newPassenger->passportNum);
		fscanf(mainPassengers, "%d\n", &newPassenger->miles);

		newPassenger->nextPassenger = NULL;

		if (pssgrPtr == NULL){
			(*passengerHead) = newPassenger;
			pssgrPtr = (*passengerHead);
		}
		else{
			pssgrPtr->nextPassenger = newPassenger;
			pssgrPtr = pssgrPtr->nextPassenger;	
		}
		fscanf(mainPassengers, "-\n");
	}
}

/*	
To do:
	Modularity Optimization
	Testing and debugging
	Bug/s found:
*/

/*
Updates from fms10:
	Edit ptr updated
		- Now checks all hte passengers before the edit
		- Segfault on flight not found fixed.
		- Checks all flights in edit passenger information
*/

//Last to do: UpdateSort for flight