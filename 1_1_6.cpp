#include <glog/logging.h>
#include <string>
#include <iostream>

using namespace std;

class Point{
    public:
        Point(float xval);
        virtual ~Point();

        float x() const;
        static int PointCount();

    protected:
        virtual ostream& print(ostream& os) const;

        int x_;
        static int point_count_ ;
};

int main(int argv, char** argc[])
{   
    cout << sizeof(Point) << endl;

    return 0;
}