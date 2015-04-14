/*---------------------------------------------------------------------------*\
 This file is part of the Fab@Home Project.
 Fab@Home operates under the BSD Open Source License.

 Copyright (c) 2009, Karl Gluck (kwg8@cornell.edu)

 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the <organization> nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\*---------------------------------------------------------------------------*/
#include "slicestacktsi.h"

SliceStackTSI::SliceStackTSI(QScriptEngine& engine,
                             const SliceStack slice_stack)
  :  ToolScriptInterface(engine),
     slices_(slice_stack)
{}

SliceStackTSI::SliceStackTSI(QScriptEngine& engine)
    : ToolScriptInterface(engine){}

const SliceStack& SliceStackTSI::slices() const{
    return slices_;
}

int SliceStackTSI::getNumberOfSlices()
{
    return slices_.getSlices().size();
}

QScriptValue SliceStackTSI::getSlices(int startSlice, int endSlice)
{
    SliceStack new_slice_stack;
    for (int i = startSlice; i <= endSlice; i++)
        new_slice_stack.addSlice(slices_.getSlices().at(i));
    const SliceStack slice_stack(new_slice_stack);
    return newQObject(new SliceStackTSI(engine(), slice_stack));
}
/*
QScriptValue SliceStackTSI::getSlices(double startPercentage, double endPercentage)
{
    return getSlices(startPercentage * getNumberOfSlices(), endPercentage * getNumberOfSlices());
}
*/


