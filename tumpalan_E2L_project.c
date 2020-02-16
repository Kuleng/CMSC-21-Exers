/*

					FLIGHT MANAGEMENT SYSTEM
   					by John Karl Tumpalan

   					CMSC 21 - E2L

   					This program will help manage the passengers 
   					in the flights of an airline

*/

#include "tumpalan_E2L_project.h"

int main(){
	FILE *mainFlight = NULL;
	FILE *mainPassengers = NULL;
	int emptyHead;

	int choice, choice2, flightCount = 1, passengerCount, choice1Validity, choice2Validity;
	char tempChoice1[20], tempChoice2[20];

	FLIGHT *headFlightPtr = NULL;
	FLIGHT *mainFlightPtr = NULL;
	PASSENGERS *headPssgrPtr = NULL;
	PASSENGERS *mainPssgrPtr = NULL;
	printf("\t+-------------------------------------------+\n");
	printf("\t|         FLIGHT MANAGEMENT SYSTEM          |\n");
	printf("\t|            -CMSC 21 PROJECT-              |\n");
	printf("\t+-------------------------------------------+\n");
	mainFlight = fopen("flights.txt", "r");
	if (mainFlight == NULL){
		printf("\t+-------------------------------------------+\n");
		printf("\t|          Error loading flights.txt        |\n");
		printf("\t|          The file does not exist          |\n");
		printf("\t+-------------------------------------------+\n");	
	}
	else{
		loadFlights(mainFlight, &headFlightPtr, &flightCount);
		printf("\t+-------------------------------------------+\n");
		printf("\t|            flights.txt loaded             |\n");
		printf("\t+-------------------------------------------+\n");	
	}

	mainPassengers = fopen("passengers.txt", "r");
	if (mainPassengers == NULL){
		printf("\t+-------------------------------------------+\n");
		printf("\t|        Error loading passengers.txt       |\n");
		printf("\t|           The file does not exist         |\n");
		printf("\t+-------------------------------------------+\n");	
	}
	else{
		loadPassengers(mainPassengers,  &headPssgrPtr);
		printf("\t+-------------------------------------------+\n");
		printf("\t|           passengers.txt loaded           |\n");
		printf("\t+-------------------------------------------+\n");	
	}

	while (choice != 10){
		choice = 0;

		do{
			printMenu(1);
			scanf("%[^\n]s", tempChoice1);
			choice1Validity = getInt(&choice, tempChoice1);
			getchar();
		} while (choice1Validity != 1);

		if(choice == 1){
			//ADD FLIGHT
			if (headFlightPtr == NULL){
				FLIGHT *newFlight = (FLIGHT*) malloc(sizeof(FLIGHT));
				addInfo_flight(newFlight, &headFlightPtr, &flightCount);
				headFlightPtr = newFlight;
			}
			else{
				addFlight(&headFlightPtr, &flightCount);
				printf("\t[!]   Added successfully   [!]\n");
			}
			flightCount++;
			continue;
		}
		else if (choice == 2){
			//EDIT FLIGHT
			emptyHead = isEmpty(&headFlightPtr);
			if (emptyHead == 1) continue;

			editFlight(&headFlightPtr);
			updateSortF(&headFlightPtr);
		}
		else if (choice == 3){
			//VIEW FLIGHTS
			emptyHead = isEmpty(&headFlightPtr);
			if (emptyHead == 1) continue;

			do{
				printMenu(2);
				scanf("%[^\n]s", tempChoice2);
				choice2Validity = getInt(&choice2, tempChoice2);
				getchar();
			} while (choice2Validity != 1);

			viewFlights(&headFlightPtr, choice2);
			continue;
		}
		else if (choice ==4){
			emptyHead = isEmpty(&headFlightPtr);
			if (emptyHead == 1) continue;

			int isDeleted = deleteFlight(&headFlightPtr);
			if (isDeleted != 0) flightCount --;
			continue;
		}
		else if (choice ==5){
			//ADD A PASSENGER
			if (headPssgrPtr == NULL){
				PASSENGERS *newHeadPssgr = (PASSENGERS*) malloc(sizeof(PASSENGERS));
				addPassengerInformation(newHeadPssgr);
				headPssgrPtr = newHeadPssgr;
			}
			else{
				addPassenger(&headPssgrPtr);
			}
		}
		else if (choice ==6){
			//EDIT PASSENGER DETAILS

			if (headPssgrPtr == NULL){
				printf("\t+-------------------------------------------+\n");
				printf("\t|        There are no passengers yet.        |\n");
				printf("\t|        Please add passengers first.        |\n");
				printf("\t+-------------------------------------------+\n");	
				continue;	
			}

			editPassengerDetails(&headPssgrPtr, &headFlightPtr);
			updateSort(&headPssgrPtr);		
			viewAirlinePassengers(&headPssgrPtr);
		}
		else if (choice ==7){
			//BOOK A FLIGHT RESERVATION
			emptyHead = isEmpty(&headFlightPtr);
			if (emptyHead == 1) continue;

			addPassengersToFlight(&headFlightPtr, &headPssgrPtr);
		}
		else if (choice ==8){
			emptyHead = isEmpty(&headFlightPtr);
			if (emptyHead == 1) continue;

			deleteFlightReservations(&headFlightPtr, &headPssgrPtr);
			//REMOVE A FLIGHT RESERVATION
		}
		else if (choice ==9){
			viewFlightReservations(&headFlightPtr, &headPssgrPtr);
			//VIEW RESERVATION
		}
		else if (choice == 10){
			mainFlight = fopen("flights.txt", "w");
			saveFlights(mainFlight, &headFlightPtr, &flightCount);

			mainPassengers = fopen("passengers.txt", "w");
			savePassengers(mainPassengers, &headPssgrPtr);

			printf("\n\n [!]   Program exit.   [!]\n\n");

			break;
		}
		else{
			printf("\t[!]   Invalid input    [!]\n");
		}
		continue;
	}

	freeFlights(&headFlightPtr);
	freePassengers(&headPssgrPtr);

	fclose(mainFlight);
	fclose(mainPassengers);

	return 0;
}