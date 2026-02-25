template <typename T>
class Vector {
    private:
        T x,y;

    public:
        Vector(T x_, T y_): x(x_), y(y_) {}

        template <typename U>
        Vector operator+ (const Vector<U>& other) const {
            return Vector(x + other.x, y +other.y);
        }

        friend std::ostream& operator<< (std::ostream& os, const Vector& v) {
            os << "(" << v.x << ", " << v.y << ")" ;
            return os;
        }
};

int main() {
    
    Vector<double> vd(1.5, 2.5);
    Vector<int> vi(1,2);

    auto r = vd + vi;
    
    return 0;
}