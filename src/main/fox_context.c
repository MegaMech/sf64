#include "prevent_context_reordering.h"
#include "sys.h"
#include "sf64level.h"
#include "sf64object.h"
#include "sf64player.h"

s32 gOverlaySetup;
s32 gOverlayStage;
s32 D_80177824; // some sort of flag
s32 D_8017782C; // some sort of flag. all range related?
GameState gGameState;
s32 D_Timer_8017783C; // next game state timer?
s32 D_80177844;       // timer for vs item spawn
OptionState gOptionMenuStatus;
s32 D_80177854; // pause-related state
s32 D_80177868; // some sort of state. pause-related?
LevelMode gLevelMode;
DrawMode gDrawMode;
s32 gPlayerNum;
s32 gCamCount;
s32 gTeamShields[6];
s32 gSavedTeamShields[6];
UNK_TYPE D_801778F0[6];
s32 gTeamDamage[6];
u8 D_80177930; // next planet path
f32 gGroundLevel;
f32 D_80177950;
f32 D_80177968;
f32 D_80177970;
f32 gCsCamEyeX;
f32 gCsCamEyeY;
f32 gCsCamEyeZ;
f32 gCsCamAtX;
f32 gCsCamAtY;
f32 gCsCamAtZ;
Vec3f D_801779D8;
Vec3f D_801779E8;
bool gExpertMode;
s32 D_80177A10[10];
f32 D_80177A48[10];
s32 gCsFrameCount;
u8 D_80177A98;
u8 D_80177AB0;
u8 D_80177AC8;
s32 D_80177AE0;
s32 gMainController;
s32 D_80177B40;
s32 gCurrentPlanet; // D_80177B48 // Arrow pointer?
s32 D_80177B50[7];
s32 D_80177B70[7];
PlanetId D_80177B90[7];
s32 D_80177BB0[7];
s32 D_80177BD8[22]; // overruns D_80177C30?
s32 D_80177C38[6];
s32 D_80177C58[6];
u8 gSoundMode;
s32 gVolumeSettings[3];
u16 D_80177C90;
u8 gLevelType;
s32 D_80177CA0;
UNK_TYPE F_80177CA8;
f32 D_80177CB0;
UNK_TYPE F_80177CB8;
f32 D_80177CC0;
f32 D_80177CC8;
f32 D_80177CE8;
f32 D_80177D08;
f32 D_80177D20;
f32 D_80177D38;
f32 D_80177D50;
f32 D_80177D68;
UNK_TYPE F_80177D80;
UNK_TYPE F_80177DE8;
s32 gGameFrameCount;
s32 D_80177DC8;
s32 D_80177E70;
s32 D_80177E78;
s32 D_80177E80;
Vec3f D_80177E88;
Vec3f D_80177F10;
UNK_TYPE F_80178020;
s32 D_8017812C;
LevelId gCurrentLevel;
s32 D_8017827C;
s32 gBossActive;
s32 D_8017828C;
s32 D_80178294;
s32 gRadioState;
s32 D_801782A4;
s32 D_Timer_801782AC;
s32 D_Timer_801782B4;
u8 D_800D3180[30] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
s32 D_801782C0;
s32 D_801782C8;
s32 D_801782D0;
s32 D_801782D8;
UNK_TYPE F_801782E0;
s32 D_801782E8;
UNK_TYPE F_801782F0;
s32 D_801782F8;
s32 D_80178300;
u16* D_80178308;
ObjectInit* D_80178310;
UNK_TYPE F_80178318;
s32 gFogRed;
s32 gFogGreen;
s32 gFogBlue;
s32 gFogAlpha;
s32 D_80178340; // alpha something
s32 D_80178348; // red something
s32 D_80178350; // green something
s32 D_80178354; // blue something
s32 D_80178358; // alpha target
s32 D_8017835C; // alpha step
s32 D_80178360; // 2 lights second color
s32 D_80178364;
s32 D_80178368;
f32 D_8017836C; // 2 lights second color brightness
f32 D_80178370; // Vec3f?
f32 D_80178374;
f32 D_80178378;
s32 D_8017837C;
u32 D_80178380[4]; // player alphas
s32 D_80178390[4]; // player reds
s32 D_801783A0[4]; // player greens
s32 D_801783B0[4]; // player alphas
UNK_TYPE D_801783C0[4];
f32 D_801783D0; // something x translate
f32 D_801783D4; // something y translate
s32 gFogNear;   // near
s32 gFogFar;    // far
UNK_TYPE F_801783E0;
UNK_TYPE F_801783E4;
UNK_TYPE F_801783E8;
UNK_TYPE F_801783EC;
UNK_TYPE F_801783F0;
UNK_TYPE F_801783F4;
UNK_TYPE F_801783F8;
UNK_TYPE F_801783FC;
UNK_TYPE F_80178400;
UNK_TYPE F_80178404;
UNK_TYPE F_80178408;
UNK_TYPE F_8017840C;
s32 D_80178410;
f32 D_80178414;
f32 D_80178418;
UNK_TYPE F_8017841C;
f32 D_80178420;
f32 D_80178424;
f32 D_80178428;
f32 D_8017842C;
f32 D_80178430;
UNK_TYPE F_80178434;
UNK_TYPE F_80178438;
UNK_TYPE F_8017843C;
f32 D_80178440;
f32 D_80178444;
f32 D_80178448;
f32 D_80178450[3];
f32 D_80178460[3];
f32 D_80178470[3];
f32 D_8017847C;
s32 D_80178480;
s32 D_80178484;
bool D_80178488;
UNK_TYPE F_8017848C;
UNK_TYPE F_80178490;
s32 D_80178494;
f32 D_80178498;
f32 D_8017849C;
f32 D_801784A0;
s32 D_801784A4;
UNK_TYPE F_801784A8;
s32 D_801784AC;
UNK_TYPE F_801784B0;
UNK_TYPE F_801784B4;
f32 D_801784B8; // effective Vec3f
f32 D_801784BC;
f32 D_801784C0;
f32 D_801784C4; // effective Vec3f
f32 D_801784C8;
f32 D_801784CC;
f32 D_801784D0; // effective Vec3f
f32 D_801784D4;
f32 D_801784D8;
s32 gLight1x; // Vec3i light direction
s32 gLight1y;
s32 gLight1z;
f32 D_801784E8;
f32 D_801784EC; // effective Vec3f?
f32 D_801784F0;
f32 D_801784F4;
f32 D_801784F8; // effective Vec3f
f32 D_801784FC;
f32 D_80178500;
s32 gLight2x; // Vec3i light direction alternate
s32 gLight2y;
s32 gLight2z;
f32 D_80178510;
UNK_TYPE F_801784514;
UNK_TYPE F_801784518;
UNK_TYPE F_80178451C;
f32 D_80178520; // effective Vec3f
f32 D_80178524;
f32 D_80178528;
UNK_TYPE F_80178452C;
UNK_TYPE F_801784530;
UNK_TYPE F_801784534;
f32 D_80178538;
f32 D_8017853C;
s32 D_80178540;
s32 D_80178544;
s32 gLight1R; // Color32 light color 1
s32 gLight1G;
s32 gLight1B;
s32 gAmbientR; // Color32 ambient color
s32 gAmbientG;
s32 gAmbientB;
UNK_TYPE F_80178560;
s32 gLight2R; // Color32 light color 2
s32 gLight2G;
s32 gLight2B;
UNK_TYPE P_800D31A0 = 0;
s32 D_80178570; // Color32 light color 2 modifier?
s32 D_80178574;
s32 D_80178578;
s32 D_80161A70; // Color32? start of bss
s32 D_80161A74;
s32 D_80161A78;
s32 D_80161A7C;
s32 D_80161A80;
s32 D_80161A84;
s32 D_80161A88;
s32 D_80161A8C;
u8 gGoldRingCount[4];
u8 D_80161A94[4];
s32 gHitCount;
s32 gSavedHitCount;
s16 gLifeCount[4];
LaserStrength gLaserStrength[4];
s32 D_80161AB8;
UNK_TYPE F_80161AC0[4];
UNK_TYPE F_80161AD0[4];
UNK_TYPE F_80161AEC[4];
UNK_TYPE F_80161AF0[4];
UNK_TYPE P_800D31A4 = 0;
Object_80 gObjects80[50];
Object_4C gObjects4C[40];
Actor gActors[60];
Boss gBosses[4];
Effect gEffects[100];
Item gItems[20];
PlayerShot gPlayerShots[16];
UnkEntity30 gUnkEntities30[100];
UnkEntity28 gUnkEntities28[65];
BonusText gBonusText[10];
s32 D_80176550[2];
f32 D_80176558[2][100];
f32 D_80176878[2][100];
f32 D_80176B98[2][100];
f32 D_80176EB8[2][100];
f32 D_801771D8[2][100];
f32 D_80177500[2][100];
UNK_TYPE P_800D31A8 = 0;
u16 D_80177828; // enemy shot speed?
u8 D_80177830;  // show level complete status overlay
s32 D_80177838; // level clear related
s32 D_80177840; // timer for mission accomplished scrren
s32 gBossHealthBar;
s32 D_80177850; // bonus text related. set to 15 but never read
s32 D_80177858[4];
s32 D_80177870[4];
s32 gHandicap[4];
VsStage gVersusStage;
s32 D_801778A4;
s32 D_801778AC;
s32 D_801778C8;
bool gVersusMode;
u16 gBoostButton[4];
u16 gBrakeButton[4];
u16 gShootButton[4];
u16 gBombButton[4];
f32 D_80177958[4];
s32 D_8017796C;
OSContPad* gInputHold;
OSContPad* gInputPress;
u8* D_80177984;
s32 D_80177990[4];
f32 D_801779A8[4];
u8 D_801779BC;
s32 gChargeTimers[4];
f32 D_801779E4;
f32 D_801779F4;
s32 D_Timer_80177A00[4];
s32 D_Timer_80177A38[4];
s32 D_Timer_80177A70[4];
s32 D_Timer_80177A88[4];
f32 D_80177AA0[4];
f32 D_80177AB8[4];
s32 D_80177AD0[4];
s32 D_80177AE8[4];
s32 D_80177B00[4][4];
u8 D_Timer_80177B44;
u8 D_80177B4C;
u8 D_80177B6C;
u8 D_80177B8C;
u8 D_80177BAC;
u16 D_Timer_80177BD0[4];
u16 D_80177C30[4];
s32 D_80177C50;
s32 D_80177C70;
s32 D_80177C78;
s32 D_80177C8C;
s32 D_80177C94;
s32 D_80177C9C;
s32 D_80177CA4;
s32 D_80177CAC;
s32 D_80177CB4;
s32 D_80177CBC;
s32 D_80177CC4;
s32 D_80177CD0[6];
s32 D_80177CF0[6];
s32 gRightWingHealth[4];
s32 gLeftWingHealth[4];
s32 D_80177D40[4];
s32 D_80177D58[4];
s32 D_80177D70[4];
s32 D_80177D88[4];
s32 gBombCount[4];
s32 D_80177DB8[4];
s32 D_80177DD0[4][10];
s32 D_80177E74;
s32 D_80177E7C;
s32 D_80177E84;
Vec3f D_80177E98[10];
f32 D_80177F20[65];
f32 D_80178028[65];
f32 D_80178130[65];
u8 D_80178238[65];
Player* gPlayer;
f32* D_80178288;
f32* D_80178290;
u32* D_80178298;
UNK_TYPE F_801782A0;
Object_58* gObjects58;
UNK_TYPE F_801782B0;
s32 D_801782B8;
s32 D_801782BC;
PosRot* D_801782C4;
f32* D_801782CC;
f32* D_801782D4;
f32* D_801782DC;
f32* D_801782E4;
f32* D_801782EC;
UNK_TYPE F_801782F4;
s32 D_801782FC;
UNK_TYPE F_80178304;
UNK_TYPE F_8017830C;
UNK_TYPE F_80178314;
UNK_TYPE F_8017831C;
UNK_TYPE F_80178324;
UNK_TYPE F_8017832C;
UNK_TYPE F_80178334;
UNK_TYPE F_8017833C;
UNK_TYPE F_80178344;
UNK_TYPE F_8017834C;
