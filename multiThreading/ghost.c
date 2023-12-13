#include <stdio.h>
#include <string.h>
#include "defs.h"

/*  
  Function: initGhostList()
  Purpose:  initializes a the head and tail in ghost list
       in:  list, is the linked list we are going to initalize
*/
void initGhostList(GhostListType* list){
	list->head = NULL;
	list->tail = NULL;
}
/*  
  Function: initGhost()
  Purpose:  initializes a ghost
       in:  id, is the id we want to set the ghosts id to
       in:  gt, is the EnumType we want to set the ghost enum to
       in:  r, is the roomtype we want to set the ghosts roomtype to
       in:  like, is the likelihood we want to set the ghosts likelihood to
   in/out:  ghosts, is a pointer to another pointer, basically where we want to store all the data in
*/
void initGhost(int id, GhostEnumType gt, RoomType *r, float like, GhostType **ghost){
//*ghost=malloc(sizeof(GhostType))
	*ghost = malloc(sizeof(GhostType));
	(*ghost)->id = id;
	(*ghost)->ghostType=gt;
	(*ghost)->room = r;
	(*ghost)->likelihood=like;
}
/*  
  Function: addGhost()
  Purpose:  adds a ghost to the end of the ghosts list
   in/out:  list, is the list we want to add to the end of
       in:  ghost, is the ghost we want to add to the end of the list
*/
void addGhost(GhostListType *list, GhostType *ghost){
	NodeType* temp = NULL;
	NodeType* current = list->head;
	NodeType* previous = NULL;

	
	
	while(current != NULL){
		previous = current;
		current = current->next;	
	}

	temp = malloc(sizeof(NodeType));
	temp->data = ghost;

	if(previous == NULL){
		list->head = temp;
		list->tail = temp;
		
	}else{

		previous->next = temp;
		list->tail = temp;
	}

	temp->next = current;

}
/*  
  Function: addGhostByLikelihood()
  Purpose:  adds the ghost to the right spot, compared by likelihood
   in/out:  list, is the list we want to add to the end of
       in:  ghost, is the ghost we want to add to the end of the list
*/
void addGhostByLikelihood(GhostListType* list, GhostType* ghost){
	NodeType* temp = NULL;

	NodeType* current = list->head;
	NodeType* previous = NULL;

	
	
	while(current != NULL){
		if(ghost->likelihood >= current->data->likelihood){
				break;
		}
	
		previous = current;
		current = current->next;	
	}
	//maybe malloc temp here
	temp = malloc(sizeof(NodeType));
	temp->data = ghost;
	//move if statment
	if(previous == NULL){
		list->head = temp;
		//already doing above
		//list->head->next = NULL;
		list->tail = temp;
		//done above
		//list->tail->next=NULL;
	}else{
	//below make else statment
		previous->next = temp;
		list->tail = temp;
	}
	//keep out
	temp->next = current;
	//[]->[]->[]->[]->[]
}
/*  
  Function: cleanupGhostData()
  Purpose:  cleans up all the data we used in GhostListType
       in:  list, where we want to clear the data from
*/
void cleanupGhostData(GhostListType* list){
	NodeType* current = list->head;
	NodeType* next = NULL;
	while(current != NULL){
		next = current->next;
		free(current->data);
		current = next;
	}
	

}
/*  
  Function: cleanupGhostData()
  Purpose:  cleans up the list in GhostListType
       in:  list, where we want to clear the data from
*/
void cleanupGhostList(GhostListType* list){
	NodeType* current = list->head;
	NodeType* next = NULL;
	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
}
/*  
  Function: printGhost()
  Purpose:  prints out all the ghosts with their proper names/ghost types
       in:  ghost, is the ghost we want to print out
*/
void printGhost(GhostType *ghost){
	
	if(ghost->ghostType == POLTERGEIST){
		if(ghost->room == NULL){
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "POLTERGEIST", "UNKNOWN", ghost->likelihood);
		}else{
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "POLTERGEIST", ghost->room->name, ghost->likelihood);
		}
	}else if(ghost->ghostType == WRAITH){
		if(ghost->room == NULL){
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "WRAITH", "UNKNOWN", ghost->likelihood);
		}else{
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "WRAITH", ghost->room->name, ghost->likelihood);
		}
	}else if(ghost->ghostType == PHANTOM){
		if(ghost->room == NULL){
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "PHANTOM", "UNKNOWN", ghost->likelihood);
		}else{
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "PHANTOM", ghost->room->name, ghost->likelihood);
		}
	}else if(ghost->ghostType == BULLIES){
		if(ghost->room == NULL){
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "BULLIES", "UNKNOWN", ghost->likelihood);
		}else{
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "BULLIES", ghost->room->name, ghost->likelihood);
		}
	}else if(ghost->ghostType == OTHER){
		if(ghost->room == NULL){
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "OTHER", "UNKNOWN", ghost->likelihood);
		}else{
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "OTHER", ghost->room->name, ghost->likelihood);
		}
	}else{
		if(ghost->room == NULL){
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "UNKNOWN", "UNKNOWN", ghost->likelihood);
		}else{
			printf("ID: %d, GhostType: %s, Room: %s, Likelihood: %.2f \n", ghost->id, "UNKNOWN", ghost->room->name, ghost->likelihood);
		}
	}
	
}

/*  
  Function: printGhosts()
  Purpose:  calls the print ghost function and prints out all the ghosts in the list
       in:  list, is the list we want to print out
       in:  ends, lets 
*/
void printGhosts(GhostListType* list, int ends){
	NodeType* current = list->head;
	while(current!= NULL){
		printGhost(current->data);
		current= current->next;
	}
	if(ends == C_TRUE){
		printGhost(list->head->data);
		printGhost(list->tail->data);
	}
}
/*  
  Function: printGhosts()
  Purpose:  calls the print ghost function and prints out all the ghosts in the list by likelihood
       in:  origList, is the list we want to print out
       in:  ends, tells us if we need to print out the head and tail again
*/
void printByLikelihood(GhostListType* origList, int ends){
	GhostListType* temp = malloc(sizeof(GhostListType));
	initGhostList(temp);
	NodeType* current = origList->head;
	
	while(current!=NULL){
		addGhostByLikelihood(temp,current->data);
		current = current->next;
	}
	
	printGhosts(temp, ends);
	cleanupGhostList(temp);
	free(temp);
}













