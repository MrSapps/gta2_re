#include "laughing_blackwell_0x1EB54.hpp"
#include "registry.hpp"
#include "error.hpp"
#include "debug.hpp"
#include "root_sound.hpp"
#include "jolly_poitras_0x2BC0.hpp"
#include "lucid_hamilton.hpp"
#include "text_0x14.hpp"
#include "gbh_graphics.hpp"
#include "Bink.hpp"
#include "sharp_pare_0x15D8.hpp"
#include "gtx_0x106C.hpp"
#include "magical_germain_0x8EC.hpp"
#include "file.hpp"
#include "dma_video.hpp"
#include <io.h>
#include <stdio.h>
#include <wchar.h>

#pragma comment(lib, "dxguid.lib")

laughing_blackwell_0x1EB54* gLaughing_blackwell_0x1EB54_67DC84;

DWORD dword_67D6F8;
int* dword_67D704;
BYTE byte_67D6FC;
DWORD gSoundIdx_67D700;
int dword_67D818;
BYTE byte_67D81C;
unsigned int counter_706C4C;
int dword_67D930;
unsigned short gTableSize_61FF20 = 25;

extern wchar_t word_67DC8C[50];

DWORD dword_67D9FC;

__int16 word_703C3C;

DIOBJECTDATAFORMAT stru_5E9110[256] =
{
  { &GUID_Key, 0u, 2147483660u, 0u },
  { &GUID_Key, 1u, 2147483916u, 0u },
  { &GUID_Key, 2u, 2147484172u, 0u },
  { &GUID_Key, 3u, 2147484428u, 0u },
  { &GUID_Key, 4u, 2147484684u, 0u },
  { &GUID_Key, 5u, 2147484940u, 0u },
  { &GUID_Key, 6u, 2147485196u, 0u },
  { &GUID_Key, 7u, 2147485452u, 0u },
  { &GUID_Key, 8u, 2147485708u, 0u },
  { &GUID_Key, 9u, 2147485964u, 0u },
  { &GUID_Key, 10u, 2147486220u, 0u },
  { &GUID_Key, 11u, 2147486476u, 0u },
  { &GUID_Key, 12u, 2147486732u, 0u },
  { &GUID_Key, 13u, 2147486988u, 0u },
  { &GUID_Key, 14u, 2147487244u, 0u },
  { &GUID_Key, 15u, 2147487500u, 0u },
  { &GUID_Key, 16u, 2147487756u, 0u },
  { &GUID_Key, 17u, 2147488012u, 0u },
  { &GUID_Key, 18u, 2147488268u, 0u },
  { &GUID_Key, 19u, 2147488524u, 0u },
  { &GUID_Key, 20u, 2147488780u, 0u },
  { &GUID_Key, 21u, 2147489036u, 0u },
  { &GUID_Key, 22u, 2147489292u, 0u },
  { &GUID_Key, 23u, 2147489548u, 0u },
  { &GUID_Key, 24u, 2147489804u, 0u },
  { &GUID_Key, 25u, 2147490060u, 0u },
  { &GUID_Key, 26u, 2147490316u, 0u },
  { &GUID_Key, 27u, 2147490572u, 0u },
  { &GUID_Key, 28u, 2147490828u, 0u },
  { &GUID_Key, 29u, 2147491084u, 0u },
  { &GUID_Key, 30u, 2147491340u, 0u },
  { &GUID_Key, 31u, 2147491596u, 0u },
  { &GUID_Key, 32u, 2147491852u, 0u },
  { &GUID_Key, 33u, 2147492108u, 0u },
  { &GUID_Key, 34u, 2147492364u, 0u },
  { &GUID_Key, 35u, 2147492620u, 0u },
  { &GUID_Key, 36u, 2147492876u, 0u },
  { &GUID_Key, 37u, 2147493132u, 0u },
  { &GUID_Key, 38u, 2147493388u, 0u },
  { &GUID_Key, 39u, 2147493644u, 0u },
  { &GUID_Key, 40u, 2147493900u, 0u },
  { &GUID_Key, 41u, 2147494156u, 0u },
  { &GUID_Key, 42u, 2147494412u, 0u },
  { &GUID_Key, 43u, 2147494668u, 0u },
  { &GUID_Key, 44u, 2147494924u, 0u },
  { &GUID_Key, 45u, 2147495180u, 0u },
  { &GUID_Key, 46u, 2147495436u, 0u },
  { &GUID_Key, 47u, 2147495692u, 0u },
  { &GUID_Key, 48u, 2147495948u, 0u },
  { &GUID_Key, 49u, 2147496204u, 0u },
  { &GUID_Key, 50u, 2147496460u, 0u },
  { &GUID_Key, 51u, 2147496716u, 0u },
  { &GUID_Key, 52u, 2147496972u, 0u },
  { &GUID_Key, 53u, 2147497228u, 0u },
  { &GUID_Key, 54u, 2147497484u, 0u },
  { &GUID_Key, 55u, 2147497740u, 0u },
  { &GUID_Key, 56u, 2147497996u, 0u },
  { &GUID_Key, 57u, 2147498252u, 0u },
  { &GUID_Key, 58u, 2147498508u, 0u },
  { &GUID_Key, 59u, 2147498764u, 0u },
  { &GUID_Key, 60u, 2147499020u, 0u },
  { &GUID_Key, 61u, 2147499276u, 0u },
  { &GUID_Key, 62u, 2147499532u, 0u },
  { &GUID_Key, 63u, 2147499788u, 0u },
  { &GUID_Key, 64u, 2147500044u, 0u },
  { &GUID_Key, 65u, 2147500300u, 0u },
  { &GUID_Key, 66u, 2147500556u, 0u },
  { &GUID_Key, 67u, 2147500812u, 0u },
  { &GUID_Key, 68u, 2147501068u, 0u },
  { &GUID_Key, 69u, 2147501324u, 0u },
  { &GUID_Key, 70u, 2147501580u, 0u },
  { &GUID_Key, 71u, 2147501836u, 0u },
  { &GUID_Key, 72u, 2147502092u, 0u },
  { &GUID_Key, 73u, 2147502348u, 0u },
  { &GUID_Key, 74u, 2147502604u, 0u },
  { &GUID_Key, 75u, 2147502860u, 0u },
  { &GUID_Key, 76u, 2147503116u, 0u },
  { &GUID_Key, 77u, 2147503372u, 0u },
  { &GUID_Key, 78u, 2147503628u, 0u },
  { &GUID_Key, 79u, 2147503884u, 0u },
  { &GUID_Key, 80u, 2147504140u, 0u },
  { &GUID_Key, 81u, 2147504396u, 0u },
  { &GUID_Key, 82u, 2147504652u, 0u },
  { &GUID_Key, 83u, 2147504908u, 0u },
  { &GUID_Key, 84u, 2147505164u, 0u },
  { &GUID_Key, 85u, 2147505420u, 0u },
  { &GUID_Key, 86u, 2147505676u, 0u },
  { &GUID_Key, 87u, 2147505932u, 0u },
  { &GUID_Key, 88u, 2147506188u, 0u },
  { &GUID_Key, 89u, 2147506444u, 0u },
  { &GUID_Key, 90u, 2147506700u, 0u },
  { &GUID_Key, 91u, 2147506956u, 0u },
  { &GUID_Key, 92u, 2147507212u, 0u },
  { &GUID_Key, 93u, 2147507468u, 0u },
  { &GUID_Key, 94u, 2147507724u, 0u },
  { &GUID_Key, 95u, 2147507980u, 0u },
  { &GUID_Key, 96u, 2147508236u, 0u },
  { &GUID_Key, 97u, 2147508492u, 0u },
  { &GUID_Key, 98u, 2147508748u, 0u },
  { &GUID_Key, 99u, 2147509004u, 0u },
  { &GUID_Key, 100u, 2147509260u, 0u },
  { &GUID_Key, 101u, 2147509516u, 0u },
  { &GUID_Key, 102u, 2147509772u, 0u },
  { &GUID_Key, 103u, 2147510028u, 0u },
  { &GUID_Key, 104u, 2147510284u, 0u },
  { &GUID_Key, 105u, 2147510540u, 0u },
  { &GUID_Key, 106u, 2147510796u, 0u },
  { &GUID_Key, 107u, 2147511052u, 0u },
  { &GUID_Key, 108u, 2147511308u, 0u },
  { &GUID_Key, 109u, 2147511564u, 0u },
  { &GUID_Key, 110u, 2147511820u, 0u },
  { &GUID_Key, 111u, 2147512076u, 0u },
  { &GUID_Key, 112u, 2147512332u, 0u },
  { &GUID_Key, 113u, 2147512588u, 0u },
  { &GUID_Key, 114u, 2147512844u, 0u },
  { &GUID_Key, 115u, 2147513100u, 0u },
  { &GUID_Key, 116u, 2147513356u, 0u },
  { &GUID_Key, 117u, 2147513612u, 0u },
  { &GUID_Key, 118u, 2147513868u, 0u },
  { &GUID_Key, 119u, 2147514124u, 0u },
  { &GUID_Key, 120u, 2147514380u, 0u },
  { &GUID_Key, 121u, 2147514636u, 0u },
  { &GUID_Key, 122u, 2147514892u, 0u },
  { &GUID_Key, 123u, 2147515148u, 0u },
  { &GUID_Key, 124u, 2147515404u, 0u },
  { &GUID_Key, 125u, 2147515660u, 0u },
  { &GUID_Key, 126u, 2147515916u, 0u },
  { &GUID_Key, 127u, 2147516172u, 0u },
  { &GUID_Key, 128u, 2147516428u, 0u },
  { &GUID_Key, 129u, 2147516684u, 0u },
  { &GUID_Key, 130u, 2147516940u, 0u },
  { &GUID_Key, 131u, 2147517196u, 0u },
  { &GUID_Key, 132u, 2147517452u, 0u },
  { &GUID_Key, 133u, 2147517708u, 0u },
  { &GUID_Key, 134u, 2147517964u, 0u },
  { &GUID_Key, 135u, 2147518220u, 0u },
  { &GUID_Key, 136u, 2147518476u, 0u },
  { &GUID_Key, 137u, 2147518732u, 0u },
  { &GUID_Key, 138u, 2147518988u, 0u },
  { &GUID_Key, 139u, 2147519244u, 0u },
  { &GUID_Key, 140u, 2147519500u, 0u },
  { &GUID_Key, 141u, 2147519756u, 0u },
  { &GUID_Key, 142u, 2147520012u, 0u },
  { &GUID_Key, 143u, 2147520268u, 0u },
  { &GUID_Key, 144u, 2147520524u, 0u },
  { &GUID_Key, 145u, 2147520780u, 0u },
  { &GUID_Key, 146u, 2147521036u, 0u },
  { &GUID_Key, 147u, 2147521292u, 0u },
  { &GUID_Key, 148u, 2147521548u, 0u },
  { &GUID_Key, 149u, 2147521804u, 0u },
  { &GUID_Key, 150u, 2147522060u, 0u },
  { &GUID_Key, 151u, 2147522316u, 0u },
  { &GUID_Key, 152u, 2147522572u, 0u },
  { &GUID_Key, 153u, 2147522828u, 0u },
  { &GUID_Key, 154u, 2147523084u, 0u },
  { &GUID_Key, 155u, 2147523340u, 0u },
  { &GUID_Key, 156u, 2147523596u, 0u },
  { &GUID_Key, 157u, 2147523852u, 0u },
  { &GUID_Key, 158u, 2147524108u, 0u },
  { &GUID_Key, 159u, 2147524364u, 0u },
  { &GUID_Key, 160u, 2147524620u, 0u },
  { &GUID_Key, 161u, 2147524876u, 0u },
  { &GUID_Key, 162u, 2147525132u, 0u },
  { &GUID_Key, 163u, 2147525388u, 0u },
  { &GUID_Key, 164u, 2147525644u, 0u },
  { &GUID_Key, 165u, 2147525900u, 0u },
  { &GUID_Key, 166u, 2147526156u, 0u },
  { &GUID_Key, 167u, 2147526412u, 0u },
  { &GUID_Key, 168u, 2147526668u, 0u },
  { &GUID_Key, 169u, 2147526924u, 0u },
  { &GUID_Key, 170u, 2147527180u, 0u },
  { &GUID_Key, 171u, 2147527436u, 0u },
  { &GUID_Key, 172u, 2147527692u, 0u },
  { &GUID_Key, 173u, 2147527948u, 0u },
  { &GUID_Key, 174u, 2147528204u, 0u },
  { &GUID_Key, 175u, 2147528460u, 0u },
  { &GUID_Key, 176u, 2147528716u, 0u },
  { &GUID_Key, 177u, 2147528972u, 0u },
  { &GUID_Key, 178u, 2147529228u, 0u },
  { &GUID_Key, 179u, 2147529484u, 0u },
  { &GUID_Key, 180u, 2147529740u, 0u },
  { &GUID_Key, 181u, 2147529996u, 0u },
  { &GUID_Key, 182u, 2147530252u, 0u },
  { &GUID_Key, 183u, 2147530508u, 0u },
  { &GUID_Key, 184u, 2147530764u, 0u },
  { &GUID_Key, 185u, 2147531020u, 0u },
  { &GUID_Key, 186u, 2147531276u, 0u },
  { &GUID_Key, 187u, 2147531532u, 0u },
  { &GUID_Key, 188u, 2147531788u, 0u },
  { &GUID_Key, 189u, 2147532044u, 0u },
  { &GUID_Key, 190u, 2147532300u, 0u },
  { &GUID_Key, 191u, 2147532556u, 0u },
  { &GUID_Key, 192u, 2147532812u, 0u },
  { &GUID_Key, 193u, 2147533068u, 0u },
  { &GUID_Key, 194u, 2147533324u, 0u },
  { &GUID_Key, 195u, 2147533580u, 0u },
  { &GUID_Key, 196u, 2147533836u, 0u },
  { &GUID_Key, 197u, 2147534092u, 0u },
  { &GUID_Key, 198u, 2147534348u, 0u },
  { &GUID_Key, 199u, 2147534604u, 0u },
  { &GUID_Key, 200u, 2147534860u, 0u },
  { &GUID_Key, 201u, 2147535116u, 0u },
  { &GUID_Key, 202u, 2147535372u, 0u },
  { &GUID_Key, 203u, 2147535628u, 0u },
  { &GUID_Key, 204u, 2147535884u, 0u },
  { &GUID_Key, 205u, 2147536140u, 0u },
  { &GUID_Key, 206u, 2147536396u, 0u },
  { &GUID_Key, 207u, 2147536652u, 0u },
  { &GUID_Key, 208u, 2147536908u, 0u },
  { &GUID_Key, 209u, 2147537164u, 0u },
  { &GUID_Key, 210u, 2147537420u, 0u },
  { &GUID_Key, 211u, 2147537676u, 0u },
  { &GUID_Key, 212u, 2147537932u, 0u },
  { &GUID_Key, 213u, 2147538188u, 0u },
  { &GUID_Key, 214u, 2147538444u, 0u },
  { &GUID_Key, 215u, 2147538700u, 0u },
  { &GUID_Key, 216u, 2147538956u, 0u },
  { &GUID_Key, 217u, 2147539212u, 0u },
  { &GUID_Key, 218u, 2147539468u, 0u },
  { &GUID_Key, 219u, 2147539724u, 0u },
  { &GUID_Key, 220u, 2147539980u, 0u },
  { &GUID_Key, 221u, 2147540236u, 0u },
  { &GUID_Key, 222u, 2147540492u, 0u },
  { &GUID_Key, 223u, 2147540748u, 0u },
  { &GUID_Key, 224u, 2147541004u, 0u },
  { &GUID_Key, 225u, 2147541260u, 0u },
  { &GUID_Key, 226u, 2147541516u, 0u },
  { &GUID_Key, 227u, 2147541772u, 0u },
  { &GUID_Key, 228u, 2147542028u, 0u },
  { &GUID_Key, 229u, 2147542284u, 0u },
  { &GUID_Key, 230u, 2147542540u, 0u },
  { &GUID_Key, 231u, 2147542796u, 0u },
  { &GUID_Key, 232u, 2147543052u, 0u },
  { &GUID_Key, 233u, 2147543308u, 0u },
  { &GUID_Key, 234u, 2147543564u, 0u },
  { &GUID_Key, 235u, 2147543820u, 0u },
  { &GUID_Key, 236u, 2147544076u, 0u },
  { &GUID_Key, 237u, 2147544332u, 0u },
  { &GUID_Key, 238u, 2147544588u, 0u },
  { &GUID_Key, 239u, 2147544844u, 0u },
  { &GUID_Key, 240u, 2147545100u, 0u },
  { &GUID_Key, 241u, 2147545356u, 0u },
  { &GUID_Key, 242u, 2147545612u, 0u },
  { &GUID_Key, 243u, 2147545868u, 0u },
  { &GUID_Key, 244u, 2147546124u, 0u },
  { &GUID_Key, 245u, 2147546380u, 0u },
  { &GUID_Key, 246u, 2147546636u, 0u },
  { &GUID_Key, 247u, 2147546892u, 0u },
  { &GUID_Key, 248u, 2147547148u, 0u },
  { &GUID_Key, 249u, 2147547404u, 0u },
  { &GUID_Key, 250u, 2147547660u, 0u },
  { &GUID_Key, 251u, 2147547916u, 0u },
  { &GUID_Key, 252u, 2147548172u, 0u },
  { &GUID_Key, 253u, 2147548428u, 0u },
  { &GUID_Key, 254u, 2147548684u, 0u },
  { &GUID_Key, 255u, 2147548940u, 0u }
};

