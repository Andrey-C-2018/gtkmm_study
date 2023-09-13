#pragma once
#include <gtkmm/drawingarea.h>
#include "GameScreen.h"

struct IEventsHandler;
typedef std::shared_ptr<IEventsHandler> EvtHandlerPtr;

class GameField : public Gtk::DrawingArea {
	GameScreen game_screen;
	EvtHandlerPtr evt_handler;
    sigc::connection timer_conn;

protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
	bool on_button_press_event(GdkEventButton *event) override;
	bool on_button_release_event(GdkEventButton *event) override;
	bool on_key_press_event(GdkEventKey *event) override;
	bool on_key_release_event(GdkEventKey *event) override;
    bool on_timeout(int timer_number);

public:
	GameField();

	GameField(const GameField &obj) = delete;
	GameField(GameField &&obj) = default;
	GameField &operator=(const GameField &obj) = delete;
	GameField &operator=(GameField &&obj) = default;

	void init(EvtHandlerPtr evt_handler);
    void enableTimer();
    void disableTimer();

	~GameField() override;
};
