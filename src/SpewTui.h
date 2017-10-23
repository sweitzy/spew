//////////////////////////  -*-C++-*- /////////////////////////////////////////
//
// SpewTui.h
//
// Spew
//
// Copyright (C) 2004 Hewlett-Packard Corp.
//
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the
// Free Software Foundation version 2 of the License.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef SPEWTUI_H
#define SPEWTUI_H

#include <string>

#include "TimeHack.h"
#include "SpewDisplay.h"
#include "Tui.h"

class SpewTuiHelpWindow;
class SpewTuiProgressWindow;
class SpewTuiStatisticsWindow;
class SpewTuiStatusWindow;

class SpewTui: public SpewDisplay
{
public:
   static int sHelpWindowHeight;
   static int sHelpWindowWidth;
   static int sHelpWindowStartY;
   static int sHelpWindowStartX;
   
   static int sStatisticsWindowHeight;
   static int sStatisticsWindowWidth;
   static int sStatisticsWindowStartY;
   static int sStatisticsWindowStartX;
   
   static int sProgressWindowHeight;
   static int sProgressWindowWidth;
   static int sProgressWindowStartY;
   static int sProgressWindowStartX;

   static int sStatusWindowHeight;
   static int sStatusWindowWidth;
   static int sStatusWindowStartY;
   static int sStatusWindowStartX;

public:
   SpewTui(unsigned int iterationsToDo, 
           Units_t units,
           bool showProgress,
           Verbosity_t verbosity);  
   
   virtual int init();
   virtual int close();
   virtual int resize();


   virtual unsigned int getCurrentPauseLength() const;

   virtual unsigned int getCurrentNumVerticalHacks() const;
   virtual unsigned int getCurrentNumHorizontalHacks() const;

   virtual void hack();
   virtual void endHack();
   virtual void errorHack();
   virtual void errorEndHack();
   virtual void noHack();
   virtual void noEndHack();
   virtual void nextHackRow();

   virtual void intermediateStatistics(capacity_t hackRowBytesTransferred,
                                       const TimeHack& hackRowTransferTime,
                                       capacity_t jobBytesTransferred,
                                       const TimeHack& jobTransferTime,
                                       capacity_t bytesInJob,
                                       capacity_t totalBytesRead,
                                       const TimeHack& totalReadTransferTime,
                                       capacity_t totalBytesWritten,
                                       const TimeHack& totalWriteTransferTime,
                                       const TimeHack& totalRunTime);
   virtual void cumulativeStatistics(capacity_t jobBytesTransferred,
                                     const TimeHack& jobTransferTime,
                                     capacity_t jobOps,
                                     capacity_t totalBytesRead,
                                     const TimeHack& totalReadTransferTime,
                                     capacity_t totalReadOps,
                                     capacity_t totalBytesWritten,
                                     const TimeHack& totalWriteTransferTime,
                                     capacity_t totalWriteOps,
                                     const TimeHack& totalRunTime);

   virtual void startRun();
   virtual void endRun();
   virtual void startJob(unsigned int iteration, IoDirection_t direction);
   virtual void endJob();
   virtual void nextJob();


   ~SpewTui();

protected:
   virtual unsigned int getCurrentNumHackRows() const;
   virtual unsigned int getCurrentNumHackColumns() const;

private:
   void setWindowsDimensions(int screenRows, int screenColums);
   int checkScreenDimensions();
   void checkKeyboard();              // Check for key presses.
   void help();                       // Pause and put up the help screen.
   int getKey(bool block=false);      // Get a keypress.
   void pause(unsigned int timeout);  // Pause until keypress or timeout 
                                      // seconds.

private:
   SpewTui(); // Hide default constructor.

private:
   Tui *mTui;
   SpewTuiHelpWindow *mHelpWindow;
   SpewTuiProgressWindow *mProgressWindow;
   SpewTuiStatisticsWindow *mStatsWindow;
   SpewTuiStatusWindow *mStatusWindow;
};

#endif // SPEWTUI_H
