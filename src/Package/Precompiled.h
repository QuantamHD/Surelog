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
 * File:   Precompiled.h
 * Author: alain
 *
 * Created on April 28, 2018, 10:27 AM
 */
#ifndef PRECOMPILED_H
#define PRECOMPILED_H

#include <filesystem>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace fs = std::filesystem;

class Precompiled final {
 public:
  static Precompiled* getSingleton();

  void addPrecompiled(const std::string& package_name,
                      const std::string& fileName);

  std::string getFileName(const std::string& packageName) const;
  bool isFilePrecompiled(const fs::path& fileName) const;
  bool isPackagePrecompiled(const std::string& package) const;

 private:
  Precompiled();  // Only accessed via singleton.
  Precompiled(const Precompiled&) = delete;

  struct fs_path_hash final {
    std::size_t operator()(const fs::path& path) const {
      return fs::hash_value(path);
    }
  };

  std::unordered_map<std::string, std::string> m_packageMap;
  std::unordered_set<fs::path, fs_path_hash> m_packageFileSet;
};

#endif /* PRECOMPILED_H */
