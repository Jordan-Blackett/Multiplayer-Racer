#pragma once

#include <vector>
#include <string>

class FileManager
{
public:
	FileManager();
	~FileManager();

	void LoadContent(const char* filename, std::vector<std::vector<std::string>> attributes,
						std::vector<std::vector<std::string>> contents);
};

