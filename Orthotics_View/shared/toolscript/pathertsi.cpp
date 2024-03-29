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
#include "pathertsi.h"
#include "pathstacktsi.h"
#include "amfregiontsi.h"
#include "shared/pather/pathstack.h"

PatherTSI::PatherTSI(QScriptEngine& engine,
                     PatherImplementation implementation,
                     PatherProgressCallback* callback)
    : ToolScriptInterface(engine),
      pather_(implementation),
      callback_(callback) {
}


void PatherTSI::set(const QString& name, float value) {
  pather_.set(name, value);
}
//
//void PatherTSI::set(const QString& name, int value) {
//  pather_.set(name, value);
//}
//
//
//void PatherTSI::set(const QString& name, bool value) {
//  pather_.set(name, value);
//}
//
//
//void PatherTSI::set(const QString& name, const QString& value) {
//  pather_.set(name, value);
//}


void PatherTSI::doPathing(QScriptValue amf_region) {
  AMFRegionTSI* argument = (AMFRegionTSI*)castTo(amf_region, "AMFRegionTSI");

  if (!argument) {
    throwError("Invalid object passed to pather's doPathing()");
    return;
  }

  if (!argument->slices()) {
    throwError("AMF Region " + argument->uniqueName() + " has not been sliced");
    return;
  }

  if (!pather_.doPathing(*argument->slices(), callback_)) {
    throwError("Unable to perform pathing:  " + pather_.getLastErrorString());
    return;
  }

  // For debugging--pathstacks are usable with the VisualPather program to
  // get an image of each slice
//  pather_.getPathStack().writeToVisualizerFile("doubleedge.pathstack");

  argument->setPaths(new PathStack(pather_.getPathStack()));
}

void PatherTSI::doPathing(QScriptValue amf_region, QScriptValue slice_stack_script)
{
    AMFRegionTSI* argument = (AMFRegionTSI*)castTo(amf_region, "AMFRegionTSI");

    SliceStackTSI* slice_stack = (SliceStackTSI*)castTo(slice_stack_script, "SliceStackTSI");

    if (!argument) {
      throwError("Invalid object passed to pather's doPathing()");
      return;
    }

    if (!pather_.doPathing(slice_stack->slices(), callback_)) {
      throwError("Unable to perform pathing:  " + pather_.getLastErrorString());
      return;
    }

    // For debugging--pathstacks are usable with the VisualPather program to
    // get an image of each slice
//    pather_.getPathStack().writeToVisualizerFile("doubleedge.pathstack");

    argument->addPaths(new PathStack(pather_.getPathStack()));
}

void PatherTSI::setPather(int i)
{
    PatherImplementation imp = PatherInterface::getImplementation(i);
    pather_.setPather(imp);
}

QScriptValue PatherTSI::copy()
{
    PatherImplementation imp = PatherInterface::getImplementation(0);
    return newQObject(new PatherTSI(engine(),imp,callback_));
}
