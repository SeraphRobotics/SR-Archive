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
#pragma once

#include <QObject>
#include <QtScript>

class AMFFile;
class SliceStack;
class PathStack;
class AMFRegion;

/**
 * Holds intermediate region information used in the tool-script.  This
 * method stores the source geometry as well as paths and slices for the
 * given mesh region.
 */
class AMFRegionTSI : public QObject {
  Q_OBJECT

public:
    AMFRegionTSI(AMFRegion* region);
    virtual ~AMFRegionTSI();

    /**
     * Every AMF region is given a *globally* unique name consisting of some
     * random characters.  This is because every region must have its own
     * variable in the script.
     */
    QString uniqueName();

    const AMFRegion* region();

    void setSlices(SliceStack* slices);

    /**
     * Obtains the set of slices computed for this region, or returns null
     * if they do not yet exist.
     */
    SliceStack* slices();

    /**
      Sets paths equal to paths_.
      @param paths The new PathStack that is set equal to paths_
      */
    void setPaths(PathStack* paths);

    /**
      Adds paths to the current PathStack paths_
      @param paths The new PathStack whose slices should be appended to paths_
      */


    void addPaths(PathStack* paths);
    /**
     * Gets the set of paths computed for this region, or returns null
     * if they do not yet exist.
     */
    PathStack* paths();


private:
    QString unique_name_;
    AMFRegion* region_;
    SliceStack* slices_;
    PathStack* paths_;
};