DIOBJECTDATAFORMAT stru_5EA110[44] =
{
  { &GUID_XAxis, 0u, 2164260611u, 256u },
  { &GUID_YAxis, 4u, 2164260611u, 256u },
  { &GUID_ZAxis, 8u, 2164260611u, 256u },
  { &GUID_RxAxis, 12u, 2164260611u, 256u },
  { &GUID_RyAxis, 16u, 2164260611u, 256u },
  { &GUID_RzAxis, 20u, 2164260611u, 256u },
  { &GUID_Slider, 24u, 2164260611u, 256u },
  { &GUID_Slider, 28u, 2164260611u, 256u },
  { &GUID_POV, 32u, 2164260624u, 0u },
  { &GUID_POV, 36u, 2164260624u, 0u },
  { &GUID_POV, 40u, 2164260624u, 0u },
  { &GUID_POV, 44u, 2164260624u, 0u },
  { NULL, 48u, 2164260620u, 0u },
  { NULL, 49u, 2164260620u, 0u },
  { NULL, 50u, 2164260620u, 0u },
  { NULL, 51u, 2164260620u, 0u },
  { NULL, 52u, 2164260620u, 0u },
  { NULL, 53u, 2164260620u, 0u },
  { NULL, 54u, 2164260620u, 0u },
  { NULL, 55u, 2164260620u, 0u },
  { NULL, 56u, 2164260620u, 0u },
  { NULL, 57u, 2164260620u, 0u },
  { NULL, 58u, 2164260620u, 0u },
  { NULL, 59u, 2164260620u, 0u },
  { NULL, 60u, 2164260620u, 0u },
  { NULL, 61u, 2164260620u, 0u },
  { NULL, 62u, 2164260620u, 0u },
  { NULL, 63u, 2164260620u, 0u },
  { NULL, 64u, 2164260620u, 0u },
  { NULL, 65u, 2164260620u, 0u },
  { NULL, 66u, 2164260620u, 0u },
  { NULL, 67u, 2164260620u, 0u },
  { NULL, 68u, 2164260620u, 0u },
  { NULL, 69u, 2164260620u, 0u },
  { NULL, 70u, 2164260620u, 0u },
  { NULL, 71u, 2164260620u, 0u },
  { NULL, 72u, 2164260620u, 0u },
  { NULL, 73u, 2164260620u, 0u },
  { NULL, 74u, 2164260620u, 0u },
  { NULL, 75u, 2164260620u, 0u },
  { NULL, 76u, 2164260620u, 0u },
  { NULL, 77u, 2164260620u, 0u },
  { NULL, 78u, 2164260620u, 0u },
  { NULL, 79u, 2164260620u, 0u }
};

DIOBJECTDATAFORMAT stru_5EA3D0[7] =
{
  { &GUID_XAxis, 0u, 16776963u, 0u },
  { &GUID_YAxis, 4u, 16776963u, 0u },
  { &GUID_ZAxis, 8u, 2164260611u, 0u },
  { NULL, 12u, 16776972u, 0u },
  { NULL, 13u, 16776972u, 0u },
  { NULL, 14u, 2164260620u, 0u },
  { NULL, 15u, 2164260620u, 0u }
};

DIDATAFORMAT gKeyboardDataFormat_601A54 = { 24u, 16u, DIDF_RELAXIS, 256u, 256u, stru_5E9110 };
DIDATAFORMAT gInputDeviceFormat_601A6C = { 24u, 16u, DIDF_ABSAXIS, 80u, 44u, stru_5EA110 };
DIDATAFORMAT stru_601A84 = { 24u, 16u, DIDF_RELAXIS, 16u, 7u, stru_5EA3D0 };

extern LPDIRECTINPUTA gpDInput_67B804;
extern HWND gHwnd_707F04;

DWORD dword_70675C;
DWORD dword_70679C;

extern int window_width_706630;
extern int window_height_706B50;

struct struc_61F0C8
{
    char field_0_tga_name[128];
    int field_80_len;
    int field_84_img;
};

