#include <stdio.h>
#include <string.h>
#include "defs.h"
/*  
  Function: initRoomArray()
  Purpose:  Initializes the room array
   in/out:  arr this is a RoomArrayType parameter we want to initalize
*/
void initRoomArray(RoomArrayType *arr){
	arr->size = 0;
}
/*  
  Function: initRoom()
  Purpose:  initializes a room
       in:  id, is the id we want to set the rooms id to
       in:  name, is the name we want to set the rooms name to
   in/out:  room, this is a RoomType parameter we want to initalize
*/
void initRoom(int id, char *name, RoomType **room){
	
	*room = malloc(sizeof(RoomType));
	(*room)->id = id;
	strcpy((*room)->name,name);

	(*room)->ghosts = malloc(sizeof(GhostListType));
	initGhostList((*room)->ghosts);
	
}
/*  
  Function: addRoom()
  Purpose:  add a room to the end of the array in the RoomArrayType
       in:   r, is the room we want to add at the end of the RoomArray
   in/out:  arr, this is the RoomArrayType we want to add to the end of
*/
void addRoom(RoomArrayType *arr, RoomType *r){
	arr->elements[arr->size]= r;
	arr->size+=1;
}
/*  
  Function: cleanupRoomArray()
  Purpose:  to clean up any dynamically allocated data used 
   in/out:   arr, is the RoomArrayType we want to clean up 
*/
void cleanupRoomArray(RoomArrayType *arr){
	for(int i = 0; i<arr->size;i++){
		cleanupGhostList(arr->elements[i]->ghosts);
		free(arr->elements[i]->ghosts);
		free(arr->elements[i]);
	}
}
/*  
  Function: printRooms()
  Purpose:  prints out all the rooms in RoomArrayType
       in:  arr, is the RoomArray we want to print out
*/
void printRooms(RoomArrayType* arr){
	for(int i = 0; i < arr->size;i++){	
		printf("Room name: %s \n",arr->elements[i]->name);
		printGhosts(arr->elements[i]->ghosts,C_FALSE);
		printf("\n");
	}
}






