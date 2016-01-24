#pragma once

class ColAndRowUtil {
public:
	/*can be converted into a map, form a key with x & y to get value */
	inline static int composeRowValue(int x, int y) {
		if (x == 0 || x == 1 || x == 2) {
			if (y < 3) {
				return 0;
			}
			if (2 < y && y < 6) {
				return 1;
			}
			if (5 < y && y < 9) {
				return 2;
			}
		}
		if (x == 3 || x == 4 || x == 5) {
			if (y < 3) {
				return 3;
			}
			if (2 < y && y < 6) {
				return 4;
			}
			if (5 < y && y < 9) {
				return 5;
			}
		}
		if (x == 6 || x == 7 || x == 8) {
			if (y < 3) {
				return 6;
			}
			if (2 < y && y < 6) {
				return 7;
			}
			if (5 < y && y < 9) {
				return 8;
			}
		}
	}
	inline static int composeColumnValue(int x, int y) {
		if (x == 0 || x == 3 || x == 6) {
			if (y == 0 || y == 3 || y == 6) {
				return 0;
			}
			if (y == 1 || y == 4 || y == 7) {
				return 1;
			}
			if (y == 2 || y == 5 || y == 8) {
				return 2;
			}
		}
		if (x == 1 || x == 4 || x == 7) {
			if (y == 0 || y == 3 || y == 6) {
				return 3;
			}
			if (y == 1 || y == 4 || y == 7) {
				return 4;
			}
			if (y == 2 || y == 5 || y == 8) {
				return 5;
			}
		}
		if (x == 2 || x == 5 || x == 8) {
			if (y == 0 || y == 3 || y == 6) {
				return 6;
			}
			if (y == 1 || y == 4 || y == 7) {
				return 7;
			}
			if (y == 2 || y == 5 || y == 8) {
				return 8;
			}
		}
	}
};