struc_61F0C8 tgaArray_61F0C8[25] =
{
  { "data\\frontend\\1.tga", 347564, 0 },
  { "data\\frontend\\1_Options.tga", 266924, 0 },
  { "data\\frontend\\1_Play.tga", 266924, 0 },
  { "data\\frontend\\1_Quit.tga", 266924, 0 },
  { "data\\frontend\\2.tga", 347564, 0 },
  { "data\\frontend\\2_Bonus1.tga", 266924, 0 },
  { "data\\frontend\\2_Bonus2.tga", 266924, 0 },
  { "data\\frontend\\2_Bonus3.tga", 266924, 0 },
  { "data\\frontend\\2_League.tga", 266924, 0 },
  { "data\\frontend\\2_Level1.tga", 266924, 0 },
  { "data\\frontend\\2_Level2.tga", 266924, 0 },
  { "data\\frontend\\2_Level3.tga", 266924, 0 },
  { "data\\frontend\\2_Name.tga", 266924, 0 },
  { "data\\frontend\\2_Restart.tga", 266924, 0 },
  { "data\\frontend\\3.tga", 347564, 0 },
  { "data\\frontend\\3_Tables.tga", 614444, 0 },
  { "data\\frontend\\GameComplete.tga", 614444, 0 },
  { "data\\frontend\\LevelComplete.tga", 614444, 0 },
  { "data\\frontend\\MPLose.tga", 614444, 0 },
  { "data\\frontend\\PlayerDead.tga", 614444, 0 },
  { "data\\frontend\\Mask.tga", 104300, 0 },
  { "data\\frontend\\Mask2.tga", 53594, 0 },
  { "data\\frontend\\Credits.tga", 614444, 0 },
  { "data\\frontend\\Mask3.tga", 130427, 0 },
  { "data\\frontend\\DemoInfo.tga", 614939, 0 }
};


int __stdcall SetGamma_5D9910(int gamma)
{
    // todo
    return 0;
}

// match
void __stdcall laughing_blackwell_0x1EB54::create_4ACFA0()
{
    if (!gLaughing_blackwell_0x1EB54_67DC84)
    {
        gLaughing_blackwell_0x1EB54_67DC84 = new laughing_blackwell_0x1EB54();
    }

    if (!bSkip_audio_67D6BE)
    {
        dword_67D818 = 0;
        byte_67D81C = 0;
        dword_67D6F8 = 2;
        dword_67D704 = &dword_67D818;
        byte_67D6FC = 0;
        gSoundIdx_67D700 = gRoot_sound_66B038.sub_40EFB0(&dword_67D6F8);
        gRoot_sound_66B038.LoadStyle_40EFF0("data\\fstyle.sty");
        gRoot_sound_66B038.Set3DSound_40F160(0);
    }

    Bink::Reset_513210();
}

// match
void __stdcall laughing_blackwell_0x1EB54::destroy_4AD070()
{
    if (!bSkip_audio_67D6BE && gSoundIdx_67D700)
    {
        gRoot_sound_66B038.sub_40EFD0(gSoundIdx_67D700);
        gSoundIdx_67D700 = 0;
    }

    if (gLaughing_blackwell_0x1EB54_67DC84)
    {
        delete gLaughing_blackwell_0x1EB54_67DC84;
        gLaughing_blackwell_0x1EB54_67DC84 = 0;
    }

    Bink::Close1_513340();
    Bink::Close2_513390();
}

void laughing_blackwell_0x1EB54::sub_4B3170(unsigned __int16 arg0)
{
    // todo

}

int laughing_blackwell_0x1EB54::sub_4AEDB0()
{
    // todo
    return 0;
}

const char* laughing_blackwell_0x1EB54::intro_bik_4B5E50()
{
    // todo
    return "meh.dat";
}

// match
bool laughing_blackwell_0x1EB54::intro_bik_exists_4B5FF0()
{
    // note: ecx wasn't first due to global being an object instead of a pointer
    _finddata_t findData;

    // note: put call in argument rather than local to change inst ordering
    const long hFind = _findfirst(gLaughing_blackwell_0x1EB54_67DC84->intro_bik_4B5E50(), &findData);

    if (hFind == -1)
    {
        return 0;
    }

    _findclose(hFind);
    return 1;

}

void sub_SetGamma()
{
    const int gammaVal = gRegistry_6FF968.Get_Screen_Setting_5870D0("gamma", 10);
    if (counter_706C4C)
    {
        if (SetGamma_5D9910(gammaVal))
        {
            --counter_706C4C;
        }
        else
        {
            counter_706C4C = 0;
        }
    }
}

// match
void laughing_blackwell_0x1EB54::sub_4AEC00()
{
    sub_4AFEB0();
    sub_4B6780();

    dword_67D818 = 0;

    switch (field_110_state)
    {
    case 3:
        sub_4B2F60();
        break;

    case 5:
        sub_4B8280();
        break;

    case 1:
        if (field_132_f136_idx == 9)
        {
            byte_67D81C = 1;
            sub_4B7A10();
        }
        else
        {
            byte_67D81C = 0;
            sub_4AE2D0();
        }
        break;

    case 2:
        sub_4AE990();
        break;

    case 4:
        sub_4AE9A0();
        break;

    default:
        FatalError_4A38C0(1006, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2059, field_110_state);
    }

    if (!bSkip_audio_67D6BE)
    {
        gRoot_sound_66B038.sub_40EFA0();
    }

    if (counter_706C4C > 0)
    {
        sub_SetGamma();
    }
}

void laughing_blackwell_0x1EB54::sub_4AFEB0()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4B6780()
{
    loving_borg_0xBCA* pBorg = &field_136[field_132_f136_idx];
    if (this->field_110_state != 2)
    {
        if (field_132_f136_idx == 0)
        {
            switch (pBorg->field_BC6_nifty_idx)
            {
            case 0:
                field_EE08 = 1;
                break;

            case 1:
                field_EE08 = 0;
                break;

            case 2:
                field_EE08 = 2;
                break;
            }
        }
        else if (field_132_f136_idx == 1)
        {
            switch (pBorg->field_BC6_nifty_idx)
            {
            case 0u:
                this->field_EE08 = 10;
                break;
            case 1u:
                this->field_EE08 = 11;
                break;
            case 2u:
                this->field_EE08 = 6;
                break;
            case 3u:
                this->field_EE08 = gLucid_hamilton_67E8E0.sub_4C5980() + 7;
                break;
            case 4u:
                this->field_EE08 = ((unsigned __int8)gLucid_hamilton_67E8E0.sub_4C5990() >> 4) + 3;
                break;
            default:
                break;
            }
        }
        else if (field_132_f136_idx == 5)
        {
            field_EE08 = 12;
        }
        else if (field_132_f136_idx == 2)
        {
            field_EE08 = 13;
        }
        else if (field_132_f136_idx == 3u ||
            field_132_f136_idx == 6 ||
            field_132_f136_idx == 7 ||
            field_132_f136_idx == 0xB ||
            field_132_f136_idx == 0xE)
        {
            field_EE08 = 16;
        }
        else if (field_132_f136_idx == 4 || field_132_f136_idx == 0xA)
        {
            field_EE08 = 15;
        }
        else if (field_132_f136_idx == 9)
        {
            field_EE08 = 17;
        }
        else
        {
            field_EE08 = 7;
        }
    }
}


void laughing_blackwell_0x1EB54::sub_4B7A10()
{
    char v2; // cl
    char *field_8_keys; // eax
    int v4; // edx
    int v5; // eax
    int v6; // eax

    timeGetTime();
    sub_4AFEB0();
    v2 = 0;
    field_8_keys = this->field_8_keys;
    v4 = 256;
    do
    {
        if (*field_8_keys < 0)
            v2 = 1;
        ++field_8_keys;
        --v4;
    } while (v4);
    if (v2)
    {
        if (!this->field_C9B3)
        {
        LABEL_7:
            this->field_108 = 1;
            return;
        }
    }
    else
    {
        this->field_C9B3 = 0;
    }
    if (++this->field_1EB30)
    {
        v5 = this->field_1EB34;
        this->field_1EB30 = 0;
        if (v5 <= -327680)
        {
            while (++this->field_1EB38 != 600)
            {
                v6 = ((unsigned __int16)this->field_EE0E_unk.field_2[(unsigned __int16)this->field_1EB38].field_4 << 14)
                    + this->field_1EB34;
                this->field_1EB34 = v6;
                if (v6 > -327680)
                    goto LABEL_13;
            }
            goto LABEL_7;
        }
    LABEL_13:
        this->field_1EB34 -= dword_67D9FC;
    }
}

void laughing_blackwell_0x1EB54::sub_4AE2D0()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4AE990()
{
    field_108 = 3;
}

void laughing_blackwell_0x1EB54::sub_4B2F60()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4AE9A0()
{
    __int16 v2; // ax
    int v3; // eax

    if (this->field_C9D0)
    {
        v2 = this->field_EE0A;
        if (v2 == 210)
        {
            if (this->field_EE0C != 1)
            {
                FatalError_4A38C0(1006, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 1934);
            }

            sub_4B4410();
        }
        else if (v2 != 230)
        {
            dword_67D818 = 5;
        }
        else
        {
            this->field_110_state = 1;
            dword_67D818 = 5;
        }
    }

    if (this->field_C9D1)
    {
        this->field_110_state = 1;
        dword_67D818 = 6;
    }

    if (this->field_C9CE)
    {
        if (this->field_EE0A == 190 || this->field_EE0A == 210)
        {
            this->field_EE0A = 230;
        }
        else
        {
            if (this->field_EE0A != 230)
            {
                FatalError_4A38C0(1006, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 1968);
            }
            this->field_EE0A = 210;
        }
        dword_67D818 = 1;
    }

    if (this->field_C9CF)
    {
        if (this->field_EE0A != 190)
        {
            if (this->field_EE0A == 210)
            {
                this->field_EE0A = 230;
                dword_67D818 = 2;
            }
            else if (this->field_EE0A != 230)
            {
                FatalError_4A38C0(1006, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 1991);
            }
        }
        else
        {
            this->field_EE0A = 210;
            dword_67D818 = 2;
        }
    }

    v3 = this->field_118 - 1;
    this->field_118 = v3;
    if (v3 <= 0)
    {
        this->field_114 = this->field_114 == 0;
        this->field_118 = 2;
    }
}

void laughing_blackwell_0x1EB54::sub_4B8280()
{
    // todo
}

// match
void laughing_blackwell_0x1EB54::sub_4B4410()
{
    sub_4B43E0()->sub_56B630();
    gJolly_poitras_0x2BC0_6FEAC0->sub_56BA60(field_136[1].field_4[0].field_6E_count);
    sub_4B42E0();
}

// match
dreamy_clarke_0xA4* laughing_blackwell_0x1EB54::sub_4B43E0()
{
    // note: movsx vs movzx due to signedness
    unsigned short idx = gLucid_hamilton_67E8E0.sub_4C59B0();
    return &gJolly_poitras_0x2BC0_6FEAC0->field_26A0[idx];
}

void laughing_blackwell_0x1EB54::sub_4B42E0()
{
    // todo
}

