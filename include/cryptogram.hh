#pragma once

#include <string>
#include <unordered_map>

class Cryptogram {
  public:
  void static generateMap(std::unordered_map<char, int>& umap);

  private:
  int static generateRandInt();
};