#include <iostream>
#include "FileReader.h"
#include "PolyLine.h"
#include "Utils.h"

int main()
{
    std::string filePath;
    std::string target;

    std::cout << "File path:" << std::endl;
    std::cin >> filePath;

    std::cout << "Target:" << std::endl;
    std::cin >> target;

    Vec3 targetVec;
    if (!GetVec3FromStr(target, targetVec))
        std::cout << "Error: wrong target" << std::endl;

    FileReader loader(filePath);
    if (!loader.LoadData())
        std::cout << "Error: wrong points data" << std::endl;

    PolyLine pLine(loader.GetPointsData());
    pLine.FindNearPoint(targetVec);

    return 0;
}
