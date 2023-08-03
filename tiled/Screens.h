#pragma once
#include <cstddef>
#include <vector>
#include <string>
#include <map>

struct IGameScreen;

class Screens final {
	static std::vector<IGameScreen*> screens;
	static std::map<std::string, size_t> names;

public:
	enum Builtin {
		MESSAGES
	};

	static IGameScreen *getByName(const char *name);
	static IGameScreen *getById(size_t id);
	static size_t registerScreen(IGameScreen *screen, const char *name);
};