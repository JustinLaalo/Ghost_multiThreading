#include "defs.h"
/*  
  Function: loadBuildingData()
  Purpose:  calls all the functions and inializes them
       in:  building, the place where we are adding the following information
*/
void loadBuildingData(BuildingType *building)
{
  GhostType*  ghost;
  RoomType*   room;
  int currRoomId = NEXT_ROOM_ID;
  int currGhostId = NEXT_GHOST_ID;

  initRoom(currRoomId++, "Master Bedroom", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, PHANTOM, room, 50.09f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, WRAITH, room, 47.33f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, OTHER, room, 62.46f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Bathroom", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, OTHER, room, 17.42f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, PHANTOM, room, 98.64f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, BULLIES, room, 11.88f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Guest Bedroom", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, POLTERGEIST, room, 15.60f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Living Room", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, OTHER, room, 77.71f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Kitchen", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, POLTERGEIST, room, 34.33f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, BULLIES, room, 1.85f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, PHANTOM, room, 60.44f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Dining Room", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, OTHER, room, 23.81f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Basement", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, WRAITH, room, 42.40f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, PHANTOM, room, 62.89f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Attic", &room);
  addRoom(&building->rooms, room);
  initGhost(currGhostId++, POLTERGEIST, room, 12.28f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);
  initGhost(currGhostId++, WRAITH, room, 30.85f, &ghost);
  addGhost(&building->ghosts, ghost);
  addGhost(room->ghosts, ghost);

  initRoom(currRoomId++, "Garage", &room);
  addRoom(&building->rooms, room);

  initRoom(currRoomId++, "Entryway", &room);
  addRoom(&building->rooms, room);

  initRoom(currRoomId++, "Hallway", &room);
  addRoom(&building->rooms, room);

  initRoom(currRoomId++, "Staircase", &room);
  addRoom(&building->rooms, room);

  initGhost(currGhostId++, POLTERGEIST, NULL, 38.0f, &ghost);
  addGhost(&building->ghosts, ghost);

  initGhost(currGhostId++, OTHER, NULL, 98.2f, &ghost);
  addGhost(&building->ghosts, ghost);
}
/*  
  Function: initBuilding()
  Purpose:  initializes a building
       in:  b, is the BuildingType we are going to use to set up GhostList and RoomArray
*/
void initBuilding(BuildingType * b){
	initGhostList(&b->ghosts);
	initRoomArray(&b->rooms);
}
/*  
  Function: cleanupBuilding()
  Purpose:  cleans up all dynamically data used in BuildingType
       in:  b, is the BuildingType we are going to clean up
*/
void cleanupBuilding(BuildingType * b){
	cleanupGhostData(&b->ghosts);
	cleanupGhostList(&b->ghosts);
	cleanupRoomArray(&b->rooms);
}

