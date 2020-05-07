/*****************************************************************************
/ IC.cpp
/
/ Copyright (c) 2012-2020 Ignacio Calvo
/ https://forum.cockos.com/member.php?u=130806
/ http://github.com/reaper-oss/sws
/
/ Permission is hereby granted, free of charge, to any person obtaining a copy
/ of this software and associated documentation files (the "Software"), to deal
/ in the Software without restriction, including without limitation the rights to
/ use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
/ of the Software, and to permit persons to whom the Software is furnished to
/ do so, subject to the following conditions:
/
/ The above copyright notice and this permission notice shall be included in all
/ copies or substantial portions of the Software.
/
/ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
/ EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
/ OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
/ NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
/ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
/ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/ FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
/ OTHER DEALINGS IN THE SOFTWARE.
/
******************************************************************************/
#include "stdafx.h"
#include "IC.h"
#include "IC_MidiEditor.h"
#include "../Breeder/BR_Util.h"
#include "../SnM/SnM.h"
#include "../SnM/SnM_Util.h"
#include "../reaper/localize.h"

/******************************************************************************
* Globals                                                                     *
******************************************************************************/

/******************************************************************************
* Command hook                                                                *
******************************************************************************/

/******************************************************************************
* CSurf                                                                       *
******************************************************************************/

/******************************************************************************
* Continuous actions                                                          *
******************************************************************************/

