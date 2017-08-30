#ifndef ATOM_H
#define ATOM_H
#include <glog/logging.h>
#include <complex>
#include <array>
namespace atom
{
  template <unsigned long DIM>
    class Atom
    {
    public:
      Atom() = default;
      virtual ~Atom() = default;
    protected:
      std::array<double,DIM> pos;
      std::array<double,DIM> vel;
    private:
    };

  template <unsigned long DIM>
    class PointParticle: public Atom<DIM>
    {
    public:
      PointParticle() = default;
      virtual ~PointParticle()=default;
    };
}
#endif
