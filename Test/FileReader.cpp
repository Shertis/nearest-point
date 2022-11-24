#include "FileReader.h"

#include <fstream>
#include <sstream>
#include "Utils.h"

FileReader::FileReader(const std::string& iFileName)
    : m_filePath(iFileName)
{
}

bool FileReader::LoadData()
{
    std::ifstream istr;
    istr.open(m_filePath, std::ifstream::in);

    if (istr.fail())
        return false;

    std::string line;

    while (!istr.eof())
    {
        std::getline(istr, line);

        MathUtils::Vec3 vec;
        if (GetVec3FromStr(line, vec))
            m_loadedData.emplace_back(vec);
        else
            return false; 
    }

    return true;
}

std::vector<MathUtils::Vec3> FileReader::GetPointsData()
{
    return m_loadedData;
}