// match
void laughing_blackwell_0x1EB54::sub_4B4230()
{
    unsigned __int16 count = field_136[1].field_4[0].field_6E_count;
    wchar_t* pStr = gJolly_poitras_0x2BC0_6FEAC0->field_26A0[count].field_90_str;
    wcsncpy(pStr, field_C9A0, 9u);
    HandleCheatCode_4B3DD0(pStr);
    gJolly_poitras_0x2BC0_6FEAC0->sub_56BA60(count);
}

void laughing_blackwell_0x1EB54::HandleCheatCode_4B3DD0(const wchar_t *String)
{
    // todo
}

// match
void laughing_blackwell_0x1EB54::sub_4B4280()
{
    wcsncpy(
        field_C9A0,
        gJolly_poitras_0x2BC0_6FEAC0->field_26A0[field_136[1].field_4[0].field_6E_count].field_90_str,
        9u);
}

void laughing_blackwell_0x1EB54::sub_4B8530()
{
    short total = field_C9CA;
    if (total < 9)
    {
        int remainder = 9 - total;
        //remainder &= 0xFFFF;
        wchar_t* pStart = &field_C9B8[total];
        while (remainder)
        {
            *pStart = 0;
            pStart++;
            remainder--;
        }
//        wmemset(&field_C9B8[total], 0, remainder);
    }
}

// match
void laughing_blackwell_0x1EB54::sub_4B8560()
{
    if (!wcscmp(field_C9B8, L"WFUSDFCF")) // french bonus mission unlocks?
    {
        if (intro_bik_exists_4B5FF0()
            && gRegistry_6FF968.Get_Screen_Setting_5870D0("do_play_movie", 1) == 1)
        {
            sub_4B3170(8u);
        }
        else
        {
            sub_4B3170(0);
        }
    }
    else
    {
        field_110_state = 5;
        field_C9CA = 0;

        sub_4B8530();

        field_C9B3 = 1;
        field_C9B4 = 28;
        field_C9B6 = 5;

        wcsncpy(field_136[14].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_rnt1"), 0x32u);
        wcsncpy(field_136[14].field_518[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_rnt2"), 0x32u);
        wcsncpy(field_136[14].field_518[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_rnt3"), 0x32u);
        
        field_C9CB = 1;
    }
}

void laughing_blackwell_0x1EB54::sub_4B8020()
{
    dreamy_clarke_0xA4* pClarke = sub_4B43E0();
    unsigned __int8 idx = gLucid_hamilton_67E8E0.sub_4C5980();

    if (sub_4B7FB0())
    {
        sub_4B3170(4);
    }
    else if (idx == field_1EB50_idx - 1)
    {
        sub_4B3170(10);
    }
    else
    {
        // note: reg swap + push swap due to redundant local
        unsigned __int8 i = 3;
        while (
            !pClarke->field_0[idx][i].field_0 || 
            i >= field_1EB51_blocks[idx])
        {
            i--;
        }

        sub_4B4D00(idx, i);
        gLucid_hamilton_67E8E0.sub_4C5AD0(0);
        field_EE08 = 16;
        field_110_state = 2;
    }
}

char laughing_blackwell_0x1EB54::sub_4B7FB0()
{
    dreamy_clarke_0xA4 *v2; // eax
    unsigned __int16 v3; // bx
    unsigned __int16 v4; // dx

    v2 = sub_4B43E0();
    v3 = 0;
    if (!this->field_1EB50_idx)
        return 1;
    while (1)
    {
        v4 = 0;
        if (this->field_1EB51_blocks[v3])
            break;
    LABEL_5:
        if (++v3 >= (unsigned __int8)this->field_1EB50_idx)
            return 1;
    }
    while (v2->field_0[v3][v4].field_0)
    {
        if (++v4 >= this->field_1EB51_blocks[v3])
            goto LABEL_5;
    }
    return 0;
}

void laughing_blackwell_0x1EB54::sub_4B4D00(unsigned __int8 mainBlockIdx, unsigned __int8 bonusBlockIdx)
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4ADF50(int bQuit)
{
    // todo
}

void __stdcall sub_5D7D30()
{
    Vid_GetSurface(gVidSys_7071D0);
    MakeScreenTable(
        (int)gVidSys_7071D0->field_50_surface_pixels_ptr,
        gVidSys_7071D0->field_54_surface_pixels_pitch,
        gVidSys_7071D0->field_4C_rect_bottom);

    if (gVidSys_7071D0->field_40_full_screen == -2)
    {
        dword_70679C = window_height_706B50 - 1;
        dword_70675C = window_width_706630 - 1;
    }
    else
    {
        dword_70675C = gVidSys_7071D0->field_48_rect_right - 1;
        dword_70679C = gVidSys_7071D0->field_4C_rect_bottom - 1;
    }

    gbh_SetWindow(0, 0, dword_70675C, dword_70679C);
}

void __cdecl FreeSurface_5D7DC0()
{
    Vid_FreeSurface(gVidSys_7071D0);
}

void laughing_blackwell_0x1EB54::sub_4ADFB0(int a2)
{
    sub_5D7D30();

    gbh_BeginScene();
    DrawBackground_4B6E10();
    sub_4ADF50(a2);
    gbh_EndScene();

    FreeSurface_5D7DC0();

    Vid_FlipBuffers(gVidSys_7071D0);

    Vid_ClearScreen(
        gVidSys_7071D0,
        0,
        0,
        0,
        0,
        0,
        gVidSys_7071D0->field_48_rect_right,
        gVidSys_7071D0->field_4C_rect_bottom);
}


void laughing_blackwell_0x1EB54::DrawBackground_4B6E10()
{
    // todo
    BYTE tga_idx; // [esp+50h] [ebp-8h] BYREF
    BYTE not_used; // [esp+54h] [ebp-4h] BYREF

    if (field_EE08 == 13
        || field_EE08 == 16
        || field_EE08 == 14
        || field_EE08 == 15
        || field_EE08 == 12
        || field_EE08 == 17)
    {
        sub_4B6B00(field_EE08, &tga_idx, &not_used);
        int blitRet = gbh_BlitImage(tgaArray_61F0C8[tga_idx].field_84_img, 0, 0, 640, 480, 0, 0);
        if (blitRet == -10)
        {
            // need to reload image
            Load_tga_4B6520(tga_idx);
            gbh_BlitImage(tgaArray_61F0C8[tga_idx].field_84_img, 0, 0, 640, 480, 0, 0);
        }
        
    }
    else
    {
        sub_4B6B00(field_EE08, &tga_idx, &not_used);

        int blitRet = gbh_BlitImage(tgaArray_61F0C8[tga_idx].field_84_img, 0, 0, 278, 480, 0, 0);
        if (blitRet == -10)
        {
            Load_tga_4B6520(tga_idx);
            blitRet = gbh_BlitImage(tgaArray_61F0C8[tga_idx].field_84_img, 0, 0, 278, 480, 0, 0);
        }

        if (blitRet == 0)
        {
            blitRet = gbh_BlitImage(tgaArray_61F0C8[not_used].field_84_img, 0, 0, 362, 480, 278, 0);
            if (blitRet == -10)
            {
                Load_tga_4B6520(not_used);
                gbh_BlitImage(tgaArray_61F0C8[not_used].field_84_img, 0, 0, 362, 480, 278, 0);
            }
        }
    }
    
}

// match
void laughing_blackwell_0x1EB54::sub_4B6B00(unsigned __int8 a1, BYTE *pTgaIdx, BYTE *a3)
{
    switch (a1)
    {
    case 0u:
        *pTgaIdx = 1;
        *a3 = 0;
        break;

    case 1u:
        *pTgaIdx = 2;
        *a3 = 0;
        break;

    case 2u:
        *pTgaIdx = 3;
        *a3 = 0;
        break;

    case 3u:
        *pTgaIdx = 5;
        *a3 = 4;
        break;

    case 4u:
        *pTgaIdx = 6;
        *a3 = 4;
        break;
    case 5u:
        *pTgaIdx = 7;
        *a3 = 4;
        break;

    case 6u:
        *pTgaIdx = 8;
        *a3 = 4;
        break;

    case 7u:
        *pTgaIdx = 9;
        *a3 = 4;
        break;
    case 8u:
        *pTgaIdx = 10;
        *a3 = 4;
        break;

    case 9u:
        *pTgaIdx = 11;
        *a3 = 4;
        break;

    case 10u:
        *pTgaIdx = 12;
        *a3 = 4;
        break;

    case 11u:
        *pTgaIdx = 13;
        *a3 = 4;
        break;
    case 12u:
        *pTgaIdx = 15;
        *a3 = 0;
        break;

    case 13u:
        *pTgaIdx = 19;
        *a3 = 0;
        break;

    case 16u:
        *pTgaIdx = 17;
        *a3 = 0;
        break;

    case 14u:
        *pTgaIdx = 18;
        *a3 = 0;
        break;

    case 15u:
        *pTgaIdx = 16;
        *a3 = 0;
        break;

    case 17u:
        *pTgaIdx = 22;
        *a3 = 0;
        break;

    default:
        return;
    }
}

// match
void laughing_blackwell_0x1EB54::Load_tga_4B6520(unsigned __int16 idx)
{
    Error_SetName_4A0770(tgaArray_61F0C8[idx].field_0_tga_name);

    FILE* hFile = fopen(tgaArray_61F0C8[idx].field_0_tga_name, "rb");
    if (!hFile)
    {
        FatalError_4A38C0(16, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 6516);
    }

    void* pAlloc = malloc(tgaArray_61F0C8[idx].field_80_len);
    if (!pAlloc)
    {
        FatalError_4A38C0(174, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 6523);
    }

    if (fread(pAlloc, 1u, tgaArray_61F0C8[idx].field_80_len, hFile) != tgaArray_61F0C8[idx].field_80_len)
    {
        FatalError_4A38C0(187, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 6529);
    }

    tgaArray_61F0C8[idx].field_84_img = gbh_LoadImage((SImage*)pAlloc);

    fclose(hFile);
    free(pAlloc);


}

// todo: move me
void __stdcall sub_5D7CB0()
{
    // todo
}

laughing_blackwell_0x1EB54::laughing_blackwell_0x1EB54()
{
    field_10D = 1;

    gText_0x14_704DFC = new text_0x14();
    if (!gText_0x14_704DFC)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2288);
    }

    gGtx_0x106C_703DD4 = new gtx_0x106C();
    if (!gGtx_0x106C_703DD4)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2290);
    }

    gSharp_pare_0x15D8_705064 = new sharp_pare_0x15D8();
    if (!gSharp_pare_0x15D8_705064)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2292);
    }

    if (gText_0x14_704DFC->field_10_lang_code == 'j')
    {
        // pmagical_germain_0x8EC = pmagical_germain_0x8EC_mem ? magical_germain_0x8EC::ctor_4D2C80(pmagical_germain_0x8EC_mem) : 0;
        gMagical_germain_0x8EC_6F5168 = new magical_germain_0x8EC();
        if (!gMagical_germain_0x8EC_6F5168)
        {
            FatalError_4A38C0(32, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2297);
        }
    }
    InitKeyBoardDevice_4AFBE0();
    
    gText_0x14_704DFC->Load_5B5E90();
    gGtx_0x106C_703DD4->LoadSty_5AB750("data\\fstyle.sty");

    gSharp_pare_0x15D8_705064->sub_5B9350();

    sub_5D7CB0();

    gbh_SetAmbient(1.0);
    
    if (gMagical_germain_0x8EC_6F5168)
    {
        gMagical_germain_0x8EC_6F5168->sub_4D2B40();
    }

    field_110_state = 1;
    field_114 = 0;
    field_118 = 0;
    field_C9D5 = 0;
    field_C9D6 = 0;
    field_C9D3 = 0;
    field_C9D4 = 0;
    field_C9D7 = 0;
    field_C9D8 = 0;
    field_C9D9 = 0;
    field_10C_bKeyboardAcquired = 0;
    field_108 = 2;
    field_C9E1_bCheatsEnabled = 0;
    
    sub_4AF0E0();
    
    field_C9DC = timeGetTime();
    field_C9E0 = 0;
    field_132_f136_idx = 0;
    field_C9E4 = 0;
    
    sub_4B0220();
    
    field_C9B2 = 0;
    field_C9B3 = 1;
    field_C9B4 = 256;
    field_C9B6 = 5;

    memset(&field_C9A0, 0, sizeof(field_C9A0));
    /*
    *(_DWORD *)this->field_C9A0 = 0;
    *(_DWORD *)&this->field_C9A0[2] = 0;
    *(_DWORD *)&this->field_C9A0[4] = 0;
    *(_DWORD *)&this->field_C9A0[6] = 0;
    this->field_C9A0[8] = 0;
    */

    memset(&field_C9B8, 0, sizeof(field_C9B8));
    /*
    *(_DWORD *)this->field_C9B8 = 0;
    *(_DWORD *)&this->field_C9B8[2] = 0;
    *(_DWORD *)&this->field_C9B8[4] = 0;
    *(_DWORD *)&this->field_C9B8[6] = 0;
    *(_WORD *)&this->field_C9C8 = 0;
    */
    field_C9CA = 0;
    field_C9CB = 0;
    field_1EB50_idx = 0;

    field_1EB51_blocks[0] = 0;
    field_1EB51_blocks[1] = 0;
    field_1EB51_blocks[2] = 0;
    
    sub_4B4440();
    LoadPlySlotSvgs_4B53C0();
    
    field_EE08 = 1;
    
    Load_tgas_4B66B0();

    field_EE0D = 0;
    field_EE0A = 190;
    field_EE0C = 0;
    field_1EB30 = 0;
    field_1EB38 = 0;
    field_1EB34 = dword_67D930;
    field_1EB4A = 0;
    field_1EB4B = 0;
    field_1EB4C = 0;
    field_1EB4D = 0;
    field_1EB4E = 0;
    field_1EB4F = 0;


    // todo: fix me
    /*
    for (int i = 0; i < 8; i++)
    {

    }

    v11 = &this->field_1EB42;
    v12 = 8;
    do
    {
        *((_BYTE *)v11 - 8) = -1;
        *(_BYTE *)v11 = -1;
        v11 = (__int16 *)((char *)v11 + 1);
        --v12;
    } while (v12);
    */
}

