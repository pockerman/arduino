#include "two_motors_vehicle.h"

TwoMotorsVehicle::TwoMotorsVehicle(int rdirpin,int rpwmpin,int ldirpin,int lpwmpin,int max_speed)
:
r_(rdirpin,rpwmpin,max_speed),
l_(ldirpin,lpwmpin,max_speed)
{}
