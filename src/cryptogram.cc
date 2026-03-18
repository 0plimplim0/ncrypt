#include "cryptogram.hh"

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>

// TODO: Improve chars mapping to support more chars
void Cryptogram::generateMap(std::unordered_map<char, int>& umap){
  const static char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'l', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  std::vector<int> nums;
  umap.insert({' ', 0});
  for (char c : chars) {
    int num;
    do {
      num = generateRandInt();
    } while ((std::find(nums.begin(), nums.end(), num)) != nums.end());
    umap.insert({c, num});
  }
}

int Cryptogram::generateRandInt() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<> dis(1, 50);

  return dis(gen);
}