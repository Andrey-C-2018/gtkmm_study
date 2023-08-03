#include <cassert>
#include <stdexcept>
#include "Screens.h"

std::vector<IGameScreen*> Screens::screens;
std::map<std::string, size_t> Screens::names;

IGameScreen *Screens::getByName(const char *name) {

	assert (name);
	auto p = names.find(name);
	if (p == names.end())
		throw std::logic_error(std::string("no such screen: ") + name);

	assert (p->second < screens.size());
	return screens[p->second];
}

IGameScreen *Screens::getById(size_t id) {

	assert (id < screens.size());
	return screens[id];
}

size_t Screens::registerScreen(IGameScreen *screen, const char *name) {

	assert (screen);
	assert (name);
	assert (names.find(name) == names.end());

	names[name] = screens.size();
	screens.push_back(screen);
	return screens.size() - 1;
}
