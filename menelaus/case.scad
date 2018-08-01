// -*- mode: c -*-
/* All distances are in mm. */

$fn = 50;
angle = 10;
hole_radius = 1.5;
washer_radius = 3 * hole_radius;
spacing = 19;
hand_distance = spacing * 2;
switch_size = 13.97;
rows = 4;
cols = 5;
row_offset = 4;

module rz(angle, center=undef) translate(center) rotate(angle) translate(-center) children();
module mirrored() { children(); mirror ([1, 0, 0]) { children(); } }
module key(pos, size) translate(pos) square([size, size], center=true);
module hole(pos, size) translate(pos) circle(size);
module add_hand_distance() translate([0.5 * hand_distance, 0]) children();
module rotate_half() add_hand_distance() rz(angle, [hand_distance, spacing]) children();
module plate_bottom() difference() { hull() { holes(washer_radius); } holes(hole_radius); }
module plate_top() difference() { plate_bottom(); keys(switch_size); }

module keys(size) mirrored() rotate_half() {
  for (c =[0 : cols - 1]) for(r=[0 : rows - 1]) {
    offset = c == 2 && r != 0 ? 4 : c == row_offset ? -row_offset : 0;
    if (!(r == 0 && (c == 3 || c == 4))) key([c * spacing, r * spacing + offset], size);
  }
}

module holes(radius) mirrored() {
  //translate([0, 10]) square([15, 30], center=true);
  offset = spacing * 0.5 + 3;
  top_corner = [(cols - 1) * spacing+offset, (rows - 1) * spacing + offset - row_offset];
  rotate_half() {
    hole(top_corner, radius);
    hole([(cols - 1) * spacing + offset, spacing - offset - row_offset], radius);
    hole([2 * spacing + offset, -offset], radius);
    hole([-offset, -offset], radius);
  }
  translate([((cols - 2) * -spacing - offset) / cos(angle), 0]) rotate_half() hole(top_corner, radius);
}

module plate_middle() {
  union() {
    difference() {
      plate_bottom();
      hull() keys(spacing);
      //polygon([[0, 85],[-112,89],[-122,35],[0,0]]);
    }
    holes(washer_radius);
    //translate([0, 85]) polygon([[-20, -5],[20,-5],[32,7],[-32,7]]);
  }
  holes(hole_radius);
  //translate([0, 93]) square([38, 8], center=true);
  //translate([0, 93]) square([16, 30], center=true);
}

plate_top();
translate([0, 130]) plate_bottom();
translate([300, 130]) plate_middle();