laughing_blackwell_0x1EB54::~laughing_blackwell_0x1EB54()
{
    FreeKeyBoardDevice_4AFD00();

    if (gSharp_pare_0x15D8_705064)
    {
        delete gSharp_pare_0x15D8_705064;
        gSharp_pare_0x15D8_705064 = 0;
    }

    if (gGtx_0x106C_703DD4)
    {
        delete gGtx_0x106C_703DD4;
        gGtx_0x106C_703DD4 = 0;
    }

    if (gText_0x14_704DFC)
    {
        delete gText_0x14_704DFC;
        gText_0x14_704DFC = 0;
    }

    if (gMagical_germain_0x8EC_6F5168)
    {
        delete gMagical_germain_0x8EC_6F5168;
        gMagical_germain_0x8EC_6F5168 = 0;
    }

    FreeImageTable_4B6750();
}

void laughing_blackwell_0x1EB54::AcquireKeyBoard_4AFD70()
{
    LPDIRECTINPUTDEVICEA field_4_pKeyboardDevice; // eax

    field_4_pKeyboardDevice = this->field_4_pKeyboardDevice;
    if (!field_4_pKeyboardDevice || field_4_pKeyboardDevice->Acquire() < 0)
    {
        this->field_10C_bKeyboardAcquired = 1;
    }
}

// matches
void laughing_blackwell_0x1EB54::FreeKeyBoardDevice_4AFD00()
{
    if (field_4_pKeyboardDevice)
    {
        field_4_pKeyboardDevice->Unacquire();
        field_4_pKeyboardDevice->Release();
        field_4_pKeyboardDevice = 0;
    }
}

// match
void laughing_blackwell_0x1EB54::FreeImageTable_4B6750()
{
    gbh_FreeImageTable();
}

// match
char laughing_blackwell_0x1EB54::KeyBoard_GetKeyStates_4AFDD0()
{
    HRESULT hr = this->field_4_pKeyboardDevice->GetDeviceState(256, field_8_keys);
    if (FAILED(hr))
    {
        if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED)
        {
            if (FAILED(field_4_pKeyboardDevice->Acquire()))
            {
                return 0;
            }

            field_4_pKeyboardDevice->GetDeviceState(256, field_8_keys);
        }
        return 0;
    }

    return 1;
}

// match
void laughing_blackwell_0x1EB54::InitKeyBoardDevice_4AFBE0()
{
    field_0_pDInput = gpDInput_67B804;
    field_4_pKeyboardDevice = 0;
    
    if (field_0_pDInput->CreateDevice(GUID_SysKeyboard, &field_4_pKeyboardDevice, 0) < 0)
    {
        FatalError_4A38C0(31, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2469);
    }

    if (field_4_pKeyboardDevice->SetDataFormat(&gKeyboardDataFormat_601A54) < 0)
    {
        FatalError_4A38C0(9, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2480);
    }

    if (field_4_pKeyboardDevice->SetCooperativeLevel(gHwnd_707F04, 6) < 0)
    {
        FatalError_4A38C0(10, "C:\\Splitting\\GTA2\\Source\\frontend2.cpp", 2487);
    }

    AcquireKeyBoard_4AFD70();
}

void laughing_blackwell_0x1EB54::sub_4AF0E0()
{
    // todo
}

