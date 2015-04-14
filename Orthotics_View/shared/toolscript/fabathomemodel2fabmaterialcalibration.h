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

#include "toolscriptinterface.h"
#include "shared/pather/pathstack.h"

class PathStack;
class QDomDocument;
class QDomElement;

class FabAtHomeModel2FabMaterialCalibration : public ToolScriptInterface {
  Q_OBJECT

  typedef QPair<QString, QString> StringStringPair;

public:
  FabAtHomeModel2FabMaterialCalibration(QScriptEngine& engine, const QString& name);


public slots:

  /**
   * Associates the given XML node name with some value in the materialCalibration
   * section of the FAB file.  This value is always printed with trailing decimal
   * places, even if they are all zeroes.
   */
  void set(const QString& name, float value);

  /**
   * Associates the given XML node name with some integer value in the materialCalibration
   * section of the FAB file.  This value will never be printed with a decimal place.
   */
  void setInt(const QString& name, int value);


  /**
   * Adds a set of paths to this fab-file writer.  If the path stack has
   * multiple materials, the materials will be written on each slice.
   */
  void setPaths(QScriptValue path_stack);

  /**
   * Returns the name of this material calibration.  This is the name
   * that should be used for each path associated with this material
   * as well.
   */
  const QString& getName() const;

  /**
   * Initializes the given XML document element with the calibration
   * settings that were added to this material by the print script.
   */
  void initCalibrationElement(QDomDocument& document, QDomElement& element);

  /**
   * Returns the set of paths associated with this material type
   */
  const PathStack* getPathStack() const;

private:
  QString name_;
  QList<StringStringPair> calibration_;
  const PathStack* paths_;
};

