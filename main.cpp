#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Sparse>

using namespace std;
using namespace Eigen;

class node;

class coordinates {
    protected:
    VectorXd coorcomp;


    public:

    coordinates(double a,double b,double c) {
        coorcomp.resize(3);
        coorcomp(0) = a;
        coorcomp(1) = b;
        coorcomp(2) = c;
    };
    coordinates(double a,double b) {
        coorcomp.resize(2);
        coorcomp(0) = a;
        coorcomp(1) = b;
    };
    coordinates(double a) {
        coorcomp.resize(1);
        coorcomp(0) = a;
    };
    coordinates() {

    };

//    coordinates operator + (coordinates param) {
//        coordinates temp;
//        int ndim1 = coorcomp.size();
//        int ndim2 = param.coorcomp.size();
//        if (ndim1 != ndim2) {
//            cout << "Error: trying to sum different sizes coordinates!" << endl;
//            exit(0);
//        };
//        double a,b,c;
//        switch (ndim1) {
//            case 3:
//                a = coorcomp(0) + param.coorcomp(0);
//                b = coorcomp(1) + param.coorcomp(1);
//                c = coorcomp(2) + param.coorcomp(2);
//                temp.coorassign(a,b,c);
//                return(temp);
//                break;
//            case 2:
//                a = coorcomp(0) + param.coorcomp(0);
//                b = coorcomp(1) + param.coorcomp(1);
//                temp.coorassign(a,b);
//                return(temp);
//                break;
//            case 1:
//                a = coorcomp(0) + param.coorcomp(0);
//                temp.coorassign(a);
//                return(temp);
//                break;
//            case 0:
//                cout << "Error: coordinates undefined!" << endl;
//                exit(0);
//                break;
//        };
//
//    };

    coordinates operator + (coordinates param) {
        int ndim1 = coorcomp.size();
        int ndim2 = param.coorcomp.size();
        if (ndim1 != ndim2) {
            cout << "Error: trying to sum different sizes coordinates!" << endl;
            exit(0);
        };
        double a,b,c;
        switch (ndim1) {
            case 3:
                a = coorcomp(0) + param.coorcomp(0);
                b = coorcomp(1) + param.coorcomp(1);
                c = coorcomp(2) + param.coorcomp(2);
                this -> coorassign(a,b,c);
                return *this;
                break;
            case 2:
                a = coorcomp(0) + param.coorcomp(0);
                b = coorcomp(1) + param.coorcomp(1);
                this -> coorassign(a,b);
                return *this;
                break;
            case 1:
                a = coorcomp(0) + param.coorcomp(0);
                this -> coorassign(a);
                return *this;
                break;
            case 0:
                cout << "Error: coordinates undefined!" << endl;
                exit(0);
                break;
        };

    };


    void coorassign(double a,double b,double c) {
        coorcomp.resize(3);
        coorcomp(0) = a;
        coorcomp(1) = b;
        coorcomp(2) = c;
    };
    void coorassign(double a,double b) {
        coorcomp.resize(2);
        coorcomp(0) = a;
        coorcomp(1) = b;
    };
    void coorassign(double a) {
        coorcomp.resize(1);
        coorcomp(0) = a;
    };

    void coorprint() {
        int ndim = coorcomp.size();
        switch (ndim) {
            case 3:
                cout << "x = " << coorcomp(0) << ", y = "
                << coorcomp(1) << ", z = " << coorcomp(2) << endl;
                break;
            case 2:
                cout << "x = " << coorcomp(0) << ", y = "
                << coorcomp(1) << endl;
                break;
            case 1:
                cout << "x = " << coorcomp(0) << endl;
                break;
            case 0:
                cout << "Error: coordinates undefined!" << endl;
                exit(0);
                break;
        }
    }

    friend class node;
};

class node : public coordinates{

    int nodeindex;

    public:

    node (int a, coordinates param) {
        nodeindex = a;
        this -> coorcomp = param.coorcomp;
    }
    node (int a, double b, double c, double d) {
        nodeindex = a;
        this -> coorassign(b,c,d);
    };
    node (int a, double b, double c) {
        nodeindex = a;
        this -> coorassign(b,c);
    };
    node (int a, double b) {
        nodeindex = a;
        this -> coorassign(b);
    };
    node (int a) {
        nodeindex = a;
    };
    node () {
    };



    void nodeprint() {
        cout << "Node " << nodeindex << ": ";
        this -> coorprint();
    };

};

int main()
{

    node n_1(250,1,2,3);

    n_1.nodeprint();

    coordinates c_1(10,11);
    node n_2(1500,c_1);

    n_2.nodeprint();


    return 0;
}
