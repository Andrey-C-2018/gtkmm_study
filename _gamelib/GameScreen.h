#pragma once
#include <memory>
#include <vector>
#include "IGameScreen.h"
#include "IEventsHandler.h"
#include "IDrawable.h"

class GameScreen : public IGameScreen, public IDrawable {
	struct CellProperties {
		Color color;
		std::string text;
	};

	Gtk::DrawingArea *parent;
	std::vector<std::vector<CellProperties>> cells;
	size_t cols, rows;

	void drawText(const DrawingContext &cr, \
					double x, double y, const char *text);

public:
	explicit GameScreen(Gtk::DrawingArea *parent);

	GameScreen(const GameScreen &obj) = delete;
	GameScreen(GameScreen &&obj) = default;
	GameScreen &operator=(const GameScreen &obj) = delete;
	GameScreen &operator=(GameScreen &&obj) = default;

	void setSize(size_t cols, size_t rows, Color def_color) override;
	void setCellColor(size_t col, size_t row, Color color) override;
	void setCellText(size_t col, size_t row, const char *text) override;
	bool draw(const DrawingContext &cr, \
				int screen_width, int screen_height) override;
	void reset(Color color) override;

	virtual ~GameScreen();
};