/******************************************************************************
* Commands                                                                    *
******************************************************************************/
//!WANT_LOCALIZE_1ST_STRING_BEGIN:sws_actions
static COMMAND_T g_commandTable[] =
{
	/******************************************************************************
	* MIDI editor - Misc                                                          *
	******************************************************************************/
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Velocity" },                                                                              "IC_ME_HIDE_CC_LANE_M01",                    NULL, NULL,  -1, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 000 Bank Select MSB" },                                                                   "IC_ME_HIDE_CC_LANE_000",                    NULL, NULL,   0, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 001 Mod Wheel MSB" },                                                                     "IC_ME_HIDE_CC_LANE_001",                    NULL, NULL,   1, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 002 Breath MSB" },                                                                        "IC_ME_HIDE_CC_LANE_002",                    NULL, NULL,   2, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 003" },                                                                                   "IC_ME_HIDE_CC_LANE_003",                    NULL, NULL,   3, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 004 Foot Pedal MSB" },                                                                    "IC_ME_HIDE_CC_LANE_004",                    NULL, NULL,   4, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 005 Portamento MSB" },                                                                    "IC_ME_HIDE_CC_LANE_005",                    NULL, NULL,   5, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 006 Data Entry MSB" },                                                                    "IC_ME_HIDE_CC_LANE_006",                    NULL, NULL,   6, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 007 Volume MSB" },                                                                        "IC_ME_HIDE_CC_LANE_007",                    NULL, NULL,   7, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 008 Balance MSB" },                                                                       "IC_ME_HIDE_CC_LANE_008",                    NULL, NULL,   8, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 009" },                                                                                   "IC_ME_HIDE_CC_LANE_009",                    NULL, NULL,   9, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 010 Pan Position MSB" },                                                                  "IC_ME_HIDE_CC_LANE_010",                    NULL, NULL,  10, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 011 Expression MSB" },                                                                    "IC_ME_HIDE_CC_LANE_011",                    NULL, NULL,  11, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 012 Control 1 MSB" },                                                                     "IC_ME_HIDE_CC_LANE_012",                    NULL, NULL,  12, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 013 Control 2 MSB" },                                                                     "IC_ME_HIDE_CC_LANE_013",                    NULL, NULL,  13, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 014" },                                                                                   "IC_ME_HIDE_CC_LANE_014",                    NULL, NULL,  14, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 015" },                                                                                   "IC_ME_HIDE_CC_LANE_015",                    NULL, NULL,  15, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 016 GP Slider 1 MSB" },                                                                   "IC_ME_HIDE_CC_LANE_016",                    NULL, NULL,  16, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 017 GP Slider 2 MSB" },                                                                   "IC_ME_HIDE_CC_LANE_017",                    NULL, NULL,  17, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 018 GP Slider 3 MSB" },                                                                   "IC_ME_HIDE_CC_LANE_018",                    NULL, NULL,  18, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 019" },                                                                                   "IC_ME_HIDE_CC_LANE_019",                    NULL, NULL,  19, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 020" },                                                                                   "IC_ME_HIDE_CC_LANE_020",                    NULL, NULL,  20, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 021" },                                                                                   "IC_ME_HIDE_CC_LANE_021",                    NULL, NULL,  21, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 022" },                                                                                   "IC_ME_HIDE_CC_LANE_022",                    NULL, NULL,  22, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 023" },                                                                                   "IC_ME_HIDE_CC_LANE_023",                    NULL, NULL,  23, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 024" },                                                                                   "IC_ME_HIDE_CC_LANE_024",                    NULL, NULL,  24, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 025" },                                                                                   "IC_ME_HIDE_CC_LANE_025",                    NULL, NULL,  25, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 026" },                                                                                   "IC_ME_HIDE_CC_LANE_026",                    NULL, NULL,  26, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 027" },                                                                                   "IC_ME_HIDE_CC_LANE_027",                    NULL, NULL,  27, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 028" },                                                                                   "IC_ME_HIDE_CC_LANE_028",                    NULL, NULL,  28, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 029" },                                                                                   "IC_ME_HIDE_CC_LANE_029",                    NULL, NULL,  29, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 030" },                                                                                   "IC_ME_HIDE_CC_LANE_030",                    NULL, NULL,  30, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 031" },                                                                                   "IC_ME_HIDE_CC_LANE_031",                    NULL, NULL,  31, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 032 Bank Select LSB" },                                                                   "IC_ME_HIDE_CC_LANE_032",                    NULL, NULL,  32, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 033 Mod Wheel LSB" },                                                                     "IC_ME_HIDE_CC_LANE_033",                    NULL, NULL,  33, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 034 Breath LSB" },                                                                        "IC_ME_HIDE_CC_LANE_034",                    NULL, NULL,  34, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 035" },                                                                                   "IC_ME_HIDE_CC_LANE_035",                    NULL, NULL,  35, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 036 Foot Pedal LSB" },                                                                    "IC_ME_HIDE_CC_LANE_036",                    NULL, NULL,  36, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 037 Portamento LSB" },                                                                    "IC_ME_HIDE_CC_LANE_037",                    NULL, NULL,  37, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 038 Data Entry LSB" },                                                                    "IC_ME_HIDE_CC_LANE_038",                    NULL, NULL,  38, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 039 Volume LSB" },                                                                        "IC_ME_HIDE_CC_LANE_039",                    NULL, NULL,  39, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 040 Balance LSB" },                                                                       "IC_ME_HIDE_CC_LANE_040",                    NULL, NULL,  40, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 041" },                                                                                   "IC_ME_HIDE_CC_LANE_041",                    NULL, NULL,  41, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 042 Pan Position LSB" },                                                                  "IC_ME_HIDE_CC_LANE_042",                    NULL, NULL,  42, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 043 Expression LSB" },                                                                    "IC_ME_HIDE_CC_LANE_043",                    NULL, NULL,  43, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 044 Control 1 LSB" },                                                                     "IC_ME_HIDE_CC_LANE_044",                    NULL, NULL,  44, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 045 Control 2 LSB" },                                                                     "IC_ME_HIDE_CC_LANE_045",                    NULL, NULL,  45, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 046" },                                                                                   "IC_ME_HIDE_CC_LANE_046",                    NULL, NULL,  46, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 047" },                                                                                   "IC_ME_HIDE_CC_LANE_047",                    NULL, NULL,  47, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 048 GP Slider 1 LSB" },                                                                   "IC_ME_HIDE_CC_LANE_048",                    NULL, NULL,  48, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 049 GP Slider 2 LSB" },                                                                   "IC_ME_HIDE_CC_LANE_049",                    NULL, NULL,  49, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 050 GP Slider 3 LSB" },                                                                   "IC_ME_HIDE_CC_LANE_050",                    NULL, NULL,  50, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 051" },                                                                                   "IC_ME_HIDE_CC_LANE_051",                    NULL, NULL,  51, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 052" },                                                                                   "IC_ME_HIDE_CC_LANE_052",                    NULL, NULL,  52, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 053" },                                                                                   "IC_ME_HIDE_CC_LANE_053",                    NULL, NULL,  53, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 054" },                                                                                   "IC_ME_HIDE_CC_LANE_054",                    NULL, NULL,  54, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 055" },                                                                                   "IC_ME_HIDE_CC_LANE_055",                    NULL, NULL,  55, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 056" },                                                                                   "IC_ME_HIDE_CC_LANE_056",                    NULL, NULL,  56, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 057" },                                                                                   "IC_ME_HIDE_CC_LANE_057",                    NULL, NULL,  57, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 058" },                                                                                   "IC_ME_HIDE_CC_LANE_058",                    NULL, NULL,  58, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 059" },                                                                                   "IC_ME_HIDE_CC_LANE_059",                    NULL, NULL,  59, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 060" },                                                                                   "IC_ME_HIDE_CC_LANE_060",                    NULL, NULL,  60, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 061" },                                                                                   "IC_ME_HIDE_CC_LANE_061",                    NULL, NULL,  61, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 062" },                                                                                   "IC_ME_HIDE_CC_LANE_062",                    NULL, NULL,  62, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 063" },                                                                                   "IC_ME_HIDE_CC_LANE_063",                    NULL, NULL,  63, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 064 Hold Pedal (on/off)" },                                                               "IC_ME_HIDE_CC_LANE_064",                    NULL, NULL,  64, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 065 Portamento (on/off)" },                                                               "IC_ME_HIDE_CC_LANE_065",                    NULL, NULL,  65, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 066 Sostenuto (on/off)" },                                                                "IC_ME_HIDE_CC_LANE_066",                    NULL, NULL,  66, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 067 Soft Pedal (on/off)" },                                                               "IC_ME_HIDE_CC_LANE_067",                    NULL, NULL,  67, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 068 Legato Pedal (on/off)" },                                                             "IC_ME_HIDE_CC_LANE_068",                    NULL, NULL,  68, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 069 Hold 2 Pedal (on/off)" },                                                             "IC_ME_HIDE_CC_LANE_069",                    NULL, NULL,  69, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 070 Sound Variation" },                                                                   "IC_ME_HIDE_CC_LANE_070",                    NULL, NULL,  70, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 071 Timbre/Resonance" },                                                                  "IC_ME_HIDE_CC_LANE_071",                    NULL, NULL,  71, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 072 Sound Release" },                                                                     "IC_ME_HIDE_CC_LANE_072",                    NULL, NULL,  72, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 073 Sound Attack" },                                                                      "IC_ME_HIDE_CC_LANE_073",                    NULL, NULL,  73, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 074 Brightness/Cutoff Freq" },                                                            "IC_ME_HIDE_CC_LANE_074",                    NULL, NULL,  74, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 075 Sound Control 6" },                                                                   "IC_ME_HIDE_CC_LANE_075",                    NULL, NULL,  75, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 076 Sound Control 7" },                                                                   "IC_ME_HIDE_CC_LANE_076",                    NULL, NULL,  76, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 077 Sound Control 8" },                                                                   "IC_ME_HIDE_CC_LANE_077",                    NULL, NULL,  77, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 078 Sound Control 9" },                                                                   "IC_ME_HIDE_CC_LANE_078",                    NULL, NULL,  78, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 079 Sound Control 10" },                                                                  "IC_ME_HIDE_CC_LANE_079",                    NULL, NULL,  79, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 080 GP Button 1 (on/off)" },                                                              "IC_ME_HIDE_CC_LANE_080",                    NULL, NULL,  80, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 081 GP Button 2 (on/off)" },                                                              "IC_ME_HIDE_CC_LANE_081",                    NULL, NULL,  81, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 082 GP Button 3 (on/off)" },                                                              "IC_ME_HIDE_CC_LANE_082",                    NULL, NULL,  82, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 083 GP Button 4 (on/off)" },                                                              "IC_ME_HIDE_CC_LANE_083",                    NULL, NULL,  83, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 084" },                                                                                   "IC_ME_HIDE_CC_LANE_084",                    NULL, NULL,  84, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 085" },                                                                                   "IC_ME_HIDE_CC_LANE_085",                    NULL, NULL,  85, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 086" },                                                                                   "IC_ME_HIDE_CC_LANE_086",                    NULL, NULL,  86, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 087" },                                                                                   "IC_ME_HIDE_CC_LANE_087",                    NULL, NULL,  87, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 088" },                                                                                   "IC_ME_HIDE_CC_LANE_088",                    NULL, NULL,  88, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 089" },                                                                                   "IC_ME_HIDE_CC_LANE_089",                    NULL, NULL,  89, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 090" },                                                                                   "IC_ME_HIDE_CC_LANE_090",                    NULL, NULL,  90, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 091 Effects Level" },                                                                     "IC_ME_HIDE_CC_LANE_091",                    NULL, NULL,  91, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 092 Tremolo Level" },                                                                     "IC_ME_HIDE_CC_LANE_092",                    NULL, NULL,  92, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 093 Chorus Level" },                                                                      "IC_ME_HIDE_CC_LANE_093",                    NULL, NULL,  93, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 094 Celeste Level" },                                                                     "IC_ME_HIDE_CC_LANE_094",                    NULL, NULL,  94, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 095 Phaser Level" },                                                                      "IC_ME_HIDE_CC_LANE_095",                    NULL, NULL,  95, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 096 Data Button Inc" },                                                                   "IC_ME_HIDE_CC_LANE_096",                    NULL, NULL,  96, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 097 Data Button Dec" },                                                                   "IC_ME_HIDE_CC_LANE_097",                    NULL, NULL,  97, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 098 Non-Reg Parm LSB" },                                                                  "IC_ME_HIDE_CC_LANE_098",                    NULL, NULL,  98, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 099 Non-Reg Parm MSB" },                                                                  "IC_ME_HIDE_CC_LANE_099",                    NULL, NULL,  99, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 100 Reg Parm LSB" },                                                                      "IC_ME_HIDE_CC_LANE_100",                    NULL, NULL, 100, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 101 Reg Parm MSB" },                                                                      "IC_ME_HIDE_CC_LANE_101",                    NULL, NULL, 101, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 102" },                                                                                   "IC_ME_HIDE_CC_LANE_102",                    NULL, NULL, 102, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 103" },                                                                                   "IC_ME_HIDE_CC_LANE_103",                    NULL, NULL, 103, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 104" },                                                                                   "IC_ME_HIDE_CC_LANE_104",                    NULL, NULL, 104, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 105" },                                                                                   "IC_ME_HIDE_CC_LANE_105",                    NULL, NULL, 105, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 106" },                                                                                   "IC_ME_HIDE_CC_LANE_106",                    NULL, NULL, 106, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 107" },                                                                                   "IC_ME_HIDE_CC_LANE_107",                    NULL, NULL, 107, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 108" },                                                                                   "IC_ME_HIDE_CC_LANE_108",                    NULL, NULL, 108, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 109" },                                                                                   "IC_ME_HIDE_CC_LANE_109",                    NULL, NULL, 109, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 110" },                                                                                   "IC_ME_HIDE_CC_LANE_110",                    NULL, NULL, 110, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 111" },                                                                                   "IC_ME_HIDE_CC_LANE_111",                    NULL, NULL, 111, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 112" },                                                                                   "IC_ME_HIDE_CC_LANE_112",                    NULL, NULL, 112, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 113" },                                                                                   "IC_ME_HIDE_CC_LANE_113",                    NULL, NULL, 113, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 114" },                                                                                   "IC_ME_HIDE_CC_LANE_114",                    NULL, NULL, 114, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 115" },                                                                                   "IC_ME_HIDE_CC_LANE_115",                    NULL, NULL, 115, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 116" },                                                                                   "IC_ME_HIDE_CC_LANE_116",                    NULL, NULL, 116, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 117" },                                                                                   "IC_ME_HIDE_CC_LANE_117",                    NULL, NULL, 117, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 118" },                                                                                   "IC_ME_HIDE_CC_LANE_118",                    NULL, NULL, 118, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 119" },                                                                                   "IC_ME_HIDE_CC_LANE_119",                    NULL, NULL, 119, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 120" },                                                                                   "IC_ME_HIDE_CC_LANE_120",                    NULL, NULL, 120, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 121" },                                                                                   "IC_ME_HIDE_CC_LANE_121",                    NULL, NULL, 121, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 122" },                                                                                   "IC_ME_HIDE_CC_LANE_122",                    NULL, NULL, 122, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 123" },                                                                                   "IC_ME_HIDE_CC_LANE_123",                    NULL, NULL, 123, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 124" },                                                                                   "IC_ME_HIDE_CC_LANE_124",                    NULL, NULL, 124, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 125" },                                                                                   "IC_ME_HIDE_CC_LANE_125",                    NULL, NULL, 125, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 126" },                                                                                   "IC_ME_HIDE_CC_LANE_126",                    NULL, NULL, 126, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 127" },                                                                                   "IC_ME_HIDE_CC_LANE_127",                    NULL, NULL, 127, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Pitch" },                                                                                 "IC_ME_HIDE_CC_LANE_128",                    NULL, NULL, 128, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Program" },                                                                               "IC_ME_HIDE_CC_LANE_129",                    NULL, NULL, 129, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Channel Pressure" },                                                                      "IC_ME_HIDE_CC_LANE_130",                    NULL, NULL, 130, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Program/Bank Select" },                                                                   "IC_ME_HIDE_CC_LANE_131",                    NULL, NULL, 131, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Text Events" },                                                                           "IC_ME_HIDE_CC_LANE_132",                    NULL, NULL, 132, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Sysex" },                                                                                 "IC_ME_HIDE_CC_LANE_133",                    NULL, NULL, 133, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 00/32 14-bit Bank Select" },                                                              "IC_ME_HIDE_CC_LANE_134",                    NULL, NULL, 134, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 01/33 14-bit Mod Wheel" },                                                                "IC_ME_HIDE_CC_LANE_135",                    NULL, NULL, 135, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 02/34 14-bit Breath" },                                                                   "IC_ME_HIDE_CC_LANE_136",                    NULL, NULL, 136, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 03/35 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_137",                    NULL, NULL, 137, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 04/36 14-bit Foot Pedal" },                                                               "IC_ME_HIDE_CC_LANE_138",                    NULL, NULL, 138, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 05/37 14-bit Portamento" },                                                               "IC_ME_HIDE_CC_LANE_139",                    NULL, NULL, 139, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 06/38 14-bit Data Entry" },                                                               "IC_ME_HIDE_CC_LANE_140",                    NULL, NULL, 140, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 07/39 14-bit Volume" },                                                                   "IC_ME_HIDE_CC_LANE_141",                    NULL, NULL, 141, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 08/40 14-bit Balance" },                                                                  "IC_ME_HIDE_CC_LANE_142",                    NULL, NULL, 142, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 09/41 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_143",                    NULL, NULL, 143, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 10/42 14-bit Pan Position" },                                                             "IC_ME_HIDE_CC_LANE_144",                    NULL, NULL, 144, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 11/43 14-bit Expression" },                                                               "IC_ME_HIDE_CC_LANE_145",                    NULL, NULL, 145, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 12/44 14-bit Control 1" },                                                                "IC_ME_HIDE_CC_LANE_146",                    NULL, NULL, 146, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 13/45 14-bit Control 2" },                                                                "IC_ME_HIDE_CC_LANE_147",                    NULL, NULL, 147, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 14/46 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_148",                    NULL, NULL, 148, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 15/47 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_149",                    NULL, NULL, 149, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 16/48 14-bit GP Slider 1" },                                                              "IC_ME_HIDE_CC_LANE_150",                    NULL, NULL, 150, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 17/49 14-bit GP Slider 2" },                                                              "IC_ME_HIDE_CC_LANE_151",                    NULL, NULL, 151, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 18/50 14-bit GP Slider 3" },                                                              "IC_ME_HIDE_CC_LANE_152",                    NULL, NULL, 152, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 19/51 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_153",                    NULL, NULL, 153, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 20/52 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_154",                    NULL, NULL, 154, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 21/53 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_155",                    NULL, NULL, 155, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 22/54 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_156",                    NULL, NULL, 156, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 23/55 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_157",                    NULL, NULL, 157, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 24/56 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_158",                    NULL, NULL, 158, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 25/57 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_159",                    NULL, NULL, 159, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 26/58 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_160",                    NULL, NULL, 160, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 27/59 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_161",                    NULL, NULL, 161, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 28/60 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_162",                    NULL, NULL, 162, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 29/61 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_163",                    NULL, NULL, 163, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 30/62 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_164",                    NULL, NULL, 164, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane 31/63 14-bit" },                                                                          "IC_ME_HIDE_CC_LANE_165",                    NULL, NULL, 165, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Notation Events" },                                                                       "IC_ME_HIDE_CC_LANE_166",                    NULL, NULL, 166, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },
	{ { DEFACCEL, "SWS/IC: Hide CC Lane Velocity Off" },                                                                          "IC_ME_HIDE_CC_LANE_167",                    NULL, NULL, 167, NULL, SECTION_MIDI_EDITOR, ME_HideCCLane },

	{ {}, LAST_COMMAND}
};
//!WANT_LOCALIZE_1ST_STRING_END

/******************************************************************************
* IC init/exit                                                                *
******************************************************************************/
int IC_Init ()
{
	// Register actions
	SWSRegisterCommands(g_commandTable);

	return 1;
}

void IC_Exit ()
{
}
