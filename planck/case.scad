// -*- mode: c -*-
/* All distances are in mm. */

$fn = 50;
cx = 233;
cy = 81;
cz = 8;
cw = 4;
ux = 35;
uw = 10;
uz = 5;
bz = 0;//4;

difference() {
    cube([cx, cy, bz+cz], center=false);
    translate([cw, cw, bz]) { cube([cx - cw*2, cy - cw*2, cz*2], center=false); }
    translate([ux, cy - cw*2, bz]) { cube([uw, cw*4, uz], center=false); }
 }