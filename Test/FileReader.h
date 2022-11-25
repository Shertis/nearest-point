#pragma once
#include <string>
#include <vector>
#include "Math.h"

/**
 * Implementation of loading data with points from a file
 */
class FileReader
{
public:
	FileReader(const std::string& iFileName);

/**
 * loading point data from given file
 *
 * @return returns true or false depending on the result of loading from file
 */
	bool LoadData();

/**
 * returns points loaded from file 
 * if the file is empty or with an error, then will be returned empty vector 
 *
 * @return returns a vector of points
 */
	std::vector<MathUtils::Vec3> GetPointsData();

private:

	std::string m_filePath;
	std::vector<MathUtils::Vec3> m_loadedData;

};

