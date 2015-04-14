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
#include "doubleedgepather.h"
#include "path.h"
#include <QString>
#include <QTextStream>
#include <QDebug>

DoubleEdgePather::DoubleEdgePather()
  : initialized_(false),
    path_width_(0.0) {
}



void DoubleEdgePather::initialize() {
  if (!initialized_) {
    initialized_ = true;
    path_width_ = getSettings().get("PathWidth", 1.5f);
  }
}


bool DoubleEdgePather::runPathingAlgorithm(
        const SliceMaterialRegion& region,
        PathSliceRegion* returned_paths,
        PatherProgressCallback* callback) {
  initialize();

  { // Add all inner loops to returned paths
    foreach (const FAHLoopInXYPlane& boundary, region.getInnerBoundaries()) {
      addPaths(boundary, returned_paths, callback, false);
    }
  }

  addPaths(region.getOuterBoundary(), returned_paths, callback, true);

  // Success
  return true;
}

void DoubleEdgePather::addPaths(const FAHLoopInXYPlane& loop,
                                PathSliceRegion* returned_paths,
                                PatherProgressCallback* callback,
                                bool is_outer_loop) {
  // expanded[0] is the loop offset by half a path-width
  // expanded[1] is the expanded[0] offset by a path-width
  QVector<FAHLoopInXYPlane> expanded[2];
  loop.expand((is_outer_loop ? -0.5 : -0.5) * path_width_, &expanded[0]);
  loop.expand((is_outer_loop ? -1.5 : -1.5) * path_width_, &expanded[1]);
  if (expanded[0].size() != 1 || expanded[1].size() != 1) {
    {
      QString issue;
      QTextStream(&issue) << "Expanded edge broken; using only primary edge loop";
      if (callback) callback->encounteredIssue(issue);
    }
    // just add the plus loops; no doubling
    returned_paths->addPath(loop);
  } else {
    FAHLoopInXYPlane inner_first_half(expanded[1].first()),
                     inner_second_half(expanded[1].first());
    int size = expanded[1].first().points.size();
    int half_size = size / 2;
    inner_first_half.points.remove(half_size, size - half_size);
    inner_second_half.points.remove(0, half_size);

    Path p;
    p.append(inner_second_half.points);
    p.addPathPointEnd(inner_first_half.points.first());
    p.appendReversed(expanded[0].first());
    //p.addPathPointEnd(expanded[0].first().points.last());
    p.append(inner_first_half.points);
    p.addPathPointEnd(inner_second_half.points.first());

    returned_paths->addPath(p);
  }

}
