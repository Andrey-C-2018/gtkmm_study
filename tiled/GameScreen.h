#pragma once
#include <vector>
#include "IGameScreen.h"
#include "IEventsHandler.h"
#include "IDrawable.h"

class GameScreen : public IGameScreen, public IDrawable {
	enum Constants {
		DEF_TEXT_SIZE = 24
	};
	struct CellProperties {
		Color color;
		std::string text;
	};

	Gtk::DrawingArea *parent;
	int cell_width, cell_height;
	std::vector<std::vector<CellProperties>> cells;
	size_t cols, rows;
	Pango::FontDescription font;

	void drawText(const DrawingContext &cr, \
					double x, double y, const char *text);

public:
	explicit GameScreen(Gtk::DrawingArea *parent);

	GameScreen(const GameScreen &obj) = delete;
	GameScreen(GameScreen &&obj) = default;
	GameScreen &operator=(const GameScreen &obj) = delete;
	GameScreen &operator=(GameScreen &&obj) = default;

	void screenSizeChanged(const Gtk::Allocation &allocation);
	size_t getColByXCoord(gdouble x) const;
	size_t getRowByYCoord(gdouble y) const;

	void setSize(size_t cols, size_t rows, Color def_color) override;
	void setCellColor(size_t col, size_t row, Color color) override;
	void setCellText(size_t col, size_t row, const char *text) override;
	bool draw(const DrawingContext &cr) override;
	void redraw() override;
	void reset(Color color) override;

	virtual ~GameScreen();
};
