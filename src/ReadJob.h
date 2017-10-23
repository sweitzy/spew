//////////////////////////  -*-C++-*- /////////////////////////////////////////
//
// ReadJob.h
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

#ifndef READJOB_H
#define READJOB_H

#include "Job.h"

class ReadJob: public Job
{
public:
   ReadJob(Log &logger,
           const string &fileName,
           capacity_t offset,
           capacity_t transferSize,
           capacity_t minBufferSize,
           capacity_t maxBufferSize,
           TransferInfoList::buffer_size_method_t bufferSizeMethod,
           pattern_t pattern,
			  unsigned char userPattern,
           TransferInfoList::fill_method_t fillMethod,
           io_method_t ioMethod,
           u32_t seed,
           capacity_t jobId);

   virtual int startJob();
   virtual int finishJob();

   virtual int runTransfers(capacity_t numTransfers, bool continueAfterError);

   ~ReadJob() {};

private:
   ReadJob();               // Hide default constructor.
   ReadJob(const ReadJob&); // Hide copy constructor.
};

#endif // READJOB_H
