#include <iostream>
#include "FileReader.h"
#include "PolyLine.h"
#include "Utils.h"

int main()
{
    std::string filePath;
    std::string target;

    std::cout << "File path:" << std::endl;
    std::getline(std::cin, filePath);

    std::cout << "Target:" << std::endl;
    std::getline(std::cin, target);

    MathUtils::Vec3 targetVec;
    if (!GetVec3FromStr(target, targetVec))
        std::cout << "Error: wrong target" << std::endl;

    FileReader loader(filePath);
    if (!loader.LoadData())
        std::cout << "Error: wrong points data" << std::endl;

    PolyLine pLine(loader.GetPointsData());
    auto result = pLine.FindNearPoint(targetVec);

    for (const auto& resPoint : result)
        std::cout << "segment " << resPoint.segment << " point " << resPoint.Point.x << " " << resPoint.Point.y << " " << resPoint.Point.z << std::endl;

    return 0;
}
