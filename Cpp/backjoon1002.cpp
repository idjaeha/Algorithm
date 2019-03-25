#include <iostream>
#include <vector>
#include <math.h>

#define square(x) ((x) * (x))

using namespace std;

class turret {
private:
	float x1, y1, r1, x2, y2, r2;

public:
	turret(float x1, float y1, float r1, float x2, float y2, float r2) {
		this->x1 = x1;
		this->y1 = y1;
		this->r1 = r1;
		this->x2 = x2;
		this->y2 = y2;
		this->r2 = r2;
	}

	int Calculate() {
		float r1r2 = square(r1 + r2);
		float dist = square(x2 - x1) + square(y2 - y1);


		//원의 중심이 같을 때 
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				return -1;
			}
			else {
				return 0;
			}
		}
		
		// 원의 중심이 내부에 있을 때
		else if (dist <= r1 || dist <= r2) {
			if (square(r1 - r2) == dist) {
				return 1;
			}
			else if (square(r1 - r2) > dist){
				return 0;
			}
			else {
				return 2;
			}
		}

		// 원의 중심이 외부에 있을 때 
		else if (dist < r1r2) {
			return 2;
		}
		else if (dist == r1r2) {
			return 1;
		}
		else {
			return 0;
		}
	}
};

int main() {
	int nums;
	float x1, y1, r1, x2, y2, r2;
	vector<turret *> turretVec;
	cin >> nums;
	for (int i = 0; i < nums; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		turretVec.push_back(new turret(x1, y1, r1, x2, y2, r2));
	}

	for (int i = 0; i < nums; i++) {
		cout << turretVec[i]->Calculate() << endl;
	}
}
