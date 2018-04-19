//
// Created by luca on 18/12/17.
//

#include "Numero.h"

double Numero::pi=3.1415926535;
double Numero::e=2.71828;

double Numero::rad_to_deg(double r) {
    return r*180/pi;
}

double Numero::deg_to_rad(double g) {
    return g*pi/180;
}

static double Numero::subparse(std::string s){
  std::size_t pos = s.find(".");
  double p_int=0, p_dec=0;
  if(pos!=-1){
    for(auto it=s[pos-1], int esp=0; it!=s.cbegin(); --it, ++esp)
      p_int=p_int+(*it)*pow(10,esp);
    for(auto it=s[pos+1], int esp=0; it!=s.cbegin(); ++it, --esp)
      p_dec=p_dec+(*it)*pow(10,esp);
  }
  else{
    auto it=s.cend();
    for(int esp=0; it!=s.cbegin(); --it, ++esp)
      p_int=p_int+(*it)*pow(10,esp);
  }
  return p_int+p_dec;
}
