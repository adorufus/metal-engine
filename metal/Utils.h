#pragma once
#include <map>
class Utils {
public:
	static bool animContainsKey(std::map<const char*, Animation>& animMap, const char* key) {
		if (animMap.find(key) == animMap.end()) return false;
		return true;
	}
};