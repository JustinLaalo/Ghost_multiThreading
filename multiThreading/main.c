#include "defs.h"
/*  
  Function: main()
  Purpose:  links all the files and functions to allow the program to run
   return:  returns 0 if the program ran fine
*/
int main()
{
  int choose = -1;
  
  BuildingType build;
  
  initBuilding(&build);
  
  loadBuildingData(&build);
  
  while(choose != 0){
  	if(choose == 1){
  		printRooms(&build.rooms);
  	}else if(choose == 2){
  		printGhosts(&build.ghosts, C_TRUE);
  	}else if(choose == 3){
  		printByLikelihood(&build.ghosts,C_FALSE);
  	}
  	printMenu(&choose);
  }
  cleanupBuilding(&build);
  return(0);
}
/*  
  Function: printMenu()
  Purpose:  links all the files and functions to allow the program to run
       in:  choice, takes in 
   return:  returns nothing, it is just used to get out of the funciton
*/
void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

