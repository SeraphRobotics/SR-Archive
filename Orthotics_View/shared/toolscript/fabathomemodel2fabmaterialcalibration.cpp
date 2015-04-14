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

#include "fabathomemodel2fabmaterialcalibration.h"
#include "pathstacktsi.h"
#include "shared/pather/pathstack.h"
#include <QDomElement>


FabAtHomeModel2FabMaterialCalibration::FabAtHomeModel2FabMaterialCalibration(QScriptEngine& engine, const QString& name)
  : ToolScriptInterface(engine), name_(name) {
  StringStringPair ssp("name", name);
  calibration_.push_back(ssp);
}


void FabAtHomeModel2FabMaterialCalibration::set(const QString& name, float value) {
  QString valueStr;
  StringStringPair ssp(name, valueStr.sprintf("%f", value));
  calibration_.push_back(ssp);
}


void FabAtHomeModel2FabMaterialCalibration::setInt(const QString& name, int value) {
  QString valueStr;
  StringStringPair ssp(name, valueStr.sprintf("%d", value));
  calibration_.push_back(ssp);
}


void FabAtHomeModel2FabMaterialCalibration::setPaths(QScriptValue path_stack) {
  PathStackTSI* path_stack_tsi = (PathStackTSI*)castTo(path_stack, "PathStackTSI");
  paths_ = &path_stack_tsi->paths();
}


const QString& FabAtHomeModel2FabMaterialCalibration::getName() const {
  return name_;
}


void FabAtHomeModel2FabMaterialCalibration::initCalibrationElement(QDomDocument& document, QDomElement& element) {
  for (int i = 0; i < calibration_.size(); ++i) {
    const StringStringPair& ssp = calibration_.at(i);
    QDomElement calibration_element = document.createElement(ssp.first);
    calibration_element.appendChild(document.createTextNode(ssp.second));
    element.appendChild(calibration_element);
  }
}

const PathStack* FabAtHomeModel2FabMaterialCalibration::getPathStack() const {
  return paths_;
}
