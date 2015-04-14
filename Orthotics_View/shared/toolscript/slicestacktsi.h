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
#pragma once

#include <QtScript>
#include <QObject>
#include <QSharedPointer>
#include "shared/slicer/slicer.h"
#include "toolscriptinterface.h"

using namespace std;

class SliceStack;

/**
 * Intermediate type between the slicer and the pather
 */
class SliceStackTSI : public ToolScriptInterface {
  Q_OBJECT

public:

  SliceStackTSI(QScriptEngine& engine,
                               const SliceStack slice_stack);

  SliceStackTSI(QScriptEngine& engine);

  /**
   * Accessor when this class is passed to the pather TSI
   */
  const SliceStack& slices() const;

public slots:

    /**
      Gets a specific region of slices from the list of slices contained in slices_ starting from
      startSlice and ending with endSlice (inclusive and going from the bottom up).
      @param startSlice The starting slice of the region
      @param endSlice The ending slice of the region
      @return A QScriptValue representing a SliceStackTSI object made up of the region of slices from
      startSlice to endSlice.
      */
    QScriptValue getSlices(int startSlice, int endSlice);

    /**
      Gets a specific region of slices from the list of slices contained in slices_ starting from
      the slice at startPercentage and ending with the slice endPercentage
      (inclusive and going from the bottom up).
      @param startPercentage The starting percentage of the region
      @param endPercentage The ending percentage of the region
      @return A QScriptValue representing a SliceStackTSI object made up of the region of slices from
      startSlice to endSlice.
      */
    //QScriptValue getSlices(double startPercentage, double endPercentage);

    /**
      Return the number of slices there are in this SliceStackTSI
      @return The number of slices
      */
    int getNumberOfSlices();

private:
  const SliceStack slices_;
};


