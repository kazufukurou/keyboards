// -*- mode: c -*-
/* All distances are in mm. */

$fn = 50;
simple = false;
angle = 10;
thumb_angle = simple ? 0 : 20;
hole_radius = 1.5;
washer_radius = 4 * hole_radius;
hand_distance = 8;
spacing = 19;
space_size = spacing + 1;
switch_size = 13.97;
key_size = 17;
rows = 4;
cols = 6;
row_offsets = [0, 0, 0, 4, 0, -4];

module rz(angle, center=undef) translate(center) rotate(angle) translate(-center) children();
module mirrored() { children(); mirror ([1,0,0]) { children(); } }
module key(pos, size) translate(pos) square([size, size], center=true);
module hole(pos, size) translate(pos) circle(size);
module add_hand_distance() translate([0.5 * hand_distance, 0]) children();
module rotate_half() add_hand_distance() rz(angle, [hand_distance, spacing]) children();
module plate_top() difference() { plate_bottom(); keys(space_size, false); }
module plate_bottom() difference() { hull() { holes(washer_radius); } holes(hole_radius); }
module plate_switch() difference() { plate_bottom(); keys(switch_size, true); }

module keys(size, switches) mirrored() rotate_half() {
  o = spacing*0.5;
  for (c=[1:(cols-1)]) for(r=[1:(rows-1)]) key([c*spacing + o, r*spacing + row_offsets[c] + o], size);
  //for (c=[(switches ? 2 :1):(cols-2)]) key([c*spacing + o, row_offsets[c] + o], size);
  for (c=[(switches ? 2 :1):(cols-3)]) key([c*spacing + o, o], size); 
  rz(thumb_angle, [2*spacing, 0]) {
    key([spacing + o, o + (simple ? row_offsets[1] : 0)], size);
    rz(thumb_angle, [spacing, 0]) {
      key([o, o], size);
      if (!switches && !simple) key([spacing + o, o], size);
    }
  }
}

module holes(radius) mirrored() {
  //translate([0, 30]) square([15, 30], center=true);
  o = 6;
  top_corner = [cols * spacing + o, rows*spacing + row_offsets[cols-1]];
  rotate_half() {
    hole(top_corner, radius);
    hole([cols * spacing + o, spacing + row_offsets[cols-1] - (simple ? spacing : 0)], radius);
    rz(thumb_angle, [2*spacing, 0]) rz(thumb_angle, [spacing, 0]) hole([o, row_offsets[0] - o], radius);
  }
  translate([(-spacing*4 - o*2) / cos(angle), 0]) rotate_half() hole(top_corner, radius);
}

module plate_middle() difference() {
  union() {
    difference() {
      plate_bottom();
      hull() keys(key_size, false);
    }
    holes(washer_radius);
    translate([0, 85]) polygon([[-20, -5],[20,-5],[40,5],[-40,5]]);
  }
  holes(hole_radius);
  translate([0, 95]) square([36, 15], center=true);
}

plate_switch();
//plate_bottom();
translate([0, 130]) plate_bottom();
//translate([300, 130]) plate_middle();
//translate([300, 0]) plate_top();