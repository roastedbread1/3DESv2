#include <string>
#include <vector>
#include "DES.h"
std::string TDES(std::string mode, std::vector<std::string> rkeys1,std::vector<std::string> rkeys2, std::vector<std::string> rkeys3, std::string pt) {
    std::string pt1, pt2, pt3;
    if(mode=="E") {
        pt1 = DES("E", rkeys1, pt);
        pt2 = DES("D", rkeys2, pt1);
        pt3 = DES("E", rkeys3, pt2); 
    } else if (mode=="D") {
        pt1 = DES("D", rkeys3, pt);
        pt2 = DES("E", rkeys2, pt1);
        pt3 = DES("D", rkeys1, pt2);
    }
    return pt3;
}