void laughing_blackwell_0x1EB54::sub_4B0220()
{
    __int16 v30; // ax

    // local_4 = (-(ushort)(cVar1 != 'j') & 0xfffc) + 0x10;

    int v2 = gText_0x14_704DFC->field_10_lang_code != 'j' ? 12 : 16;
    this->field_134 = 16;
 
    this->field_136[0].field_0 = 3; 
    this->field_136[0].field_4[0].field_0 = 1; // ebx
    this->field_136[0].field_4[0].field_2 = 300; // edi
    this->field_136[0].field_4[0].field_4 = 250;
    wcsncpy(this->field_136[0].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("play"), 0x32u);
    this->field_136[0].field_4[0].field_80 = 1;
    this->field_136[0].field_4[1].field_0 = 1;
    this->field_136[0].field_4[1].field_2 = 300;
    this->field_136[0].field_4[1].field_4 = 270;
    wcsncpy(this->field_136[0].field_4[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("options"), 0x32u);
    this->field_136[0].field_4[1].field_80 = 257;
    this->field_136[0].field_4[2].field_0 = 1;
    this->field_136[0].field_4[2].field_2 = 300;
    this->field_136[0].field_4[2].field_4 = 290;
    wcsncpy(this->field_136[0].field_4[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("quit"), 0x32u);
    this->field_136[0].field_4[2].field_80 = 9;
    this->field_136[0].field_B8A[0].field_0 = 280;
    this->field_136[0].field_B8A[0].field_2 = 258;
    this->field_136[0].field_B8A[1].field_0 = 280;
    this->field_136[0].field_B8A[1].field_2 = 278;
    this->field_136[0].field_B8A[2].field_0 = 280;
    this->field_136[0].field_B8A[2].field_2 = 298;
    this->field_136[0].field_BC6_nifty_idx = 0;
    this->field_136[0].field_BC8 = 0;
    this->field_136[1].field_0 = 5;
    this->field_136[1].field_4[0].field_0 = 2;
    this->field_136[1].field_4[0].field_2 = 300;
    this->field_136[1].field_4[0].field_4 = 210;
    wcsncpy(this->field_136[1].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("charctr"), 0x32u);
    this->field_136[1].field_4[0].field_6E_count = 0;
    this->field_136[1].field_4[0].field_70 = 0;
    this->field_136[1].field_4[0].field_7E = 7;
    
    unsigned short v77 = 0;
    do
    {
        this->field_136[1].field_4[0].field_72[v77++] = 1;
    } while (v77 <= this->field_136[1].field_4[0].field_7E);

    this->field_136[1].field_4[1].field_0 = 1;
    this->field_136[1].field_4[1].field_2 = 300;
    this->field_136[1].field_4[1].field_4 = 230;
    wcsncpy(this->field_136[1].field_4[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("savepos"), 0x32u);
    this->field_136[1].field_4[1].field_80 = 260;
    this->field_136[1].field_4[2].field_0 = 1;
    this->field_136[1].field_4[2].field_2 = 300;
    this->field_136[1].field_4[2].field_4 = 250;
    wcsncpy(this->field_136[1].field_4[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("hi_scre"), 0x32u);
    this->field_136[1].field_4[2].field_80 = 5;
    this->field_136[1].field_4[3].field_0 = 1;
    this->field_136[1].field_4[3].field_2 = 300;
    this->field_136[1].field_4[3].field_4 = 270;
    wcsncpy(this->field_136[1].field_4[3].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("strtlev"), 0x32u);
    this->field_136[1].field_4[3].field_80 = 264;
    this->field_136[1].field_4[4].field_0 = 1;
    this->field_136[1].field_4[4].field_2 = 300;
    this->field_136[1].field_4[4].field_4 = 350;
    wcsncpy(this->field_136[1].field_4[4].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("bonslev"), 0x32u);
    this->field_136[1].field_4[4].field_80 = 265;
    this->field_136[1].field_B8A[0].field_0 = 280;
    this->field_136[1].field_B8A[0].field_2 = 218;
    this->field_136[1].field_B8A[1].field_0 = 280;
    this->field_136[1].field_B8A[1].field_2 = 238;
    this->field_136[1].field_B8A[2].field_0 = 280;
    this->field_136[1].field_B8A[2].field_2 = 258;
    this->field_136[1].field_B8A[3].field_0 = 280;
    this->field_136[1].field_B8A[3].field_2 = 278;
    this->field_136[1].field_B8A[4].field_0 = 280;
    this->field_136[1].field_B8A[4].field_2 = 358;
    this->field_136[1].field_BC6_nifty_idx = 3;
    this->field_136[1].field_BC8 = 3;
    this->field_136[1].field_2 = 10;
    this->field_136[1].field_518[0].field_0 = 3;
    this->field_136[1].field_518[0].field_2 = 420;
    this->field_136[1].field_518[0].field_4 = 310;
    this->field_136[1].field_518[0].field_6_wstr_buf[0] = 0;
    this->field_136[1].field_518[1].field_0 = 3;
    this->field_136[1].field_518[1].field_2 = 420;
    this->field_136[1].field_518[1].field_4 = 390;
    this->field_136[1].field_518[1].field_6_wstr_buf[0] = 0;
    this->field_136[1].field_518[2].field_0 = 1;
    this->field_136[1].field_518[2].field_2 = 410;
    this->field_136[1].field_518[2].field_4 = 298;
    wcsncpy(this->field_136[1].field_518[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("car_dam"), 0x32u);
    this->field_136[1].field_518[2].field_6A = word_703C3C;
    this->field_136[1].field_518[3].field_0 = 1;
    this->field_136[1].field_518[3].field_2 = 410;
    this->field_136[1].field_518[3].field_4 = 378;
    wcsncpy(this->field_136[1].field_518[3].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("car_dam"), 0x32u);
    this->field_136[1].field_518[3].field_6A = word_703C3C;
    this->field_136[1].field_518[4].field_2 = 380;
    this->field_136[1].field_518[4].field_4 = 310;
    this->field_136[1].field_518[5].field_2 = 460;
    this->field_136[1].field_518[5].field_4 = 310;
    this->field_136[1].field_518[6].field_2 = 380;
    this->field_136[1].field_518[7].field_2 = 460;
    this->field_136[1].field_518[4].field_0 = 3;
    this->field_136[1].field_518[4].field_6_wstr_buf[0] = 3;
    this->field_136[1].field_518[5].field_0 = 3;
    this->field_136[1].field_518[5].field_6_wstr_buf[0] = 4;
    this->field_136[1].field_518[6].field_0 = 3;
    this->field_136[1].field_518[6].field_4 = 390;
    this->field_136[1].field_518[6].field_6_wstr_buf[0] = 3;
    this->field_136[1].field_518[7].field_0 = 3;
    this->field_136[1].field_518[7].field_4 = 390;
    this->field_136[1].field_518[7].field_6_wstr_buf[0] = 4;
    this->field_136[1].field_518[8].field_0 = 3;
    this->field_136[1].field_518[8].field_2 = 290;
    this->field_136[1].field_518[8].field_4 = 222;
    this->field_136[1].field_518[8].field_6_wstr_buf[0] = 3;
    this->field_136[1].field_518[9].field_0 = 3;
    this->field_136[1].field_518[9].field_2 = 580;
    this->field_136[1].field_518[9].field_4 = 222;
    this->field_136[1].field_518[9].field_6_wstr_buf[0] = 4;
    this->field_136[11].field_0 = 3;
    this->field_136[11].field_2 = 1;
    this->field_136[11].field_518[0].field_0 = 1;
    this->field_136[11].field_518[0].field_2 = 35;
    this->field_136[11].field_518[0].field_4 = 11;
    wcscpy(this->field_136[11].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("plr_qut"));
    this->field_136[11].field_518[0].field_6A = this->field_130;
    this->field_136[11].field_518[0].field_6C = 5;
    this->field_136[11].field_4[0].field_0 = 1;
    this->field_136[11].field_4[0].field_4 = 392;
    wcsncpy(this->field_136[11].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("savepos"), 0x32u);
    this->field_136[11].field_4[0].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[11].field_4[0].field_6_wstr_buf,
        this->field_136[11].field_4[0].field_6A,
        320);
    this->field_136[11].field_4[0].field_80 = 260;
    this->field_136[11].field_4[1].field_0 = 1;
    this->field_136[11].field_4[1].field_4 = 412;
    wcsncpy(this->field_136[11].field_4[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("replay"), 0x32u);
    this->field_136[11].field_4[1].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[11].field_4[1].field_6_wstr_buf,
        this->field_136[11].field_4[1].field_6A,
        320);
    this->field_136[11].field_4[1].field_80 = 259;
    this->field_136[11].field_4[2].field_0 = 1;
    this->field_136[11].field_4[2].field_4 = 432;
    wcsncpy(this->field_136[11].field_4[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("mainmen"), 0x32u);
    this->field_136[11].field_4[2].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[11].field_4[2].field_6_wstr_buf,
        this->field_136[11].field_4[2].field_6A,
        320);
    this->field_136[11].field_4[2].field_80 = 0;
    this->field_136[11].field_B8A[0].field_0 = 150;
    this->field_136[11].field_B8A[0].field_2 = 400;
    this->field_136[11].field_B8A[1].field_0 = 150;
    this->field_136[11].field_B8A[1].field_2 = 420;
    this->field_136[11].field_B8A[2].field_0 = 150;
    this->field_136[11].field_B8A[2].field_2 = 440;
    this->field_136[11].field_BC6_nifty_idx = 0;
    this->field_136[11].field_BC8 = 0;
    this->field_136[2].field_0 = 3;
    this->field_136[2].field_2 = 1;
    this->field_136[2].field_518[0].field_0 = 1;
    this->field_136[2].field_518[0].field_2 = 35;
    this->field_136[2].field_518[0].field_4 = 11;
    wcsncpy(this->field_136[2].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("plr_ded"), 0x32u);
    this->field_136[2].field_518[0].field_6A = this->field_130;
    this->field_136[2].field_518[0].field_6C = 0;
    this->field_136[2].field_4[0].field_0 = 1;
    this->field_136[2].field_4[0].field_4 = 392;
    wcsncpy(this->field_136[2].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("savepos"), 0x32u);
    this->field_136[2].field_4[0].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[2].field_4[0].field_6_wstr_buf,
        this->field_136[2].field_4[0].field_6A,
        320);
    this->field_136[2].field_4[0].field_80 = 260;
    this->field_136[2].field_4[1].field_0 = 1;
    this->field_136[2].field_4[1].field_4 = 412;
    wcsncpy(this->field_136[2].field_4[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("replay"), 0x32u);
    this->field_136[2].field_4[1].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[2].field_4[1].field_6_wstr_buf,
        this->field_136[2].field_4[1].field_6A,
        320);
    this->field_136[2].field_4[1].field_80 = 259;
    this->field_136[2].field_4[2].field_0 = 1;
    this->field_136[2].field_4[2].field_4 = 432;
    wcsncpy(this->field_136[2].field_4[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("mainmen"), 0x32u);
    this->field_136[2].field_4[2].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[2].field_4[2].field_6_wstr_buf,
        this->field_136[2].field_4[2].field_6A,
        320);
    this->field_136[2].field_4[2].field_80 = 0;
    this->field_136[2].field_B8A[0].field_0 = 150;
    this->field_136[2].field_B8A[0].field_2 = 400;
    this->field_136[2].field_B8A[1].field_0 = 150;
    this->field_136[2].field_B8A[1].field_2 = 420;
    this->field_136[2].field_B8A[2].field_0 = 150;
    this->field_136[2].field_B8A[2].field_2 = 440;
    this->field_136[2].field_BC6_nifty_idx = 0;
    this->field_136[2].field_BC8 = 0;
    this->field_136[3].field_0 = 5;
    this->field_136[3].field_2 = 1;
    this->field_136[3].field_518[0].field_0 = 1;
    this->field_136[3].field_518[0].field_2 = 35;
    this->field_136[3].field_518[0].field_4 = 11;
    wcsncpy(this->field_136[3].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("cmpltd"), 0x32u);
    this->field_136[3].field_518[0].field_6A = this->field_12C;
    this->field_136[3].field_4[0].field_0 = 1;
    this->field_136[3].field_4[0].field_4 = 365;
    wcsncpy(this->field_136[3].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("nxt_lvl"), 0x32u);
    this->field_136[3].field_4[0].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[3].field_4[0].field_6_wstr_buf,
        this->field_136[3].field_4[0].field_6A,
        320);
    this->field_136[3].field_4[0].field_80 = 261;
    this->field_136[3].field_4[1].field_0 = 1;
    this->field_136[3].field_4[1].field_4 = 385;
    wcsncpy(this->field_136[3].field_4[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("savepos"), 0x32u);
    this->field_136[3].field_4[1].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[3].field_4[1].field_6_wstr_buf,
        this->field_136[3].field_4[1].field_6A,
        320);
    this->field_136[3].field_4[1].field_80 = 260;
    this->field_136[3].field_4[2].field_0 = 1;
    this->field_136[3].field_4[2].field_4 = 405;
    wcsncpy(this->field_136[3].field_4[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("replay"), 0x32u);
    this->field_136[3].field_4[2].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[3].field_4[2].field_6_wstr_buf,
        this->field_136[3].field_4[2].field_6A,
        320);
    this->field_136[3].field_4[2].field_80 = 259;
    this->field_136[3].field_4[3].field_0 = 1;
    this->field_136[3].field_4[3].field_4 = 425;
    wcsncpy(this->field_136[3].field_4[3].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("contnue"), 0x32u);
    this->field_136[3].field_4[3].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[3].field_4[3].field_6_wstr_buf,
        this->field_136[3].field_4[3].field_6A,
        320);
    this->field_136[3].field_4[3].field_80 = 266;
    this->field_136[3].field_4[4].field_0 = 1;
    this->field_136[3].field_4[4].field_4 = 445;
    wcsncpy(this->field_136[3].field_4[4].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("mainmen"), 0x32u);
    this->field_136[3].field_4[4].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[3].field_4[4].field_6_wstr_buf,
        this->field_136[3].field_4[4].field_6A,
        320);
    this->field_136[3].field_4[4].field_80 = 0;
    this->field_136[3].field_B8A[0].field_0 = 150;
    this->field_136[3].field_B8A[0].field_2 = 373;
    this->field_136[3].field_B8A[1].field_0 = 150;
    this->field_136[3].field_B8A[1].field_2 = 393;
    this->field_136[3].field_B8A[2].field_0 = 150;
    this->field_136[3].field_B8A[2].field_2 = 413;
    this->field_136[3].field_B8A[3].field_0 = 150;
    this->field_136[3].field_B8A[3].field_2 = 433;
    this->field_136[3].field_B8A[4].field_0 = 150;
    this->field_136[3].field_B8A[4].field_2 = 453;
    this->field_136[3].field_BC6_nifty_idx = 0;
    this->field_136[3].field_BC8 = 0;
    this->field_136[4].field_0 = 1;
    this->field_136[4].field_2 = 1;
    this->field_136[4].field_518[0].field_0 = 1;
    this->field_136[4].field_518[0].field_4 = 230;
    wcsncpy(this->field_136[4].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("gam_cmp"), 0x32u);
    v30 = this->field_130;
    this->field_136[4].field_518[0].field_6A = v30;
    this->field_136[4].field_518[0].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[4].field_518[0].field_6_wstr_buf,
        v30,
        320);
    this->field_136[4].field_518[0].field_6C = 4;
    this->field_136[4].field_4[0].field_0 = 1;
    this->field_136[4].field_4[0].field_2 = 180;
    this->field_136[4].field_4[0].field_4 = 410;
    wcsncpy(this->field_136[4].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("mainmen"), 0x32u);
    this->field_136[4].field_4[0].field_80 = 0;
    this->field_136[4].field_B8A[0].field_0 = 160;
    this->field_136[4].field_B8A[0].field_2 = 418;
    this->field_136[4].field_BC6_nifty_idx = 0;
    this->field_136[4].field_BC8 = 0;
    this->field_136[5].field_0 = 1;
    this->field_136[5].field_2 = 5;
    this->field_136[5].field_4[0].field_0 = 2;
    this->field_136[5].field_4[0].field_2 = 300;
    this->field_136[5].field_4[0].field_4 = 155;
    this->field_136[5].field_4[0].field_6E_count = 0;
    this->field_136[5].field_4[0].field_70 = 0;
    this->field_136[5].field_4[0].field_7E = 11;

    unsigned short v323 = 0;
    do
    {
        this->field_136[5].field_4[0].field_72[v323++] = 1;
    } while (v323 <= field_136[5].field_4[0].field_7E);

    this->field_136[5].field_B8A[0].field_0 = 280;
    this->field_136[5].field_B8A[0].field_2 = 163;
    this->field_136[5].field_BC6_nifty_idx = 0;
    this->field_136[5].field_BC8 = 0;
    this->field_136[5].field_518[0].field_0 = 3;
    this->field_136[5].field_518[0].field_2 = 450;
    this->field_136[5].field_518[0].field_4 = 197;
    this->field_136[5].field_518[0].field_6_wstr_buf[0] = 0;
    this->field_136[5].field_518[1].field_0 = 1;
    this->field_136[5].field_518[1].field_2 = 440;
    this->field_136[5].field_518[1].field_4 = 185;
