//FlyingPoints.h

class FlyingPoints{
int in, out;
void updateBalance();

public:
FlyingPoints();
FlyingPoints(int, int);
void display() const;
FlyingPoints& operator +=(const FlyingPoints&);
friend bool operator == (const FlyingPoints&, const FlyingPoints&);
};

FlyingPoints operator +(const FlyingPoints&, const FlyingPoints&);
