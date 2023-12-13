#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "libc/stdbool.h"
#include "structs.h"
#include "fox_option.h"

void Controller_Init(void);
void Controller_UpdateInput(void);
void Controller_ReadData(void);
void Save_ReadData(void);
void Save_WriteData(void);
void Controller_Rumble(void);

s32 Lib_vsPrintf(char* dst, const char* fmt, va_list args);
void Lib_Perspective(Gfx** dList);
void Lib_Ortho(Gfx** dList);
void Lib_DmaRead(void* src, void* dst, s32 size);
void Lib_FillScreen(u8 setFill);

void Lights_SetOneLight(Gfx** dList, s32 dirX, s32 dirY, s32 dirZ, s32 colR, s32 colG, s32 colB, s32 ambR, s32 ambG, s32 ambB);
void Lights_SetTwoLights(Gfx** dList, s32 dir1x, s32 dir1y, s32 dir1z, s32 dir2x, s32 dir2y, s32 dir2z, s32 col1r, s32 col1g,
                   s32 col1b, s32 col2r, s32 col2g, s32 col2b, s32 ambR, s32 ambG, s32 ambB);  
f32 Math_ModF(f32 value, f32 mod);
void Rand_Init(void);
f32 Rand_ZeroOne(void);
void Rand_SetSeed(s32 seed1, s32 seed2, s32 seed3);
f32 Rand_ZeroOneSeeded(void);
f32 Math_Atan2F(f32 y, f32 x);
f32 Math_Atan2F_XY(f32 x, f32 y);
f32 Math_Atan2F_XYAlt(f32 x, f32 y);
f32 Math_PowF(f32 base, s32 exp);
void Math_MinMax(s32* min, s32* max, s32 val1, s32 val2, s32 val3);

void Matrix_Copy(Matrix*, Matrix*);
void Matrix_Push(Matrix** mtxStack);
void Matrix_Pop(Matrix** mtxStack);
void Matrix_Mult(Matrix*, Matrix*, u8);
void Matrix_Translate(Matrix*, f32, f32, f32, u8);
void Matrix_Scale(Matrix*, f32, f32, f32, u8);
void Matrix_RotateX(Matrix*, f32, u8);
void Matrix_RotateY(Matrix*, f32, u8);
void Matrix_RotateZ(Matrix*, f32, u8);
void Matrix_RotateAxis(Matrix*, f32, f32, f32, f32, u8);
void Matrix_ToMtx(Mtx *dest);
void Matrix_FromMtx(Mtx *src, Matrix *dest);
void Matrix_MultVec3f(Matrix*, Vec3f*, Vec3f*);
void Matrix_MultVec3fNoTranslate(Matrix*, Vec3f*, Vec3f*);
void Matrix_GetYRPAngles(Matrix*, Vec3f*);
void Matrix_GetXYZAngles(Matrix*, Vec3f*);
void Matrix_LookAt(Matrix*, f32, f32, f32, f32, f32, f32, f32, f32, f32, u8);
void Matrix_SetGfxMtx(Gfx**);

s32 Timer_CreateTask(u64, TimerAction, s32*, s32);

void Memory_FreeAll(void);
void* Memory_Allocate(s32);

void Timer_Increment(s32* address, s32 value);
void Timer_SetValue(s32* address, s32 value);
void Timer_CompleteTask(TimerTask*);
void Timer_Wait(u64);

s32 Save_WriteEeprom(SaveFile*);
s32 Save_ReadEeprom(SaveFile*);

void Fault_ThreadEntry(void*);
void func_80007FE4(FrameBuffer*, u16, u16);
void Fault_Init(void);

void func_8000FFCC(void);

u8* func_8001C3EC(void);
void func_80016A50(void);
void func_800182F4(s32);
void func_80019218(u32, Vec3f*, u8, f32*, f32*, s8*);
void func_8001A500(Vec3f*);
void func_8001A55C(f32*, u32);
void func_8001A838(u32);
void func_8001ACDC(s32);
void func_8001AE58(void);
s32 func_8001AE78(void);
s32 func_8001AED4(void);
void func_8001AF40(s32);
void func_8001D1C8(s32, s32);
void func_8001D400(s32);
void func_8001D444(u8, u16, u8, u8);
void func_8001D638(u8);
void func_8001DA90(u8);
void func_8001DBD0(s32);
void func_8001DC6C(u8, u16);
void func_8001D8A8(u8, u8);
void func_8001D8F4(u8);
void func_8001DCE0(void);
void func_8001DECC(void);

