// vector.cpp -- vector class using templates

#include <iostream>

template <typename T>
class Vector {
    private: 
        T vec_x, vec_y;

    public:
        Vector() {}
        Vector(T x_, T y_): vec_x(x_), vec_y(y_) {}
        
        Vector operator+ (const Vector &other) const {
            return Vector(vec_x + other.vec_x, vec_y + other.vec_y);
        }

        Vector operator+ (T scalar) const {
            return Vector(scalar + vec_x, scalar +vec_y);
        }

        friend Vector operator+ (T scalar, const Vector& v) {
            return Vector(v.vec_x + scalar, v.vec_y + scalar);
        }

        void print() const{
            std::cout << "x and y\n" << vec_x << ", " << vec_y << std::endl;
        }

        // improve print
        friend std::ostream& operator<< (std::ostream& os, const Vector& v) {
            os << "(" << v.vec_x << ", " << v.vec_y << ")";
            return os;
        }
};

int main () {
    Vector<double> v1(3.0, 2.5);
    Vector<int> v2(1, 2);

    Vector<double> v3 = v1 + v1;
    Vector<int> v4 = v2 + v2;

    std::cout << "v3 = ";
    v3.print();

    std::cout << "v4 = ";
    v4.print();

    std::cout << "v3: " << v3 << std::endl;

    Vector<int> v5 = v2 + 2;

    std::cout << "v5: " << v5 << std::endl;

    Vector<int> v6 = 2 + v2;

    std::cout << "v6: " << v6 << std::endl;

    

}