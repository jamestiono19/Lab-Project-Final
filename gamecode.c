#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//Ini module untuk mission, ada character selection dan gameplay
int missionModule(){
	int characterName = 1;
	int HP, ATK, DEF, SPE, damage, damageReduction, counter = 0;
	printf("This is mission page.\n");
	switch(characterName){
		case 1:
			HP = 100;
			ATK = 70;
			DEF = 70;
			SPE = 100;
			break;
			
		case 2:
			HP = 75;
			ATK = 100;
			DEF = 60;
			SPE = 120;
			break;
			
		case 3:
			HP = 150;
			ATK = 40;
			DEF = 100;
			SPE = 50;
			break;
	}
	int maxHP = HP;
	int enemyHP = 100;
	int enemyATK = 30;
	int enemyDEF = 75;
	char actionChoice;
	while(enemyHP >= 0 && HP >= 0){
	
		switch(characterName){
			//Consecute
			case 1: 
				printf("Consecute: Next order, Cap?\n");
				printf("================================\n");
				printf("a. Singular Punch\n");
				printf("b. Up n' Down\n");
				printf("c. Block\n");
				scanf("%c", &actionChoice); getchar();
				//Input Validation
				if(actionChoice != 'a' && actionChoice != 'b' && actionChoice != 'c'){
					printf("Consecute: Not sure what you're talking about. How about another one?\n");
					printf("(Invalid input, please input only a, b, or c. Inputs are case sensitive.)\n");
					scanf("%c", &actionChoice); getchar();
				}
				//Clear terminal/console/whatever you want to call it
				system("cls");
				
				switch(actionChoice){
					//Basic Attack
					case 'a':
						damage = ATK/(1 + enemyDEF/100);
						enemyHP -= damage;
						Sleep(500);
						printf("Consecute punched the enemy, dealing %d damage to the enemy. The enemy has %d HP left.\n", damage, enemyHP); 
						break;
					//Active Skill 1
					case 'b':
						damage = (ATK * 2)/(1 + enemyDEF/100);
						enemyHP -= damage;
						HP -= maxHP / 20;
						Sleep(500);
						printf("Consecute threw and smashed the enemy, dealing %d damage to the enemy. The enemy has %d HP left. \n", damage, enemyHP);
						break;
					//Active Skill 3
					case 'c':
						damageReduction = 2;
						counter = 1;
						Sleep(500);
						printf("Consecute is blocking.\n");
						break;
					//Formality :moyai:
					default:
						break;
				}
				break;
				
			//Vindictor
			case 2: 
				break;
				
			//Crescent
			case 3:
				break;
				
			default:
				break;
		}
		Sleep(500);
		//Ini buat enemy nge-attack player
		damage = (enemyATK/(1 + DEF/100)) / damageReduction; 
		HP -= damage; 
		printf("Enemy attacked you for %d damage, %d have %d HP left.\n", damage, characterName, HP);

		//Ini khusus Consecute, karena ada skill counter-attack
		if(counter == 1){
			Sleep(500);
			damage = (ATK / 3)/(1 + enemyDEF/100);
			enemyHP -= damage;
			printf("Consecute counterattacks, dealing %d damage to the enemy. Enemy has %d HP left.\n", damage, enemyHP);
			counter = 0;
		}
		Sleep(1500);
	}
}

//Ini buat character database, isinya lore, stats, skill explanation, etc. Stats sama skill boleh sama kalian, lore sama gerald aja.
void characterDatabase(){
	printf("This is character database.");
}

//Ini buat enemy database, isinya stats, lore, sama skill enemy. Sama kyk character database, lore sama gerlad aja
void enemyDatabase(){
	printf("This is enemy database.");
	printf("Return? (y/n)");
	
	
}

//Ini main, nyambung-nyambungin module dan sebagai menu utama.
int main(){
	int menuChoice, choiceTries, validRetry = 0;
	char gameOn = 'y';
	
	printf("Loading...\n");
	sleep(1);
	printf("Captain's Interface Data loaded, initiating system...\n");
	sleep(1);
	printf("System initiated, waking up Lightdust...\n");
	sleep(1);
	printf("\n");
	printf("Welcome back, Captain. What would you like to do?\n");
	while(gameOn == 'y'){
		validRetry = 0;
		menuChoice = 0;
		choiceTries = 0;
		printf("1. Start a mission \n");
		printf("2. Access Your Team's Units Database \n");
		printf("3. Access Monster Data\n");
		printf("4. Exit System\n");
		printf("Your choice, Captain: ");
		
		scanf("%d", &menuChoice); getchar();
		while(1){
			if(menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4){
				switch(choiceTries % 4){
					case 0: 
						printf("Invalid choice, please choose again (1, 2, 3, or 4): ");
						choiceTries++;
						break;
						
					case 1: 
						printf("Please try 1, 2, 3, or 4. There are only 4 options, Captain. (1, 2, 3, or 4): ");
						choiceTries++;
						break;
						
					case 2: 
						printf("Captain, please... (1, 2, 3, or 4): ");
						choiceTries++;
						break;
						
					case 3: 
						printf("Captain... (1, 2, 3, or 4): ");
						choiceTries++;
						break;
				}
	
				scanf("%d", &menuChoice);
			} else {
				break;
			}
		}
		
	
		switch(menuChoice){
			case 1: 
				missionModule();
				printf("again?");
				while(1){
					scanf("%c", &gameOn);
					if(gameOn == 'y' || gameOn == 'n'){
						break;
					} else {
						printf("Invalid input, please input only y or n (not case sensitive)");
					}
				}
				break;
				
			case 2:
				characterDatabase();
				printf("again?");
				while(1){
					scanf("%c", &gameOn);
					gameOn = tolower(gameOn);
					if(gameOn == 'y' || gameOn == 'n'){
						break;
					} else {
						printf("Invalid input, please input only y or n (not case sensitive)");
					}
				}
				break;
				
			case 3:
				enemyDatabase();
				printf("again?");
				while(validRetry == 0){
					scanf("%c", &gameOn);
					gameOn = tolower(gameOn);
					if(gameOn == 'y' || gameOn == 'n'){
						validRetry = 1;
						break;
					} else {
						printf("Invalid input, please input only y or n (not case sensitive)");
					}
				}
				break;
				
			default:
				gameOn = 'n';
				break;
			
		}
	}
	
	printf("Ending system...\n");
	sleep(1);
	printf("System ended. See you next time, Captain. Lightdust, signing out.");
	
	return 0;
	
}
