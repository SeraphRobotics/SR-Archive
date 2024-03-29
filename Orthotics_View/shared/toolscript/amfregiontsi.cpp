/*---------------------------------------------------------------------------*\
 This file is part of the Fab@Home Project.
 Fab@Home operates under the BSD Open Source License.

 Copyright (c) 2010, Karl Gluck (kwg8@cornell.edu)

 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the Fab@Home nor the
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
#include "amfregiontsi.h"
#include "slicertsi.h"
#include "pathertsi.h"
#include "shared/slicer/slicestack.h"
#include "shared/pather/pathstack.h"

AMFRegionTSI::AMFRegionTSI(AMFRegion* region)
    : region_(region),
      slices_(0),
      paths_(0) {
  QString unique_name = QUuid::createUuid().toString();
  unique_name.remove(QChar('{'));
  unique_name.remove(QChar('}'));
  unique_name.remove(QChar('-'));
  QTextStream(&unique_name_) << "amfrgn_" << unique_name;
}

AMFRegionTSI::~AMFRegionTSI() {
  delete slices_;
  delete paths_;
}

QString AMFRegionTSI::uniqueName() {
  return unique_name_;
}

const AMFRegion* AMFRegionTSI::region() {
  return region_;
}

void AMFRegionTSI::setSlices(SliceStack* slices) {
  delete slices_;
  slices_ = slices;
}

SliceStack* AMFRegionTSI::slices() {
  return slices_;
}

void AMFRegionTSI::setPaths(PathStack* paths) {
  delete paths_;
  paths_ = paths;
}

void AMFRegionTSI::addPaths(PathStack* paths)
{
    if (paths_ == NULL)
        setPaths(paths);
    else
        paths_->appendPaths(paths);
}

PathStack* AMFRegionTSI::paths() {
  return paths_;
}

