#include "evolve.h"
#include <algorithm>
#include <cmath>

Evolver::dt = 1/252.0

Evolver::Evolver(double k, double sigma){
    A = exp(-k*dt);
    B = sqrt((1-A*A)/2/k)*sigma;
}

void Evolver::operator()(
        std::vector<double> const& Xvec, 
        std::vector<double> const& Zvec,
        std::vector<double> & Xvec_next){
    std::vector<double>::iterator xp(Xvec.begin()), zp(Zvec.begin()), xp_next(Xvec_next.begin());
    while(xp!=Xvec.end()){
        *xp_next = A*(*xp) + B*(*zp);
        xp++;xp_next++;zp++;
    }
}


