#pragma once
#include <memory>
#include <vector>
#include <gtkmm/drawingarea.h>
#include "IGameField.h"
#include "IGameEventsHandler.h"

class GameField : public Gtk::DrawingArea, public IGameField {
	struct CellProperties {
		Gdk::Color color;
		std::string text;
	};

	std::vector<std::vector<CellProperties>> cells;
	bool is_initialized;
	size_t cols, rows;
	std::unique_ptr<IGameEventsHandler> evt_handler;
	sigc::connection timer_conn;

protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	bool on_timeout(int timer_number);

public:
	GameField();

	GameField(const GameField &obj) = delete;
	GameField(GameField &&obj) = default;
	GameField &operator=(const GameField &obj) = delete;
	GameField &operator=(GameField &&obj) = default;

	void initScreen(size_t cols, size_t rows, Gdk::Color def_color, \
					std::unique_ptr<IGameEventsHandler> evt_handler) override;
	void setCellColor(size_t col, size_t row, Gdk::Color color) override;
	void setCellText(size_t col, size_t row, const char *text) override;

	void setTimer(unsigned duration) override;
	void stopTimer() override;

	void redraw() override;
	void reset(Gdk::Color color) override;

	virtual ~GameField();
};
