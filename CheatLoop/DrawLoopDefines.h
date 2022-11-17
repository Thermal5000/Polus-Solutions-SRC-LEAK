#pragma once
DWORD_PTR Uworld;
DWORD_PTR LocalPawn;
DWORD_PTR Rootcomp;
DWORD_PTR Localplayer;
DWORD_PTR PlayerController;
DWORD_PTR Ulevel;
DWORD_PTR PlayerState;
DWORD_PTR Persistentlevel;
DWORD_PTR CurrentActorMesh;
int localplayerID;
typedef struct _FNlEntity
{
	uint64_t Actor;
	int ID;
	uint64_t mesh;
	DWORD_PTR rootcomp;
	std::string name;
}FNlEntity;
std::vector<FNlEntity> entityList;
