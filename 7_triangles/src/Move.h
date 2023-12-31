#pragma once
#include <cstddef>

class Move final {
	size_t l;
	size_t r;

public:
	inline Move(size_t left_, size_t right_) : l(left_), r(right_) { }

	inline bool operator==(const Move &obj) const { return l == obj.l && r == obj.r; }
	inline bool operator!=(const Move &obj) const { return !operator==(obj); }

	inline size_t left() const { return l; }
	inline size_t right() const { return r; }

	inline bool empty() const { return l == r; }

	static inline Move createEmpty() { return {0, 0}; }
};
