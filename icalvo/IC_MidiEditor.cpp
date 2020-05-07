/******************************************************************************
/ BR_MidiEditor.cpp
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
#include "IC_MidiEditor.h"
#include "../Fingers/RprMidiCCLane.h"
#include "../SnM/SnM.h"
#include "../SnM/SnM_Chunk.h"
#include "../SnM/SnM_Track.h"
#include "../SnM/SnM_Util.h"
#include "../reaper/localize.h"

/******************************************************************************
* Globals                                                                     *
******************************************************************************/

/******************************************************************************
* Commands: MIDI editor - Misc                                                *
******************************************************************************/
void ME_HideCCLane (COMMAND_T* ct, int val, int valhw, int relmode, HWND hwnd)
{
	int ccLaneId = (int)ct->user;
	RprMidiCCLanePtr laneView = RprMidiCCLane::createFromMidiEditor();

	int ccLaneIndex = 0;
	for (int i = 0; i < laneView->countShown(); ++i)
		if (laneView->getIdAt(i) == ccLaneId) {
			laneView->remove(i--);
			return;
		}
}

