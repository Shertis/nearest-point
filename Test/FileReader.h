#pragma once
#include <string>
#include <vector>
#include "Math.h"

class FileReader
{
public:
	FileReader(const std::string& iFileName);
	bool LoadData();

	std::vector<MathUtils::Vec3> GetPointsData();

private:

	std::string m_filePath;
	std::vector<MathUtils::Vec3> m_loadedData;

};