SPTask* func_8001DF50(void);
void func_8001EE00(void);

f32 func_8001FE60(f32);
f64 func_8001FE6C(f64);
s32 func_8001FE78(f32);
s32 func_8001FE88(f64);
f32 func_8001FE98(f32);
f64 func_8001FEA4(f64);
s32 func_8001FEB0(f32);
s32 func_8001FEC0(f64);
f32 func_8001FED0(f32);
f64 func_8001FEDC(f64);
s32 func_8001FEE8(f32);
s32 func_8001FEF8(f64);
f32 func_8001FF08(f32);
f64 func_8001FF14(f64);
s32 func_8001FF20(f32);
s32 func_8001FF30(f64);
f32 func_8001FF40(f32);
f64 func_8001FF5C(f64);
s32 func_8001FF7C(f32);
s32 func_8001FF9C(f64);
f32 func_8001FAE4(f32);
f32 func_8001FB04(f32);
f64 func_8001FB24(f64);
f32 func_8001FB58(f32);
f32 func_8001FB88(f32);
f32 func_8001FBA8(f32);
f32 func_8001FBC8(f32);

void RdRam_CheckIPL3(void);
void Mio0_Decompress(void* header, u8* dst);
s32 vsprintf(char* dst, const char* fmt, va_list args);

f32 Math_FAtanF(f32);
f32 Math_FAtan2F(f32, f32);
f32 Math_FAsinF(f32);
f32 Math_FAcosF(f32);

f32 __sinf(f32);
f32 __cosf(f32);

s64 __ull_div(s64, s64);
s64 __ll_mul(s64, s64);
s64 __ll_rshift(s64, s64);

// sf_2EFE0
void func_8002E3E0(Object_2F4 *);
void func_8002E548(void);
void func_8002E5E0(Object*);
void func_8002E604(Object*);
void func_8002E628(Object*);
void func_8002E64C(Object*);
void func_8002E670(Object*);
void func_8002E694(Object*);
void func_8002E6B8(Object*);
void func_8002E6DC(Object*);
void func_8002F5F4(void);
void func_800319AC(Object*);
void func_80035448(Object*);

//sf_36930
void func_80035E48(Object_70 *);
void func_8003DA0C(void);
void func_8003DAF0(void);
void func_8003DE68(s32, s32);
void func_8003E1E8(void);
void func_80040450(void);
void func_80040954(void);
void func_80040CDC(void);
void func_80040CE4(void);

// sf_43AC0
void func_80042FAC(Object_408 *);
void func_80042FB8(Object*);
void func_80042FC4(Object*);
void func_80042FD0(Object_408 *);
void func_80042FDC(Object*);
void func_80042FE8(Object*);
void func_800444BC(UnkStruct_D_80178280 *);
void func_800515C4(void);

// sf_496E0
void func_8004F8AC(Object*);
void func_8004FEC0(Object*);

// fox_52730
void func_80053658(UnkStruct_D_80161630 *);
void func_8005465C(s32);
void func_80057814(UnkStruct_D_80178280* arg0);
void func_80057D00(void);

// fox_edata
void func_800594F0(Object_80*);
void func_800595D0(Object_80*);
void func_800596C0(void);
void func_800596B0(Object_2F4*);

// fox_edisplay
void func_8005980C(f32);
void func_80059850(Object_4C*);
void func_800598E8(Object_2F4*);
void func_80059A24(Object_2F4*);
void func_80059AEC(Object_80*);
void func_80059B20(Object_80*);
void func_80059BBC(Object_80*);
void func_80059BF0(Object_2F4*);
void func_80059C34(Object_4C*);
void func_80059C40(Object_4C*);
void func_80059F68(Object_6C*);
void func_80059FDC(Object_6C*);
void func_8005A094(Object_2F4*);
void func_8005B6A4(Object_2F4*);
void func_8005B71C(Object_2F4*);
void func_8005B7CC(Object_2F4*);
void func_8005B848(Object_2F4*);
void func_8005B9A4(Object_2F4*);
void func_8005BA30(Object_2F4*);
void func_8005C5F0(Object_6C*);
void func_8005C900(Object_6C*);
void func_8005C9C0(Object_6C*);
void func_8005CA80(Object_6C*);
void func_8005CB44(Object_6C*);
void func_8005CC9C(Object_6C*);
void func_8005CDA8(Object_6C*);
void func_8005F030(Vec3f*);
void func_8005F0E8(Vec3f*, Vec3f*);
void func_8005F1EC(Vec3f*);
void func_8005F290(Vec3f*, Vec3f*);
void func_8005F670(Vec3f*);
s32 func_8005F9DC(Vec3f*);