//    v34 = ;
    this->field_136[5].field_518[2].field_4 = 197;
    this->field_136[5].field_518[3].field_4 = 197;
    this->field_136[5].field_518[1].field_6A = word_703C3C; // v34
    this->field_136[5].field_518[2].field_0 = 3;
    this->field_136[5].field_518[2].field_2 = 410;
    this->field_136[5].field_518[2].field_6_wstr_buf[0] = 3;
    this->field_136[5].field_518[3].field_0 = 3;
    this->field_136[5].field_518[3].field_2 = 490;
    this->field_136[5].field_518[3].field_6_wstr_buf[0] = 4;
    this->field_136[5].field_518[4].field_0 = 1;
    this->field_136[5].field_518[4].field_2 = 340;
    this->field_136[5].field_518[4].field_4 = v2;
    wcsncpy(this->field_136[5].field_518[4].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("hi_scre"), 0x32u);
    this->field_136[5].field_518[4].field_6A = this->field_126;
    this->field_136[6].field_0 = 3;
    this->field_136[6].field_2 = 3;
    this->field_136[6].field_518[0].field_0 = 1;
    this->field_136[6].field_518[0].field_2 = 35;
    this->field_136[6].field_518[0].field_4 = 11;
    wcsncpy(this->field_136[6].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("bonslev"), 0x32u);
    this->field_136[6].field_518[0].field_6A = this->field_130;
    this->field_136[6].field_518[0].field_6C = 5;
    this->field_136[6].field_518[1].field_0 = 1;
    this->field_136[6].field_518[1].field_2 = 170;
    this->field_136[6].field_518[1].field_4 = 250;
    wcsncpy(this->field_136[6].field_518[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("score"), 0x32u);
    this->field_136[6].field_518[2].field_0 = 1;
    this->field_136[6].field_518[2].field_2 = 400;
    this->field_136[6].field_518[2].field_4 = 250;
    __int16 v38 = this->field_120;
    this->field_136[6].field_4[0].field_0 = 1;
    this->field_136[6].field_518[2].field_6A = v38;
    this->field_136[6].field_4[0].field_4 = 340;
    wcsncpy(this->field_136[6].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("repbons"), 0x32u);
    this->field_136[6].field_4[0].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[6].field_4[0].field_6_wstr_buf,
        v38,
        320);
    this->field_136[6].field_4[0].field_80 = 259;
    this->field_136[6].field_4[1].field_0 = 1;
    this->field_136[6].field_4[1].field_4 = 360;
    wcsncpy(this->field_136[6].field_4[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("nxt_lvl"), 0x32u);
    this->field_136[6].field_4[1].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[6].field_4[1].field_6_wstr_buf,
        this->field_136[6].field_4[1].field_6A,
        320);
    this->field_136[6].field_4[1].field_80 = 261;
    this->field_136[6].field_4[2].field_0 = 1;
    this->field_136[6].field_4[2].field_4 = 380;
    wcsncpy(this->field_136[6].field_4[2].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("mainmen"), 0x32u);
    this->field_136[6].field_4[2].field_2 = laughing_blackwell_0x1EB54::sub_4B0190(
        this->field_136[6].field_4[2].field_6_wstr_buf,
        this->field_136[6].field_4[2].field_6A,
        320);
    this->field_136[6].field_4[2].field_80 = 0;
    this->field_136[6].field_B8A[0].field_0 = 150;
    this->field_136[6].field_B8A[0].field_2 = 348;
    this->field_136[6].field_B8A[1].field_0 = 150;
    this->field_136[6].field_B8A[1].field_2 = 368;
    this->field_136[6].field_B8A[2].field_0 = 150;
    this->field_136[6].field_B8A[2].field_2 = 388;
    this->field_136[6].field_BC6_nifty_idx = 0;
    this->field_136[6].field_BC8 = 0;
    this->field_136[7].field_0 = 1;
    this->field_136[7].field_2 = 14;
    this->field_136[7].field_518[0].field_0 = 1;
    this->field_136[7].field_518[0].field_2 = 35;
    this->field_136[7].field_518[0].field_4 = 11;
    this->field_136[7].field_518[0].field_6A = this->field_130;
    this->field_136[7].field_518[0].field_6C = 5;
    this->field_136[7].field_518[1].field_0 = 1;
    this->field_136[7].field_518[1].field_2 = 100;
    this->field_136[7].field_518[1].field_4 = 170;
    wcsncpy(this->field_136[7].field_518[1].field_6_wstr_buf, word_67DC8C, 50u);
    this->field_136[7].field_518[2].field_0 = 1;
    this->field_136[7].field_518[2].field_2 = 100;
    this->field_136[7].field_518[2].field_4 = 190;
    wcsncpy(this->field_136[7].field_518[2].field_6_wstr_buf, word_67DC8C, 0x32u);
    this->field_136[7].field_518[3].field_0 = 1;
    this->field_136[7].field_518[3].field_2 = 100;
    this->field_136[7].field_518[3].field_4 = 210;
    wcsncpy(this->field_136[7].field_518[3].field_6_wstr_buf, word_67DC8C, 0x32u);
    this->field_136[7].field_518[4].field_0 = 1;
    this->field_136[7].field_518[4].field_2 = 100;
    this->field_136[7].field_518[4].field_4 = 230;
    wcsncpy(this->field_136[7].field_518[4].field_6_wstr_buf, word_67DC8C, 0x32u);
    this->field_136[7].field_518[5].field_0 = 1;
    this->field_136[7].field_518[5].field_2 = 100;
    this->field_136[7].field_518[5].field_4 = 250;
    wcsncpy(this->field_136[7].field_518[5].field_6_wstr_buf, word_67DC8C, 0x32u);
    this->field_136[7].field_518[6].field_0 = 1;
    this->field_136[7].field_518[6].field_2 = 100;
    this->field_136[7].field_518[6].field_4 = 270;
    wcsncpy(this->field_136[7].field_518[6].field_6_wstr_buf, word_67DC8C, 0x32u);
    this->field_136[7].field_518[7].field_0 = 1;
    this->field_136[7].field_518[7].field_4 = 300;
    wcsncpy(this->field_136[7].field_518[7].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("kills_h"), 0x32u);
    this->field_136[7].field_518[7].field_2 = sub_4B0190(
        this->field_136[7].field_518[7].field_6_wstr_buf,
        this->field_136[7].field_518[7].field_6A,
        320);
    this->field_136[7].field_518[8].field_0 = 1;
    this->field_136[7].field_518[8].field_2 = 100;
    this->field_136[7].field_518[8].field_4 = 320;
    this->field_136[7].field_518[9].field_0 = 1;
    this->field_136[7].field_518[9].field_2 = 100;
    this->field_136[7].field_518[9].field_4 = 340;
    this->field_136[7].field_518[10].field_0 = 1;
    this->field_136[7].field_518[10].field_2 = 100;
    this->field_136[7].field_518[10].field_4 = 360;
    this->field_136[7].field_518[11].field_0 = 1;
    this->field_136[7].field_518[11].field_2 = 100;
    this->field_136[7].field_518[11].field_4 = 380;
    this->field_136[7].field_518[12].field_0 = 1;
    this->field_136[7].field_518[12].field_2 = 100;
    this->field_136[7].field_518[12].field_4 = 400;
    this->field_136[7].field_518[13].field_0 = 1;
    this->field_136[7].field_518[13].field_2 = 30;
    this->field_136[7].field_518[13].field_4 = 150;
    this->field_136[7].field_4[0].field_0 = 1;
    this->field_136[7].field_4[0].field_4 = 430;
    wcsncpy(this->field_136[7].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("quit"), 0x32u);
    this->field_136[7].field_4[0].field_2 = sub_4B0190(
        this->field_136[7].field_4[0].field_6_wstr_buf,
        this->field_136[7].field_4[0].field_6A,
        320);
    this->field_136[7].field_4[0].field_80 = 258;
    this->field_136[7].field_B8A[0].field_0 = 180;
    this->field_136[7].field_B8A[0].field_2 = 438;
    this->field_136[7].field_BC6_nifty_idx = 0;
    this->field_136[7].field_BC8 = 0;
    this->field_136[8].field_0 = 1;
    this->field_136[8].field_2 = 0;
    this->field_136[8].field_4[0].field_0 = 1;
    this->field_136[8].field_4[0].field_2 = 200;
    this->field_136[8].field_4[0].field_4 = 280;
    wcsncpy(this->field_136[8].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("mainmen"), 0x32u);
    this->field_136[8].field_4[0].field_80 = 0;
    this->field_136[8].field_B8A[0].field_0 = 180;
    this->field_136[8].field_B8A[0].field_2 = 288;
    this->field_136[8].field_BC6_nifty_idx = 0;
    this->field_136[8].field_BC8 = 0;
    this->field_136[10].field_0 = 1;
    this->field_136[10].field_2 = 1;
    this->field_136[10].field_518[0].field_0 = 1;
    this->field_136[10].field_518[0].field_4 = 230;
    wcsncpy(this->field_136[10].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("nicetry"), 0x32u);
