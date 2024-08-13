#pragma once
#include "Common.hpp"
#include "Types.hpp"

namespace Big {
	//----------------\
	// FUNCTIONS	   |
	//----------------/

	extern bool Godmode;
	extern bool Invisible;
	extern bool SuperJump;
	extern bool NeverWanted;

	void FunctionsOnTick();

	void ClonePlayer(Player selectedPed);


	//=================
	// PED FUNCTIONS
	//=================

	Ped ClonePed(Ped ped);
	Ped CreatePed(const char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle);

	//Animations
	void LoadAnim(const char* dict);
	void playAnimation(Ped ped, bool loop, const char* dict, const char* anim);

	//SKINS
	bool applyChosenSkin(std::string skinName);

	//CONTROL
	void RequestControlOfEnt(Entity entity);

	//FORCE
	void ApplyForceToEntity(Entity e, float x, float y, float z);

	//NEARBY PEDS
	std::set<Ped> getNearbyPeds();
	void update_nearby_peds(Ped playerPed, int count);

	//VEHICLE
	bool get_vehicle_keyboard_result(uint32_t* outModel);

	//little one-line function called '$' to convert $TRING into a hash-key:
	Hash $(std::string str);

	//Converts Radians to Degrees
	float degToRad(float degs);

	//quick function to get-coords-of-entity:
	Vector3 coordsOf(Entity entity);

	//quick function to get distance between 2 points:
	float distanceBetween(Vector3 A, Vector3 B);

	//quick "get random int in range 0-x" function:
	int rndInt(int start, int end);

	//TELEPORTATION
	Vector3 get_blip_marker();
	void teleport_to_marker();
	void teleport_to_objective();
	void teleport_to_coords(Entity e, Vector3 coords);

	//KEYBOARD
	std::string show_keyboard(const char* title_id, const char* prepopulated_text);

	//VECTOR/FLOAT
	Vector3 rot_to_direction(Vector3* rot);
	Vector3 add(Vector3* vectorA, Vector3* vectorB);
	Vector3 multiply(Vector3* vector, float x);
	float get_distance(Vector3* pointA, Vector3* pointB);
	float get_vector_length(Vector3* vector);

	//NOTIFICATION
	void notifyBottom(const char* fmt, ...);
	void notifyBottom(std::string str);
	void notifyMap(const char* fmt, ...);
	void notifyMap(std::string str);
	void notifyCenter(const char* fmt, ...);
	void notifyCenter(std::string str);
	void update_status_text();
	void notifyleft(const char* msg);
	void notify_Custom(const char* Head_txt, const char* fmt, ...);
	void notify_Original(const char* fmt, ...);
	void notify_Red(const char* fmt, ...);
	void notify_Green(const char* fmt, ...);

	// Header
	extern bool HeaderImage;
	const char* Add_Strings(const char* string1, const char* string2);
	std::string Documents_Patha();

	//DRAWING FUNCTIONS
	void draw_rect(float A_0, float A_1, float A_2, float A_3, int A_4, int A_5, int A_6, int A_7);
	void draw_menu_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);
}