#pragma once
#include <string>
#include <vector>
#include "Math.h"

class FileReader
{
public:
	FileReader(const std::string& iFileName);
	bool LoadData();

	std::vector<Vec3> GetPointsData();

private:
	void CloseFile();

	std::string m_filePath;
	std::vector<Vec3> m_loadedData;

};