//    v46 = this->field_130;
    this->field_136[10].field_518[0].field_6A = this->field_130; // v46;
    this->field_136[10].field_518[0].field_2 = sub_4B0190(
        this->field_136[10].field_518[0].field_6_wstr_buf,
        this->field_130, //v46,
        320);
    this->field_136[10].field_518[0].field_6C = 4;
    this->field_136[10].field_4[0].field_0 = 1;
    this->field_136[10].field_4[0].field_2 = 180;
    this->field_136[10].field_4[0].field_4 = 410;
    wcsncpy(this->field_136[10].field_4[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("mainmen"), 0x32u);
    this->field_136[10].field_4[0].field_80 = 0;
    this->field_136[10].field_B8A[0].field_0 = 160;
    this->field_136[10].field_B8A[0].field_2 = 418;
    this->field_136[10].field_BC6_nifty_idx = 0;
    this->field_136[10].field_BC8 = 0;
    this->field_136[14].field_0 = 1;
    this->field_136[14].field_2 = 5;
    this->field_136[14].field_4[0].field_0 = 1;
    this->field_136[14].field_4[0].field_2 = 170;
    this->field_136[14].field_4[0].field_4 = 340;
    this->field_136[14].field_4[0].field_80 = 268;
    this->field_136[14].field_518[0].field_0 = 1;
    this->field_136[14].field_518[0].field_2 = 20;
    this->field_136[14].field_518[0].field_4 = 160;
    wcsncpy(this->field_136[14].field_518[0].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_ent1"), 0x32u);
    this->field_136[14].field_518[1].field_0 = 1;
    this->field_136[14].field_518[1].field_2 = 20;
    this->field_136[14].field_518[1].field_4 = 180;
    wcsncpy(this->field_136[14].field_518[1].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_ent2"), 0x32u);
    this->field_136[14].field_518[2].field_0 = 1;
    this->field_136[14].field_518[2].field_2 = 20;
    this->field_136[14].field_518[2].field_4 = 200;
    wcsncpy(this->field_136[14].field_518[2].field_6_wstr_buf, word_67DC8C, 0x32u);
    this->field_136[14].field_518[3].field_0 = 1;
    this->field_136[14].field_518[3].field_2 = 20;
    this->field_136[14].field_518[3].field_4 = 300;
    wcsncpy(this->field_136[14].field_518[3].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("fr_pmpt"), 0x32u);
    this->field_136[14].field_518[4].field_0 = 1;
    this->field_136[14].field_518[4].field_2 = 20;
    this->field_136[14].field_518[4].field_4 = 320;
    wcsncpy(this->field_136[14].field_518[4].field_6_wstr_buf, gText_0x14_704DFC->Find_5B5F90("score"), 0x32u);
    this->field_136[14].field_B8A[0].field_0 = 150;
    this->field_136[14].field_B8A[0].field_2 = 348;
    this->field_136[14].field_BC6_nifty_idx = 0;
    this->field_136[14].field_BC8 = 0;
    field_EE0E_unk.sub_483F20();
}

void laughing_blackwell_0x1EB54::sub_4B4440()
{
    // todo
}

void laughing_blackwell_0x1EB54::LoadPlySlotSvgs_4B53C0()
{
    char FileName[256];
    for (unsigned int i = 0; i < 8; i++)
    {
        if (PlySlotSvgExists_4B5370(i))
        {
            GetPlySlotSvgName_4B51D0(i, FileName);
            field_EDE8_plySlots[i].LoadPlySlotSvg_4B6480(FileName);
        }
        else
        {
            field_EDE8_plySlots[i].field_0 = 0;
            field_EDE8_plySlots[i].field_1 = 3;
            field_EDE8_plySlots[i].field_2 = 4;
            field_EDE8_plySlots[i].field_3 = 0;
        }
    }
}

// match
void laughing_blackwell_0x1EB54::Load_tgas_4B66B0()
{
    if (gbh_InitImageTable(gTableSize_61FF20) != -1)
    {
        for (unsigned short i = 0; i < gTableSize_61FF20; ++i)
        {
            Load_tga_4B6520(i);
        }
    }
}

// match
void laughing_blackwell_0x1EB54::GetPlySlotSvgName_4B51D0(unsigned __int8 idx, char *pStr)
{
    char Buffer[8];
    _itoa(idx, Buffer, 10);
    strcpy(pStr, "player\\plyslot");
    strcat(pStr, Buffer);
    strcat(pStr, ".svg");
}

// match
char laughing_blackwell_0x1EB54::PlySlotSvgExists_4B5370(int idx)
{
    char FileName[256];
    GetPlySlotSvgName_4B51D0(idx, FileName);
    
    _finddata_t findData;
    long hFind = _findfirst(FileName, &findData);
    if (hFind == -1)
    {
        return 0;
    }

    _findclose(hFind);
    return 1;
}

extern BYTE byte_6F4BF4;
extern bool bDoFrontEnd_626B68;

void __stdcall laughing_blackwell_0x1EB54::sub_5E53C0(BYTE *a1)
{
    if (bDoFrontEnd_626B68)
    {
        if (gLaughing_blackwell_0x1EB54_67DC84)
        {
            gLaughing_blackwell_0x1EB54_67DC84->field_10D = *a1;
        }
    }
    else
    {
        byte_6F4BF4 = *a1;
    }
}

int laughing_blackwell_0x1EB54::sub_4B0190(wchar_t* a2, __int16 a3, int a4)
{
    // todo
    /*
    int v4; // eax
    int v5; // ecx

    if (a3 == -1)
        v4 = sub_5D8990((__int16 *)a2, this->field_11C);
    else
        v4 = sub_5D8990((__int16 *)a2, a3);
    HIWORD(v5) = HIWORD(v4);
    LOWORD(v5) = (unsigned __int16)v4 >> 1;
    return a4 - v5;
    */
    return 0;
}

loving_borg_0xBCA::loving_borg_0xBCA()
{
    field_0 = 0;
    field_2 = 0;
    field_BC6_nifty_idx = 0;
    field_BC8 = 0;
}

loving_borg_0xBCA::~loving_borg_0xBCA()
{
    field_0 = 0;
    field_2 = 0;
    field_BC6_nifty_idx = 0;
    field_BC8 = 0;
}

bool loving_borg_0xBCA::sub_4B61B0()
{
    unsigned __int16 oldIdx = field_BC6_nifty_idx;
    do
    {
        if (!field_BC6_nifty_idx)
        {
            field_BC6_nifty_idx = field_0 - 1;
        }
        else
        {
            field_BC6_nifty_idx--;
        }
    } while (!field_B8A[field_BC6_nifty_idx].field_4);
    return oldIdx != field_BC6_nifty_idx ? true : false;
}

bool loving_borg_0xBCA::sub_4B6200()
{
    unsigned __int16 oldIdx = field_BC6_nifty_idx;
    do
    {
        if (field_BC6_nifty_idx == field_0 - 1)
        {
            field_BC6_nifty_idx = 0;
        }
        else
        {
            field_BC6_nifty_idx++;
        }
    } while (!field_B8A[field_BC6_nifty_idx].field_4);
    return oldIdx != field_BC6_nifty_idx ? true : false;
}

competent_noyce_0x6E::competent_noyce_0x6E()
{
    field_0 = 0;
    field_2 = 0;
    field_4 = 0;
    field_1 = 1;
    wcscpy(field_6_wstr_buf, word_67DC8C);
    field_6A = -1;
    field_6C = -1;
}

competent_noyce_0x6E::~competent_noyce_0x6E()
{
    field_1 = 1;
    field_0 = 0;
    field_2 = 0;
    field_4 = 0;
    field_6A = -1;
    field_6C = -1;
}

nifty_maxwell_0x82::nifty_maxwell_0x82()
{
    field_6A = -1;
    field_6C = -1;
    field_0 = 0;
    field_1 = 1;
    field_2 = 0;
    field_4 = 0;
    field_6E_count = 0;
    field_70 = 0;
    memset(&field_72, 0, sizeof(field_72));
    field_76 = 0;
    field_7A = 0;
    wcscpy(field_6_wstr_buf, word_67DC8C);
    field_7E = 0;
    field_80 = 0;
}

nifty_maxwell_0x82::~nifty_maxwell_0x82()
{
    field_0 = 0;
    field_1 = 1;
    field_2 = 0;
    field_4 = 0;
    field_6A = -1;
    field_6C = -1;
    field_6E_count = 0;
    field_70 = 0;
    field_7E = 0;
    field_80 = 0;
}

BYTE byte_67DA80;

bool nifty_maxwell_0x82::sub_4B6330()
{
    BYTE tmp = byte_67DA80;
    unsigned __int16 old_count = field_6E_count;
    unsigned __int16 new_count = old_count;
    char bFound = 0;
    do
    {
        new_count++;
        if (new_count > field_7E)
        {
            if (tmp)
            {
                new_count = 0;
            }
            else
            {
                new_count += 0xFFFF;
            }
        }

        if (field_72[new_count])
        {
            bFound = 1;
        }

    } while (new_count != old_count && !bFound); // note: field_6E_count being reg cached instead of re-read from this
    
    field_6E_count = new_count;

    return old_count != new_count ? true : false;
}

bool nifty_maxwell_0x82::sub_4B6390()
{
    unsigned __int16 oldCount = this->field_6E_count;
    unsigned __int16 new_count = oldCount;
    char bFound = 0;
    do
    {
       
        if (new_count ==0 )
        {
            if (byte_67DA80)
            {
                new_count = this->field_7E;
            }
        }
      
        else
        {
            --new_count; // add     eax, 0FFFFh
           
        }

        if (this->field_72[new_count])
        {
            bFound = 1;
        }

    } while (new_count != this->field_6E_count && !bFound); // 6E not reloaded

    this->field_6E_count = new_count;

    return oldCount != new_count ? true : false;
}

kind_beaver_6::kind_beaver_6()
{
    field_0 = 0;
    field_2 = 0;
    field_4 = 1;
}

kind_beaver_6::~kind_beaver_6()
{
    field_0 = 0;
    field_2 = 0;
    field_4 = 1;
}

xenodochial_morse::xenodochial_morse()
{
    field_0 = 0;
}

void xenodochial_morse::sub_483F20()
{
    // todo
}

sleepy_stonebraker_0x6C::sleepy_stonebraker_0x6C()
{
    field_0 = 0;
    field_2 = 0;
    field_4 = 0;
    field_6 = 0;
    memset(field_8_strBuf, 0u, sizeof(field_8_strBuf));
}

sleepy_stonebraker_0x6C::~sleepy_stonebraker_0x6C()
{

}

admiring_euler_4::admiring_euler_4()
{
    field_0 = 0;
    field_1 = 0;
    field_2 = 0;
}

admiring_euler_4::~admiring_euler_4()
{
    field_0 = 0;
    field_1 = 0;
    field_2 = 0;
}

// match
void admiring_euler_4::LoadPlySlotSvg_4B6480(const char *FileName)
{
    File::Global_Open_4A7060(FileName);

    svg_stru svg;
    unsigned int len = sizeof(svg_stru);
    File::Global_Read_4A71C0(&svg, &len);

    File::Global_Close_4A70C0();

    field_0 = 1;
    field_1 = svg.field_4B;
    field_2 = svg.field_4C;
    field_3 = svg.field_4D;
}