// fox_enmy1
void func_80060714(s32 arg0);
void func_8006089C(u8 arg0);
void func_80060968(void);
void func_80060FBC(Object*, Vec3f*);
s32 func_80060FE4(Vec3f*, f32);
void func_800612B8(ObjectStruct_1C*, u32);
void func_80061364(Object_80*);
void func_80061394(Object_4C*);
void func_800613C4(Object_2F4*);
void func_80061404(Object_408*);
void func_80061444(Object_6C*);
void func_80061474(Object_8C*);
void func_80061B68(void);
void func_80061CD0(void);
void func_80061E48(Object_2F4* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80061F0C(Object_2F4* arg0, ObjectInit* arg1, s32 arg2);
void func_80062180(ObjectInit* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 func_800631A8(Vec3f*, f32*, Vec3f*);
s32 func_8006326C(Vec3f* arg0, Vec3f* arg1, s32 arg2, Object* arg3);
void func_800652CC(Object_80*);
void func_800654E4(Object *);
void func_800656D4(Object_2F4*);
void func_800660F0(Object_2F4*);
void func_80066254(Object_2F4*);
void func_8006654C(Object_2F4*);
void func_8006684C(Object_2F4*);
void func_800669A0(Object_2F4*);
void func_80066A80(Object_2F4*);
void func_80066C00(Object_80*);
void func_80066D5C(Object_80*);
void func_80066E8C(Object_4C*);
void func_80066EA8(Object_80*);
void func_80066EF0(Object_6C *);
void func_800671D0(Object_6C *);
void func_800674B4(f32, f32, f32, f32, f32, f32, f32, f32);
void func_8006753C(Object_2F4*);
void func_80067874(Object_2F4*);
void func_80067B1C(Object_6C*);
void func_80067BEC(Object_6C*);
void func_80067F6C(Object_6C*);
void func_80068020(Object_6C*);
void func_800685D8(Object_6C*);
void func_800685F8(Object_6C*);
void func_80068618(Object_6C*);
void func_80068688(Object_6C*);
void func_80068914(Object_6C*);
void func_80068C48(Object_6C*);
void func_80068C88(Object_6C*);
void func_80068FE0(Object_4C*);
void func_800690D0(s32, s32);
void func_80069924(Object_8C *);
void func_800693E8(Object_2F4 *);
void func_80069658(Object_408 *);
void func_800696F8(Object_80 *);
void func_80069858(Object_4C *);
void func_80069A10(Object_6C *);
void func_80069AAC(Object_2F4*);
void func_80069CBC(Object_408 *);
void func_80069DF4(Object_80 *);
void func_80069E88(Object_4C *);
void func_80069F30(Object_6C *);
void func_80069FD4(Object_8C *);
void func_8006A06C(UnkStruct_D_80174750*);
void func_8006A38C(void);
void func_8006A3E8(void);

//sf_6B3B0
void func_8006A96C(Object*);
void func_8006A978(Object*);
void func_8006AA98(Object*);
void func_8006AC08(Object*);
void func_8006AD18(Object*);
void func_8006B094(Object*);
void func_8006B0A0(Object_2F4 *, s32);
void func_8006B74C(Object_2F4 *);
void func_8006B95C(Object*);
void func_8006BB78(Object*);
void func_8006C008(Object*);
void func_8006D350(Object*);
void func_8006EEFC(s32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_80072594(Object*);
void func_80074F90(Object*);
void func_80074FF0(Object*);
void func_800763A4(Object_2F4 *, s32);
void func_8007717C(Object_2F4 *, s32);
void func_800771CC(Object*);
void func_80077218(Object*);

// sf_77E40
void func_80077240(f32 posX, f32 posY, f32 posZ, s32 arg3);
void func_8007729C(void);
void func_80077790(void);
Object_8C* func_8007783C(s32 objId);
void func_8007797C(f32 posX, f32 posY, f32 posZ, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_80077A00(Object_8C* arg0);
void func_80077A7C(Object_8C* arg0);
void func_80077B78(void* arg0);
void func_80077B84(Object_8C* arg0);
void func_80078038(Object_8C* arg0);
void func_800780F8(Object_8C* arg0);
void func_800783C0(Object_8C* arg0);
void func_80078438(Object_8C* arg0);
void func_800784B4(Object_8C* arg0);
void func_80078550(Object_8C* arg0);
void func_80078604(Object_8C* arg0);
void func_8007868C(Object_8C* arg0);
void func_8007879C(Object_8C* arg0);
void func_800788B0(Object_8C* arg0);
void func_80078A64(Object_8C* arg0);
void func_80078AEC(Object_8C* arg0);
void func_80078B8C(void *unused);
void func_80078BE0(Object_8C* arg0);
void func_80078C84(Object_8C* arg0);
void func_80078CE8(Object_8C* arg0);
void func_80078E50(f32 posX, f32 posY, f32 posZ, f32 arg3);
void func_80078EBC(Object_8C* arg0);
void func_80078F78(Object_8C* arg0);
void func_8007905C(Object_8C* arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, u8 arg5);
void func_800794CC(f32 posX, f32 posY, f32 posZ, f32 arg3);
void func_8007953C(f32 posX, f32 posY, f32 posZ, f32 arg3);
void func_800795AC(f32 posX, f32 posY, f32 posZ, f32 arg3);
void func_80079618(f32 posX, f32 posY, f32 posZ, f32 arg3);
void func_8007968C(Object_8C *arg0);
s32 func_800798C4(s32 arg0, Gfx** arg1, Vec3f* arg2, Vec3f* arg3, void* arg4); //OverrideLimbDraw
void func_800798F0(Object_8C* arg0);
void func_8007A28C(Object_8C* arg0);
void func_8007A3C0(Object_8C* arg0);
void func_8007A568(f32 xPos, f32 yPos, f32 zPos, f32 arg3);
void func_8007A5F8(Object_8C* arg0, Vec3f* arg1, u32 arg2);
void func_8007A6F0(Vec3f *, u32);
void func_8007A748(Object_8C*);
s32 func_8007A774(UnkStruct_D_80178280*, Object_8C*, f32);
void func_8007A818(Object_8C*, f32 posX, f32 posY, f32 posZ, f32, u8, u8, u16);
void func_8007A900(f32 posX, f32 posY, f32 posZ, f32, u8, u8, u16);
void func_8007A994(Object_8C*);
void func_8007AA60(Object_8C*);
void func_8007AB50(Object_8C*);
void func_8007ACE0(f32, f32, f32, f32, f32, f32);
void func_8007ADF4(f32 arg0, f32 posY, f32 arg2, f32 arg3, f32 arg4);
void func_8007AFD0(f32 posX, f32 posZ, f32 arg2, f32 arg3, f32 arg4);
void func_8007B040(Object_8C*);
void func_8007B0F4(Object_8C*);
void func_8007B228(f32 posX, f32 posY, f32 posZ, f32 arg3);
void func_8007B344(f32 xPos, f32 yPos, f32 zPos, f32 arg3, s32 arg4);
void func_8007B3B8(Object_8C*);
void func_8007B550(f32 posX, f32 posY, f32 posZ, f32 arg3, s32 arg4);
void func_8007B5C0(Object_8C*);
void func_8007B62C(Object_8C*);
void func_8007B670(void*);
void func_8007B67C(Object_8C*);
void func_8007B758(Object_8C*);
void func_8007B8F8(f32 posX, f32 posY, f32 posZ, f32 arg3);
void func_8007B960(Object_8C*);
void func_8007BC7C(f32, f32, f32, f32);
void func_8007BCE8(Object*);
void func_8007B9DC(Object*);
void func_8007BDE0(Object*);
void func_8007BE54(Object*);
void func_8007BEE8(Object*);
void func_8007BFFC(f32, f32, f32, f32, f32, f32, f32, s32);
void func_8007C120(f32, f32, f32, f32, f32, f32, f32, s32);
void func_8007C250(Object*);
void func_8007C484(f32, f32, f32, f32, f32, f32, f32, s32);
void func_8007C50C(Object*);
void func_8007C8C4(Object*);
void func_8007C9E0(Object*);
void func_8007CAF0(Object*);
void func_8007D074(f32, f32, f32, f32);
void func_8007D0E0(f32, f32, f32, f32);
void func_8007D10C(f32, f32, f32, f32);
void func_8007D2C8(f32, f32, f32, f32);
void func_8007D2F4(Object*);
void func_8007D55C(Object*);
void func_8007D748(Object*);
void func_8007D8A8(Object*);
void func_8007DA58(Object*);
void func_8007DAE4(Object*);
void func_8007DB70(Object*);
void func_8007DED4(Object*);
void func_8007E014(Object*);
void func_8007E258(Object*);
void func_8007E298(Object*);
void func_8007E330(Object*);
void func_8007E3E4(Object*);
void func_8007E45C(Object*);
void func_8007E5CC(Object*);
void func_8007E648(Object*);
void func_8007F04C(s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32); // Object_Spawn?
void func_8007F438(Object*);
void func_8007F6B0(Object*);
void func_8007F958(Object*);
void func_8007FBE0(Object*);
void func_8007FE88(Object*);
void func_800802B8(Object*);
void func_800802D8(Object*);
void func_800802F8(Object*);
void func_80080360(Object*);
void func_8008040C(Object*);
void func_8008092C(Object*);
void func_80080ACC(Object*);
void func_80080D04(Object*);
void func_80081C5C(Object*);
void func_80082F78(Object*);
void func_800837EC(Object*);
void func_80083B8C(Object*);
void func_80083FA8(Object*);
void func_80084194(Object_8C*);

// fox_84F70
void func_80084370(s32);
void func_800843FC(s32);
void func_80084488(s32);
void func_80084688(s32, s32);

// fox_hud
void func_80084B94(s32);
void func_800857DC(f32, f32, f32, f32);
void func_80085890(f32, f32, f32, f32);
void func_80086110(f32, f32, s32);
void func_80086664(f32, f32);
void func_800869A0(f32, f32, s32, f32, s32, s32);
void func_80087530(f32, f32, s32);
void func_8008865C(void);
void func_8008AD94(void);
void func_8008B5B0(f32 x, f32 y);
s32 func_8008B774(void);
void func_8008BD00(u8*, s32, s32, u8);
void func_8008C390(f32, f32, f32, s32);
void func_8008C5C8(f32, f32, f32, s32);
void func_8008C6F4(s32, s32);
s32 func_8008BCBC(s32);
void func_8008CA44(void);
s32 func_8008CB8C(void);
void func_8008D0DC(f32, f32, f32, f32, f32);
void func_8008DE68(void);
void func_8008E51C(s32* , f32);
void func_8008E9EC(f32, f32);
void func_8008EA14(f32, f32);
void func_8008FA84(void);
void func_8008FE78(Object*);
void func_8008FFF0(Object_408*, s32);
bool func_8009092C(Object_2F4*);
void func_800907C4(Object_408*);
s32 func_800915FC(Object_2F4*);
void func_80092D48(Object_2F4 *);
void func_80092EC0(Object*);
void func_80094954(Object_8C*);
void func_80094BBC(Object_8C*);
void func_80094D20(f32, f32);

// fox_97F80
void func_80098860(Plane *plane, Vec3f *point, Vec3f *normal);
s32 func_800988B4(Vec3f *vec, Plane *plane);
s32 func_800998FC(Vec3f*, Vec3f*, Vec3f*, s32, Vec3f*, f32*);

// fox_A24B0
void func_800A18B0(void);
void func_800A1980(void);
bool func_800A1B6C(void);
void func_800A1C14(Gfx **);
void func_800A1E68(Gfx **);
void func_800A1F44(void);
void func_800A1FB0(Gfx **, u8 , u8);
void func_800A24DC(s32);
void func_800A26C0(void);
void func_800A25DC(void);
Object_2F4 *func_800A3608(s32);

// fox_A4290
bool func_800A3690(Vec3f*, Vec3f*, s32, Vec3f*);

// fox_A48A0
void func_800A3CA0(void);

// sf_A4B50
s32 func_800A3F50(u16);
void func_800A5844(void);
void func_800A5D6C(void);
void func_800A6148(void);
void func_800A6CD0(UnkStruct_D_80178280 *, s32, s32);
void func_800B6F50(f32, f32, f32, f32, f32, f32);
void func_800B73E0(UnkStruct_D_80178280 *);
s32 func_800A73E4(f32* arg0, s32* arg1, f32 posX, f32 posY, f32 posZ);
void func_800B86CC(void);

// fox_radio
s32 func_800BA7BC(u16*, s32);
void func_800BA808(u16*, s32);
void func_800BB5D0(void);

// fox_reset
void Graphics_NMIWipe(void);

// sf_versus
void func_800C1ED4(void);
void func_800C20B0(void);
void func_800C2190(void);

// fox_save
s32 Save_Write(void);
s32 Save_Read(void); 

void func_EFFA40_80187520(s32, void*);

void func_DF4260_801878D8(Object_408 *);
void func_DF4260_8018B0B4(Object_2F4 *);
void func_DF4260_8018BE7C(Object_408 *);    
void func_DF4260_8019250C(Object_2F4 *);    
void func_DF4260_80192CB0(Object_2F4 *);    
void func_DF4260_80192EA4(Object_2F4 *);
void func_DF4260_801933B4(Object_2F4 *);    
void func_DF4260_801935CC(Object_408 *);
void func_DF4260_80198310(Object_408 *);
void func_DF4260_801988E0(void);

void func_E08400_80187B08(Object_2F4 *, s32);
void func_E08400_80188A40(Object_408 *);

void func_E16C50_80187754(Object_408 *);
void func_E16C50_80190F08(Object_2F4 *);
void func_E16C50_801915A4(Object_2F4 *);
void func_E16C50_80191BB8(Object_2F4 *);
void func_E16C50_801932AC(Object_408 *);
void func_E16C50_8019B1F0(Object_2F4 *);
void func_E16C50_8019B810(Object_2F4 *);
void func_E16C50_8019C200(Object_2F4 *);
void func_E16C50_8019D060(Object_2F4 *);
void func_E16C50_801AA20C(void);
void func_E16C50_801ACBB4(void);
void func_E16C50_801AD688(Object_2F4 *);
void func_E16C50_801AE3AC(Object_2F4 *);
void func_E16C50_801AF9FC(Object_2F4 *);
void func_E16C50_801B10F8(Object_408 *);
void func_E16C50_801B6344(Object_2F4 *);
void func_E16C50_801B6E54(Object_2F4 *);
void func_E16C50_801B7AF0(Object_2F4 *);
void func_E16C50_801BA57C(Object_2F4 *);
void func_E16C50_801BB26C(Object_2F4 *);

void func_E51970_80193CA4(Object_408 *);
void func_E51970_80198594(Object_408 *, s32);

void func_E6A810_80189B80(Object_2F4 *);
void func_E6A810_8018ADC4(Object_2F4 *);
void func_E6A810_8018B720(Object_2F4 *, s32);
void func_E6A810_8018B96C(Object_2F4 *);
void func_E6A810_8018BFB0(Object_2F4 *);
void func_E6A810_8018E3B0(Object_2F4 *);
void func_E6A810_8018E3CC(Object_2F4 *);
void func_E6A810_8018E5E8(Object_2F4 *);
void func_E6A810_8018EFF0(Object_4C *); 
void func_E6A810_8018F0D8(Object_80 *); 
void func_E6A810_8018FA48(Object_408 *);
void func_E6A810_801990DC(Object_408 *, s32);
void func_E6A810_80199F8C(Object_2F4 *);
void func_E6A810_801A3E70(Object_2F4 *);
void func_E6A810_801A4660(Object_2F4 *);
void func_E6A810_801A4AF8(Object_2F4 *);
void func_E6A810_801A5E2C(Object_2F4 *);
void func_E6A810_801A6134(Object_2F4 *);
void func_E6A810_801A65E0(Object_80 *); 
void func_E6A810_801A7D98(Object_2F4 *);
void func_E6A810_801B58AC(Gfx **, f32);
s32 func_E6A810_801B6AEC(f32, f32, f32);
void func_E6A810_801B6E20(f32, f32, f32 *, f32 *, f32 *); 

void func_E9F1D0_801888F4(Object_2F4 *, s32);
void func_E9F1D0_8018D16C(Object_408 *);
void func_E9F1D0_80197CC4(Object_408 *);
void func_E9F1D0_801A6164(UnkStruct_D_80178280 *);

void func_EF0260_8018A96C(void);
void func_EF0260_8018AAC4(void);

#endif
