#pragma once
#include <gtkmm/drawingarea.h>
#include "GameScreen.h"

struct IEventsHandler;
typedef std::unique_ptr<IEventsHandler> EvtHandlerPtr;

class GameField : public Gtk::DrawingArea {
	GameScreen game_screen;
	EvtHandlerPtr evt_handler;

protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	bool on_button_press_event(GdkEventButton *event) override;
	bool on_button_release_event(GdkEventButton *event);
	bool on_key_press_event(GdkEventKey *event) override;
	bool on_key_release_event(GdkEventKey *event) override;

public:
	GameField();

	GameField(const GameField &obj) = delete;
	GameField(GameField &&obj) = default;
	GameField &operator=(const GameField &obj) = delete;
	GameField &operator=(GameField &&obj) = default;

	void init(EvtHandlerPtr evt_handler);

	virtual ~GameField();
};
