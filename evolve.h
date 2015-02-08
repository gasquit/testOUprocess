#ifndef _EVOLVE_OU_H
#define _EVOLVE_OU_H
#include <vector>

class Evolver{
    public:
        static double dt;

        Evolver(double k, double sigma);
        void operator()(std::vector<double>& Xvec, std::vector<double>& Zvec);

    private:
        double A, B;

};
#endif
