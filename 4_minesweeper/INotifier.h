#pragma once

struct INotifier {

	virtual void onVictory() = 0;
	virtual void onDefeat() = 0;
	virtual void onReset() = 0;
	virtual void onMinesPlaced(size_t mines_count) = 0;
	virtual void onFlag(size_t flags_count) = 0;

	virtual ~INotifier() { }
};
