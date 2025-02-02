/*
 Copyright 2019 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   PackageAndRootElaboration.h
 * Author: alain
 *
 * Created on June 3, 2019, 10:02 PM
 */

#ifndef PACKAGEANDROOTELABORATION_H
#define PACKAGEANDROOTELABORATION_H

#include "DesignCompile/CompileDesign.h"
#include "DesignCompile/ElaborationStep.h"

namespace SURELOG {

class PackageAndRootElaboration : public ElaborationStep {
 public:
  PackageAndRootElaboration(CompileDesign* compileDesign)
      : ElaborationStep(compileDesign) {}

  ~PackageAndRootElaboration() override;

  bool elaborate() override;

 private:
};

};  // namespace SURELOG

#endif /* PACKAGEANDROOTELABORATION_H */
