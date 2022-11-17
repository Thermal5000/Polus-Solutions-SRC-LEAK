
#include "defs.h"
#pragma comment (lib, "d3d9.lib")
#include "../overlay/definesforoverlay.h"
Vector3 localactorpos;
Vector3 LinePos;
ImU32 filled;
auto isVisible(DWORD_PTR mesh) -> bool
{
	float fLastSubmitTime = read_new<float>(mesh + 0x330);
	float fLastRenderTimeOnScreen = read_new<float>(mesh + 0x338);

	const float fVisionTick = 0.06f;
	bool bVisible = fLastRenderTimeOnScreen + fVisionTick >= fLastSubmitTime;

	return bVisible;
}

FTransform GetBoneIndex(DWORD_PTR mesh, int index) {
	DWORD_PTR bonearray = read_new<DWORD_PTR>(mesh + Offsets::BoneArray);
	if (bonearray == NULL) {
		bonearray = read_new<DWORD_PTR>(mesh + Offsets::BoneArray + 0x10);
	}
	return read_new<FTransform>(bonearray + (index * 0x60));
}

Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id) {
	FTransform bone = GetBoneIndex(mesh, id);
	FTransform ComponentToWorld = read_new<FTransform>(mesh + 0x240);//0x240
	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}

#define M_PI 3.14159265358979323846264338327950288419716939937510
D3DMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0)) {
	float radPitch = (rot.x * float(M_PI) / 180.f);
	float radYaw = (rot.y * float(M_PI) / 180.f);
	float radRoll = (rot.z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}






struct Camera
{
	float FieldOfView;
	Vector3 Rotation;
	Vector3 Location;
};
Camera GetCamera(int64 a1)
{
	Camera FGC_Camera;
	int64 v1;
	int64 v6;
	int64 v7;
	int64 v8;

	v1 = read_new<int64>(Localplayer + 0xd0);
	int64 v9 = read_new<int64>(v1 + 0x10); // 0x10

	FGC_Camera.FieldOfView = 80.0f / (read_new<double>(v9 + 0x680) / 1.19f); // 0x600

	FGC_Camera.Rotation.x = read_new<double>(v9 + 0x7D0);
	FGC_Camera.Rotation.y = read_new<double>(a1 + 0x148);

	uint64_t FGC_Pointerloc = read_new<uint64_t>(Uworld + 0x100);
	FGC_Camera.Location = read_new<Vector3>(FGC_Pointerloc);




	return FGC_Camera;
}



Vector3 ProjectWorldToScreen(Vector3 WorldLocation)
{
	Camera vCamera = GetCamera(Rootcomp);
	vCamera.Rotation.x = (asin(vCamera.Rotation.x)) * (180.0 / M_PI);


	D3DMATRIX tempMatrix = Matrix(vCamera.Rotation);

	Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	Vector3 vDelta = WorldLocation - vCamera.Location;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	return Vector3((Width / 2.0f) + vTransformed.x * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (Height / 2.0f) - vTransformed.y * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);
}
Vector3 AimbotCorrection(float bulletVelocity, float bulletGravity, float targetDistance, Vector3 targetPosition, Vector3 targetVelocity) {
	Vector3 recalculated = targetPosition;
	float gravity = fabs(bulletGravity);
	float time = targetDistance / fabs(bulletVelocity);
	return recalculated;
}

double GetCrossDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}



enum InjectedInputMouseOptions
{
	Absolute = 32768,
	HWheel = 4096,
	LeftDown = 2,
	LeftUp = 4,
	MiddleDown = 32,
	MiddleUp = 64,
	Move = 1,
	MoveNoCoalesce = 8192,
	None = 0,
	RightDown = 8,
	RightUp = 16,
	VirtualDesk = 16384,
	Wheel = 2048,
	XDown = 128,
	XUp = 256
};

typedef struct _InjectedInputMouseInfo
{
	int DeltaX;
	int DeltaY;
	unsigned int MouseData;
	InjectedInputMouseOptions MouseOptions;
	unsigned int TimeOffsetInMilliseconds;
	void* ExtraInfo;
} InjectedInputMouseInfo;

typedef bool (WINAPI* InjectMouseInput_t)(InjectedInputMouseInfo* inputs, int count);

InjectMouseInput_t InjectMouseInput;
static auto aimbot(float x, float y) -> void {
	float center_x = (ImGui::GetIO().DisplaySize.x / 2);
	float center_y = (ImGui::GetIO().DisplaySize.y / 2);

	int AimSpeed = Settings::Aim_Speed;
	float target_x = 0;
	float target_y = 0;

	//if (isVisible)
	{
		if (x != 0.f)
		{
			if (x > center_x)
			{
				target_x = -(center_x - x);
				target_x /= Settings::Aim_Speed;
				if (target_x + center_x > center_x * 2.f) target_x = 0.f;
			}

			if (x < center_x)
			{
				target_x = x - center_x;
				target_x /= Settings::Aim_Speed;
				if (target_x + center_x < 0.f) target_x = 0.f;
			}
		}

		if (y != 0.f)
		{
			if (y > center_y)
			{
				target_y = -(center_y - y);
				target_y /= Settings::Aim_Speed;
				if (target_y + center_y > center_y * 2.f) target_y = 0.f;
			}

			if (y < center_y)
			{
				target_y = y - center_y;
				target_y /= Settings::Aim_Speed;
				if (target_y + center_y < 0.f) target_y = 0.f;
			}
		}


		InjectedInputMouseInfo info = { 0 };
		info.DeltaX = target_x;
		info.DeltaY = target_y;
		InjectMouseInput(&info, 1);

	}
}
bool isaimbotting;
bool isaimbotting1;
void AimAt(DWORD_PTR entity) {
	uint64_t currentactormesh = read_new<uint64_t>(entity + Offsets::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, Settings::hitbox);

	if (Settings::Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = read_new<uint64_t>(entity + Offsets::RootComponent);
		Vector3 vellocity = read_new<Vector3>(CurrentActorRootComponent + Offsets::Velocity);
		Vector3 Predicted = AimbotCorrection(-504, 35, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= Settings::AimFOV * 1)) {
				//Beep(9000, 3);
				aimbot(rootHeadOut.x, rootHeadOut.y);

			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= Settings::AimFOV * 1)) {
				//Beep(9000, 3);
				aimbot(rootHeadOut.x, rootHeadOut.y);
			}
		}
	}
}










void AimAt2(DWORD_PTR entity) {
	uint64_t currentactormesh = read_new<uint64_t>(entity + Offsets::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, Settings::hitbox);

	if (Settings::Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = read_new<uint64_t>(entity + Offsets::RootComponent);
		Vector3 vellocity = read_new<Vector3>(CurrentActorRootComponent + Offsets::Velocity);
		Vector3 Predicted = AimbotCorrection(-504, 35, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= Settings::AimFOV * 1)) {
				if (Settings::lockline) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImColor(255, 0, 0, 255), 1.0f);
				}
			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= Settings::AimFOV * 1)) {
				if (Settings::lockline) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImColor(255, 0, 0, 255), 1.0f);
				}
			}
		}
	}
}