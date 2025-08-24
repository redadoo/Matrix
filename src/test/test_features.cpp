#include "Maft.hpp"
#include "../utils/hash.hpp"
#include <unordered_map>

using namespace Maft;

void test_hash()
{
    std::unordered_map<Vector2i, std::string> map2;
    map2[{1, 2}] = "hello";
    map2[{3, 4}] = "world";

    for (auto &kv : map2) {
        std::cout << "vec2(" << kv.first.x << "," << kv.first.y
                  << ") -> " << kv.second << "\n";
    }

    std::unordered_map<Vector3i, int> map3;
    map3[{1,2,3}] = 42;
    map3[{4,5,6}] = 99;

    std::cout << "vec3(1,2,3) = " << map3[{1,2,3}] << "\n";
    std::cout << "vec3(4,5,6) = " << map3[{4,5,6}] << "\n";
}