#include <string>
#include <unordered_map>

class Cryptogram {
  private:
  void generateMap(std::unordered_map<char, int>& umap);
  int generateRandInt();
};