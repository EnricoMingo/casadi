#include <panoc-alm/alm.hpp>
#include <panoc-alm/inner/lbfgs.hpp>
#include <panoc-alm/inner/panoc.hpp>

namespace pa {
template class ALMSolver<PANOCSolver<LBFGS>>;
}